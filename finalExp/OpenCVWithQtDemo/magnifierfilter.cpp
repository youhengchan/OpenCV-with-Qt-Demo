/*
 * This file is part of wsapps & wslibs.
 *
 * Wslibs & Wsapps is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Wslibs & Wsapps distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Wslibs & Wsapps; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#include <stdio.h>
#include <string.h>
#include "magnifierfilter.h"

namespace namespace_wslibs{
	namespace namespace_wsbaswidgets{


MagnifierFilter::MagnifierFilter(int _w,int _h,int _factor,qreal curve)
{
	m_matrixX = NULL;
	m_matrixY = NULL;
	m_curve = curve;
	m_factor = _factor;
	init(_w,_h,_factor,curve);
}
MagnifierFilter::~MagnifierFilter()
{
	if(m_matrixX)
		delete m_matrixX;
	if(m_matrixY)
		delete m_matrixY;
}
void MagnifierFilter::init(int _w,int _h,int _factor,qreal curve)
{
	if(m_width == _w && m_height == _h && m_factor == _factor && m_curve == curve)
		return;
	if(m_matrixX)
		delete m_matrixX;
	if(m_matrixY)
		delete m_matrixY;
	m_width = _w;m_height = _h;
	int *dataX = (int*)malloc(m_width * m_height * sizeof(int));
	int *dataY = (int*)malloc(m_width * m_height * sizeof(int));
	m_easingCurve  = QEasingCurve(QEasingCurve::OutInQuad);
    int valuex,valuey;
    qreal s1,s2,l1,l2;
    l1 = 0.2;
    l2 = 0.8;
	qreal prog,prog1,prog2;
    s1 = m_easingCurve.valueForProgress(l1);
    s2 = m_easingCurve.valueForProgress(l2);
    qreal s = (s2 - s1)/(l2 - l1);
	for(int h = 0;h < m_height;h++){
		int pos = h * m_width;
        prog = qreal(h+1)/(qreal)m_height;
        if(prog < l1 || prog > l2){
            prog1 = m_easingCurve.valueForProgress(prog);
            valuey = m_height * prog1;
        }else{
            prog1 = (s) * (prog - l1) + s1 ; 
            valuey = m_height * prog1;
        }
		for(int w = 0;w < m_width;w++){
            prog = qreal(w+1)/(qreal)m_width;
            if(prog < l1 || prog > l2){
                prog2 = m_easingCurve.valueForProgress(prog);
                valuex = m_width * prog2;
            }else{
                prog2 = (s) * (prog - l1) + s1; 
                valuex = m_width * prog2;
            }
			dataX[pos + w] = valuex;
			dataY[pos + w] = valuey;
		}
	}
	m_matrixX = new WsMatrix(_w,_h,dataX);
	m_matrixY = new WsMatrix(_w,_h,dataY);
}
bool MagnifierFilter::selfCheck()
{
	return true;
}
QString MagnifierFilter::filterVersion()
{
	return "0.1";
}
QString MagnifierFilter::filterName()
{
	return "WsMagnifierFilter";
}
QString MagnifierFilter::filterDescription()
{
	return "a simpel magnifir";
}
QString MagnifierFilter::filterHomeUrl()
{
    return "";
}
bool MagnifierFilter::filter(const QImage & source,QImage & dest,QRect region)
{
	for(int i = region.left();i < region.right();i++){
		for(int j = region.top();j < region.bottom();j++){
			int x = m_matrixX->get(i,j);
			int y = m_matrixY->get(i,j);
			dest.setPixel(i,j,source.pixel(x,y));
		}
	}
	return true;
}

	}//wslibs
}//wsbaswidgets


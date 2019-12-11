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
#ifndef _magnifierfilter_h_
#define _magnifierfilter_h_
#include <QEasingCurve>
#include <QImage>
#include "wsmatrix.h"
namespace namespace_wslibs{
	namespace namespace_wsbaswidgets{
class MagnifierFilter
{
public:
	MagnifierFilter(int _w,int _h,int _factor,qreal curve);
	~MagnifierFilter();
	void init(int _w,int _h,int _factor,qreal curve);
	bool selfCheck();
	QString filterVersion();
	QString filterName();
	QString filterDescription();
	QString filterHomeUrl();
	bool filter(const QImage & source,QImage & dest,QRect region);
private:
	WsMatrix *m_matrixX;
	WsMatrix *m_matrixY;
	QEasingCurve m_easingCurve;
	int m_width;
	int m_height;
	int m_factor;
	qreal m_curve;
};

	}//wslibs
}//wsbaswidgets
#endif

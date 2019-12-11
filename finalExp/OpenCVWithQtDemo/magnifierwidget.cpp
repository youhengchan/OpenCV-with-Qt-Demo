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
#include <QDialog>
#include <QApplication>
#include <QMouseEvent>
#include <QVBoxLayout>
#include "magnifierwidget.h"

namespace namespace_wslibs{
	namespace namespace_wsbaswidgets{
	
DrawWidget::DrawWidget(MagnifierWidget *parent)
{
	QPalette pal = palette();
	pal.setBrush(QPalette::Base,Qt::transparent);
	setPalette(pal);
	setAutoFillBackground(false);
	m_magifier = parent;
}		
void DrawWidget::paintEvent(QPaintEvent *_event)
{
	QPainter paint(this);
	static QPixmap pix ;
	pix = QPixmap::fromImage(m_magifier->dest);
	//paint.drawImage(0,0,m_magifier->dest);
	paint.drawPixmap(0,0,pix);
	paint.drawEllipse(1,1,width()-2,height()-2);
}
MagnifierWidget::MagnifierWidget(const QRegion _region,QWidget *parent)
{
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags(Qt::Tool | Qt::FramelessWindowHint|Qt::WindowSystemMenuHint|Qt::WindowStaysOnTopHint ) ;
	m_maskRegion = _region;
	resize(160,160);
}
MagnifierWidget::MagnifierWidget(QWidget *parent)
{
	setWindowFlags(Qt::Tool | Qt::FramelessWindowHint|Qt::WindowSystemMenuHint|Qt::WindowStaysOnTopHint ) ;
#ifdef Q_WS_X11
//		printf("x11");
//		setWindowOpacity(0.5);
		setAttribute(Qt::WA_TranslucentBackground);				
#else
		setAttribute(Qt::WA_TranslucentBackground);				
#endif
	QVBoxLayout *layout = new QVBoxLayout;
	m_draw = new DrawWidget(this);
	layout->addWidget(m_draw);
	layout->setSpacing(0);
	layout->setMargin(0);
	setLayout(layout);
	resize(160,160);
	m_filter = new MagnifierFilter(160,160,2,0.1);	
	connect(&m_timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
}
MagnifierWidget::~MagnifierWidget()
{
}
void MagnifierWidget::setMaskRegion(const QRegion _region)
{
	m_maskRegion = _region;
}
void MagnifierWidget::focusInEvent(QFocusEvent *_event)
{
}
void MagnifierWidget::paintEvent(QPaintEvent *_event)
{
/*	QPainter paint(this);
	paint.drawPixmap(0,0,m_drawPixmap);*/
}
static bool in = false;
void MagnifierWidget::enterEvent(QEvent *_event)
{
	if(in){
		in = false;
	}else{
		QWidget *desktop = reinterpret_cast<QWidget*>(QApplication::desktop());	
		if(desktop != NULL){		
			setWindowOpacity(0.0);				
			m_capturePixmap = QPixmap::grabWindow(desktop->winId());//,pos().x(),pos().y(),width(),height());
			setWindowOpacity(1.0);	
			in = true;
			QPixmap drawpix = m_capturePixmap.copy(pos().x(),pos().y(),width(),height());
			source = drawpix.toImage();
			dest = source;
			m_filter->filter(source,dest,source.rect());
			m_draw->repaint();
		}
	}
	return QWidget::enterEvent(_event);
}
void MagnifierWidget::leaveEvent(QEvent *_event)
{
	return QWidget::leaveEvent(_event);
}
void MagnifierWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}
void MagnifierWidget::mouseReleaseEvent(QMouseEvent *_event)
{
	return QWidget::mouseReleaseEvent(_event);
}
void MagnifierWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
	return QWidget::mouseMoveEvent(event);
}
void MagnifierWidget::moveEvent(QMoveEvent *_event)
{		
	QPixmap drawpix = m_capturePixmap.copy(pos().x(),pos().y(),width(),height());
	source = drawpix.toImage();
	dest = source;
	m_filter->filter(source,dest,source.rect());		
	m_draw->repaint();
	return QWidget::moveEvent(_event);
}
void MagnifierWidget::slotTimer()
{
	return;
}

void MagnifierWidget::slotFocusChanged(QWidget*,QWidget*)
{
	QDialog dia;
	dia.exec();
}
void MagnifierWidget::resizeEvent(QResizeEvent *_event)
{
	if(m_maskRegion.isEmpty()){
		QRegion mask(0,0,width(),height(),QRegion::Ellipse);
		setMask(mask);
	}else{
		setMask(m_maskRegion);
	}	
	QWidget *desktop = reinterpret_cast<QWidget*>(QApplication::desktop());	
	if(desktop != NULL){		
		setWindowOpacity(0.0);				
		m_capturePixmap = QPixmap::grabWindow(desktop->winId(),pos().x(),pos().y(),width(),height());					
		setWindowOpacity(1.0);				
		source = m_capturePixmap.toImage();
		dest = source;
		m_filter->filter(source,dest,source.rect());		
	}	
	m_draw->repaint();	
}
	}//wslibs
}//wsbaswidgets


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
#ifndef _magnifier_h_
#define _magnifier_h_
#include <QPixmap>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QRegion>
#include "magnifierfilter.h"
namespace namespace_wslibs{
	namespace namespace_wsbaswidgets{
class DrawWidget;
class MagnifierWidget;	

class DrawWidget : public QWidget
{
	Q_OBJECT
public:
	DrawWidget(MagnifierWidget *parent);
	~DrawWidget(){}		
	void paintEvent(QPaintEvent *_event);
private:
	MagnifierWidget *m_magifier;
		
};

class MagnifierWidget : public QWidget
{
	Q_OBJECT
	friend class DrawWidget;
public:
	MagnifierWidget(const QRegion _region,QWidget *parent = NULL);
	MagnifierWidget(QWidget *parent = NULL);
	virtual ~MagnifierWidget();
	void setMaskRegion(const QRegion _region);
protected:
	void focusInEvent(QFocusEvent *_event);
	void paintEvent(QPaintEvent *_event);
	void enterEvent(QEvent *_event);
	void leaveEvent(QEvent *_event);
	void mousePressEvent(QMouseEvent *_event);
	void moveEvent(QMoveEvent *_event);
	void mouseReleaseEvent(QMouseEvent *_event);
	void mouseMoveEvent(QMouseEvent *_event);
	void resizeEvent(QResizeEvent *_event);
private slots:
	void slotFocusChanged(QWidget*,QWidget*);
	void slotTimer();
protected:	
	QPixmap m_capturePixmap;
private:	
	QRegion m_maskRegion;	
	QImage source;
	QImage dest;
	QPoint dragPosition;
	DrawWidget *m_draw;
	QTimer m_timer;
	QPoint m_pos;
	QRect m_rect;
	MagnifierFilter *m_filter;
};

		
	}//wslibs
}//wsbaswidgets
#endif

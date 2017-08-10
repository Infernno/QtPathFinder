#ifndef QVIEWZOOM_H
#define QVIEWZOOM_H

#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QApplication>
#include <QScrollBar>

#include <qmath.h>

class QViewZoom : public QObject
{
    Q_OBJECT
   public:
     QViewZoom(QGraphicsView* view);
     void gentle_zoom(double factor);
     void set_modifiers(Qt::KeyboardModifiers modifiers);
     void set_zoom_factor_base(double value);

   private:
     QGraphicsView* _view;
     Qt::KeyboardModifiers _modifiers;
     double _zoom_factor_base;
     QPointF target_scene_pos, target_viewport_pos;
     bool eventFilter(QObject* object, QEvent* event);

   signals:
     void zoomed();
};

#endif // QVIEWZOOM_H

#ifndef MEASUREBOX_H
#define MEASUREBOX_H

#include <QtGui>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

class MeasureBox : public QGraphicsRectItem {
      int instrumentId;
      int measureNumber;
public:
      MeasureBox();
      void mousePressEvent(QGraphicsSceneMouseEvent *event) {
            if(event->button() == Qt::LeftButton) {
                  if(event->modifiers() == Qt::ShiftModifier) {

                  } else if(event->modifiers() == Qt::AltModifier){

                  } else {
                        qDebug() << "Custom item left clicked.";
                        QGraphicsItem::mousePressEvent(event);
                        event->accept();

                        setBrush(QColor(Qt::black));
                  }
            } else if(event->button() == Qt::RightButton) {
                  qDebug() << "Custom item right clicked.";
                  event->ignore();
            }
      }

      int type() const {
            // Enable the use of qgraphicsitem_cast with this item.
            return UserType+1;
      }

      int getInstrumentId() {return instrumentId;}
      int getMeasureNumber() {return measureNumber;}
};

#endif // MEASUREBOX_H

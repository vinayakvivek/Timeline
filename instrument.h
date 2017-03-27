#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QGraphicsRectItem>

class Instrument
{
public:
      QString name;
      QGraphicsTextItem *nameText;
      QGraphicsRectItem *nameBox;
      QVector<QGraphicsRectItem*> measureBoxes;

      qreal nameBoxWidth, nameBoxLength;

      Instrument();
};

#endif // INSTRUMENT_H

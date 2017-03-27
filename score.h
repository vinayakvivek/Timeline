#ifndef SCORE_H
#define SCORE_H

#include "instrument.h"
#include "tempo.h"

#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

class Score
{
public:
      QVector<Instrument*> instruments;
      Tempo *tempo;

      QGraphicsScene *scene;
      QGraphicsRectItem *currentMeasure;

      qreal x, y; // top left point of Timeline
      qreal nameBoxWidth, nameBoxLength;
      int noOfMeasures;
      int count; // total no of rows

      Score();

      void addTitle();
      void addInstrument(QString name);
      void addTempo();
};

#endif // SCORE_H

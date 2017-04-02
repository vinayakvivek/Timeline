#ifndef TEMPO_H
#define TEMPO_H

#include <QGraphicsItem>
#include <QGraphicsScene>

class TempoItem {
      QString name;
public:
      QGraphicsRectItem *nameBox;
      QGraphicsTextItem *nameText;
      QColor nameColor;
      QColor textColor;
      int startMeasure;

      TempoItem();
      TempoItem(QString name, int startMeasure);
};

class Tempo
{
public:
      QString name;
      QGraphicsTextItem *nameText;
      QGraphicsRectItem *nameBox;
      QColor nameColor;
      qreal nameBoxWidth, nameBoxLength;

      QVector<QGraphicsRectItem*> measureBoxes;
      QVector<TempoItem*> tempoItems;
      qreal x, y;

      Tempo();
      void addTempoItem(QGraphicsScene *scene, QString name, int startMeasure);
};

#endif // TEMPO_H

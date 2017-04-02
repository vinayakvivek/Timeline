#include "score.h"

#include <QDebug>

Score::Score() {
      x = -100;
      y = 0;
      count = 0;
      nameBoxLength = 100;
      nameBoxWidth = 20;
      noOfMeasures = 30;

      instruments.resize(0);

}

void Score::addInstrument(QString name) {
      Instrument* newInstrument = new Instrument();
      newInstrument->name = name;
      qreal width = newInstrument->nameBoxWidth;
      qreal length = newInstrument->nameBoxLength;

      newInstrument->nameText = scene->addText(QString(name));
      newInstrument->nameText->setPos(x, y + count * width);
      newInstrument->nameBox = scene->addRect(QRectF(x, y + count * width, length, width));

      for (int i = 0; i < noOfMeasures; ++i) {
            QGraphicsRectItem *measureBox = scene->addRect(QRectF(x + length + i*width, y + count * width, width, width));
            measureBox->setToolTip(name + " measure " + QString("%1").arg(i + 1));
            newInstrument->measureBoxes.push_back(measureBox);
      }

      instruments.push_back(newInstrument);
      count++;
}

void Score::addTempo() {
      tempo = new Tempo();
      qreal width = tempo->nameBoxWidth;
      qreal length = tempo->nameBoxLength;

      tempo->x = x;
      tempo->y = y + count * width;
      tempo->nameText = scene->addText(tempo->name);
      tempo->nameText->setPos(x, y + count * width);
      tempo->nameBox = scene->addRect(QRectF(x, y + count * width, length, width));
      tempo->nameBox->setBrush(QBrush(tempo->nameColor));

      for (int i = 0; i < noOfMeasures; ++i) {
            tempo->measureBoxes.push_back(scene->addRect(QRectF(x + length + i*width, y + count * width, width, width)));
      }

      y += 5;
      count++;
}

void Score::addTitle() {
      qreal width = nameBoxWidth;
      qreal length = nameBoxLength;
      scene->addRect(x, y, length + noOfMeasures * width, width);
      scene->addText("Measures")->setPos(x, y);

      for (int i = 1; i <= noOfMeasures; i += 4) {
            scene->addText(QString("%1").arg(i))->setPos(x + length + (i-1)*width, y);
      }

      y += 5;
      count++;
}

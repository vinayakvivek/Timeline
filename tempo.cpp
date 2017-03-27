#include "tempo.h"

Tempo::Tempo() {
      name = QString("Tempo");
      nameBoxLength = 100;
      nameBoxWidth = 20;
      nameColor = QColor(0, 20, 30, 50);
}

void Tempo::addTempoItem(QGraphicsScene *scene, QString name, int startMeasure, int endMeasure) {
      TempoItem* newTempoItem = new TempoItem(name);
      newTempoItem->startMeasure = startMeasure;
      newTempoItem->endMeasure = endMeasure;

      newTempoItem->nameBox = scene->addRect(x + nameBoxLength + nameBoxWidth*(startMeasure-1), y, nameBoxWidth*(endMeasure - startMeasure + 1), nameBoxWidth);
      newTempoItem->nameBox->setBrush(QBrush(newTempoItem->nameColor));

      newTempoItem->nameText = scene->addText(name);
      newTempoItem->nameText->setPos(x + nameBoxLength + nameBoxWidth*(startMeasure-1), y);
      newTempoItem->nameText->setDefaultTextColor(newTempoItem->textColor);

      tempoItems.push_back(newTempoItem);
}

TempoItem::TempoItem(QString name) {
      this->name = name;
      nameColor = QColor(255, 0, 0, 200);
      textColor = QColor(255, 255, 255, 255);
}

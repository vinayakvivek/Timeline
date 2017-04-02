#include "tempo.h"
#include <QDebug>
#include <QFontMetrics>
#include <QPainter>

Tempo::Tempo() {
      name = QString("Tempo");
      nameBoxLength = 100;
      nameBoxWidth = 20;
      nameColor = QColor(0, 20, 30, 50);
}

void Tempo::addTempoItem(QGraphicsScene *scene, QString name, int startMeasure) {
      TempoItem* newTempoItem = new TempoItem(name, startMeasure);

      qreal xPos = x + nameBoxLength + nameBoxWidth*(startMeasure-1), yPos = y;
      qreal paddingRight = 10;

      QPainter painter;
      QFontMetrics fm = painter.fontMetrics();
      int boxLength = fm.width(name) + paddingRight;

      newTempoItem->nameBox = scene->addRect(xPos, yPos, boxLength, nameBoxWidth);
      newTempoItem->nameBox->setBrush(QBrush(newTempoItem->nameColor));

      newTempoItem->nameText = scene->addText(name);
      newTempoItem->nameText->setPos(xPos, yPos);
      newTempoItem->nameText->setDefaultTextColor(newTempoItem->textColor);

      tempoItems.push_back(newTempoItem);
}

TempoItem::TempoItem(QString name, int startMeasure) {
      this->name = name;
      this->startMeasure = startMeasure;
      nameColor = QColor(255, 0, 0, 150);
      textColor = QColor(0,0,0, 200);
}

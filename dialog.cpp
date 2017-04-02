#include "dialog.h"
#include "ui_dialog.h"

#include <QTimer>
#include "measurebox.h"

int randInt(int low, int high) {
      // Random number between low and high
      return qrand() % ((high + 1) - low) + low;
}

Dialog::Dialog(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::Dialog)
{
      ui->setupUi(this);

      scene = new QGraphicsScene(this);
      ui->graphicsView->setScene(scene);

      score = new Score();
      score->scene = scene;

      QVector<QString> instrumentNames;
      instrumentNames.push_back("Guitar");
      instrumentNames.push_back("Banjo");
      instrumentNames.push_back("Electric Guitar");
      instrumentNames.push_back("Piano");

      score->addTitle();
      score->addTempo();

      for (int i = 0; i < instrumentNames.size(); ++i) {
            score->addInstrument(instrumentNames[i]);
      }

      // add tempo items to score
      score->tempo->addTempoItem(scene, "Allegro", 2);
      score->tempo->addTempoItem(scene, "Slow", 10);
      score->tempo->addTempoItem(scene, "Moderato", 14);
      score->tempo->addTempoItem(scene, "Prestissimo", 22);

      // color a random measure boxes
      QTimer *timer = new QTimer(this);
      connect(timer, SIGNAL(timeout()), this, SLOT(colorMeasures()));
      timer->start(500);
}

Dialog::~Dialog()
{
      delete ui;
}


void Dialog::colorMeasures() {
      int instrumentId = randInt(0, score->instruments.size()-1);
      int measureNumber = randInt(0, score->noOfMeasures-1);

      score->instruments[instrumentId]->measureBoxes[measureNumber]->setBrush(QBrush(Qt::gray));
//      score->instruments[instrumentId]->measureBoxes[measureNumber]->setBrush(QBrush(QColor((instrumentId*5) % 256, (instrumentId*20) % 256, (instrumentId*110) % 256, 200)));
}

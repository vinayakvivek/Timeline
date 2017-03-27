#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

#include "score.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
      Ui::Dialog *ui;
      QGraphicsScene *scene;
      Score *score;

private slots:
      void colorMeasures();
};

#endif // DIALOG_H

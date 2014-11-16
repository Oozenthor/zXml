#ifndef XMLEXAMPLE_H
#define XMLEXAMPLE_H

#define FILENAME "xmlfile.xml"

#include <QDebug>
#include <QMainWindow>
#include <QFile>
#include "zxml.h"

namespace Ui {
class xmlExample;
}

class xmlExample : public QMainWindow
{
  Q_OBJECT

public:
  explicit xmlExample(QWidget *parent = 0);
  ~xmlExample();

private:
  Ui::xmlExample *ui;
};

#endif // XMLEXAMPLE_H

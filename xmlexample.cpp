#include "xmlexample.h"
#include "ui_xmlexample.h"

xmlExample::xmlExample(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::xmlExample)
{
  ui->setupUi(this);

  QFile file("xmlfile.xml");

  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "Cannot read file";
    return;
  }

  ZXml xmlContents;

  if (!xmlContents.xmlRead(&file)) {
    qDebug() << "Parse error in file";
  } else {
    qDebug() << "File loaded";
  }
}

xmlExample::~xmlExample()
{
  delete ui;
}

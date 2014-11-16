#include "zxml.h"

ZXml::ZXml()
{
}

bool ZXml::xmlRead(QIODevice *device)
{
  xml.setDevice(device); // Set read position to start of file
  if (xml.readNextStartElement()) { // Find first level (root) xml tag
    qDebug() << "Root Name" << xml.name();
    if (xml.name() == XMLDOCTYPE && xml.attributes().value("version") == XMLVERSION) {
      readXmlContents();
    } else {
      qDebug() << "File has incorrect DocType /  Version.";
      xml.raiseError(QObject::tr("File has incorrect DocType /  Version."));
    }
  }
  return !xml.error();
}

QString ZXml::errorString() const
{
  return QObject::tr("%1\nLine %2, column %3")
      .arg(xml.errorString())
      .arg(xml.lineNumber())
      .arg(xml.columnNumber());
}

void ZXml::readXmlContents()  // Pick off second level xml tags
{
  qDebug() << "Contents:";

  Q_ASSERT(xml.isStartElement() && xml.name() == XMLDOCTYPE);

  while (xml.readNextStartElement()) {
    if (xml.name() == "Number") {
      qDebug() << xml.name();
      readNumber();
    } else {
      xml.skipCurrentElement();
    }
  }
}

void ZXml::readNumber()
{
  Q_ASSERT(xml.isStartElement() && xml.name() == "Number");
  bool ok;
  int value = xml.attributes().value("value").toInt(&ok);
  if (ok) {
    qDebug() << value;
  } else {
    qDebug() << "Value not found.";
  }

  while (xml.readNextStartElement()) {
    if (xml.name() == "Name")
      readName();
    else if (xml.name() == "Roman")
      readRoman();
    else
      xml.skipCurrentElement();
  }
}

void ZXml::readName()
{
  Q_ASSERT(xml.isStartElement() && xml.name() == "Name");
  qDebug() << xml.readElementText();
}

void ZXml::readRoman()
{
  Q_ASSERT(xml.isStartElement() && xml.name() == "Roman");
  qDebug() << xml.readElementText();
}

void ZXml::readValue()
{
  Q_ASSERT(xml.isStartElement() && xml.name() == "Value");
  qDebug() << xml.readElementText();
}

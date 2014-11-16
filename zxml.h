#ifndef ZXML_H
#define ZXML_H

#define XMLDOCTYPE "NumberInfo"
#define XMLVERSION "1.0"

#include <QDebug>
#include <QXmlStreamReader>

class ZXml
{
public:
  ZXml();

  bool xmlRead(QIODevice *device);
  QString errorString() const;

private:
  void readXmlContents();
  void readNumber();
  void readName();
  void readRoman();
  void readValue();

  QXmlStreamReader xml;
};

#endif // ZXML_H

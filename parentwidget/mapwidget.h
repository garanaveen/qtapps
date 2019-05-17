#pragma once

#include <QWidget>
class MapWidget : public QWidget
{
   Q_OBJECT

public:
   explicit MapWidget(QWidget* parent = NULL);
   virtual ~MapWidget();
   void EmitDummySignal();


signals:
   void DummySignal();

//public slots:
//   void DummySlot();

};

class BasicMapWidget: public MapWidget
{
   Q_OBJECT
public:
   BasicMapWidget(QWidget* parent = NULL);
   virtual ~BasicMapWidget();
};

class MapWidgetWithControls: public BasicMapWidget
{
   Q_OBJECT
public:
   MapWidgetWithControls(QWidget* parent = NULL);
   virtual ~MapWidgetWithControls();

//signals:
//   void DummySignal();

public slots:
   void DummySlot();
};

class InvalidClass
{

};

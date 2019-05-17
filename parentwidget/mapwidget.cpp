#include "mapwidget.h"
#include <QDebug>

MapWidget::MapWidget(QWidget* parent)
        :QWidget(parent)
{
}

MapWidget::~MapWidget()
{

}

void MapWidget::EmitDummySignal()
{
   emit DummySignal();
}

BasicMapWidget::BasicMapWidget(QWidget* parent)
        :MapWidget(parent)
{

}

BasicMapWidget::~BasicMapWidget()
{

}

MapWidgetWithControls::MapWidgetWithControls(QWidget* parent)
        :BasicMapWidget(parent)
{

}

MapWidgetWithControls::~MapWidgetWithControls()
{

}

void MapWidgetWithControls::DummySlot()
{
   qDebug() << "MapWidgetWithControls::DummySlot";

   Q_ASSERT(dynamic_cast<QWidget*>(sender()));
   Q_ASSERT(dynamic_cast<MapWidget*>(sender()));
   Q_ASSERT(dynamic_cast<MapWidgetWithControls*>(sender()));
//   Q_ASSERT(dynamic_cast<InvalidClass*>(sender()));// Will crash
}

#include "customitem.h"

CustomItem::CustomItem(QTreeWidgetItem *parent, const QStringList &strings, int type) : QTreeWidgetItem(parent,strings,type)
{
    m_objectName = strings.first();
}

CustomItem::~CustomItem()
{
    qDebug() << QString("%1 destruido").arg(this->data(0,Qt::EditRole).toString());
}

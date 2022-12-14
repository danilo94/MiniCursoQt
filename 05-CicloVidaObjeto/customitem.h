#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QTreeWidgetItem>
#include <QObject>
#include <QWidget>

class CustomItem : public QTreeWidgetItem
{
public:
    CustomItem(QTreeWidgetItem *parent, const QStringList &strings, int type = Type);

    ~CustomItem();


private:

    QString m_objectName;

};

#endif // CUSTOMITEM_H

#include "serializableobject.h"
#include <QVariant>
#include <QMetaObject>

SerializableObject::SerializableObject(QObject *parent) :
    QObject(parent)
{
}

SerializableObject::~SerializableObject()
{
}

QDataStream &operator<<(QDataStream &ds, const SerializableObject &obj)
{
    for(int i=0; i<obj.metaObject()->propertyCount(); ++i)
    {
        if(obj.metaObject()->property(i).isStored(&obj))
        {
            ds << obj.metaObject()->property(i).read(&obj);
        }
    }
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SerializableObject &obj)
{
    QVariant var;
    for(int i=0; i<obj.metaObject()->propertyCount(); ++i)
    {
        if(obj.metaObject()->property(i).isStored(&obj))
        {
            ds >> var;
            obj.metaObject()->property(i).write(&obj, var);
        }
    }
    return ds;
}

QDataStream &operator<<(QDataStream &ds, const SerializableObject* obj)
{
    for(int i=0; i<obj->metaObject()->propertyCount(); ++i)
    {
        if(obj->metaObject()->property(i).isStored(obj))
        {
            ds << obj->metaObject()->property(i).read(obj);
        }
    }
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SerializableObject *obj)
{
    QVariant var;
    if(obj)
    {
        for(int i=0; i<obj->metaObject()->propertyCount(); ++i)
        {
            if(obj->metaObject()->property(i).isStored(obj))
            {
                ds >> var;
                obj->metaObject()->property(i).write(obj, var);
            }
        }
    }
    return ds;
}

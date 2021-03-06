#include "message.h"

Message::Message()
{
}

Message::Message(const Message &copy)
{
    data = copy.data;
    messageSender = copy.messageSender;
    dest = copy.dest;
}

bool Message::operator==(const Message &obj)
{
    if(data == obj.data &&
       messageSender == obj.messageSender &&
       dest == obj.dest)
        return true;
    else
        return false;
}

QByteArray Message::getData() const
{
    return data;
}

void Message::setData(const QByteArray &value)
{
    data = value;
}

QString Message::getMessageSender() const
{
    return messageSender;
}

void Message::setMessageSender(const QString &value)
{
    messageSender = value;
}

MessageDestination Message::getDest() const
{
    return dest;
}

void Message::setDest(const MessageDestination &value)
{
    dest = value;
}

void Message::setDest(const int& value)
{
    dest = (MessageDestination)value;
}





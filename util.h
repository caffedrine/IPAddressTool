#ifndef UTIL_H
#define UTIL_H

#include <QCoreApplication>
#include <QHostAddress>

/* Regex stuff */
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

namespace ipv4util
{

bool IsValidIPv4(QString ip)
{
    QHostAddress address(ip);
    if (QAbstractSocket::IPv4Protocol == address.protocol())
    {
        return true;
    }
    else if (QAbstractSocket::IPv6Protocol == address.protocol())
    {
        /* IP given is v6 */
        return false;
    }
    else
    {
        return false;
    }
}

QStringList GetMatches(QString regexPattern, QString str)
{
    QStringList list;

    /* Regex to match ip address */
    QRegularExpression validator(regexPattern);

    /* Get matches */
    QRegularExpressionMatchIterator lineMatches = validator.globalMatch(str);

    /* Fill list with matches*/
    while(lineMatches.hasNext())
    {
        QRegularExpressionMatch match = lineMatches.next();
        if(match.hasMatch())
        {
            list.append(match.captured(0));
        }
    }

    return list;
}

QStringList ExtractIPv4Addresses(QString str)
{
    /* Regex to match ip address */
    QString pattern = ("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");

    return GetMatches(pattern, str);
}

long Dotted2LongIPv4(QString ip)
{
    QHostAddress address(ip);
    return (long)address.toIPv4Address();
}

QString Long2DottedIPv4(long ip)
{
    QHostAddress address(ip);
    return address.toString();
}

}/* Namespace */

#endif // UTIL_H

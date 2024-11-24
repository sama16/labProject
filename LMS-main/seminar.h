#ifndef SEMINAR_H
#define SEMINAR_H

#include <QString>
#include <QDate>
#include <QList>

class Seminar {
public:
    QString title;
    QString speaker;
    QDate date;
    QString description;
    QList<QString> feedback;

    Seminar(const QString &t, const QString &s, const QDate &d, const QString &desc)
        : title(t), speaker(s), date(d), description(desc) {}
};

#endif // SEMINAR_H

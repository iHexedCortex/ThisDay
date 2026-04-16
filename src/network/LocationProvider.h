#ifndef LOCATIONPROVIDER_H
#define LOCATIONPROVIDER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class LocationProvider : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentCity READ getCurrentCity NOTIFY locationChanged)
public:
    explicit LocationProvider(QObject *parent = nullptr);

    QString getCurrentCity() const;

    Q_INVOKABLE void detect();

signals:
    void locationChanged();
    void locationDetected(QString currentCity);

private slots:
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QString currentCity = "Detecting...";
};

#endif // LOCATIONPROVIDER_H

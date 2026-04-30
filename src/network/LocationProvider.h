#ifndef LOCATIONPROVIDER_H
#define LOCATIONPROVIDER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class LocationProvider : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double latitude READ getLatitude NOTIFY locationChanged)
    Q_PROPERTY(double longitude READ getLongitude NOTIFY locationChanged)
    Q_PROPERTY(QString city READ getCity NOTIFY locationChanged)
    Q_PROPERTY(QString country READ getCountry NOTIFY locationChanged)

public:
    explicit LocationProvider(QObject *parent = nullptr);

    double getLatitude() const;
    double getLongitude() const;
    QString getCity() const;
    QString getCountry() const;

    Q_INVOKABLE void detectCity();
    Q_INVOKABLE void searchCity(const QString &city);

signals:
    void locationChanged();
    void cityDetected(QString currentCity);
    void coordinatesFound(double latitude, double longitude);

private slots:
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;

    double latitude;
    double longitude;
    QString city;
    QString country;
};

#endif // LOCATIONPROVIDER_H

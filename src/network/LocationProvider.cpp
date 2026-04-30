#include "LocationProvider.h"

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

LocationProvider::LocationProvider(QObject *parent) : QObject(parent)
{
    this->manager = new QNetworkAccessManager(this);
    this->connect(this->manager, &QNetworkAccessManager::finished, this, &LocationProvider::onResult);
}

void LocationProvider::detectCity() {
    QUrl url("http://ip-api.com/json");
    QNetworkRequest request(url);

    this->manager->get(request);
}

void LocationProvider::searchCity(const QString &city) {
    QUrl url(QString(
        "https://geocoding-api.open-meteo.com/v1/search?name=%1&count=1&language=en&format=json"
    ).arg(city));
    QNetworkRequest request(url);

    this->manager->get(request);
}

void LocationProvider::onResult(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Location Provider Error:" << reply->errorString();
        reply->deleteLater();

        return;
    }

    QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
    QJsonObject json = jsonDocument.object();

    if (json.contains("results")) {
        QJsonArray results = json["results"].toArray();

        if (!results.isEmpty()) {
            QJsonObject resultObj = results[0].toObject();

            this->latitude = resultObj["latitude"].toDouble();
            this->longitude = resultObj["longitude"].toDouble();
            this->country = resultObj["country"].toString();
            this->city = resultObj["name"].toString();

            emit this->coordinatesFound(this->latitude, this->longitude);
        }
    }
    else if (json["status"].toString() == "success") {
        this->city = json["city"].toString();

        emit this->cityDetected(this->city);
    }

    emit this->locationChanged();
    reply->deleteLater();
}

double LocationProvider::getLatitude() const {
    return this->latitude;
}

double LocationProvider::getLongitude() const {
    return this->longitude;
}

QString LocationProvider::getCity() const {
    return this->city;
}

QString LocationProvider::getCountry() const {
    return this->country;
}

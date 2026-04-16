#include "LocationProvider.h"
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

LocationProvider::LocationProvider(QObject *parent) : QObject{parent}
{
    this->manager = new QNetworkAccessManager(this);
    this->connect(this->manager, &QNetworkAccessManager::finished, this, &LocationProvider::onResult);
}

void LocationProvider::detect() {
    QUrl url("http://ip-api.com/json");
    QNetworkRequest request(url);

    this->manager->get(request);
}

void LocationProvider::onResult(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
        QJsonObject json = jsonDocument.object();

        if (json["status"].toString() == "success") {
            this->currentCity = json["city"].toString();

            emit this->locationChanged();
            emit this->locationDetected(this->currentCity);
        }
    } else {
        qDebug() << "Location Provider Error:" << reply->errorString();
    }

    reply->deleteLater();
}

QString LocationProvider::getCurrentCity() const {
    return this->currentCity;
}

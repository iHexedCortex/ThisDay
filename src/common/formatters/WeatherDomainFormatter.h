#ifndef WEATHERDOMAINFORMATTER_H
#define WEATHERDOMAINFORMATTER_H

#include <QString>

class WeatherDomainFormatter final
{

public:
    static QString pressure(double value);
    static QString visibility(double value);
    static QString percent(double value);
};

#endif // WEATHERDOMAINFORMATTER_H

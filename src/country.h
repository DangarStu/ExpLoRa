#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

enum class CountryCode {
    AF, // Afghanistan
    AL, // Albania
    DZ, // Algeria
    US, // United States
    AR, // Argentina
    AU, // Australia
    BR, // Brazil
    CA, // Canada
    CN, // China
    FR, // France
    DE, // Germany
    IN, // India
    ID, // Indonesia
    IT, // Italy
    JP, // Japan
    KE, // Kenya
    MX, // Mexico
    NG, // Nigeria
    PK, // Pakistan
    PH, // Philippines
    RU, // Russia
    SA, // Saudi Arabia
    ZA, // South Africa
    KR, // South Korea
    ES, // Spain
    SE, // Sweden
    CH, // Switzerland
    TH, // Thailand
    GB, // United Kingdom
    VN, // Vietnam
    UNKNOWN // Reserved for unknown or invalid codes
};

class Country {
public:
    // Constructor
    Country(CountryCode code);

    // Method to get the two-letter country code as a string
    std::string toString() const;

private:
    CountryCode countryCode;
};

#endif // COUNTRY_H

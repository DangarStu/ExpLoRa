#include <string>
#include <iostream>
#include <country.h>

// Constructor to initialize with a CountryCode
Country::Country(CountryCode countryCode) : countryCode(countryCode) {}

// Method to get the two-character string representation
std::string Country::toString() const {
    switch (countryCode) {
        case CountryCode::AF: return "AF";
        case CountryCode::AL: return "AL";
        case CountryCode::DZ: return "DZ";
        case CountryCode::US: return "US";
        case CountryCode::AR: return "AR";
        case CountryCode::AU: return "AU";
        case CountryCode::BR: return "BR";
        case CountryCode::CA: return "CA";
        case CountryCode::CN: return "CN";
        case CountryCode::FR: return "FR";
        case CountryCode::DE: return "DE";
        case CountryCode::IN: return "IN";
        case CountryCode::ID: return "ID";
        case CountryCode::IT: return "IT";
        case CountryCode::JP: return "JP";
        case CountryCode::KE: return "KE";
        case CountryCode::MX: return "MX";
        case CountryCode::NG: return "NG";
        case CountryCode::PK: return "PK";
        case CountryCode::PH: return "PH";
        case CountryCode::RU: return "RU";
        case CountryCode::SA: return "SA";
        case CountryCode::ZA: return "ZA";
        case CountryCode::KR: return "KR";
        case CountryCode::ES: return "ES";
        case CountryCode::SE: return "SE";
        case CountryCode::CH: return "CH";
        case CountryCode::TH: return "TH";
        case CountryCode::GB: return "GB";
        case CountryCode::VN: return "VN";
        default: return "Unknown";
    }
}



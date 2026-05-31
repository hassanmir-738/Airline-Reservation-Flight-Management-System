#include "../include/InternationalFlight.h"
#include <iomanip>

using namespace std;

InternationalFlight::InternationalFlight(string fNum, string orig, string dest,
                                         string date, string time, int total,
                                         int available, bool visa, string country)
    : Flight(fNum, orig, dest, date, time, total, available),
      visaRequired(visa), destinationCountry(country) {}

InternationalFlight::~InternationalFlight() {}

// International flights have a higher base fare
double InternationalFlight::calculateBaseFare() const {
    return 500.0; // $500 flat base fare for international routes
}

void InternationalFlight::displayDetails() const {
    cout << "=== INTERNATIONAL FLIGHT ===" << endl;
    cout << "Flight Number      : " << getFlightNumber() << endl;
    cout << "Route              : " << getOrigin() << " -> " << getDestination() << endl;
    cout << "Date & Time        : " << getDepartureDate() << " at " << getDepartureTime() << endl;
    cout << "Destination Country: " << destinationCountry << endl;
    // Use if-else instead of ternary for beginner clarity
    if (visaRequired) {
        cout << "Visa Required      : Yes" << endl;
    } else {
        cout << "Visa Required      : No" << endl;
    }
    cout << "Seats              : " << getAvailableSeats() << "/" << getTotalSeats() << " available" << endl;
    cout << "Base Fare          : $" << fixed << setprecision(2) << calculateBaseFare() << endl;
    cout << "=============================" << endl;
}

string InternationalFlight::getFlightType() const {
    return "International";
}

bool InternationalFlight::isVisaRequired() const {
    return visaRequired;
}

string InternationalFlight::getDestinationCountry() const {
    return destinationCountry;
}

string InternationalFlight::toFileString() const {
    // Format: International,fNum,orig,dest,date,time,total,avail,visa,country
    string visaStr;
    if (visaRequired) {
        visaStr = "1";
    } else {
        visaStr = "0";
    }
    return "International," + Flight::toFileString() + "," + visaStr + "," + destinationCountry;
}

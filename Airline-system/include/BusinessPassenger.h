#ifndef BUSINESS_PASSENGER_H
#define BUSINESS_PASSENGER_H

#include "Passenger.h"

// Business class passenger - higher fare, 35 kg baggage, 75% refund
class BusinessPassenger : public Passenger {
public:
    BusinessPassenger(string id, string n, string ph, string em);
    ~BusinessPassenger();

    double getBaggageAllowance() const;  // 35 kg
    double getLoyaltyMultiplier() const; // 1.5x points
    double getRefundPercentage() const;  // 75% refund
    string getPassengerType() const;
    void displayInfo() const;
};

#endif

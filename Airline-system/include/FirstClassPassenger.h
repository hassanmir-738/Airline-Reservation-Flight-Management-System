#ifndef FIRST_CLASS_PASSENGER_H
#define FIRST_CLASS_PASSENGER_H

#include "Passenger.h"

// First class passenger - premium fare, 50 kg baggage, 90% refund
class FirstClassPassenger : public Passenger {
public:
    FirstClassPassenger(string id, string n, string ph, string em);
    ~FirstClassPassenger();

    double getBaggageAllowance() const;  // 50 kg
    double getLoyaltyMultiplier() const; // 2.0x points
    double getRefundPercentage() const;  // 90% refund
    string getPassengerType() const;
    void displayInfo() const;
};

#endif

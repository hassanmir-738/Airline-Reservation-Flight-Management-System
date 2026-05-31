#ifndef ECONOMY_PASSENGER_H
#define ECONOMY_PASSENGER_H

#include "Passenger.h"

// Economy class passenger - basic fare, 20 kg baggage, 50% refund
class EconomyPassenger : public Passenger {
public:
  EconomyPassenger(string id, string n, string ph, string em);
  ~EconomyPassenger();

  double getBaggageAllowance() const;  // 20 kg
  double getLoyaltyMultiplier() const; // 1.0x points
  double getRefundPercentage() const;  // 50% refund
  string getPassengerType() const;
  void displayInfo() const;
};

#endif

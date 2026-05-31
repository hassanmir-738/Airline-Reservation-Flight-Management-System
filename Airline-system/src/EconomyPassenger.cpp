#include "../include/EconomyPassenger.h"

using namespace std;

EconomyPassenger::EconomyPassenger(string id, string n, string ph, string em)
    : Passenger(id, n, ph, em) {}

EconomyPassenger::~EconomyPassenger() {}

double EconomyPassenger::getBaggageAllowance() const {
    return 20.0; // 20 kg for economy class
}

double EconomyPassenger::getLoyaltyMultiplier() const {
    return 1.0; // 1.0x multiplier (base rate)
}

double EconomyPassenger::getRefundPercentage() const {
    return 50.0; // 50% refund on cancellation
}

string EconomyPassenger::getPassengerType() const {
    return "Economy";
}

void EconomyPassenger::displayInfo() const {
    cout << "=== ECONOMY PASSENGER ===" << endl;
    Passenger::displayInfo(); // call base class display
    cout << "Baggage       : " << getBaggageAllowance() << " kg" << endl;
    cout << "Refund Rate   : " << getRefundPercentage() << "%" << endl;
    cout << "=========================" << endl;
}

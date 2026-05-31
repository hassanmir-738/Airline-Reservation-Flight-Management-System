# SkyLink Airways - Airline Reservation & Flight Management System

## Overview
A console-based C++ application for managing airline flights, passengers, ticket bookings, cancellations with refund rules, and generating reports. Built using Object-Oriented Programming principles.

## Project Structure
```
Airline-system/
├── include/                    # Header files
│   ├── Flight.h               # Abstract base class for flights
│   ├── DomesticFlight.h       # Domestic flight derived class
│   ├── InternationalFlight.h  # International flight derived class
│   ├── CharterFlight.h        # Charter flight derived class
│   ├── Passenger.h            # Abstract base class for passengers
│   ├── EconomyPassenger.h     # Economy passenger derived class
│   ├── BusinessPassenger.h    # Business passenger derived class
│   ├── FirstClassPassenger.h  # First class passenger derived class
│   ├── Ticket.h               # Ticket class
│   ├── Airline.h              # Main airline aggregation class
│   ├── Exceptions.h           # Custom exception classes
│   └── SearchUtility.h        # Template search utility
├── src/                        # Implementation files
│   ├── main.cpp               # Main program with menu interface
│   ├── Flight.cpp             # Flight base class implementation
│   ├── DomesticFlight.cpp     # Domestic flight implementation
│   ├── InternationalFlight.cpp# International flight implementation
│   ├── CharterFlight.cpp      # Charter flight implementation
│   ├── Passenger.cpp          # Passenger base class implementation
│   ├── EconomyPassenger.cpp   # Economy passenger implementation
│   ├── BusinessPassenger.cpp  # Business passenger implementation
│   ├── FirstClassPassenger.cpp# First class passenger implementation
│   ├── Ticket.cpp             # Ticket implementation
│   └── Airline.cpp            # Airline class implementation
├── Makefile                    # Build configuration
├── README.md                   # This file
└── instructions.md             # Assignment instructions
```

## How to Build

### Using g++ directly (Windows):
```bash
g++ -std=c++17 -Wall -Wextra -I include -o airline_system src/main.cpp src/Flight.cpp src/DomesticFlight.cpp src/InternationalFlight.cpp src/CharterFlight.cpp src/Passenger.cpp src/EconomyPassenger.cpp src/BusinessPassenger.cpp src/FirstClassPassenger.cpp src/Ticket.cpp src/Airline.cpp
```

### Using Make:
```bash
make
```

## How to Run
```bash
./airline_system       # Linux/Mac
airline_system.exe     # Windows
```

## Features
1. **Flight Management** - Add, remove, search (by number/route/date), and list flights
2. **Passenger Management** - Register, remove, and view booking history
3. **Ticket Booking** - Book seats with automatic fare calculation
4. **Cancellation & Refund** - Polymorphic refund based on passenger class and timing
5. **Reports** - Today's departures, occupancy percentage, top 5 revenue flights
6. **Data Persistence** - Auto-save/load system state to file
7. **Sample Data** - Pre-loaded 10 flights and 8 passengers for demonstration

## OOP Features Used
- **Abstract Base Classes**: `Flight` and `Passenger` with pure virtual functions
- **Inheritance**: 3 flight types + 3 passenger types
- **Polymorphism**: Virtual functions for fare calculation, refund rules, display
- **Encapsulation**: Private data members with getters/setters
- **Operator Overloading**: `<<` for Flight/Ticket display, `==` for Ticket comparison
- **Templates**: Generic search utility (`SearchUtility.h`)
- **Exception Handling**: `FlightFullException`, `InvalidCancellationException`, `DuplicateBookingException`
- **STL Usage**: `vector`, `map`, `sort`, `find_if`, `copy_if`
- **Smart Pointers**: `shared_ptr` for memory safety
- **File I/O**: Text-based persistence for all data

## Sample Data
The program includes a "Load Sample Data" option (Menu #13) that adds:
- 4 Domestic flights (Karachi, Lahore, Islamabad, Peshawar routes)
- 3 International flights (Dubai, London, Istanbul routes)
- 3 Charter flights (Skardu, Gilgit, Chitral routes)
- 3 Economy passengers, 2 Business passengers, 3 First Class passengers

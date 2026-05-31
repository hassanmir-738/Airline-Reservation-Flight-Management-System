# ✈️ SkyLink Airways — Airline Reservation & Flight Management System

A console-based **C++ application** that simulates a real airline reservation system. Built as an Object-Oriented Programming (OOP) assignment, it demonstrates all four OOP pillars — **Encapsulation, Inheritance, Polymorphism, and Abstraction** — applied to a real-world problem.

---

## 👨‍💻 Author

| Field | Details |
|---|---|
| **Name** | Hassan Ali Mir |
| **Roll No** | 2025-SET-02 |
| **Semester** | 2nd Semester |
| **University** | University of Azad Jammu & Kashmir |
| **Department** | Software Engineering |
| **Course** | Object-Oriented Programming (C++) |

---

## 📋 Table of Contents

- [Features](#-features)
- [OOP Concepts Used](#-oop-concepts-used)
- [Project Structure](#-project-structure)
- [Class Hierarchy](#-class-hierarchy)
- [How to Build](#-how-to-build)
- [How to Run](#-how-to-run)
- [Menu Options](#-menu-options)
- [Sample Data](#-sample-data)
- [Refund Rules](#-refund-rules)

---

## ✨ Features

- ✅ **Flight Management** — Add, remove, and search flights by number, route, or date
- ✅ **Passenger Management** — Register passengers in Economy, Business, or First Class
- ✅ **Ticket Booking** — Book seats with automatic fare calculation and seat assignment
- ✅ **Cancellation & Refund** — Polymorphic refund rules based on passenger class and timing
- ✅ **Reports** — Today's departures, occupancy percentages, and top 5 revenue flights
- ✅ **Loyalty Points** — Automatically awarded on every booking (multiplier varies by class)
- ✅ **Data Persistence** — All data auto-saved to `skylink_data.txt` and reloaded on startup
- ✅ **Input Validation** — Safe integer and decimal reading prevents crashes on bad input
- ✅ **Sample Data** — 10 pre-configured flights and 8 passengers for quick demonstration

---

## 🧠 OOP Concepts Used

| Concept | Where It Is Applied |
|---|---|
| **Abstraction** | `Flight` and `Passenger` are abstract base classes with pure virtual functions — they cannot be created directly |
| **Inheritance** | `DomesticFlight`, `InternationalFlight`, `CharterFlight` inherit from `Flight`; `EconomyPassenger`, `BusinessPassenger`, `FirstClassPassenger` inherit from `Passenger` |
| **Polymorphism** | `calculateBaseFare()`, `getRefundPercentage()`, `getLoyaltyMultiplier()`, and `displayDetails()` behave differently based on the actual object type at runtime |
| **Encapsulation** | All data members are `private` or `protected`; external code accesses them only through getter/setter methods |
| **Virtual Destructor** | Declared in both base classes to ensure correct memory cleanup through base-class pointers |
| **Memory Management** | All heap objects (`new`) are manually deleted in `Airline::~Airline()` to prevent memory leaks |

---

## 📁 Project Structure

```
Airline-system/
│
├── include/                        # Header files (class declarations)
│   ├── Flight.h                   # Abstract base class for all flights
│   ├── DomesticFlight.h           # Domestic flight (flat $150 fare)
│   ├── InternationalFlight.h      # International flight ($500 fare, visa info)
│   ├── CharterFlight.h            # Charter flight (contract-based pricing)
│   ├── Passenger.h                # Abstract base class for all passengers
│   ├── EconomyPassenger.h         # Economy: 20 kg baggage, 50% refund
│   ├── BusinessPassenger.h        # Business: 35 kg baggage, 75% refund
│   ├── FirstClassPassenger.h      # First Class: 50 kg baggage, 90% refund
│   ├── Ticket.h                   # Ticket class (links passenger to flight)
│   ├── Airline.h                  # Main aggregation class
│   ├── Exceptions.h               # (Reserved for future use)
│   └── SearchUtility.h            # (Reserved for future use)
│
├── src/                            # Implementation files
│   ├── main.cpp                   # Entry point, menu loop, input handlers
│   ├── Flight.cpp                 # Base flight implementation
│   ├── DomesticFlight.cpp
│   ├── InternationalFlight.cpp
│   ├── CharterFlight.cpp
│   ├── Passenger.cpp              # Base passenger implementation
│   ├── EconomyPassenger.cpp
│   ├── BusinessPassenger.cpp
│   ├── FirstClassPassenger.cpp
│   ├── Ticket.cpp
│   └── Airline.cpp                # Core system logic (booking, reports, file I/O)
│
├── Makefile                        # Build configuration
├── skylink_data.txt               # Auto-generated save file (created on first exit)
├── README.md                       # This file
└── instructions.md                 # Original assignment instructions
```

---

## 🗂️ Class Hierarchy

```
Flight  (abstract)
├── DomesticFlight          → base fare: $150 flat
├── InternationalFlight     → base fare: $500 flat  +  visa / country info
└── CharterFlight           → base fare: contract price ÷ total seats

Passenger  (abstract)
├── EconomyPassenger        → 20 kg  |  1.0× points  |  50% refund
├── BusinessPassenger       → 35 kg  |  1.5× points  |  75% refund
└── FirstClassPassenger     → 50 kg  |  2.0× points  |  90% refund

Ticket                      → links Passenger ↔ Flight (non-abstract)
Airline                     → owns and manages all flights, passengers, tickets
```

---

## 🔧 How to Build

### Requirements
- **g++** with C++17 support (`g++ --version` to check)
- On Windows: [MinGW](https://www.mingw-w64.org/) or [TDM-GCC](https://jmeubank.github.io/tdm-gcc/)
- On Linux/macOS: g++ is usually pre-installed

### Option A — Single g++ command

```bash
g++ -std=c++17 -Wall -Wextra -I include \
    src/main.cpp \
    src/Flight.cpp src/DomesticFlight.cpp src/InternationalFlight.cpp src/CharterFlight.cpp \
    src/Passenger.cpp src/EconomyPassenger.cpp src/BusinessPassenger.cpp src/FirstClassPassenger.cpp \
    src/Ticket.cpp src/Airline.cpp \
    -o airline_system
```

### Option B — Using Make

```bash
make
```

> Run `make clean` to remove the compiled binary.

---

## ▶️ How to Run

```bash
# Linux / macOS
./airline_system

# Windows
airline_system.exe
```

On startup, the program automatically loads `skylink_data.txt` if it exists. If not, it starts fresh. On exit (option 14), all data is saved back to that file.

---

## 📟 Menu Options

```
============================================
   SKYLINK AIRWAYS - Management System
============================================
  1.  Add Flight
  2.  Remove Flight
  3.  Search Flights
  4.  List All Flights
  5.  Register Passenger
  6.  Remove Passenger
  7.  View Passenger Booking History
  8.  Book a Ticket
  9.  Cancel a Ticket
  10. Today's Departures
  11. Occupancy Report
  12. Top 5 Revenue Flights
  13. Load Sample Data
  14. Save & Exit
============================================
```

| # | What it does |
|---|---|
| 1 | Add a Domestic, International, or Charter flight |
| 2 | Remove a flight (blocked if active bookings exist) |
| 3 | Search by flight number, route, or date |
| 4 | Display all flights in the system |
| 5 | Register an Economy, Business, or First Class passenger |
| 6 | Remove a passenger (blocked if active bookings exist) |
| 7 | View full booking history for any passenger |
| 8 | Book a ticket — fare, seat, and loyalty points calculated automatically |
| 9 | Cancel a ticket with refund calculation |
| 10 | Show all flights departing on a given date |
| 11 | Show seat occupancy percentage for every flight |
| 12 | Show top 5 flights ranked by revenue (bubble sort) |
| 13 | Load 10 sample flights + 8 sample passengers |
| 14 | Save all data and exit |

---

## 📦 Sample Data

Selecting option **13** loads the following pre-configured data:

### Flights

| Flight | Type | Route | Date | Seats |
|---|---|---|---|---|
| SL101 | Domestic | Karachi → Lahore | 2026-05-30 | 150 |
| SL102 | Domestic | Lahore → Islamabad | 2026-05-30 | 120 |
| SL103 | Domestic | Islamabad → Karachi | 2026-05-31 | 180 |
| SL104 | Domestic | Peshawar → Karachi | 2026-06-01 | 100 |
| SL201 | International | Karachi → Dubai (UAE) | 2026-05-30 | 200 |
| SL202 | International | Lahore → London (UK) | 2026-05-31 | 250 |
| SL203 | International | Islamabad → Istanbul (Turkey) | 2026-06-01 | 180 |
| SL301 | Charter | Karachi → Skardu (TrekCorp) | 2026-05-30 | 50 |
| SL302 | Charter | Lahore → Gilgit (MountainAir) | 2026-06-02 | 40 |
| SL303 | Charter | Islamabad → Chitral (NorthExp) | 2026-06-03 | 30 |

### Passengers

| ID | Name | Class |
|---|---|---|
| P001 | Ali Ahmed | Economy |
| P002 | Sara Khan | Economy |
| P003 | Usman Malik | Economy |
| P004 | Fatima Noor | Business |
| P005 | Hassan Raza | Business |
| P006 | Ayesha Siddiqui | First Class |
| P007 | Bilal Tariq | First Class |
| P008 | Zara Iqbal | First Class |

---

## 💰 Refund Rules

Refund percentage depends on the passenger's class. If the cancellation happens **on the same day as departure**, the refund is halved.

| Class | Normal Refund | Same-Day Cancellation |
|---|---|---|
| Economy | 50% | 25% |
| Business | 75% | 37.5% |
| First Class | 90% | 45% |

---

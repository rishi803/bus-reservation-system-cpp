#ifndef BUS_H                   // security guard
#define BUS_H

#include <iostream>
#include <string>

// CLASS BUS
class Bus {
private:
    int maxSeats, bookedSeats;
    double busFare;
    std::string busNo, source, destination, sourceTime, destinationTime;

public:
    Bus() : maxSeats(32), bookedSeats(0), busFare(0.0) {}

    // METHODS
    void addBus();
    void showAllBus();
    void showBusDetails();
    void viewBusDetails();
    void deleteBus();
    void editBus();

    // GETTERS
    std::string getBusNo() {
        return busNo;
    }

    std::string getSource() {
        return source;
    }

    std::string getDestination() {
        return destination;
    }

    std::string getSourceTime() {
        return sourceTime;
    }

    std::string getDestinationTime() {
        return destinationTime;
    }

    int getBookedSeats() {
        return bookedSeats;
    }

    int getMaxSeats() {
        return maxSeats;
    }

    double getBusFare() {
        return busFare;
    }

    // SETTERS
    void setBookedSeats() {
        bookedSeats++;
    }

    void setCancelTicket() {
        bookedSeats--;
    }

    void setSource(const std::string& s) {
        source = s;
    }

    void setDestination(const std::string& d) {
        destination = d;
    }

    void setSourceTime(const std::string& s) {
        sourceTime = s;
    }

    void setDestinationTime(const std::string& d) {
        destinationTime = d;
    }

    void setBusFare(double f) {
        busFare = f;
    }
};
#endif // !BUS_H

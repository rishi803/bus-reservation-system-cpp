#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "bus.h"
#include "ticket.h"
#include "utils.h"

using namespace std;

// ADD BUS
void Bus::addBus()
{
    fstream busFileStream;

    system("cls");

    printHeading("ADD BUS");

    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
    cin.ignore();
    getline(cin,busNo);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
    getline(cin,source);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
    getline(cin,destination);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source Time:-> ";
    getline(cin,sourceTime);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination Time:-> ";
    getline(cin,destinationTime);
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Fare:-> ";
    cin >> busFare;

    busFileStream.open("buses.dat", ios::out | ios::app | ios::binary);
    busFileStream.write((char *)this, sizeof(*this));
    busFileStream.close();

    cout << "\n\t\t\t\t\t\t\t\t\t\tBus Added Successfully...!!!:-> \n";
}

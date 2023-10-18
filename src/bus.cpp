#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>   //control over the appearance of output in your C++ programs

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
    
    // .dat files are often used by applications to store their own custom data in a binary format.
    
    // ios::out: This flag indicates that the file is opened for output (writing). It allows you to write data to the file. If the file does not exist, it will be created. If it does exist, the file's contents will be truncated (cleared) before writing.

    // ios::app: This flag stands for "append." It is used in conjunction with ios::out. If this flag is set, data is written to the end of the file rather than overwriting its contents. It's often used to add data to an existing file without erasing what's already there.

    // ios::binary: This flag indicates that the file should be treated as a binary file, as opposed to a text file. In binary mode, data is written to the file as is, without any automatic text encoding or line-ending conversions.


    busFileStream.write((char *)this, sizeof(*this));
    busFileStream.close();

    cout << "\n\t\t\t\t\t\t\t\t\t\tBus Added Successfully...!!!:-> \n";
}

// SHOW BUS DETAILS
void Bus::showBusDetails()
{
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t Bus No:-> " << getBusNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Source:-> " << getSource();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Destination:-> " << getDestination();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Time:-> " << getSourceTime() << " - " << getDestinationTime();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Total Seats:-> " << getMaxSeats();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Seats Remaining:-> " << (getMaxSeats() - getBookedSeats());
    cout << fixed << setprecision(2);
    cout << "\n\t\t\t\t\t\t\t\t\t\t Bus Fare:-> " << getBusFare();
    cout << "\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\n";
}

// VIEW ALL BUS INFO
void Bus::showAllBus()
{
    system("cls");

    fstream busFileStream;

    busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
    if (!busFileStream)
        cout << "\n\t\t\t\tFile Not Found...!!!";
    else
    {
        printHeading("BUSES");

        busFileStream.read((char *)this, sizeof(*this));

        while (!busFileStream.eof())
        {
            showBusDetails();
            busFileStream.read((char *)this, sizeof(*this));
        }
        busFileStream.close();
    }
}

// VIEW selected BUS INFO

void Bus::viewBusDetails()
{
    system("cls");
    

    string busNo;
    int chk = 0;
    fstream busFileStream;

    printHeading("VIEW BUS INFO");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
    cin.ignore();
    getline(cin,busNo);

    system("cls");
    printHeading("BUS INFO");

    busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
    if (!busFileStream)
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        // Bus busRecord;

        busFileStream.read((char *)this, sizeof(*this));
        while (!busFileStream.eof())
        {
            if (getBusNo() == busNo)
            {
                showBusDetails();
                chk = 1;
            }
            busFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Not Found...!!\n";
        }
        busFileStream.close();
    }
}

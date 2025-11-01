#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

const int TOTAL_ROOMS = 7;

// Base class
class Room 
{
public:
    int roomNumber;
    bool isBooked;
    double pricePerDay;

    Room() 
    {
        roomNumber = 0;
        isBooked = false;
        pricePerDay = 1500.0; // default price per day
    }

    void setRoom(int number, double price) 
    {
        roomNumber = number;
        pricePerDay = price;
        isBooked = false;
    }
};

// Derived class
class Customer : public Room 
{
public:
    string customerName;
    string phonenumber;
    string adhaarnumber;
    int days;

    // Function to book room
    void bookRoom() 
    {
        if (isBooked) 
        {
            cout << "------------  ------------  ------------  -------\n";
            cout << "This Room is Already Booked By Customer " << customerName << ". Please choose another Room.\n";
            cout << "------------  ------------  ------------  -------\n";
        } 
        else 
        {
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, customerName);
            cout << "Enter your phone number: ";
            cin >> phonenumber;
            cout << "Enter your Adhaar number: ";
            cin >> adhaarnumber;
            cout << "Enter number of days you want to stay: ";
            cin >> days;
            isBooked = true;
            cout << endl;
            cout << "------------  ------------  ------------  --------\n";
            cout << "Room Number " << roomNumber << " Booked By " << customerName << "\n";
            cout << "For Days: " << days << "\n";
            cout << "Phone Number: " << phonenumber << "\n";
            cout << "Adhaar Number: " << adhaarnumber << endl; 
            cout << "Price Per Day: $" << pricePerDay << "\n";
            cout << "------------  ------------  ------------  -------\n";         
        }
    }

    // Function to generate bill receipt
    void generateBill() 
    {
        double total = days * pricePerDay;
        cout << "\n================== HOTEL BILL RECEIPT ==================\n";
        cout << left << setw(20) << "Customer Name:" << customerName << endl;
        cout << left << setw(20) << "Room Number:" << roomNumber << endl;
        cout << left << setw(20) << "Phone Number:" << phonenumber << endl;
        cout << left << setw(20) << "Adhaar Number:" << adhaarnumber << endl;
        cout << left << setw(20) << "Days Stayed:" << days << endl;
        cout << left << setw(20) << "Rate per Day:" << "$" << pricePerDay << endl;
        cout << "--------------------------------------------------------\n";
        cout << left << setw(20) << "Total Amount:" << "$" << total << endl;
        cout << "========================================================\n\n";
    }

    // Function to check out
    void checkOut() 
    {
        if (isBooked) 
        {
            cout << "------------  ------------  ------------  -------\n"; 
            cout << customerName << " has checked out from room " << roomNumber << endl;
            cout << "------------  ------------  ------------  -------\n"; 
            generateBill();
            isBooked = false;
            customerName = "";
            phonenumber = "";
            adhaarnumber = "";
            days = 0;
           
        } 
        else 
        {
            cout << "------------  ------------  ------------  -------\n";
            cout << "Room is already available! You can book this one.\n";
            cout << "------------  ------------  ------------  -------\n";
        }
    }

    void showDetails() 
    {
        if (isBooked) 
        {
            cout << "Room " << roomNumber << " is booked by " << customerName << endl;
        } 
        else 
        {
            cout << "Room " << roomNumber << " is available\n";
        }
    }
};


int main() 
{
    Customer rooms[TOTAL_ROOMS];
    for (int i = 0; i < TOTAL_ROOMS; i++) 
    {
        rooms[i].setRoom(100 + i, 50 + (i * 20));
    }
    int choice;
    int roomNo;
    bool found = false;

    do {
        cout << "\n--- Hotel Reservation System ---\n";
        cout << "1. View Room Status\n";
        cout << "2. Book a Room\n";
        cout << "3. Check Out\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                for (int i = 0; i < TOTAL_ROOMS; i++) 
                {
                    rooms[i].showDetails();
                }
                break;

            case 2:
                found = false;
                cout << "Enter room number to book: ";
                cin >> roomNo;
                for (int i = 0; i < TOTAL_ROOMS; i++) 
                {
                    if (rooms[i].roomNumber == roomNo) 
                    {
                        rooms[i].bookRoom();
                        found = true;
                        break;
                    }  
                }
                if (!found)
                {
                    cout << "------------  ------------  ------------  -------\n"; 
                    cout << "Sorry! Invalid room number.\n";
                    cout << "------------  ------------  ------------  -------\n"; 
                }
                break;

            case 3:
                cout << "Enter room number to check out: ";
                cin >> roomNo;
                found = false;
                for (int i = 0; i < TOTAL_ROOMS; i++) 
                {
                    if (rooms[i].roomNumber == roomNo) 
                    {
                        rooms[i].checkOut();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Invalid room number.\n";
                break;

            case 4:
                cout << "------------  ------------  ------------  -------\n"; 
                cout << "Thank you for visiting our hotel!\n";
                cout << "------------  ------------  ------------  -------\n"; 
                break;

            default:
                cout << "------------  ------------  ------------  -------\n"; 
                cout << "Invalid choice. Try again.\n";
                cout << "------------  ------------  ------------  -------\n"; 
        }
    } 
    while (choice != 4);
    return 0;
}
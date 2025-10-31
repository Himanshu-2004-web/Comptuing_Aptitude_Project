#include <iostream>
#include <string>
using namespace std;

const int TOTAL_ROOMS = 7;

// Base class
class Room 
{
public:
    int roomNumber;
    bool isBooked;

    Room() 
    {
        roomNumber = 0;
        isBooked = false;
    }

    void setRoom(int number) 
    {
        roomNumber = number;
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

    void bookRoom() 
    {
        if (isBooked) 
        {
            cout<<"------------  ------------  ------------  -------\n";
            cout << " This Room is Alrdeady Booked By Customer "<< customerName <<" Please Choose another Room \n";
            cout<<"------------  ------------  ------------  -------\n";
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
            cout<<endl;
            cout<<"------------  ------------  ------------  --------\n";
            cout << "Room Number " << roomNumber<< " Booked By " << customerName << "\n";
            cout << "For Days: " << days<<"\n";
            cout << "Phone Number: " << phonenumber << "\n";
            cout << "Adhaar Number: " << adhaarnumber<<endl; 
            cout<<"------------  ------------  ------------  -------\n";         
        }
    }

    void checkOut() 
    {
        if (isBooked) 
        {
            cout<<"------------  ------------  ------------  -------\n"; 
            cout << customerName << " has checked out from room " << roomNumber << endl;
            cout<<"------------  ------------  ------------  -------\n"; 
            isBooked = false;
            customerName = "";
           
        } else 
        {
            cout<<"------------  ------------  ------------  -------\n";
            cout << "Room is already available! You can book this one\n";
            cout<<"------------  ------------  ------------  -------\n";
        }
    }

    void showDetails() 
    {
       
        if (isBooked) 
        {
            cout << " Room " << roomNumber << " is Already booked by " << customerName << endl;
        } else 
        {
            cout << " Room " << roomNumber << " is available\n";
        }
    }
};

int main() 
{
    Customer rooms[TOTAL_ROOMS];

    // Set room numbers
    for (int i = 0; i < TOTAL_ROOMS; i++) 
    {
        rooms[i].setRoom(100 + i);
    }

    int choice;
    int roomNo;
    bool found=false;

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
                found=false;
                cout << "Enter room number to book: ";
                cin >> roomNo;
                for (int i = 0; i < TOTAL_ROOMS; i++) 
                {
                    if (rooms[i].roomNumber == roomNo) 
                    {
                        rooms[i].bookRoom();
                        found=true;
                        break;
                    }  
                }
                if (!found)
                {
                    cout<<"------------  ------------  ------------  -------\n"; 
                    cout<< "Soory Invaild Choice of room number !"<<endl;
                    cout<<"------------  ------------  ------------  -------\n"; 
                }
                break;

            case 3:
                cout << "enter room number to check out: "<<endl;
                cin >> roomNo;
                for (int i = 0; i < TOTAL_ROOMS; i++) 
                {
                    if (rooms[i].roomNumber == roomNo) 
                    {
                        rooms[i].checkOut();
                        break;
                    }
                }
                break;

            case 4:
                cout<<"------------  ------------  ------------  -------\n"; 
                cout << "Thanking you for visiting our hotel !\n";
                cout<<"------------  ------------  ------------  -------\n"; 
                break;

            default:
                cout<<"------------  ------------  ------------  -------\n"; 
                cout << "Invalid choice. Try again.\n";
                cout<<"------------  ------------  ------------  -------\n"; 
        }
    } 
    while (choice != 4);

    return 0;
}
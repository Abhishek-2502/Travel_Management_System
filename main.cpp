#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

void menu(); // main menu function prototype

class ManageMenu
{
protected:
    string userName; // hide admin name

public:
    ManageMenu() // Constructor
    {
        system("color 0A");
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS"); // Clear output screen
        menu();        // call to main function to load after executing the constructor
    }

    ~ManageMenu() {} // Destructor (Deletes the Object)
};

class Customer
{
    // Encapsulation (Making Data Member as private)
    string name, gender, address;
    int age;
    long long int mobileNo;

protected:
    char all[999];
    static int cusID;
    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app); // open file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> mobileNo;
            cout << "Address: ";
            cin >> address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nSaved\nNOTE: We save your details record for future purposes.\n"<< endl;
    }
    void showDetails() // function to show old customer records
    {
        ifstream in("old-customers.txt"); // Reading from file
        {
            if (!in) // If file doesn't exist
            {
                cout << "File Error!" << endl;
                Sleep(1100);
                system("CLS");
                menu();
            }
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

int Customer::cusID;

class Cabs
{
    int cabChoice;
    int kilometers;
    float cabCost;
    int gotoMenu;

protected:
    static float lastCabCost;

    void cabDetails()
    {
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country" << endl;
        cout << "-----------ABC Cabs-----------\n"<< endl;
        cout << "1. Rent a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs.25 per 1KM" << endl;
        cout << "\nPress any key except 1 and 2 if you don't want to hire cab or,";
        cout << "\nTo calculate the cost for your journey enter which kind of cab you need: " << endl;
        cin >> cabChoice;

        int hireCab;

        if (cabChoice == 1)
        {
            cout << "Enter Kilometers you have to travel: ";
            cin >> kilometers;
            cabCost = kilometers * 15;
            cout << "\nYour tour will cost " << cabCost << " rupees for a standard cab." << endl;
            cout << "Press 1 to hire this cab or \nPress 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired standard cab" << endl;
                cout << "Goto Main Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else if (cabChoice == 2)
        {
            cout << "Enter Kilometers you have to travel: ";
            cin >> kilometers;
            cabCost = kilometers * 25;
            cout << "\nYour tour will cost " << cabCost << " rupees for a luxury cab." << endl;
            cout << "Press 1 to hire this cab or \nPress 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Main Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to MPrevious Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }

        else
        {
            cout << "Redirecting to Main Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect to Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
};

float Cabs::lastCabCost;

class Booking
{
    int choiceHotel;
    int packChoice1;
    int gotoMenu;

protected:
    static float hotelCost;
    void hotels()
    {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
        cout << "--> Book a Luxury Hotel using the System <--\n"<< endl;
        for (int a = 0; a < 3; a++)
        {
            cout << (a + 1) << ". Hotel " << hotelNo[a] << endl;
        }

        cout << "\nCurrently we collaborated with above hotels!" << endl;
        cout << "Press any key for back or,\nEnter Number of the hotel you want to book or see details: ";
        cin >> choiceHotel;

        system("CLS");

        if (choiceHotel == 1)
        {
            cout << "-------WELCOME TO HOTEL AVENDRA-------\n"<< endl;
            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;
            cout << "Packages offered by Avendra:\n"<< endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Avendra: Rs.15000.00" << endl;
            cout << "\nPress another key for back or,\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
                cout << "Goto Main Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
                cout << "Goto Main Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
                cout << "Goto Main Menu to take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 2)
        {
            cout << "-------WELCOME TO HOTEL CHOICEYOU-------\n"<< endl;
            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;
            cout << "Packages Offered by ChoiceYou:\n"<< endl;
            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key for back or,\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 15000.00;
                cout << "You have successfully booked Family Pack at ChoiceYou" << endl;
                cout << "Goto Main Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "You have successfully booked Couple Pack at ChoiceYou" << endl;
                cout << "Goto Main Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked Single Pack at ChoiceYou" << endl;
                cout << "Goto Main Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 3)
        {
            cout << "-------WELCOME TO HOTEL ELEPHANTBAY-------\n"<< endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for a one day!!!" << endl;
            cout << "\nPress another key for back or,\nPress 1 to book this special package: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked ElephantBay Special Pack" << endl;
                cout << "Goto Main Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect to Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
    }
};

float Booking::hotelCost;

class charges : public Customer, public Booking, public Cabs // Multiple Inheritance of some other classes to charges
{

public:
    void printBill()
    {
        ofstream outf("receipt.txt"); // receipt for bought items
        {
            outf << "------Triple A Travel Agency------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl<< endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl; // Using Manipulators
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
    }

    void showDetails()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
                Sleep(1100);
                system("CLS");
                menu();
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }

    void getDetailsfunc()
    {
        Customer::getDetails();
    }
    void showDetailsfunc()
    {
        Customer::showDetails();
    }
    void cabDetailsfunc()
    {
        Cabs::cabDetails();
    }
    void hotelsfunc()
    {
        Booking::hotels();
    }
};

void menu() // menu function contain main menu
{

    system("color 0A");
    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * Triple A Travels *\n"<< endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management      -> 1\t|" << endl;
    cout << "\t|\tCabs Booking Management  -> 2\t|" << endl;
    cout << "\t|\tHotel Booking Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill           -> 4\t|" << endl;
    cout << "\t|\tExit                     -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    charges obj;

    if (mainChoice == 1)
    {
        system("color 0B");
        cout << "------Customers------\n"<< endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if (inChoice == 1)
        {
            obj.getDetailsfunc();
        }
        else if (inChoice == 2)
        {
            obj.showDetailsfunc();
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect to Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        system("color 0C");
        obj.cabDetailsfunc();
    }
    else if (mainChoice == 3)
    {
        system("color 06");
        obj.hotelsfunc();
    }
    else if (mainChoice == 4)
    {
        system("color 0D");
        cout << "-->Get your receipt<--\n"<< endl;
        obj.printBill();
        cout << "Your receipt is already printed you can get it from file path\n"<< endl;
        cout << "To display your receipt here Enter 1, or Enter other key to goto main menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            system("CLS");
            obj.showDetails(); // Run-time Polymorphism applied as this function is also there in Customer Class (Parent Class).
            cout << "Press 1 to Redirect to Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 5)
    {
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu startObj;
    return 0;
}

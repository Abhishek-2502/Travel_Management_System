# Travel_Mangement_System

<h3>INTRODUCTION</h3>

<p>The Triple A Travel Agency Management System is a console-based application
designed to manage customer data, cab bookings, and hotel reservations. The system
provides a comprehensive suite of functions, including capturing customer details,
calculating cab costs based on user preferences, and facilitating hotel bookings.</p>

<h3>PROBLEM STATEMENT</h3>

<p>Travel agencies require efficient management systems to handle customer data, cab
bookings, and hotel reservations. The lack of such systems can lead to operational
inefficiencies, errors in booking calculations, and inadequate customer service.</p>

<h3>EXPLANATION</h3>
The provided code is implemented in C++ and consists of several classes:

- `ManageMenu`: Manages the main menu display and administrative access.
- `Customer`: Handles customer details, including capturing and displaying stored data.
- `Cabs`: Manages cab bookings and cost calculations.
- `Booking`: Handles hotel bookings and offers different packages.
- `Charges`: Combines functionalities of the Customer, Booking, and Cabs classes
calculate and print the bill.

The system prompts users for various inputs depending on the function:
- Customer details such as ID, name, age, mobile number, address, and gender.
- Cab preferences, including type of cab and distance to be traveled.
- Hotel booking preferences, including hotel selection and package choice.
  
The system displays outputs in the console:
- Confirmation messages upon successful data entry.
- Calculated cab costs based on user input.
- Detailed receipts that outline charges for services availed.

<p>The system uses text files ("old-customers.txt" and "receipt.txt") to store and retrieve
customer details and transaction receipts.</p>
1. ManageMenu Class
<p>This class initializes the application, setting the aesthetics of the console, capturing user
names, and navigating to the main menu. The use of `system("color 0A")` sets the
console text to light green, enhancing user experience.</p>
2. Customer Class
<p>This class focuses on managing customer information. Through the `getDetails()`
function, it captures and writes user details to the `old-customers.txt` file. The
`showDetails()` function reads and displays this stored data.</p>
3. Cabs Class
<p>Responsible for cab bookings, this class offers users choices between standard and luxury
cabs. It then calculates the fare based on the selected cab type and desired travel distance.</p>
4. Booking Class
<p>The Booking class, as the name suggests, manages hotel reservations. Users can select a
hotel and a package, with the system then providing detailed information and calculating
costs based on selections.</p>
5. Charges Class
<p>An amalgamation of the Customer, Booking, and Cabs classes, this class oversees the
billing process, combining all charges and generating a detailed bill.</p>
6. Main Menu Function (`menu()`)
<p>Representing the program's primary interaction point, this function directs users to
various features, such as customer management, cab reservations, hotel bookings, and
billing.</p>

<h3>CLASS DIAGRAM</h3>
<img src="https://github.com/Abhishek-2502/Travel_Mangement/assets/145414094/2ff5f926-3e03-437c-9ff7-6b3829ac3f84" alt="error">

<h3>CODE HIGHLIGHTS</h3>

1. File Operations: Utilizing C++'s `ofstream` and `ifstream`, the system can persistently
store and retrieve data, ensuring longevity and access to customer records and receipts.

2. User Interface: Through a console-based interaction model, users are presented with
clear choices and prompts, facilitating easy navigation and operation.

3. Console Manipulation: Commands like `system("color")` and `system("CLS")`
enhance the visual aesthetics of the application and ensure a clean interface.

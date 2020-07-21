#include<iostream>
using namespace std;

int main() {

// Recall that, when used as shown next, struct command creates a 
// new TYPE customer_record (and NOT a new variable) 

struct customer_record
{
   string last_name; 
   string first_name;
   int account_number;
   double monthly_fee;
};

// Now, we use the above TYPE to declare a new variable

customer_record v;

// We can read each field of the variable one-at-a-time

cout << "Enter last name: ";
cin >> v.last_name;

cout << "Enter first name: ";
cin >> v.first_name;

cout << "Enter account number: ";
cin >> v.account_number;

cout << "Enter monthly fee: ";
cin >> v.monthly_fee;

// We can print each field using couts

cout << "Last name = ";
cout << v.last_name << endl;

cout << "First name = ";
cout << v.first_name << endl;

cout << "Account number = ";
cout << v.account_number << endl;

cout << "Monthly fee = ";
cout << v.monthly_fee << endl;

}

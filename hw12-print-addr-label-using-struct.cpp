#include<iostream>
#include<string>

using namespace std;

// Recall that this creates a new TYPE (called address)
// and it does NOT create a new variable

struct address{
   string last_name; 
   string first_name;
   string city_name;
   string zip_code;
};

void print_address_label(address addr){
   cout << addr.first_name << " " << addr.last_name << endl;
   cout << addr.city_name << " " << addr.zip_code << endl; 
}

int main() {

// Now, we use the above TYPE to declare a new variable
address my_address;

// We can read each field of the variable one-at-a-time

cout << "Enter last name: ";
cin >> my_address.last_name;

cout << "Enter first name: ";
cin >> my_address.first_name;

cout << "Enter city: ";
cin >> my_address.city_name;

cout << "Enter zip code: ";
cin >> my_address.zip_code;

// We can print each field using our new function

print_address_label(my_address);

}

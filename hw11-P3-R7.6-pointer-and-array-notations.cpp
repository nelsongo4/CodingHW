#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;


int main() {

double primes[] = { 2, 3, 5, 7, 11, 13 }; 
double* p = primes + 3; // starts with the address of location-0 of array primes and adds 3 to derive the address of location-3 of array primes; assings this address to p
// Important note: When 1 is added to an address, the size of double (since pointer type is double) is added,
// when 2 is added to an address 2 times the size of double is added, and so on

cout << "primes[1] = " << primes[1] << endl; // prints the value stored at location-1 of array primes

cout << "primes + 1 = " << primes + 1 << endl; // starts with the address of location-0 of the array primes, adds 1, hence prints the address of the location-1 of primes

cout << "*(primes + 1) = " << *(primes + 1) << endl; // using the deferencing operator *, prints the value at the location-1 of the array primes 

cout << "p[1] = " << p[1] << endl; // since p is assigned the address of location-3 of array primes, location-1 of "array" p is the location-4 of array primes

cout << "p + 1 = " << p + 1 << endl; // this is simply the address of the location-4 of array primes, which is the location-1 of "array" p

cout << "*(p + 1) = " << *(p + 1) << endl; // using the deferencing operator *, prints the value at location-4 of array primes, i.e., the value at location-1 of "array" p

}




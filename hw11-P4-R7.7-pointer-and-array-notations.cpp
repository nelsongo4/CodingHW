#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;


int main() {

double primes[] = {2, 3, 5, 7, 11, 13}; 
cout << "primes = " << primes << endl; // prints address of primes[0]
cout << "*primes = " << *primes << endl; // prints value of primes[0], i.e., 2
cout << "primes + 4 = " << primes + 4 << endl; // prints address of primes[4]
cout << "*(primes + 4) = " << *(primes + 4) << endl; // prints value of primes[4], i.e., 11
cout << "primes[4] = " << primes[4] << endl; // prints values of primes[4], i.e., 11
cout << "&primes[4] = " << &primes[4] << endl; // prints address of primes[4]

}

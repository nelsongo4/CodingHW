#include <iostream>
#include <cmath>
using namespace std;
#define MAXPRIME 1000000

int main() {
   int maxnum=0;
   int l[MAXPRIME]={0};
   int i = 0;
   int j;
   int maxj;

   cout << "This program computes the primes using the sieve method" << endl; // prints a note explaining the program's functionality
   cout << "Maximum number to check for primality  = "; // prompts for input - lenght of list to sort 
   cin >> maxnum; // reads len

   if(maxnum> MAXPRIME-1){
        cout << "Maximum number too large; edit the program and recompile" << endl; // reports error when the maximum number is greater than that supported by the program
        return(-1);
   }
  for(i=1; i<=maxnum; i++){
      l[i]=1;
  }
  l[1]=0; // Mark 1 as a NON prime
  for(i=4; i<=maxnum; i=i+2){
      l[i]=0; // Mark ALL even numbers EXCEPT 2 as NON primes
  }

/*
   cout << "The initial list l:" << endl;
   for(i=1; i<=maxnum; i++){
            cout << l[i] << endl; // prints l[i]
   }
*/
  
  for(i=3; i<=sqrt(maxnum); i++){
      if(l[i]==1){
         for(j=2*i; j<=maxnum; j=j+i){
            cout << "Marking " << j << " as non prime" << endl;
            l[j]=0; // Mark all multiples of a prime as a non-prime
         }
      }
  }    
 

   cout << "The list of primes:" << endl;
   for(i=1; i<=maxnum; i++){
        if(l[i]==1){
            cout << i << endl; // prints i
        }
   }
}

#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

// prints num elements of an int array given the pointer to 
// the first element
void print_data(int* data, int num)
{
for(int i = 0; i< num; i++)
{
   cout << *data << " ";
   data = data + 1;
}
cout << endl;
}

// reads a sequence of ints followed by Q (or any other 
// non-numerical value)
// uses cin.fail() to identify and stop reading when a non-integer value 
// is input by the user
// IMPORTANT NOTE: Always use cin.clear() after cin.fail()

// starts with an array of size 10
// each time the array becomes full, creates a new array of 
// double the size,
// copies values from current array, frees the current array, 
// and points the current array name to the new array
// after finishing reading, repeats this to finally create 
// an array of exactly the right size
int* read_data(int& size)
{
int max_size = 10;
size = 0;
int* a = NULL;
int* new_a = NULL;
a = new int[max_size];

cout << "Enter integers, Q to quit: ";
bool more = true;
while(more)
{
   cin >> a[size];
   if(cin.fail())
   {
	more = false;
   }
   else
   {
	size++;
        if(size == max_size){
	  cout << "Creating a new array of size " << 2*max_size << endl;
	  new_a = new int[2*max_size];
	  for(int j = 0; j < size; j++){
		new_a[j] = a[j];
	  }
	  max_size = 2*max_size; 
	  delete[] a;
	  a = new_a;
	}
   }
   cin.clear();
}

cout << "Creating a new array of size " << size << endl;
new_a = new int[size];
for(int j = 0; j < size; j++){
   new_a[j] = a[j];
}
delete[] a;
a = new_a;
return(a);
}

int main() 
{
int nums_rd =0;
int* vals_rd = NULL;
vals_rd = read_data(nums_rd);
print_data(vals_rd, nums_rd);
}

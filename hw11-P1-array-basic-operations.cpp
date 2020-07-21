#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

const int MAX_SIZE = 128;

void read_initial_list(string arr[], int& sz_arr){
int n_vals_to_read =0;

cout << "Enter the number of strings you wish to input (<= 128): ";
cin >> n_vals_to_read;
cout << "Enter " << n_vals_to_read << " strings (no spaces within each string): " << endl;
for(int i = 0; i < n_vals_to_read; i++){
	cin >> arr[sz_arr];
	sz_arr++;
}
}

void print_list(string arr[], int sz_arr){
for(int i = 0; i < sz_arr; i++){
	cout << arr[i] << endl;
}
}

int search_name_in_list(string arr[], int sz_arr, string srch_string){
for(int i = 0; i < sz_arr; i++){
	if(arr[i]== srch_string){
		return(i);
	}
}
return(-1); // negative value indicates that the search string was not found
}

void insert_name_to_list_loc(string arr[], int& sz_arr, string add_string, int loc){
int i= 0;
for(i = sz_arr; i > loc; i--){
	arr[i] = arr[i-1];
}
arr[loc] = add_string;
sz_arr++;
}

int add_name_to_sorted_list(string arr[], int& sz_arr, string add_string){
for(int i = 0; i < sz_arr; i++){
	if(arr[i]>= add_string){
		insert_name_to_list_loc(arr, sz_arr, add_string, i);
		return(i);
	}
}
}

void add_name(string arr[], int& sz_arr, string add_this){
	arr[sz_arr] = add_this;
	sz_arr++;
}

void remove_element_from_list_at_loc(string arr[], int& sz_arr, int loc_of_rm_name){
int i;
for(i = loc_of_rm_name; i < sz_arr - 1; i++){
	arr[i] = arr[i+1];
}
sz_arr--;
}

int remove_name_from_list(string arr[], int& sz_arr, string rm_name){
int loc_of_rm_name = 0;
loc_of_rm_name = search_name_in_list(arr, sz_arr, rm_name);
if(loc_of_rm_name < 0){
	return(-1);
}
else{
	remove_element_from_list_at_loc(arr, sz_arr, loc_of_rm_name);
	return(loc_of_rm_name);
}

}

void swap(string& a, string& b){
string temp;
temp = a;
a = b;
b = temp;
}

void sort_list(string arr[], int sz_arr){
// implements a very simple version of bubble-sort
bool swapped = 1;

while(swapped == 1){
	swapped = 0;
	for(int i = 0; i < sz_arr - 1; i++){
		if(arr[i]>arr[i+1]){
			swap(arr[i], arr[i+1]); 
			swapped = 1;
		}
	}
}
}

int main(){
string names[MAX_SIZE];
int sz_names = 0;

read_initial_list(names, sz_names);

cout << "Initial list contains: " << endl;
print_list(names, sz_names);

string search_name = "";
int found_in_location = 0;
cout <<  "Enter a string to search (no space within the string): ";
cin >> search_name;
found_in_location = search_name_in_list(names, sz_names, search_name);
if(found_in_location < 0){
	cout << "Does not exist in the list" << endl;
}
else{
	cout << "The string appears at location-" << found_in_location << " of the list" << endl;
}

string addnl_name = "";
cout <<  "Enter a string to add to the list (no space within the string): ";
cin >> addnl_name;
add_name(names, sz_names, addnl_name);

cout << "The updated list contains: " << endl;
print_list(names, sz_names);


string remove_name = "";
cout <<  "Enter a string to delete (no space within the string): ";
cin >> remove_name;
if(remove_name_from_list(names, sz_names, remove_name) < 0){
	cout << "The string you wished to delete did not exist in the list" << endl;
}

cout << "The updated list contains: " << endl;
print_list(names, sz_names);

sort_list(names, sz_names);
cout << "Sorting the list" << endl;

cout << "The updated list contains: " << endl;
print_list(names, sz_names);

cout <<  "Enter a string to add to the list in sorted order (no space within the string): ";
cin >> addnl_name;
add_name_to_sorted_list(names, sz_names, addnl_name);

cout << "The updated list contains: " << endl;
print_list(names, sz_names);



}

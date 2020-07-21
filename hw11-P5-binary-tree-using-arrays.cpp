#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

const int MAX_SIZE = 256;

void print_binary_tree_array(string arr[], int n_levels){
int starting_loc = 0;
cout << "Printing binary tree" << endl;
for(int i = 0; i < n_levels; i++){
	cout << "Level-" << i << ": ";
	for(int j = 0; j < pow(2, i); j++){
		cout << arr[starting_loc] << " * ";
		starting_loc++;
	}
	cout << endl;
}
}

void create_binary_tree_array_load_leaves(string bin_tr_arr[], int n_levels, string leaves_val_arr[]){
int starting_loc = 0;
for(int i = 0; i < n_levels - 1; i++){
	for(int j = 0; j < pow(2, i); j++){
		bin_tr_arr[starting_loc] = "";
		starting_loc++;
	}
}
for(int j = 0; j < pow(2, n_levels - 1); j++){
	bin_tr_arr[starting_loc] = leaves_val_arr[j];
	starting_loc++;
}
}

int main(){
string bin_tr_arr[MAX_SIZE];
int n_levels = 4; // ours is a 4-level tree

string leaves_val_arr[MAX_SIZE] = {"A", "B", "C", "D", "E", "F", "G", "H"};

create_binary_tree_array_load_leaves(bin_tr_arr, n_levels, leaves_val_arr);

print_binary_tree_array(bin_tr_arr, n_levels);
}

#include <iostream>
#include <cmath>
#include <climits>
#include <set>
#include <vector>
#include <map>
#include <sstream>
using namespace std;



struct tr_node{
    string val = "";
    tr_node* l = NULL;
    tr_node* r = NULL;
};

/*********************************FUNCTION HEADERS *************************************/
string tr_node_to_string(bool complete, tr_node* node);

void print_character(string chr, int range);

void print_plus(int node_length);

// Print node in format: (node)
void print_node(string val, int current_size, int node_length);

// PRINT TREE HELPER
void print_tree_helper(tr_node* rt, int current_level, int total_level, int node_length);

// Print the tree branch in format: -+--------+-
void print_branch(tr_node* rt, int current_level, int total_level, int node_length);

void find_max_node_length_helper(bool value, tr_node* rt, int& node_length);

void find_max_node_length(bool value, tr_node* rt, int& node_length);

// PRINT TREE FUNCTION
void print_tree_b(tr_node* rt, int total_level);

// CELL SCALING
string scale_cell(string val, int val_length);

// GENERATE MAP ID HELPER
void generate_map_helper(tr_node* rt, int& count, int current_level, int total_level);
// GENERATE MAP ID
void generate_map(tr_node* rt, int total_level);

// PRINT MAP HELPER
void print_map_helper(tr_node* rt, int& count, int current_level, int total_level, int val_length);

// PRINT MAP FUNCTION
void print_map(tr_node* rt, int total_level);

// CHECK LOOP OR CYCLE IN THE TREE
bool loop_detection(tr_node* rt, string parent, string& loop_error);

// CHECK TREE MAX HEIGHT AND TOTAL NODES IN THE TREE
void check_tree(tr_node* rt, int& max_height, int current_height, int& total_nodes);

// PRINT AND CHECK 
void print_and_check(tr_node* rt);

/************************************YOUR FUNCTIONS********************************************/
// --------------- 2. YOUR CODE GOES HERE -------------

// (a)
tr_node* create_empty_complete_binary_tree(int n)
{
    if(n==0){
        return(NULL);
    }
    
    tr_node* sub_tree_root = new tr_node;
    
    sub_tree_root->l = create_empty_complete_binary_tree(n-1);
    sub_tree_root->r = create_empty_complete_binary_tree(n-1);
    
    return(sub_tree_root);
    
}

// (b) 

void insert_value(tr_node* root, string code, string value)
{
    tr_node* here = root;
    
    for(int i=0; code[i]; i++)
    {
        if(code[i] == '0'){
            here = here->l;
        }
        else if(code[i] == '1'){
            here = here->r;
        }
        else{
            cout << "Code not found";
            return;
        }
    }
    here->val = value;
    return;
}

tr_node* fill_complete_binary_tree_with_symbols(tr_node* root, int n)
{
    
    string code="";
    string value = "";
    
    cout << "PLEASE ENTER THE CODE AND SYMBOL (Set code to -1 to exit): ";
    cin >> code >> value;
    while(code != "-1"){
        insert_value(root, code, value);
        cout << "PLEASE ENTER THE CODE AND SYMBOL (Set code to -1 to exit): ";
        cin >> code >> value;
    }
    return(root);
}


// (c) Print tree
void print_tree(tr_node* root){
    
    if(root == NULL){
        return;
    }
    
    cout << "Node Address: " << root << "\t";
    cout << "Node Value: " << root->val << "\t";
    cout << "Left Child Address: " << root->l << "\t";
    cout << "Right Child Address: " << root->r << endl;
    
    print_tree(root->l);
    print_tree(root->r);

}

// (d) retrieval value from code
void retrieval_val_from_code(tr_node* root, string code_for_retrieval)
{
    tr_node* here = root;
    
    for(int i=0; code_for_retrieval[i]; i++)
    {
        if(code_for_retrieval[i] == '0'){
            here = here->l;
        }
        else if(code_for_retrieval[i] == '1'){
            here = here->r;
        }
        else{
            cout << "Code not found";
            return;
        }
    }
    cout << "The value at " << code_for_retrieval << " is: " << here->val;
}

/*********************************MAIN PROGRAM *************************************/
/** TO DO: Create a createTree function */
int main()
{
    int n = 0;
    cout << "This program creates complete binary tree with n levels" << endl;
    cout << "Enter n: ";
    cin >> n;
    tr_node* root = NULL;

    // --------------- 2. YOUR CODE GOES HERE -------------
    
    // (a) Create a tree with n levels
    root = create_empty_complete_binary_tree(n);
    
    // (b) Fill the val to the tree leaf node
    root = fill_complete_binary_tree_with_symbols(root, n);
    
    // (c) Print the whole tree
    cout << "The following is the tree structure:" << endl;
    print_tree(root);
    
    // (d) Retrieve particular location
    string code_for_retrieval = "";
    cout << "Enter the code for retrieval:";
    cin >> code_for_retrieval;
    retrieval_val_from_code(root, code_for_retrieval);

    // -------------------------------------------------
    print_and_check(root);
    return 0;
}


/********************************DO NOT TOUCH THE CODES BELOW************************************/
map<string, int> tree_id; 
map<string, string> tree_val; 
map<string, string> tree_traversal;
set<string> visited;

string tr_node_to_string(bool complete, tr_node* node){
    ostringstream get_the_address; 
    get_the_address << node;
    string address = get_the_address.str(); 
    if (complete){
        return ("Id: " + to_string(tree_id[address]) + " , " + "Value: " + tree_val[address]); 
    }
    return address;
}

void print_character(string chr, int range){
    for (int i = 0 ; i < range; i++){
        cout << chr;
    }
}

void print_plus(int node_length){
    cout << "-";
    print_character("+", node_length - 2);
    cout << "-";
}

// Print node in format: (Id: id, Value: val)
void print_node(string val, int current_size, int node_length){
    int space = (node_length - current_size - 2);
    print_character(" ", space/2);
    if (val != " "){
        cout << "(" << val << ")";
    }
    else{
        cout << " " << val << " ";
    }
    print_character(" ", (space + 1)/2);
}

// PRINT TREE HELPER
void print_tree_helper(tr_node* rt, int current_level, int total_level, int node_length){
    if(rt!= NULL){
        if (current_level == total_level){
            string node = tr_node_to_string(true, rt); 

            int current_length = node.size();
            // print node
            print_node(node, current_length, node_length);
            print_character(" ", (pow(2, current_level) - 1)*node_length);
            return;
        }
        print_tree_helper(rt->l, current_level, total_level - 1, node_length);
        print_tree_helper(rt->r, current_level, total_level - 1, node_length);
    }
    else{
        if (current_level == total_level){
            // print empty node
            print_node(" ", 1, node_length);
            print_character(" ", (pow(2, current_level) - 1)*node_length);
            return;
        }
        print_tree_helper(NULL, current_level, total_level - 1, node_length);
        print_tree_helper(NULL, current_level, total_level - 1, node_length);
    }
}

// Print the tree branch in format: -+--------+-
void print_branch(tr_node* rt, int current_level, int total_level, int node_length){
    if(rt!= NULL){
        //Print branch
        if (current_level == total_level){
            if (rt->l != NULL){
                print_plus(node_length);
                print_character("-", (pow(2, current_level - 1) - 1)*node_length/2);
            }
            else{
                print_character(" ", node_length);
                print_character(" ", (pow(2, current_level - 1) - 1)*node_length/2);
            }
            
            if (rt->r != NULL){
                print_character("-", ((pow(2, current_level - 1) - 1)*node_length + 1)/2);
                print_plus(node_length);
                print_character(" ", (pow(2, current_level - 1) - 1)*node_length);
            }
            else{
                print_character(" ", ((pow(2, current_level - 1) - 1)*node_length + 1)/2);
                print_character(" ", node_length);
                print_character(" ", (pow(2, current_level - 1) - 1)*node_length);
            }
            return;
        }
        
        print_branch(rt->l, current_level, total_level - 1, node_length);
        print_branch(rt->r, current_level, total_level - 1, node_length);
    }
    else{
        // Print empty branch
        if (current_level == total_level){
            print_character(" ", node_length);
            print_character(" ", (pow(2, current_level - 1) - 1)*node_length);
            print_character(" ", node_length);
            print_character(" ", (pow(2, current_level - 1) - 1)*node_length);
            return;
        }
        print_branch(NULL, current_level, total_level - 1, node_length);
        print_branch(NULL, current_level, total_level - 1, node_length);
    }
}

void find_max_node_length_helper(bool value, tr_node* rt, int& node_length){
    if(rt!= NULL){
        string node = rt->val;
        if (!value){
            node = tr_node_to_string(true, rt); 
        }
        
        int current_length = node.size();
        if (visited.count(node)){
            return;
        }
        else{
            visited.insert(node);
        }
        
        if (current_length > node_length){
            node_length = current_length;
        }
        
        find_max_node_length_helper(value, rt->l, node_length);
        find_max_node_length_helper(value, rt->r, node_length);
    }
}

void find_max_node_length(bool value, tr_node* rt, int& node_length){
    find_max_node_length_helper(value, rt, node_length);
    visited.clear();
}

// PRINT TREE FUNCTION
void print_tree_b(tr_node* rt, int total_level){
    int node_length = -1;
    find_max_node_length(false, rt, node_length);
    node_length += 2;

    for (int current_level = total_level; current_level > 0; current_level--){
        // print tree node in level order
        print_character(" ", (pow(2, current_level - 1) - 1)*(node_length)); // prefix space
        print_tree_helper(rt, current_level, total_level, node_length);
        cout << endl;
        
        // print branch 
        if (current_level > 1){
            print_character(" ", (pow(2, current_level - 2) - 1)*(node_length)); // prefix space
            print_branch(rt, current_level, total_level, node_length);
        }
        
        cout << endl;
    }
    
}

// CELL SCALING
string scale_cell(string val, int val_length){
    int diff = val_length - val.size() + 2;
    string space = "";
    for (int i = 0; i < (diff + 1)/2 - 1; i++){
        space += " ";
    }
    val = space + val;
    
    space = "";
    for (int i = 0; i < (diff)/2 - 1; i++){
        space += " ";
    }
    
    val = val + space;
    
    return val;
}

// GENERATE MAP ID HELPER
void generate_map_helper(tr_node* rt, int& count, int current_level, int total_level){
    if(rt!= NULL){
        if (current_level == total_level){
            string address =  tr_node_to_string(false, rt);
            if (visited.count(address) > 0){
                return;
            }

            tree_id.insert({address, count});
            tree_val.insert({address, rt->val});
            visited.insert(address);
            
            count++;
            return;
        }
        generate_map_helper(rt->l, count, current_level, total_level - 1);
        generate_map_helper(rt->r, count, current_level, total_level - 1);
    }
}

// GENERATE MAP ID
void generate_map(tr_node* rt, int total_level){
    int count = 0;
    for (int current_level = total_level; current_level > 0; current_level--){
        // print tree node in level order
        generate_map_helper(rt, count, current_level, total_level);
    }
}

// PRINT MAP HELPER
void print_map_helper(tr_node* rt, int& count, int current_level, int total_level, int val_length){
    if(rt!= NULL){
        if (current_level == total_level){
            string address =  tr_node_to_string(false, rt);
            if (visited.count(address) > 0){
                return;
            }
            string left_child_addr = tr_node_to_string(false, rt->l);
            string right_child_addr = tr_node_to_string(false, rt->r);
            
            cout << scale_cell(to_string(count), 8) << " | " << rt << " | " << scale_cell(rt->val, val_length + 4);
            cout << " | " << scale_cell(to_string(tree_id[left_child_addr]), 14) << " | " << scale_cell(left_child_addr, 14);
            cout << " | " << scale_cell(to_string(tree_id[right_child_addr]), 14) << " | " << scale_cell(right_child_addr, 14) << endl;

            visited.insert(address);
           
            count++;
            return;
        }
        print_map_helper(rt->l, count, current_level, total_level - 1,  val_length);
        print_map_helper(rt->r, count, current_level, total_level - 1,  val_length);
    }
}

// PRINT MAP FUNCTION
void print_map(tr_node* rt, int total_level){
    int count = 0;
    int val_length = -1;
    find_max_node_length(true, rt, val_length);
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << " Node ID | Node Addr | Value | Left Child ID | Left Child Addr | Right Child ID | Right Child Addr" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;

    for (int current_level = total_level; current_level > 0; current_level--){
        // print tree node in level order
        print_map_helper(rt, count, current_level, total_level, val_length);
    }
    cout << endl;
}

// CHECK LOOP OR CYCLE IN THE TREE
bool loop_detection(tr_node* rt, string parent, string& loop_error){
    if (rt == NULL){
        return false;
    }
    
    string address = tr_node_to_string(false, rt);
    
    string visited_node = "(Id: " + to_string(tree_id[address]) + ", Value: " + rt->val + ")";
    if (visited.count(address)){
        loop_error = visited_node + " has two parents " + "(Id: " + to_string(tree_id[tree_traversal[address]]) +  ") and (" + "Id: " + to_string(tree_id[parent]) +  ")";
        return true;
    }
    else{
        visited.insert(address);
        tree_traversal.insert({address, parent});
    }

    return loop_detection(rt->l, address, loop_error) || loop_detection(rt->r, address, loop_error);
}

// CHECK TREE MAX HEIGHT AND TOTAL NODES IN THE TREE
void check_tree(tr_node* rt, int& max_height, int current_height, int& total_nodes){
    string addr = tr_node_to_string(false, rt);
    if (rt == NULL || visited.count(addr) > 0){
        if (current_height > max_height){
            max_height = current_height;
        }
        return;
    }

    visited.insert(addr);
    total_nodes++;
    
    check_tree(rt->l, max_height, current_height + 1, total_nodes);
    check_tree(rt->r, max_height, current_height + 1, total_nodes);
}

// PRINT AND CHECK 
void print_and_check(tr_node* rt){
    bool passed = true;
    int level = 0;
    int max_height = INT_MIN;
    int total_nodes = 0;
    string loop_error = "";
    
    // QUERIES
    string check_all_nodes = "";
    string check_linked_list = "";
    
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "Enter the tree level that you want to check: " << endl;
    cout << "-> ";
    
    cin >> level;
    cout << "Do you want to check if your binary tree is complete ? (For example, a complete tree with 3 levels will have 7 nodes total, answer 'yes' or 'no'): " << endl;
    cout << "-> ";

    cin >> check_all_nodes;
    cout << "Do you want to check if your tree behaves like a linked list ? (Answer 'yes' or 'no'): " << endl;
    cout << "-> ";
    cin >> check_linked_list;
    
    cout << endl;
    
    check_tree(rt, max_height, 0, total_nodes);
    visited.clear();
    
    generate_map(rt, max_height);
    visited.clear();

    cout << "-------Address and ID table----------\n" << endl;
    print_map(rt, max_height);
    visited.clear();

    if (loop_detection(rt, "", loop_error)){
        cout << "--------------Report---------------" << endl;
        cout << "There is a loop in your tree" << endl;
        cout << endl;
        cout << loop_error << endl;
        

        return;
    }
    

    cout << "--------------Your Tree--------------\n" << endl;
    print_tree_b(rt, max_height);
    
    cout << "Total level of your tree: " << max_height << endl;
    cout << "Total nodes of your tree: " << total_nodes << endl;
    cout << endl;
    cout << "--------------Report---------------" << endl;
    
    if (max_height != level){
        cout << "The height of your tree does not match the input level" << endl;
        cout << "Expected level is " << level << endl;
        cout << "Your tree level is " << max_height << endl;
        cout << "------------------------------------" << endl;
        passed = false;
    }
    
    if (check_linked_list == "yes"){
        if (max_height == total_nodes){
            cout << "Your tree behaves like a linked list" << endl;
            cout << "------------------------------------" << endl;
            passed = false;
        }
    }
    
    if (check_all_nodes == "yes"){
        
        if (total_nodes != (pow(2, level) - 1) || max_height != level){
            cout << "The tree does not contain all of the possible nodes" << endl;
            cout << "Expected total nodes for " << level << "-level tree are " << (pow(2, level) - 1) << endl;
            cout << "Your total nodes are " << total_nodes << " but since your tree has " << max_height << "-level" << " then the expected total nodes should be " << (pow(2, max_height) - 1) << endl;
            cout << "------------------------------------" << endl;

            passed = false;
            
        }
    }
    
    
    if (passed){
        cout << "Your tree is correct" << endl;
        cout << "------------------------------------" << endl;
    }
    
    cout << endl;
    
}
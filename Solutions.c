#include <iostream>
#include <string>
using namespace std;

struct lst_elem
{
    string val;
    lst_elem *next = NULL;
};

/************************************FUNCTION HEADERS********************************************/

bool detect_loop(lst_elem *p);
bool check_order(lst_elem *p);
void check_and_print_my_list(lst_elem *p);

/************************************YOUR FUNCTIONS********************************************/
// --------------- 2. YOUR CODE GOES HERE -------------
//read_initial_list()
//print_list()
//search_name_in_list()
//add_name_to_list()
//remove_name_from_list()

// (a)
lst_elem* read_initial_list()
{
    lst_elem* start = NULL;    
    lst_elem* tail = NULL;
    int n = 0;
    cout << "How many list elements to create: ";
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        lst_elem* tmp = new lst_elem;
        cout << "PLEASE GIVE THE " << i << "TH NAME: ";
        cin >> tmp->val;
        tmp->next = NULL;
        
        if(start == NULL)
        {
            start = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    
    return start;

}


// (b)
void print_list(lst_elem* p)
{
    lst_elem* here = NULL;
    here = p;
    int count = 0;
    while (here != NULL)
    {
        cout << "(List element " << count << ", Value: " << here->val << ")" << endl;
        here = here->next;
        count++;
    }
    cout << "\n\n";
    
}

// (c)
void search_name_in_list(lst_elem* p, string search_name)
{
    lst_elem* here = NULL;
    here = p;
    int count = 0;
    while(here != NULL)
    {
        if(here->val == search_name)
        {
            cout << "THE NAME " << search_name << " IS AT " << count << "TH POSITION" << endl;
            return ;
        }
        count++;
        here = here->next;
    }
    cout << "DOES NOT EXIT IN THE LIST" << endl;
    
}

// (d)
lst_elem* add_name_to_list(lst_elem* start, string add_name)
{   
    lst_elem* prev = NULL;
    lst_elem* here = NULL;
    
    here = start;
    
    lst_elem* tmp = new lst_elem;
    tmp->val = add_name;
    
    
    if(here->val >= add_name){
        tmp->next = here;
        here = tmp;
        start = here;
        return(start);
    }
    
    while(here->next != NULL){
        
        if(here->next->val >= add_name){
            tmp->next = here->next;
            here->next = tmp;
            return(start);
        }

        here = here->next;
    }
    
    // add to last one
    here->next = tmp;
    return(start);
    
}

// (e)
lst_elem* remove_name_from_list(lst_elem* start, string val_to_delete){
    lst_elem* here = NULL;
    lst_elem* tmp = NULL;
    here = start;
    
    if(here->val == val_to_delete){
        start = here->next;
        delete here;
        return(start);
    }
    
    while(here->next != NULL){
        if(here->next->val == val_to_delete){
            tmp = here->next;
            here->next = here->next->next;
            delete tmp;
            return(start);
        }
        here = here->next;
    }
    cout << "NAME NOT FOUND" << endl;
    return(start);
    
}





// -------------------------------------------------
/************************************MAIN PROGRAM************************************************/
int main()
{

    // --------------- 1. YOUR CODE GOES HERE -------------
    // TODO: CREATE YOUR LINKED LIST 
    
    // (a)
    lst_elem* start = read_initial_list();
    
    // (b)
    print_list(start);

    // (c)
    string search_name;
    cout << "INPUT THE NAME YOU WANT TO SEARCH: ";
    cin >> search_name;
    search_name_in_list(start, search_name);

    // (d)
    string add_name;
    cout << "INPUT THE NAME YOU WANT TO ADD: ";
    cin >> add_name;
    start = add_name_to_list(start, add_name);
    print_list(start);

    // (e)
    string val_to_delete;
    cout << "INPUT THE NAME YOU WANT TO DELETE: ";
    cin >> val_to_delete;
    start = remove_name_from_list(start, val_to_delete);
    print_list(start);

    // -------------------------------------------------
    // TESTING YOUR LINKED LIST
    check_and_print_my_list(start);
    return 0;
}

/************************************ DO NOT TOUCH THE CODES BELOW ***************************************/

bool detect_loop(lst_elem *p)
{

    lst_elem *slow_p = p;
    lst_elem *fast_p = p;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return true;
        }
    }
    return false;
}

bool check_order(lst_elem *p)
{
    while (p != NULL)
    {    

        if (p->next != NULL)
        {
            if (p->val >= p->next->val)
                {
                    return false;
                }
        }

        p = p->next;
    }
    

    return true;
}

void check_and_print_my_list(lst_elem *p)
{
    int size;
    cout << endl;
    cout << "--------------------------------------------\n" << endl;
    cout << "How many elements in the list ? ";
    cin >> size;

    lst_elem *here = NULL;
    here = p;

    int count = 0;

    if (detect_loop(p))
    {
        cout << "-----------------Report-----------------" << endl;
        cout << "There is a loop in your linked list" << endl;
        return;
    }
    
    cout << "\n------------------Your Linked List--------------------\n" << endl;
    while (here != NULL)
    {
        cout << "(List element " << count << ", Value: " << here->val << ")";
        if (here->next != NULL){
            cout << " -> ";
        }
        here = here->next;
        count++;
    }
    cout << "\n\n";
    
    here = p;
    count = 0;
    
    cout << "------------------Linked List Details--------------------\n" << endl;
    while (here != NULL)
    {
        cout << "List element " << count << endl;
        cout << "+ Address: " << here << endl;
        cout << "+ Value: " << here->val << endl;
        cout << "Next element " << endl;
        if (here->next != NULL)
        {
            cout << "+ List element " << (count + 1) << " ";
        }
        else{
            cout << "+ No next element ";
        }
        cout << "(Address: " << here->next << ")";

        cout << endl;

        here = here->next;
        count++;
        cout  << "--------------------------------------------" << endl;
    }
    
    

    bool passed = true;
    cout << "\n-----------------Report-----------------" << endl;

    if (count != size)
    {
        cout << "The input size does not match the size of your linked list" << endl;
        cout << "Expected size is " << size << " but your size is " << count << "\n\n";
        passed = false;
    }

    if (!check_order(p))
    {
        cout << "Your linked list is not in the alphabetic order " << endl;
        passed = false;
    }else{
        cout << "Your linked list is in in the alphabetic order " << endl;
        passed = false;
    }

    
    if (passed)
        cout << "Your linked list is correct" << endl;
}
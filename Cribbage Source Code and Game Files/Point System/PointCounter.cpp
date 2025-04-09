#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  ***FUNCTIONS START HERE***

//This is a simple function that can print any (type of) vector passed through it with special formatting
template <typename t>
void print_list(vector<t> list) {
    //Declare "i" out here because we need to use it outside of the for loop below
    int i;
    for (i = 0; i < list.size() - 1; i++) { //Prints out everything except the last element of the list with a comma
        cout << list[i] << ", ";
    }
    //Print the last element of the list without a comma, and then a line break
    cout << list[i] << endl;
}

//This is a simple function that checks if a list of any type contains an element of that type and returns how many it has
template <typename t>
int amnt_of_in_vector(vector<t> list, t element) {
    int amnt = 0;
    //A for loop to loop through the whole entire list
    for (int i = 0; i < list.size(); i++) {
        //If the element is equal to the ith element, that means that the list contains thee element
        if (list[i] == element) {
            //Increment the amount of times we have seen the element
            amnt++;
        }
    }
    //Return false because we couldn't find the element in the list that we were looking for
    return amnt;
}

//This function will break a string to a vector, specifically translating stringed numbers into integers
void break_and_push_string_var_to_int_list(string &var, vector<int> &list, char delimiter = ' ') {
    //Add an extra delimiting character to "var" so that the program can get the last number correctly parsed
    var += delimiter;
    
    //A variable to store our outcome, used to break numbers and parse them individually
    string outcome;

    //A for loop to loop through the entirety of "var"
    for (int i = 0; i < var.length(); i++) {
        //If the ith element of "var" is NOT the delimiting character
        if (var[i] != delimiter) {
            //Then we want to add that character to the outcome
            outcome += var[i];
        }
        else {
            //Else, then we want to parse the outcome string, because it is one of our full numbers, and push it to the vector
            list.push_back(stoi(outcome));
            //Then, we will reset and empty "outcome" to use it again later
            outcome = "";
        }
    }
}

//This function takes a vector and sorts it from low to high. It takes a reference of the list to modify the actual vector.
void sort_vector_LtH(vector<int> &list) {
    //First, make a list to store what the contents of the referenced list should contain (this way, we can modify the main list and not lose important data on it)
    vector<int> outcome;

    //A variable to hold the size of the list before we delete elements off of it
    int initial_size = list.size();

    //A for loop to loop through the entirety of the list
    for (int i = 0; i < initial_size; i++) {
        //Two variables. One to store the smallest value in the remaining elements of the list, and another one to store the position of that element
        int smallest_num = list[0], position;

        //A for loop to loop through what remains of the list
        for (int a = 0; a < list.size(); a++) {
            //If the ath element of the list is smaller than the current smallest number
            if (list[a] <= smallest_num) {
                //Set the smallest number to this smaller element
                smallest_num = list[a];
                //Set the position of the smallest element to a, because it is the ath element
                position = a;
            }
        }
        //After the for loop above finishes, we will have the smallest value in it, so we want to push that back to the outcome to maintain LtH order
        outcome.push_back(smallest_num);
        //We don't need the smallest element anymore, so we can delete it
        list.erase(list.begin() + position);
    }

    //Now, after the for loop above fineshes, whe should have the whole entire LtH ordered list complete correctly, so we can set the referenced list to "outcome" (the sorted list)
    list = outcome;
}

//This function will look through the vector that is passed through for any pairs in it and return how many it finds
int find_pairs(vector<int> list) {
    //Variable to store the amount of pairs in
    int pairs = 0;
    
    //A for loop that will loop through the whole entire list
    for (int i = 0; i < list.size(); i++) {
        //A for loop that will loop through all the elements of the list starting from i and on
        for (int a = i+1; a < list.size(); a++) {
            //Checking if these elements form a pair
            if (list[i] == list[a]) {
                //If they do, add 1 to "pairs" to keep track
                pairs++;
            }
        }
    }
    //Return the amount of paris found
    return pairs;
}

//Function to loop through list and find 15s. A recurring function
int find_15s(vector<int> list, int sum = 0, int itterator = 0) {
    //A variable to store our amount of groups of 15s in
    int group = 0;

    //A for loop to loop through the list starting from the value of "itterator" throughout the rest of the list
    for (int i = itterator; i < list.size(); i++) {
        //If "sum" and the current list element (the ith element) is equal to 15:
        if (sum+list[i] == 15) {
            //Then increment group to signify that we have a set of cards that make 15
            group++;
        }

        /*
        We need to call this function again and change the amount of groups of 15s we have if we find any more.
        We are going to pass the list through the function, and also the sum of "sum" and our current element of our list.group
        We will also pass through i+1 so that we don't get stuck inside of an infinite loop, but also to start from checking the next element of the list, since
        we don't need to check the same element twice.
        */
        group += find_15s(list, sum+list[i], i+1);
    }
    
    //Once this loop finishes (if it even gets a chance to run at all), it will return the amount of groups of 15s it found
    return group;
}

//Function to loop through list and find runs
int find_runs(vector<int> list) {
    //A variable to store the amount of points due to runs the function finds
    int runs = 0;

    /*
    A sorting function to sort the list from lowest to highest. This is important because the function needs to work with the
    lowest numbers in the list first in order to keep track of points and how long runs are
    */
    sort_vector_LtH(list);

    //A for loop to loop through the entirety of the list
    for (int i = 0; i < list.size(); i++) {
        /*
        4 variables:
        - A checker variable to get the only next possible value in the run that makes it a valid run
        - A variable to keep track of how long a run is, even if it is not an official run
        - A multiplier to make things simpler when there are double, tripple, or even quadruple runs.
            It makes it more efficient as well because it doesn't have to run the loop as many times to find multiple runs individually, but instead grouping
            them and just multiplying the run length if there are double runs (Check Game Documentation on GitHub for more detail)
        - The itteration variable for the next for loop, because we need to access the itteration of that loop outside of its scope
        */
        int checker = list[i], run_length = 0, multiplier = 1, a;

        //A for loop to loop through the whole list
        for (a = i; a < list.size(); a++) {
            //A variable for optimization, this way the function doesn't have to run multiple times in this one loop. Stores the amount of times the value "checker" appears in the list
            int next_num = amnt_of_in_vector(list, checker);

            //Check if "next_num" is greater than 0 because if it is not, then the run is broken
            if (next_num > 0) {
                //Continue the run, increase one to the run length
                run_length++;
                //Multiply the multiplier by how many times the "checker" value was in our list
                multiplier *= next_num;
                
            }
            else {
                /*
                To help save the program some effort, we'll break here, since we don't have to check for any more possible
                options in the hand. Remember, the run is broken if "next_num" is not greater than 0.
                */
                break;
            }
            //Increment "checker" because the next value in a run is always going to be one more than the current value
            checker++;
        }

        //If the run length (without the multiplier) is greater than or equal to 3
        if (run_length >= 3) {
            //Apply the multiplier to the run length by multiplying "run_length" by "multiplier"
            run_length *= multiplier;
            //Add the potential points to "runs"
            runs += run_length;
            /*
            Now that we have just seen all possible values for a run with these values, we don't want to accidentally
            be counting the "sub runs" in the run, so set i to a (subtracted by one to avoid off-by-1 error)
            */
            i = a-1;
        }
    }

    //Return the total amount of points in runs the function has found
    return runs;
}

//  ***FUNCTIONS END HERE***


int main() {
    string input;

    getline(cin, input);

    vector<int> hand;

    break_and_push_string_var_to_int_list(input, hand);

    print_list(hand);

    unsigned points = (find_pairs(hand) * 2) + (find_15s(hand) * 2) +  find_runs(hand);

    cout << "This hand has contains " << points << " points";

    if (points <= 6) {
        cout << '.';
    }
    else if (points <= 8) {
        cout << ". Good job!";
    }
    else if (points <= 14) {
        cout << "! Great job!";
    }
    else if (points <= 20) {
        cout << "! Wow, very impressive!";
    }
    else if (points <= 24) {
        cout << "!!! Great hand, that's amazing!!!";
    }
    else if (points <= 28) {
        cout << "!!! Incredible! You're very, VERY close to the max amount of points (29)!";
    }
    else if (points <= 29) {
        cout << "!!!!! That's the most points you can get!\nIt's an extremely rare hand, congratulations!!!!!";
    }
    else {
        cout << '.';
    }
    cout << endl;

    if (hand.size() != 4) {
        cout << "This hand, though, isn't possible in cribbage." << endl;
    }

    return 0;
}

//Property of MrScriptDev, 2025
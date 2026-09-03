#include <iostream>
#include "linked_list.h"
using namespace std;

int main(int argc, char** argv) {
  LinkedList<int> list;
  string userInput = "";

  // Get user input until they enter "q" to quit
  while(userInput != "q"){
    cout << " ? ";
    getline(cin, userInput);

    //cout << "You entered: \"" << userInput << "\"" << endl;

    // Appending a new node
    if(userInput[0] == 'a'){
      // cout << "Adding \"" << userInput.substr(2) << "\" to the front of the list." << endl;

      list.push_front(stoi(userInput.substr(2)));
    }

    // Reversing the list
    else if(userInput == "r"){
      list.reverse();
    }

    // Printing the list
    else if(userInput == "p"){
      list.print();
    }

    // Deleting the front node
    else if(userInput == "d"){
      list.pop_front();
    }

    // Quitting the program
    else if(userInput == "q"){
      break;
    }

    // Invalid case
    else{
      cout << "Invalid input" << endl;
    }
  }

  return 0;
}

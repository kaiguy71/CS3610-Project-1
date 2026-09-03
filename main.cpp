#include <iostream>
#include "linked_list.h"
using namespace std;

int main(int argc, char** argv) {
  LinkedList<int> list;
  string userInput = "";

  while(userInput != "q"){
    cout << " ? ";
    getline(cin, userInput);

    //cout << "You entered: \"" << userInput << "\"" << endl;
    if(userInput[0] == 'a'){
      list.push_front(stoi(userInput.substr(2)));
    }
    else if(userInput == "r"){
      list.reverse();
    }
    else if(userInput == "p"){
      list.print();
    }
    else if(userInput == "d"){
      list.pop_front();
    }
    else if(userInput == "q"){
      break;
    }
    else{
      cout << "Invalid input" << endl;
    }
  }

  return 0;
}

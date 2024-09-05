//Andrew Roddy

/*
# NOTES 
Name
Include
using
main
SEMI COLONS

switch case default just `default`
Remember << endl!!!
Remember how lines work
Remember break; in switch -> case statements
*/

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    char again;
    do {
        char answer;
        cout << "Q:How is your day going?\nW: Good\nL: Bad\nA: ";
        cin >> answer;
        switch(answer) {
            case 'W':
                cout << "That is great I am glad to hear that :)" << endl;
                break;
            case 'L':
                cout << "Well that sucks :( I think you should go to the Casino :D and gamble your life savings away!" << endl;
                break;
            default:
                cout << "Thats not an option you idiot!";
                return 0;
        }
        cout << "Would you like me to ask again?(y/n): ";
        cin >> again;
        } while (again != 'n');
}


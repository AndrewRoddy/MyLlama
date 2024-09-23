// Create +, -, *, and / Functions
// Andrew Roddy
// 9/23/2024

#include <iostream>

using std::cin; using std::cout; using std::endl;

int add(int x, int y);
int minus(int x, int y);
int mult(int x, int y);
int divi(int x, int y);

int main(){
    int num1, num2, type, answer, again;;
    while (true){
        cout << "Enter Two Numbers:\n";
        cin >> num1;
        cin >> num2;
        cout << "(integer inputs only)\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\nYour Input:";
        cin >> type;
        switch(type){
            case 1:
                answer = add(num1,num2);
                break;
            case 2:
                answer = minus(num1,num2);
                break;
            case 3:
                answer = mult(num1,num2);
                break;
            case 4:
                answer = divi(num1,num2);
                break;
            default:
                cout << "Invalid Input" << endl;
                return 0;
        }
        cout << "Your Answer: " << answer << endl;
        
        cout << "Again?\n0 or 1:";
        cin >> again;
        if (again == 0){
            return 0;
        }
    }
        
}

int add(int x, int y){
    return (x + y);
    }
int minus(int x, int y){
    return (x - y);
    }
int mult(int x, int y){
    return (x * y);
    }
int divi(int x, int y){
    return (int) (x / y);
    }

// Notes:
// Make sure you make the program do the intended response.
// Don't try and create a looping question portion
// It takes too long!
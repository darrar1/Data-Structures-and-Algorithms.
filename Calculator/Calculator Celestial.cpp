#include <iostream>
using namespace std;


int main(){

    char op;
    float num1, num2, num3;

    cout << "My Basic Calculator - Celestial";
    cout << "\n";
    cout << "\n";
    cout << "1. Addition" <<"\n";
    cout << "2. Substraction" << "\n";
    cout << "3. Multiplication" << "\n";
    cout << "4. Division" << "\n";
    cout << "\n";

    cout << "What operator should we use today?";
    cin >> op;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch (op) {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*:
            cout << num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 / num2;
            } else {
                cout << "Error! Division by zero.";
            }

        default:
            cout << "Error! Choose only 1 to 4";
        

    }





    return 0;



}



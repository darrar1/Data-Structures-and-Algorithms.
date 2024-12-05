#include <iostream>
using namespace std;

int main() {

    char op;
    float num1, num2;

    cout << "My Basic Calculator - Celestial";
    cout << "\n\n";
    cout << "1. Addition" << "\n";
    cout << "2. Subtraction" << "\n";
    cout << "3. Multiplication" << "\n";
    cout << "4. Division" << "\n\n";

    cout << "What operator should we use today? (1/2/3/4): ";
    cin >> op;

    cout << "First Number: ";
    cin >> num1;
    cout << "Second Number: ";
    cin >> num2;

    switch (op) {
        case '1':
            cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '2':
            cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '3':
            cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '4':
            if (num2 != 0) {
                cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2;
            } else {
                cout << "Error! Division by zero.";
            }
            break;
        default:
            cout << "Error! Choose only 1 to 4.";
            break;
    }

    return 0;
}

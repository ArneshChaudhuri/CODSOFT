#include <iostream>
#include <limits>

using namespace std;

void showMenu() {
    cout << "=== SIMPLE CALCULATOR ===\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";
    cout << "Choose operation: ";
}

double getNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (!cin.fail()) return num;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again.\n";
    }
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n\n";
            continue;
        }
        if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        }
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Enter 1-5.\n\n";
            continue;
        }

        double a = getNumber("Enter first number: ");
        double b = getNumber("Enter second number: ");
        double result;

        switch (choice) {
        case 1:
            result = a + b;
            cout << a << " + " << b << " = " << result << "\n";
            break;
        case 2:
            result = a - b;
            cout << a << " - " << b << " = " << result << "\n";
            break;
        case 3:
            result = a * b;
            cout << a << " * " << b << " = " << result << "\n";
            break;
        case 4:
            if (b == 0) {
                cout << "Error: Division by zero.\n";
            }
            else {
                result = a / b;
                cout << a << " / " << b << " = " << result << "\n";
            }
            break;
        }
        cout << "\n";
    }
    return 0;
}
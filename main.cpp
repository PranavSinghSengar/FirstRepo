
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

// Store calculation history
vector<string> history;

// Get valid number input
double getNumber(string message) {
    double num;

    while (true) {
        cout << message;

        if (cin >> num) {
            return num;
        }

        cout << "Invalid input! Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Addition
double add(double a, double b) {
    return a + b;
}

// Subtraction
double subtract(double a, double b) {
    return a - b;
}

// Multiplication
double multiply(double a, double b) {
    return a * b;
}

// Division
double divide(double a, double b) {
    return a / b;
}

// Modulus
double modulus(double a, double b) {
    return fmod(a, b);
}

// Power
double power(double a, double b) {
    return pow(a, b);
}

// Square Root
double squareRoot(double a) {
    return sqrt(a);
}

// Display menu
void showMenu() {
    cout << "\n";
    cout << "====================================\n";
    cout << "         SMART CALCULATOR\n";
    cout << "====================================\n";

    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%)\n";
    cout << "6. Power (^)\n";
    cout << "7. Square Root (sqrt)\n";
    cout << "8. View History\n";
    cout << "9. Clear History\n";
    cout << "0. Exit\n";

    cout << "====================================\n";
}

// Display calculation history
void showHistory() {
    cout << "\n========== CALCULATION HISTORY ==========\n";

    if (history.empty()) {
        cout << "No calculations available.\n";
    } else {
        for (int i = 0; i < history.size(); i++) {
            cout << i + 1 << ". " << history[i] << "\n";
        }
    }

    cout << "=========================================\n";
}

// Main function
int main() {

    int choice;
    double num1, num2, result;

    cout << fixed << setprecision(6);

    cout << "\nWelcome to Smart Calculator!\n";

    while (true) {

        showMenu();

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid choice! Enter a number from 0 to 9.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        if (choice == 0) {
            cout << "\nThank you for using Smart Calculator!\n";
            break;
        }

        if (choice == 8) {
            showHistory();
            continue;
        }

        if (choice == 9) {
            history.clear();
            cout << "\nHistory cleared successfully!\n";
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "\nInvalid choice! Please try again.\n";
            continue;
        }

        // Square root operation
        if (choice == 7) {

            num1 = getNumber("Enter a number: ");

            if (num1 < 0) {
                cout << "\nError: Square root of a negative number "
                     << "is not supported in real numbers.\n";
                continue;
            }

            result = squareRoot(num1);

            cout << "\nResult: sqrt(" << num1 << ") = "
                 << result << "\n";

            history.push_back(
                "sqrt(" + to_string(num1) + ") = "
                + to_string(result)
            );

            continue;
        }

        // Get two numbers
        num1 = getNumber("Enter first number: ");
        num2 = getNumber("Enter second number: ");

        string operation;

        switch (choice) {

            case 1:
                result = add(num1, num2);
                operation = "+";
                break;

            case 2:
                result = subtract(num1, num2);
                operation = "-";
                break;

            case 3:
                result = multiply(num1, num2);
                operation = "*";
                break;

            case 4:
                if (num2 == 0) {
                    cout << "\nError: Division by zero is not allowed!\n";
                    continue;
                }

                result = divide(num1, num2);
                operation = "/";
                break;

            case 5:
                if (num2 == 0) {
                    cout << "\nError: Modulus by zero is not allowed!\n";
                    continue;
                }

                result = modulus(num1, num2);
                operation = "%";
                break;

            case 6:
                result = power(num1, num2);
                operation = "^";
                break;

            default:
                continue;
        }

        // Check invalid mathematical results
        if (!isfinite(result)) {
            cout << "\nError: Result is outside the supported range "
                 << "or is mathematically undefined.\n";
            continue;
        }

        // Display result
        cout << "\n------------------------------------\n";

        cout << "Result: " << num1 << " "
             << operation << " " << num2
             << " = " << result << "\n";

        cout << "------------------------------------\n";

        // Save in history
        history.push_back(
            to_string(num1) + " " + operation + " "
            + to_string(num2) + " = " + to_string(result)
        );
    }

    return 0;
}

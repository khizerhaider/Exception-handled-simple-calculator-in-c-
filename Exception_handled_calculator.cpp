#include <iostream>

using namespace std;

class Operation {
public:
    double compute(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw "Division by zero is not allowed";
        }
        return a / b;
    }
};

class CalculatorApp {
private:
    Operation operation;

public:
    void execute() {
        while (true) {
            try {
                cout << "Calculator Menu:" << endl;
                cout << "1. Add" << endl;
                cout << "2. Subtract" << endl;
                cout << "3. Multiply" << endl;
                cout << "4. Divide" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: ";

                int choice;
                cin >> choice;

                if (choice == 5) {
                    cout << "Exiting calculator. Goodbye!" << endl;
                    break;
                }

                double num1, num2;
                cout << "Enter first number: ";
                if (!(cin >> num1)) {
                    throw "Invalid input. Please enter a number.";
                }
                cout << "Enter second number: ";
                if (!(cin >> num2)) {
                    throw "Invalid input. Please enter a number.";
                }

                // Clear the input buffer
                while (cin.get() != '\n')
                    continue;

                double result;
                switch (choice) {
                    case 1:
                        result = operation.compute(num1, num2);
                        break;
                    case 2:
                        result = operation.subtract(num1, num2);
                        break;
                    case 3:
                        result = operation.multiply(num1, num2);
                        break;
                    case 4:
                        result = operation.divide(num1, num2);
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        continue;
                }

                cout << "Result: " << result << endl;

            } catch (const char* error) {
                cerr << "Error: " << error << endl;
                // Clear the input buffer
                while (cin.get() != '\n')
                    continue;
            } catch (...) {
                cerr << "An unexpected error occurred" << endl;
            }
        }
    }
};

int main() {
    CalculatorApp application;
    application.execute();

    return 0;
}
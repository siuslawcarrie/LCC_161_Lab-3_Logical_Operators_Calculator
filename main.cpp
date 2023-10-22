/*Program: Lab#3 Logical Expressions * Carrie Bailey
 * 10/7/2023
 *
 * Version 1
 * Ask user for 1st number
 * Ask user for operator
 * Ask user for 2nd number
 * :display an error if the user does not input an operator
 * :display an error if the user chooses division and the second number is zero
 *
 * //VARIABLES
 * string username
 *
 * int num_1
 * int num_2
 * double result
 * //end variables
 *
 * Welcome message
 * Ask user for name
 * Ask user for 2 numbers
 * Display operators
 * Ask user to choose an operator
 * function to validate
 * //IF STATEMENT
 *
 * //
*/

#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <limits>

using namespace std;

//void userWelcome(); //CHECK



const char PLUS = '+';
const char MINUS = '-';
const char MULTIPLY = '*';
const char DIVIDE = '/';
const char MODULUS = '%';
bool valid;


char user_operator_func(); //user operator
char validateOperator(char d); //function to validate operator is valid
int num_1();

int num_2();

int validation_integer(int min, int max);


int isNotZero_func(int m);

int main() {
    int m;//to test for zero when entering division and second number = 0
    char isValidOperator;

    int isInteger1, isInteger2;
    int is_not_zero;
    int result; // variables for calculation results
    // userWelcome();

    cout << "This will perform a calculation on two numbers. "
            "You will be asked to enter two separate numbers and an operator. " << endl;

    isInteger1 = num_1();
    isValidOperator = user_operator_func();
    isInteger2 = num_2();


    //performCalculation(userOperator, isInteger1, isInteger2);
    switch (isValidOperator) {
        case
            PLUS:
            result = isInteger1 + isInteger2;
            break;
        case
            MINUS:
            result = isInteger1 - isInteger1;
            break;
        case
            MULTIPLY:
            result = isInteger1 * isInteger2;
            break;
        case
            DIVIDE:
            is_not_zero = isNotZero_func(isInteger2);
            result = isInteger1 / is_not_zero;
            break;
        case
            MODULUS:
            is_not_zero = isNotZero_func(isInteger2);
            result = isInteger1 % is_not_zero;
            break;
    }
    if ((isValidOperator == '+') or (isValidOperator == '-') or (isValidOperator == '*')) {
        cout << isInteger1 << " " << isValidOperator << " " << isInteger2 << " = " << result << endl;
    }
    else
    {
        cout << isInteger1 << " " << isValidOperator << " " <<is_not_zero << " = " << result << endl;
    }


    return 0;
}

void userWelcome() {
    string user_name;
    cout << "Welcome to Carrie's Number Calculator! What is your name? ";
    cin >> user_name;
    cout << "Hi " << user_name << "! Let's play!" << endl;
    return;
}

int num_1() {

    cout << "Please enter your first number: ";


    auto min = -99999999, max = 9999999;
    return validation_integer(min, max);
}

char user_operator_func() {
    char userOperator;
    cout << "Please enter your operator from the following list: +,-,*,/,%: ";
    cin >> userOperator;

    return validateOperator(userOperator);
}

int num_2() {

    cout << "Please enter your second number: ";


    auto min = -99999999, max = 9999999;
    return validation_integer(min, max);
}


int validation_integer(int min, int max) //function to validate integers
{
    int number;
    cin >> number;
    while (!cin or (number < min) or (number > max)) {
// Explain error not entering an integer
        cout << "I'm sorry that's not a valid entry. Please enter a number between " << min << "and " << max << ": ";
// Clear input stream
        cin.clear();
// Discard previous input
        cin.ignore(123, '\n');
        cin >> number;
        cout << endl;
    }
    return number;
}

char validateOperator(char d) {

    valid = false;
    while (!valid) {
        switch (d) {
            case PLUS:
            case MINUS:
            case MULTIPLY:
            case DIVIDE:
            case MODULUS:
                valid = true;
                break;
            default:
                cout << "I'm sorry that's not a valid entry. Please enter a valid operator: ";
                cin >> d;
                break;

        }
    }
    return d;
}

int isNotZero_func(int m) {
    while (m == 0) {
        cout << "I'm sorry. You can't divide by zero. Please enter a different divisor: " << endl;
        cin >> m;
    }
    return m;
    }




/*

            int performCalculation(char
            'z', int
            x, int
            y)
            {
                switch (z) {
                    case
                        z = '+'
                        :
                        result = num_1 + num_2;

                        break;
                    case
                        z = '-'
                        :
                        result = num_1 - num_2;
                        break;
                    case
                        z = '*'
                        :
                        result = num_1 * num_2;
                        break;
                    case
                        z = '/'
                        :
                        result = num_1 / num_2;
                        break;
                    case
                        z = '%'
                        :
                        result = num_1 % num_2;
                        break;
                }


                return
                        result;
*/


/* Carrie Bailey
 * 10/7/2023

*//*Program: Lab#3 Logical Expressions *
 *  Write a program that acts as a simple calculator.
• Ask the user to input an integer.
• Ask for an operator from the following list. * / % + -
• Ask for a second integer.
• If the user does not enter a valid operator, report an error and terminate.
• If the user asks to do division or modulus and the second number is zero, report an error and
terminate.
• Otherwise, display the equation and the result
 * Due: 10/15/2023
 * * Version 1
 *
 * algorhithm
 *
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
#include <iomanip>

using namespace std;

void userWelcome(); //CHECK

//CONSTANTS
const char PLUS = '+';
const char MINUS = '-';
const char MULTIPLY = '*';
const char DIVIDE = '/';
const char MODULUS = '%';
const int BIG_NUM = INT_MAX;
const char END_LINE = '\n';

bool valid;

//END CONSTANTS
// FUNCTIONS
char user_operator_func(); //user operator
char validateOperator(char d); //function to validate operator is valid
int num_1();

int num_2();//do not need these functions, validation is getting the integers
int validation_integer(int min, int max);

int isNotZero_func(int m);
//END FUNCTIONS

int main() {
    int m;//to test for zero when entering division and second number = 0
    char isValidOperator;
    int result_divide;
    // userWelcome();
    cout << "This will perform a calculation on two numbers. "
            "You will be asked to enter two separate numbers and an operator. " << endl;

    int isInteger1 = (num_1());//call validate function directly in main, assign to integer1,
    isValidOperator = user_operator_func();
    int isInteger2 = (num_2());//call validate function directly in main, assign to integer1,
    int is_not_zero = (isNotZero_func(m));//call validate function directly in main, assign to integer1
    int result; // variables for calculation results
    //performCalculation(userOperator, isInteger1, isInteger2);
    switch (isValidOperator) {
        //call validate function directly in main, assign to integer1, change to float

        case
            PLUS:
            result = isInteger1 + isInteger2;
            break;
        case
            MINUS:
            result = isInteger1 - isInteger2;
            break;
        case
            MULTIPLY:
            result = isInteger1 * isInteger2;
            break;
        case
            MODULUS:
            is_not_zero = isNotZero_func(isInteger2);
            result = isInteger1 % is_not_zero;
            break;
        case
            DIVIDE:
            is_not_zero = isNotZero_func(isInteger2);
            auto float_is_not_zero = float(is_not_zero);
            auto float_is_Integer1 = float(isInteger1);
            auto result_divide = float_is_Integer1 / float_is_not_zero;
            cout << isInteger1 << " " << isValidOperator << " " << is_not_zero << " = " << fixed << setprecision(2) << result_divide << endl;
            break;

    }
    if ((isValidOperator == '+') or (isValidOperator == '-') or (isValidOperator == '*')) {

        cout << isInteger1 << " " << isValidOperator << " " << isInteger2 << " = " << result << endl;
    }
    else if (isValidOperator == '%') {

        cout << isInteger1 << " " << isValidOperator << " " << is_not_zero << " = " << result << endl;;
    }


}

void userWelcome() {
    string user_name;
    cout << "Welcome to Carrie's Number Calculator! What is your name? ";
    cin >> user_name;
    cout << "Hi " << user_name << "! Let's play!" << endl;
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
    if (!cin or (number < min) or (number > max)) {
// Explain error not entering an integer
        cout << "I'm sorry that's not a valid entry.";
    }
    else {
        return number;
    }
}
    int isNotZero_func(int m) {
        if (m == 0) {
            cout << "I'm sorry. You can't divide by zero. " << endl;

        }
        return m;
    }



    char validateOperator(char d) {

        valid = true;
        do {


            // set the input flag to valid
            valid = true;

            // using switch statement
            switch (d) {
                case PLUS:
                case MINUS:
                case MULTIPLY:
                case DIVIDE:
                case MODULUS:
                default:
                    cout << "Invalid input, try again" << endl;
                    valid = false;
            }

            // clear input buffer in case they entered more than one char
            cin.ignore(BIG_NUM, END_LINE);

        }
            while (!valid);

                return d;






}
return 0;
}






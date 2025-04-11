#include <iostream>
#include <string>
#include <limits>
using namespace std;

void factorialCalculator();
void numberPyramid();
void sumEvenOrOdd();
void reverseString();
void fibonacciSeries();
void palindromeChecker();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 7) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 7: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: factorialCalculator(); break;
            case 2: numberPyramid(); break;
            case 3: sumEvenOrOdd(); break;
            case 4: reverseString(); break;
            case 5: fibonacciSeries(); break;
            case 6: palindromeChecker(); break;
            case 7:
                cout << "\nGoodbye! Thanks for using the utility program.\n";
                break;
        }

        cout << "\n";

    } while (choice != 7);

    return 0;
}

// Menu Display Function
void displayMenu() {
    cout << "========= Interactive Utility Program =========\n";
    cout << "1. Factorial Claculator\n";
    cout << "2. Number Pyramid\n";
    cout << "3. Sum of Even or Odd Numbers\n";
    cout << "4. Reverse a String\n";
    cout << "5. Fibonacci Series (Bonus)\n";
    cout << "6. Palindrome Checker (Bonus)\n";
    cout << "7. Exit\n";
    cout << "===============================================\n";
    cout << "Enter your choice (1-7): ";
}

//Factorial using while loop
void factorialCalculator() {
    int n;
    cout << "\nEnter a positive integer: ";
    cin >> n;

    while (n < 0 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid positive integer: ";
        cin >> n;
    }

    int result = 1;
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }

    cout << "Factorial of " << n << " is: " << result << endl;
}

// Number Pyramid using nested for loops
void numberPyramid() {
    int rows;
    cout << "\nEnter number of rows: ";
    cin >> rows;

    while (rows <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a positive number of rows: ";
        cin >> rows;
    }

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= rows - i; ++j)
            cout << " ";
        for (int k = 1; k <= i; ++k)
            cout << k << " ";
        cout << endl;
    }
}

// Sum of Even or Odd Numbers using do-while
void sumEvenOrOdd() {
    int choice, limit;

    do {
        cout << "\nChoose an option:\n1. Sum Even Numbers\n2. Sum Odd Numbers\nEnter 1 or 2: ";
        cin >> choice;
    } while (choice != 1 && choice != 2);

    cout << "Enter an upper limit: ";
    cin >> limit;

    while (limit < 1 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid upper limit: ";
        cin >> limit;
    }

    int sum = 0, i = 1;

    do {
        if (choice == 1 && i % 2 == 0)
            sum += i;
        else if (choice == 2 && i % 2 != 0)
            sum += i;
        i++;
    } while (i <= limit);

    if (choice == 1)
        cout << "Sum of even numbers up to " << limit << ": " << sum << endl;
    else
        cout << "Sum of odd numbers up to " << limit << ": " << sum << endl;
}

// Reverse string using while loop
void reverseString() { 
    string input, reversed = "";
    cout << "\nEnter a string: ";
    cin >> input;

    int i = input.length() - 1;
    while (i >= 0) {
        reversed += input[i];
        i--;
    }

    cout << "Reversed string: " << reversed << endl;
}

// BONUS: Fibonacci series using for loop
void fibonacciSeries() {
    int n;
    cout << "\nEnter the number of terms for Fibonacci series: ";
    cin >> n;

    while (n <= 0 || cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a positive integer: ";
        cin >> n;
    }

    int t1 = 0, t2 = 1, nextTerm;

    cout << "Fibonacci Series up to " << n << " terms: ";
    for (int i = 1; i <= n; ++i) {
        cout << t1 << " ";
        nextTerm = t1 + t2;
        t1 - t2;
        t2 = nextTerm;
    }
    cout << endl;
}

// BONUS: Palindrome checker using while loop
void palindromeChecker() {
    string word, reversed = "";
    cout << "\nEnter a word to check for palindrome: ";
    cin >> word;

    int i = word.length() - 1;
    while (i >= 0) {
        reversed += word[i];
        i--;
    }

    if (word == reversed)
        cout << word << " is a palindrome." << endl;
    else
        cout << word << " is not a palindrome." << endl;
}
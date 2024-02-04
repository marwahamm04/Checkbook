#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// Above we included all libraries we are going to use 

// Here we defined the strucy check and the checknumber, checkmemo, and check amount. 
struct Check {
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
};

// Here we defined the class checkbook and assigned the public and private classes
class CheckBook {
private:
    static const int N = 5; // here we defined N as a constant and set it to 5 as said in the instructions
    float balance;
    Check checks[N];
    float lastDeposit;
    int numOfChecks;
    const int checkLimit;

public:
    
    CheckBook() : balance(0), lastDeposit(0), numOfChecks(0), checkLimit(N) {} // this is the default constructor which sets balance to 0 and numOfChecks to 0.

    CheckBook(float initialBalance) : balance(initialBalance), lastDeposit(0), numOfChecks(0), checkLimit(N) {} // this is the second constructor which takes an initial balance and sets numOfChecks to 0.

    // This is the function to deposit amount
    void deposit(float amount) {
        balance += amount;
        lastDeposit = amount;
    }

    // This is the function to display checks
    void displayChecks() {
        for (int i = numOfChecks - 1; i >= 0; i--) {
            cout << checks[i].CheckAmount << " " << checks[i].CheckNum << " " << checks[i].CheckMemo << endl;
        }
    }

    // This function is to write a check
    bool writeCheck(float amount) {
        if (amount <= balance && numOfChecks < checkLimit) {
            cout << "memo? ";
            string memo;
            cin >> memo;

            checks[numOfChecks].CheckNum = numOfChecks;
            checks[numOfChecks].CheckMemo = memo;
            checks[numOfChecks].CheckAmount = amount;

            balance -= amount;
            numOfChecks++;

            return true;
        } else {
            return false;
        }
    }

    static int getallChecks() { // This the the static integer which will keep track of the checks written in the program
        return N; 
    }
};

int main() {
    // 
    CheckBook cb1(1000), cb2(500); // This is my main program where I create two CheckBook instance cb1 and cb2

    for (int i = 0; i < 10; i++) {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }

    cout << "cb1 check details" << endl;
    cb1.displayChecks();

    cout << "cb2 check details" << endl;
    cb2.displayChecks();

    cout << "Homework 1 completed by Marwa Hammami!" << endl;


    return 0;
}

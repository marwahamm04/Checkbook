#include <iostream>
using namespace std;

class Check {
private:
    static int number; // this is the static member to keep track of the number of Check 
    int CheckNum;
    string CheckMemo;
    float CheckAmount;

public:
    // The defult constructor
    Check() : CheckNum(0), CheckMemo(""), CheckAmount(0) {
        number++; // increment of the static member
    }

    // Constructor 
    Check(int num, string memo, float amount) : CheckNum(num), CheckMemo(memo), CheckAmount(amount) {
        number++; // increment of the static member
    }

    // Getter and setter 
    int getCheckNum() const {
        return CheckNum;
    }

    void setCheckNum(int num) {
        CheckNum = num;
    }

    // Getter and setter functions for CheckMemo
    string getCheckMemo() const {
        return CheckMemo;
    }

    void setCheckMemo(string memo) {
        CheckMemo = memo;
    }

    // Getter and setter functions for CheckAmount
    float getCheckAmount() const {
        return CheckAmount;
    }

    void setCheckAmount(float amount) {
        CheckAmount = amount;
    }

    // Getter function for the static member
    static int getNumber() {
        return number;
    }
};

int Check::number = 0; // this initalizes the static member

class CheckBook {
private:
    static const int N = 5; // The size of the Check array
    Check checks[N];
    float balance;
    int numOfChecks;
    const int checkLimit;
    static int allChecks; // This is the static member to keep track of all checks written

public:
    // This is the defult constructor
    CheckBook() : balance(0), numOfChecks(0), checkLimit(N) {}

    // The constructor with initial balance
    CheckBook(float initialBalance) : balance(initialBalance), numOfChecks(0), checkLimit(N) {}

    // the getter function for allChecks
    static int getAllChecks() {
        return allChecks;
    }

    // This display checks function
    void displayChecks() {
        for (int i = numOfChecks - 1; i >= 0; --i) {
            cout << checks[i].getCheckAmount() << " " << checks[i].getCheckNum() << " " << checks[i].getCheckMemo() << endl;
        }
    }

    // This is the check function
    bool writeCheck(float amount) {
        if (numOfChecks < N && allChecks < 10 && amount <= balance) {
            // Ask for details
            cout << " memo? ";
            string memo;
            cin >> memo;

            // This created a new Check object and updates its details
            checks[numOfChecks].setCheckNum(numOfChecks);
            checks[numOfChecks].setCheckMemo(memo);
            checks[numOfChecks].setCheckAmount(amount);

            // The update balance, numOfChecks, and allChecks
            balance -= amount;
            numOfChecks++;
            allChecks++;

            return true;
        } else {
            return false;
        }
    }
};

int CheckBook::allChecks = 0; // Initialize the static member

int main() {
    // This teste the CheckBook class 
    CheckBook cb1(1000), cb2(500);

    for(int i = 0; i < 10; i++) {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }

    cout << "cb1 check details" << endl;
    cb1.displayChecks();
    
    cout << "cb2 check details" << endl;
    cb2.displayChecks();
    
    cout << "Total checks written in cb1: " << cb1.getAllChecks() << endl;
    cout << "Total checks written in cb2: " << cb2.getAllChecks() << endl;

    return 0;
}

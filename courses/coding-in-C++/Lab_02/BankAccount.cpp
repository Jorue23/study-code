#include <iostream>

using namespace std;

class BankAccount {
    private:
        string owner;
        double balance = 0.0;
    public:
        void setOwner(string new_owner);
        string getOwner();
        void deposit(double);
        void withdraw(double);
        double getBalance();
        void getAccountInfo();
};

void BankAccount::setOwner(string new_owner) {
    owner = new_owner;
    cout << "New owner is: " << getOwner() << endl;
    return;
}

string BankAccount::getOwner() {
    if(!owner.empty()) {
        return owner;
    }
    else {
        return NULL;
    }
}

void BankAccount::deposit(double added_balance) {
    if(added_balance > 0) {
        balance += added_balance;
        cout << "Added balance succesfully! New balance: " << getBalance() << endl;
    }
    else {
        cout << "Invalid deposit amount!" << endl;
    }
    return;
}

void BankAccount::withdraw(double removed_balance) {
    if(balance < removed_balance || removed_balance < 0) {
        cout << "Invalid withdraw amount!" << endl;
    }
    else {
        balance -= removed_balance;
        cout << "Withdrew successful. New balance: " << getBalance() << endl;
    }
}

double BankAccount::getBalance() {
    return balance;
}

void BankAccount::getAccountInfo() {
    cout << "Owner: " << getOwner() << endl;
    cout << "Balance: " << getBalance() << endl;
}

int main() {
    BankAccount myAccount;

    myAccount.setOwner("Hello World!");

    string AccountOwner = myAccount.getOwner();
    if(AccountOwner == "") {
        cout << "No owner found!" << endl;
    }
    else {
        cout << "Owner: " << AccountOwner << endl;
    }

    myAccount.deposit(100.36);

    myAccount.deposit(-2347.4);

    myAccount.withdraw(37.42);

    myAccount.withdraw(-23.32);

    myAccount.getAccountInfo();

    myAccount.setOwner("Max");

    myAccount.getAccountInfo();


}

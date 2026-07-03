#include<iostream>

using namespace std;

class Account{
    private:
    double balance;
    int id;
    static int accounts;

    public:
    Account(){
        balance = 0;
        id = 0;
        accounts++;
    }

    static int getaccounts() {
        return accounts;
    }
};

// Definition of static member
int Account::accounts = 0;

int main(){

    cout << Account::getaccounts() << endl;

    Account a1, a2, a3;

    cout << a1.getaccounts();

    return 0;
}
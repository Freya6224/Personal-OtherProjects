#include "check.h"
#include <string>
#include <iostream>

using namespace std;

//constructors
Check::Check() : number(0),amount{0},cashOpt(0)
{}

Check::Check(long newNumber, Money newAmount, bool newCashOpt):
number(newNumber), amount(newAmount), cashOpt(newCashOpt){}

//setters
void Check::setNumbers(long newNumber)
{
    number = newNumber;
}
void Check::setAmount(const Money& newAmount)
{
    amount = newAmount;
}
void Check::setCashOpt(bool newCashOpt)
{
    cashOpt = newCashOpt;
}

//input function for the file
void Check::input(istream & readFile )
{
    readFile >> number;
    amount.input(readFile);
    readFile >> cashOpt;
}

//input function for the keyboard
void Check::inputKey()
{
    cout << "\nEnter the check number: ";
    cin >> number;
    
    while(number < 0)
    {
        cout << "\nEnter the check number again: ";
        cin >> number;
    }
    
    cout << "\nEnter the amount: ";
    amount.input(cin);
    
    cout << "\nCashed or not(1 for yes, 0 for no): ";
    cin >> cashOpt;
    
    while(cashOpt != 0 && cashOpt != 1)
    {
        cout << "\nCashed or not(1 for yes, 0 for no): ";
        cin >> cashOpt;
    }
}




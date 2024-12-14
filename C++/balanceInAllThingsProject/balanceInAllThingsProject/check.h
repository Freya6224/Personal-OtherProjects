#ifndef check_h
#define check_h
#include "money.h"
#include <iostream>

class Check{
    
    long number;
    Money amount;
    bool cashOpt;
    
public:
    //constuctors
    Check(void);
    Check(long newNumber, Money newAmount, bool newCashOpt);
    
    //getters
    long getNumbers() const {return number;}
    Money getAmount() const {return amount;}
    bool getCashOpt() const {return cashOpt;}
    
    //setters
    void setNumbers(long newNumber);
    void setAmount(const Money& newAmount);
    void setCashOpt(bool newCashOpt);
    
    //input functions
    void input(std::istream & readFile );
    void inputKey();
    
};

#endif

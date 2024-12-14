#include "money.h"
#include <iostream>
#include <iomanip>

using namespace std;

//constructors
Money::Money(void): all_cents(0.00){}

Money::Money(long dollars) : all_cents(dollars*100){}

Money::Money(long dollars, short cents): all_cents(dollars*100 + cents){}


Money Money::add(const Money & amount) const
{
    Money addMoney;
    addMoney.all_cents = all_cents + amount.all_cents;
    return addMoney;
}


Money Money::subtract(const Money & amount) const
{
    Money subtractMoney;
    subtractMoney.all_cents = all_cents - amount.all_cents;
    return subtractMoney;
}


Money Money::negate(void) const
{
    Money negateMoney;
    negateMoney.all_cents = -all_cents;
    return negateMoney;
}

bool Money::equals(const Money & amount) const
{
    return all_cents == amount.all_cents;
}

bool Money::less(const Money & amount) const
{
    return all_cents < amount.all_cents;
}

void Money::input(std::istream & ins)
{
    //read it as a string and than divide
    //the amount depending on the '.'
    char sign = '$' ,dot = '.';
    long dollar =0, cents = 00;
    
    //updated on the suggestion
    if(ins.peek() == sign)
    {
        ins.ignore();
    }
    ins >> sign >> dollar >> dot >> cents;
    all_cents = dollar * 100 + cents;
    
}

void Money::output(std::ostream & outs) const
{
    ios_base::fmtflags orgOut = outs.flags();
    //setted up to get the right format for the money
    outs << fixed << showpoint << setprecision(2);
    outs << '$' << get_value();
    //setting into orginal formatting
    outs.flags(orgOut);
}

double Money::get_value(void) const
{
    return static_cast<double>(all_cents)/100.00;
}

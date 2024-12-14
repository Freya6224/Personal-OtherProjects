#ifndef money_h
#define money_h

#include <iostream>

class Money
{
    long all_cents; // monetary value stored as pennies
    
public:
    
    // Initializes the object to $0.00.
    Money(void);
    
    // Initializes the object to dollars*100 cents.
    Money(long dollars);
    
    // Initializes the object to dollars*100 + cents.
    Money(long dollars, short cents);
    
    // Postcondition:  return value is sum of calling object and amount.
    //                 neither amount nor calling object are changed.
    Money add(const Money & amount) const;
    
    // Postcondition:  return value is difference of calling object and amount.
    //                 neither amount nor calling object are changed.
    Money subtract(const Money & amount) const;
    
    // Postcondition:  return value is arithmetic negation of calling object.
    //                 calling object is not changed.
    Money negate(void) const;
    
    // Returns true if the calling object equals the amount, false otherwise.
    bool equals(const Money & amount) const;
    
    // Returns true if the calling object is less than the amount,
    // false otherwise.
    bool less(const Money & amount) const;
    
    // Postcondition:  calling object's value is read from the stream
    //                 in normal U.S. format:  $ddd.cc.
    void input(std::istream & ins);
    
    // Postcondition:  calling object's value is printed on the stream
    //                 in normal U.S. format:  $ddd.cc.  (calling object
    //                 is not changed)
    void output(std::ostream & outs) const;
    
    // Returns amount of money in decimal format.
    double get_value(void) const;
};

#endif

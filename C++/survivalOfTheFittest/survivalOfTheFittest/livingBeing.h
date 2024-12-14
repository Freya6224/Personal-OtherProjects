#ifndef livingBeing_h
#define livingBeing_h
#include <vector>
#include <iostream>

class LivingBeing
{
public:
    //abstract class 
    virtual ~LivingBeing(void) {}
    
    virtual std::string getName() const = 0;
    virtual long getSpeed() const = 0;
    virtual double getBirthRate() const = 0;
    virtual bool isAlive() const = 0;
    virtual void die(void) = 0;
    
};
#endif

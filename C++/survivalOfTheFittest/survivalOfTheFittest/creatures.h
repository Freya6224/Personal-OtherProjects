
#ifndef creatures_h
#define creatures_h

#include <iostream>
#include <vector>
#include "livingBeing.h"

class Creature: public LivingBeing
{
protected:
    std::string name;
    long speed;
    double birthRate;
    bool alive = true;
    
public:
    Creature();
    Creature (const std::string& name, long newSpeed,
              double birthRate);
    
    virtual void procreate(std::vector<Creature*> &population) = 0;
    virtual void choiceOfActionTaken(Creature* other) = 0;
    bool isAlive() const override;
    std::string getName() const override;
    long getSpeed() const override;
    double getBirthRate() const override;
    void die(void) override;
    
    virtual ~Creature();
}; 


#endif

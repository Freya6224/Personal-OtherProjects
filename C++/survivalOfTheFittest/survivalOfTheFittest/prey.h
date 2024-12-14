
#ifndef prey_h
#define prey_h

#include <iostream>
#include "creatures.h"

class Prey: public Creature
{
    long foodWorth;
    
public:
    Prey();
    Prey(const std::string& name, long speed, double birthRate,
             long foodWorth);
    void choiceOfActionTaken(Creature* other) override;
    //getters for foodWorth
    long getFoodWorth() const;
    void procreate(std::vector<Creature*> &population) override;
    virtual ~Prey();
};

#endif 


#ifndef predator_h
#define predator_h

#include <iostream>
#include "creatures.h"

class Predator: public Creature
{
    //energyLevel serves as hunger level
    //variables that was stated on the
    //requirement sheet
    long energyLevel;
    bool eatenPrey = false;
    
public:
    //constructors
    Predator();
    Predator(const std::string& name, long speed, double birthRate,
             long energyLevel);
    
    void choiceOfActionTaken(Creature* other) override;
    //get and update the energy level
    long getEnergyLevelValue() const;
    bool succesOfAttack();
    void updateEnergyLevel(long getValue);
    void procreate(std::vector<Creature*> &population) override;
    
    virtual ~Predator();
};

#endif 

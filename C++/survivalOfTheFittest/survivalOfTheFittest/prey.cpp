#include "prey.h"
#include <iostream>

using namespace std;

Prey::Prey():Creature(),foodWorth(0) {}
Prey::Prey(const string& newName, long newSpeed, double newBirthRate,
           long newFoodWorth): Creature(newName,newSpeed,newBirthRate), foodWorth(newFoodWorth){}

void Prey::choiceOfActionTaken(Creature* other)
{
    //give a chnace to escape
    if(getSpeed() > other->getSpeed())
    {
        cout << getName() << " successfully escaped from " <<
        other->getName() << "!\n";
    }
    else
    {
        cout << getName() << " couldn't escape from " <<
        other->getName() << " :((\n";
    }
}
long Prey::getFoodWorth() const
{
    return foodWorth;
}
//procraete the prey
void Prey::procreate(std::vector<Creature*> &population)
{
    double chance = static_cast<double>(rand()) / RAND_MAX;
    
    if (chance < getBirthRate())
    {
        population.push_back(new Prey(getName(),
                            getSpeed(),getBirthRate(),
                            getFoodWorth()));
        cout << getName() << " procreating...\n";
    }
}

Prey::~Prey(){}



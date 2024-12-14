#include "predator.h"
#include <cstdlib>
#include <iostream>

using namespace std;


Predator::Predator():Creature(),energyLevel(0) {}

Predator::Predator(const string& newName, long newSpeed,
                   double newBirthRate,long newEnergyLevel):
Creature(newName, newSpeed, newBirthRate), energyLevel(newEnergyLevel) {}

void Predator::choiceOfActionTaken(Creature* other)
{
    //depending on speed would be able to eat
    if(getSpeed() > other->getSpeed())
    {
        cout << getName() << " eats " <<
        other->getName() << "!\n";
        other->die();
        eatenPrey = true;
    }
    else
    {
        cout << getName() << " couldn't catch " <<
        other->getName() << "!\n";
    }
}

bool Predator::succesOfAttack()
{
    return eatenPrey;
}

long Predator::getEnergyLevelValue() const
{
    return energyLevel;
}
void Predator::updateEnergyLevel(long getValue)
{
    //if energy level is 0 than died
    if(getValue <= 0)
    {
        alive = false;
        cout << name << " has died due to starvation\n";
    }
    else
    {
        getValue -= speed;
    }
}
void Predator::procreate(std::vector<Creature*> &population)
{
    //procreate the predator depeding on random chance
    double chance = static_cast<double>(rand()) / RAND_MAX;
    
    if (chance < getBirthRate())
    {
        population.push_back(new Predator(getName(),
        getSpeed(),getBirthRate(),getEnergyLevelValue()));
        cout << getName() << " procreating...\n";
    }
}

Predator::~Predator(){}


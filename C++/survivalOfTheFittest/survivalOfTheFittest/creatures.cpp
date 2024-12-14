#include "creatures.h"

#include <iostream>
#include <ctime>

using namespace std;

Creature::Creature(): name(" "), speed(0),birthRate(0.0) {}

Creature::Creature (const string& newName, long newSpeed,
          double newBirthRate):
name(newName),speed(newSpeed),birthRate(newBirthRate){}


bool Creature::isAlive() const
{
    return alive;
}
string Creature::getName() const
{
    return name;
}
long Creature::getSpeed() const
{
    return speed;
}
double Creature::getBirthRate() const
{
    return birthRate;
}
void Creature::die(void)
{
    if(!alive)
    {
        cout << getName() << " is dead\n";
    }
}


Creature::~Creature() {}


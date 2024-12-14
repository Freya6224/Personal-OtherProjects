#include <iostream>
#include <algorithm>
#include <vector>
#include "prey.h"
#include "predator.h"
#include <ctime>
#include <random>
#include <typeinfo>
#include <limits>

using namespace std;

void simulateInteraction(vector<Creature*>& population);
//created a template so that long and double both data
//type variable check be checked for validation
template<typename T>
T validateTheInputs(T min, T max);

int main()
{
    //random number generator
    srand(static_cast<unsigned>(time(nullptr)));
    
    //stores Creature population
    vector<Creature*> population;
    
    //variables to stores user inputs
    string predatorName, preyName;
    long predatorEnergylevel, predatorSpeed,
    preyFoodWorth, preySpeed, predatorCount,
    preyCount;
    size_t numPredators,numPreys, numGen,
    procreateCurrentNumPred,
    procreateCurrentNumPrey;
    double predBirthRate,preyBirthRate;
    
    //ask user to input the data
    cout << "Enter number of predators: ";
    cin >> numPredators;
    cout << "Enter number of preys: ";
    cin >> numPreys;
    cout << "Enter number of generations: ";
    cin >> numGen;
    
    //getting the predators data into list
    for(size_t i = 0; i < numPredators; i++)
    {
        cout << "Enter predator name: ";
        cin >> predatorName;
        cout << "Enter predator speed (0-100): ";
        predatorSpeed = validateTheInputs<long>(0, 100);
        cout << "Enter predator birthRate (0 - 1): ";
        predBirthRate = validateTheInputs<double>(0, 1);
        cout << "Enter predator level of energy (0-100): ";
        predatorEnergylevel = validateTheInputs<long>(0, 100);
        
        population.push_back(new Predator(predatorName, predatorSpeed,
                                          predBirthRate,
                                          predatorEnergylevel));
    }
    
    //getting the preys data into list
    for(size_t i = 0; i < numPreys; i++)
    {
        cout << "Enter prey name: ";
        cin >> preyName;
        cout << "Enter prey speed: ";
        preySpeed = validateTheInputs<long>(0, 100);
        cout << "Enter prey birthRate (0 - 1): ";
        preyBirthRate = validateTheInputs<double>(0, 1);
        cout << "Enter prey food worth (0-100): ";
        preyFoodWorth = validateTheInputs<long>(0, 100);
        
        population.push_back(new Prey(preyName,
                                      preySpeed,preyBirthRate, 
                                      preyFoodWorth));
    }
    
    
    do
    {
        //keeping track of number of preds and preys
        // to preocrate
        procreateCurrentNumPred = 0;
        procreateCurrentNumPrey = 0;
        
        //procreate a creatures
        for (Creature* creature : population)
        {
            if(procreateCurrentNumPred < static_cast<size_t> 
               (numPredators) &&
               dynamic_cast<Predator*>(creature) != nullptr)
            {
                creature->procreate(population);
                ++procreateCurrentNumPred;
            }
            else if (procreateCurrentNumPrey < static_cast
                     <size_t>(numPreys) &&
                     dynamic_cast<Prey*>(creature) != nullptr)
            {
                creature->procreate(population);
                ++procreateCurrentNumPrey;
            }
        }
        //simulate the creatures till met one of the
        //stopping conditions
        simulateInteraction(population);
        
        //count all the predators and preys that are present
        // in the list
        predatorCount = count_if(population.begin(),
                                 population.end(), []
                                 (Creature *creature)
                                 { return dynamic_cast<Predator *>
            (creature) != nullptr; });
        
        preyCount = count_if(population.begin(),
                             population.end(),
                             [](Creature *creature)
                             { return dynamic_cast<Prey *>
            (creature) != nullptr; });
        
        cout << "Predators left: " << predatorCount
        << ", Prey left: " << preyCount << "\n";
        
        //update the counts
        numPreys = preyCount;
        numPredators = predatorCount;
        
        //update the generations
        --numGen;
        
    }
    while (numGen> 0 && predatorCount > 0
           && preyCount > 0);
    
    //delete the creatures
    for (Creature *creature : population)
    {
        delete creature;
    }
    
    population.clear();
    
    return 0;
}

void simulateInteraction(vector<Creature*>& population)
{
    //giving chance to predator and prey to take an action
    // depending which is it call the right mehtod
    for (Creature *creature : population)
    {
        //if the creature is predator than choose prey and attack
        if (auto *predator = dynamic_cast<Predator *>(creature))
        {
            long choosePrey = rand() % population.size();
            Creature* selectedPrey = population[choosePrey];
            
            cout << predator->getName() << " attacking the ";
            
            if (auto *prey = dynamic_cast<Prey *>(selectedPrey))
            {
                prey->choiceOfActionTaken(predator);
            }
            
            predator->choiceOfActionTaken(selectedPrey);
            
            if(predator->succesOfAttack())
            {
                long level = predator->getEnergyLevelValue();
                long foodWorth = dynamic_cast<Prey*>
                (selectedPrey)->getFoodWorth();
                predator->updateEnergyLevel(level+foodWorth);
            }
            
        }
    }
    
    //remove the dead creatures from the list
    auto remove = remove_if(population.begin(), population.end(),
                            [](Creature *creature)
                            {
        return !creature->isAlive();
    });
    
    population.erase(remove, population.end());
    
}

//check the validation of inputs
template<typename T>
T validateTheInputs(T min, T max)
{
    T checkUserInput;
    
    cin >> checkUserInput;
    
    while(checkUserInput <= min || checkUserInput >= max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input enter again in range:";
        cin >> checkUserInput;
    }
    
    return checkUserInput;
}

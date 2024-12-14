#include <iostream>
#include <cmath>
#include "city.h"
#include "cityList.h"


City CityList::get(size_t index) const
{
    //get the city at that index
    if (index < current)
    {
        return list[index];
    }
    else
    {
        std::  cout << "here" ;
        return City(" ", Point(0.0, 0.0));
    }
}

void CityList::set(size_t index,
                   const City &new_city)
{
    //set the city into the list
    //at specific rang
    if (index < current)
    {
        list[index] = new_city;
    }
    else
    {
        std::cout << "Index out of range."
        "City not updated.\n";
    }
    
}

double CityList::distanceOfCities(int city1,
                                  int city2)
{
    //calc distnace between two cities
    double calcDistance = 0.0;
    
    if((abs(city1-city2) > 0) && abs(city1) >= 1
       && abs(city2) >= 1)
    {
        calcDistance = list[city2-1].distance(list[city1-1]);
    }
    else
    {
        std::cout<< "Invalid inputs\n";
    }
    
    return calcDistance;
}

bool CityList::add(const City & new_city)
{
    //add city into the list
    
    bool validCityAdded = false;
    if (current < MAX_CITY_LIST)
    {
        list[current] = new_city;
        std::cout << new_city.getName()
        << " added to the city list.\n";
        current++;
        validCityAdded = true;
        return validCityAdded;
    }
    else
    {
        std::cout << "City list is full."
        "Cannot add more cities.\n";
        validCityAdded = false;
        return validCityAdded;
        
    }
}


void CityList::displayAllCities() const
{
    //display all the cities
    std::cout << "List of cities:\n";
    for (size_t i = 0; i < current; ++i)
    {
        std::cout << i+1 << ". ";
        list[i].display();
        std::cout << std::endl;
    }
}



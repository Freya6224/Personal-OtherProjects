
#include <iostream>
#include <cstring>
#include "city.h"


City::City() : location(Point(0,0))
{
    //default constructors
    name[0] = '\0';
}
City::City(const char* cityName,
           const Point &points)
: location(points)
{
    //paramterize constructors
    //copy the name into the variable
    //set the locations
    strncpy(name, cityName, MAX_CITY_NAME-1);
    name[MAX_CITY_NAME - 1] = '\0';
    
}

double City::distance(const City& other) const {
    return location.distance(other.location);
}

Point City::get_location() const 
{
    //return location
    return location;
}

const char* City::getName() const
{
    //return name
    //correction added
    char* getCityName = new char[MAX_CITY_NAME];
    strncpy(getCityName, name, MAX_CITY_NAME-1);
    getCityName[MAX_CITY_NAME - 1] = '\0';
    return getCityName;
}

void City::setName(const char* newName)
{
    //store the name into the variable
    strncpy(name, newName, MAX_CITY_NAME - 1);
    name[MAX_CITY_NAME - 1] = '\0';
}

void City::setLocation(Point &points)
{
    //set location into the point class
    location = points;
}

void City::display() const
{
    //display the the city
    std::cout << getName() << ": "
    << " x: " << location.get_x()
    << " y:" << location.get_y();
}


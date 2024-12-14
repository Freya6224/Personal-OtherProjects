
#ifndef cityList_h
#define cityList_h
#include "city.h"

//max num of cities in list
const size_t MAX_CITY_LIST = 10;

class CityList
{
    City list[MAX_CITY_LIST];
    size_t current = 0;
    
public:
    //default constructor
    CityList()=default;
    //checking if list is full or not
    bool full(void) const
    { return current == MAX_CITY_LIST;}
    //check if list is empty or not
    bool empty(void) const
    { return current == 0; }
    //get specfic city from the list
    City get(size_t index) const;
    //return the amount of cities that
    //has been stored in the list
    size_t get_num_cities(void) const
    {return current; }
    //set the new city into the list
    void set(size_t index,
             const City & new_city);
    bool add(const City & new_city);
    //calc the distance between cities
    //from the list
    double distanceOfCities(int city1,
                            int city2);
    //display all the cities in the list
    void displayAllCities() const;
    
    
};

#endif

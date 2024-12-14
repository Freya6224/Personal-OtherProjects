
#ifndef city_h
#define city_h

#include "point.h"


const size_t MAX_CITY_NAME = 50 ;

class City
{
    Point location;
    char name[MAX_CITY_NAME];
    
public:
    //the functions, constructors
    //in the city class
    City();
    
    City(const char* cityName,const Point &points);
    
    double distance(const City & other) const;
    
    Point get_location(void) const;
    
    const char* getName() const;
    
    void setName(const char* name);
    
    void setLocation(Point &points);
    
    void display() const;
    
};
#endif

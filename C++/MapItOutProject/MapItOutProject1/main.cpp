#include <iostream>
#include <cctype>
#include <limits>
#include <cstring>
#include "cityList.h"

using namespace std;


int main() {
    
    CityList cityList;
    
    //check if users wants to
    //quit or not
    bool quit = false;
    
    
    //correction made
    //changed while loop
    //to do while loop
    do {
        //menu options for the user
        
        cout << "\nMenu:\n";
        cout << "1) Enter city information\n";
        cout << "2) Calculate distance between "
        "two cities\n";
        cout << "3) Print all cities\n";
        cout << "4) Quit\n";
        
        //record the user chocie
        char choice;
        cout << "\nEnter your choice (1/2/3/4)"
        " or E/C/P/Q: ";
        cin >> choice;
        
        //check for user's chocie
        //and call function depending onit
        //correction made added toupper()
        switch (toupper(choice))
        {
            case '1':
            case 'E':
            {
                char cityName[MAX_CITY_NAME];
                double x = 0.0,
                y = 0.0;
                
                //if list is not full than can add more cities
                //or else throw a message that list is full
                if(!(cityList.full()))
                {
                    //flags to check for the valid inputs
                    bool checkName = false,
                    checkX = false,
                    checkY = false;
                    
                    cout << "\nEnter city information:\n";
                    
                    //user would be locked in while loop
                    
                    while(!checkName)
                    {
                        cout << "City Name: ";
                        cin.ignore();
                        cin.getline(cityName, MAX_CITY_NAME);
                        
                        if(cin.fail() || strlen(cityName) >= MAX_CITY_NAME
                           || strlen(cityName) == 0)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "\nInvalid input (maybe it's too big). ";
                        }
                        else
                        {
                            checkName = true;
                        }
                    }
                    
                    while(!checkX)
                    {
                        cout << "X-coordinate: ";
                        cin >> x;
                        
                        if(cin.fail() || x < 0.0)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "\nInvalid input. ";
                        }
                        else
                        {
                            checkX = true;
                        }
                    }
                    while(!checkY)
                    {
                        cout << "Y-coordinate: ";
                        cin >> y;
                        
                        if(cin.fail() || y < 0.0)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "\nInvalid choice. ";
                        }
                        else
                        {
                            checkY = true;
                        }
                    }
                    
                    //add new city into the list
                    //made correction instead of creating
                    //city object just cinstructed the newly created
                    //city into the citylist
                    cityList.add(City{cityName,Point(x, y)});
                }
                else
                {
                    cout << "\nSorry list is full..\n\n";
                }
                break;
            }
            case '2':
            case 'C':
            {
                //if user has entered at least 2 cities
                // than allow user to check distance
                if(cityList.get_num_cities() >= 2)
                {
                    int city1, city2;
                    
                    //correction added
                    if(cityList.get_num_cities() == 2)
                    {
                        double dist = cityList.distanceOfCities
                        (1, 2);
                        cout << "\nDistance between "
                        "the only two cities in the list right now is:\n"
                        << dist << " map units.\n\n";
                    }
                    else
                    {
                        cout << "\nSelect two cities "
                        "to calculate the distance between:\n";
                        //show the options for user
                        cityList.displayAllCities();
                        cout << "Enter the position numbers of "
                        "the two cities (separated by a space): ";
                        cin >> city1 >> city2;
                        //calc the distance
                        double dist = cityList.distanceOfCities
                        (city1, city2);
                        cout << "\nDistance between "
                        "selected cities: " << dist << " map units.\n\n";
                    }
                }
                else{
                    cout << "\nYour input is invalid "
                    "or you haven't enter atleast two cities\n\n";
                }
                break;
            }
            case '3':
            case 'P':
            {
                //if there are cities into the list
                //than print the list
                if(cityList.get_num_cities() > 0)
                {
                    cityList.displayAllCities();
                }
                else
                {
                    cout << "\nYour list is empty "
                    "please the city info first\n\n";
                }
                break;
            }
            case '4':
            case 'Q':
            {
                //if user chose to quit than the programm
                quit = true;
                break;
            }
            default:
                cout << "\nInvalid choice. "
                "\nPlease select a valid option (1/2/3/4)"
                " or E/C/P/Q\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                
        }
    } while (!quit);
    
    cityList.empty();
    
    return 0;
}

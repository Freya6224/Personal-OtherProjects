#include <iostream>
#include "frameThePhrase.h"
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
    FrameThePhrase framePhrase;
    
    //attributes for the user choices
    char inputChoice, outputChoice, frameChar,
    frameType, justification;
    
    //option given to user if data inputs
    cout << "Choose the input source (K)eyboard or (F)ile: ";
    cin >> inputChoice;
    
    while (tolower(inputChoice) != 'k' &&
           tolower(inputChoice) != 'f')
    {
        cout << "\nEnter the choice again k or f: ";
        cin >> inputChoice;
    }
    if(tolower(inputChoice) == 'k')
    {
        cin.ignore();
        
        //using overloading operator
        //taking the input phrase
        
        cout << "Enter the phrase: ";
        cin >> framePhrase;
        
        //if user chooses regular
        //than ask for frame char
        // or else use frame options
        cout << "Enter Frame Type (r/1/2/3/4): ";
        cin >> frameType;
        framePhrase.setFrameType(frameType);
        if(frameType == 'r')
        {
            cout << "Enter the frame character: ";
            cin >> frameChar;
            framePhrase.setFrameChar(frameChar);
        }
        cout << "Enter the justification: ";
        cin >> justification;
        framePhrase.setJustification(justification);
        
    }
    else if(tolower(inputChoice) == 'f')
    {
        //getting data from file
        string fileName;
        cout << "Enter the file name: ";
        cin >> fileName;
        ifstream file(fileName);
        //checking if file open correctly
        while(!file.is_open())
        {
            file.close();
            file.clear();
            cout << "Error in file opening.\n"
            "Enter file name again: ";
            cin >> fileName;
            file.open(fileName);
        }
        
        string getPhrase;
        file >> framePhrase >> frameType;
        framePhrase.setFrameType(frameType);
        //checking for user chooses
        //than reading the correct form of data
        if(frameType == 'r')
        {
            file >> frameChar>> justification;
            framePhrase.setFrameChar(frameChar);
        }
        else
        {
            file >> justification;
        }
        framePhrase.setJustification(justification);
        
        //closing the file
        file.close();
        file.clear();
    }
    
    //giving user the output choose
    cout << "Choose the output source (S)creen or (F)ile: ";
    cin >> outputChoice;
    
    while (tolower(outputChoice) != 's' &&
           tolower(outputChoice) != 'f')
    {
        //using overloading operator to the
        //print the data
        cout << "\nEnter the choice again s or f: ";
        cin >> outputChoice;
    }
    if(tolower(outputChoice) == 's')
    {
        cout << "\n\nThe result:\n";
        cout << framePhrase;
        
    }
    else if(tolower(outputChoice) == 'f')
    {
        string fileNameResult;
        cout << "Enter the file name: ";
        cin >> fileNameResult;
        ofstream file(fileNameResult);
        while(!file.is_open())
        {
            file.close();
            file.clear();
            cout << "Error in file opening.\n"
            "Enter file name again: ";
            cin >> fileNameResult;
            file.open(fileNameResult);
        }
        
        file << framePhrase;
        
        file.close();
        file.clear();
    }
    
}

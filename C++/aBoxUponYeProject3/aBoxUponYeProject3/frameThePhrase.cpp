#include "frameThePhrase.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

FrameThePhrase::FrameThePhrase(): phrase({}), 
frameType(FrameType::regular), selectedFrameChar('|'),
justification(Justification::left)
{}
FrameThePhrase::FrameThePhrase(const string& newPhrase,
                               const char& newframeType,
                               const char& newFrameChar,
                               const char& newJustifictaion)
: phrase({}),frameType(getCharToEnum<FrameType>(newframeType)), 
selectedFrameChar(newFrameChar),
justification(getCharToEnum<Justification>(newJustifictaion))
{
    setFrameThePhrase(newPhrase, newframeType,newFrameChar, 
                      newJustifictaion);
}

istream& operator >> (istream& input, FrameThePhrase& framePhrase)
{
    //reading the phrase from the stream
    //than adding the words into the vector
    framePhrase.phrase.clear();
    string getPhrase;
    getline(input,getPhrase);
    istringstream get(getPhrase);
    string word;
    while(get >> word)
    {
        framePhrase.phrase.push_back(word);
    }
    
    return input;
}
ostream& operator << (ostream& output, 
                      const FrameThePhrase& framePhrase)
{
    //call the print function to print the output
    framePhrase.printThePhrase(output);
    return output;
}
long FrameThePhrase::calcFrameWidth() const
{
    //finding the max width
    long width = 0;
    
    if(phrase.empty())
    {
        width = 0;
    }
    for (const auto& newPhrase: phrase)
    {
        width = max(width, static_cast<long>(newPhrase.length()));
    }
    
    return width;
}
void FrameThePhrase::setJustification(char newJustification)
{
    //using template setting up the justifictaion
    justification = getCharToEnum<Justification>(newJustification);
    
}

void FrameThePhrase::setFrameType(char newFrameType)
{
    //using template setting up the frame type
    frameType = getCharToEnum<FrameType>(newFrameType);
    
}
void FrameThePhrase::setFrameThePhrase(const string& newPhrase,
                                       const char& newFrameType,
                                       const char& newFrameChar,
                                       const char& newJustification)
{
    //set up to get the new phrase
    if(newFrameType == (static_cast<char>(FrameType::regular)))
    {
        selectedFrameChar = newFrameChar;
    }
    
    setFrameType(newFrameType);
    setJustification(newJustification);
    phrase.clear();
    istringstream get(newPhrase);
    string getPhrase;
    
    while(get >> getPhrase)
    {
        phrase.push_back(getPhrase);
    }
    
}
void FrameThePhrase::printThePhrase(std::ostream& output) const
{
    //printing the frame
    //divide into parts
    long width = calcFrameWidth();
    
    char getFrameType = static_cast<char>(frameType);
    
    //function for top and bottom part of the frame
    printTopBottomFrame(output, width, getFrameType);
    
    //for the main phrase
    for(const auto& writePhrase: phrase)
    {
        if(tolower(getFrameType) == 'r' || 
           tolower(getFrameType) == '1'
           || tolower(getFrameType) == '3')
        {
            printWithSingleLine(output, width, writePhrase);
        }
        else if(tolower(getFrameType) == '2' || 
                tolower(getFrameType) == '4')
        {
            printWithDoubleLine(output, width, writePhrase);
        }
    }
    
    printTopBottomFrame(output, width, getFrameType);
    
    //modification for the special frames
    if(tolower(getFrameType) == '3' || 
       tolower(getFrameType) == '4')
    {
        if(tolower(getFrameType) == '3')
        {
            output << "*\n " << string(width+4, '*') << "\n";
        }
        else
        {
            output << "#\n " << string(width+6, '#') << "\n";
        }
    }
    
}
void FrameThePhrase::printTopBottomFrame(std::ostream& output,
                        long width, char getFrameType) const
{
    //getting the top and bottom part of frame ready
    switch (tolower(getFrameType))
    {
        case 'r':
            output << "\n" << string(width+4, selectedFrameChar);
            break;
        case '1':
        case '3':
            output << "\n+" << string(width+2, '-') << "+";
            break;
        case '2':
        case '4':
            output << "\n+" << string(width+4, '=') << "+";
            break;
        default:
            break;
    }
}
void FrameThePhrase::printWithSingleLine(std::ostream& output, 
                                         long width,
                                const std::string& writePhrase) const
{
    //method for the single line frame
    if(justification == Justification::right)
    {
        output << "\n" << selectedFrameChar
        << " " << string(width-writePhrase.length(), ' ')
        << writePhrase << " " << selectedFrameChar ;
        if(frameType == FrameType::frameThree)
        {
            output << "*";
        }
        
    }
    else if (justification == Justification::left)
    {
        output << "\n" << selectedFrameChar << " " << writePhrase
        << string(width-writePhrase.length(), ' ')
        << " " << selectedFrameChar;
        if(frameType == FrameType::frameThree)
        {
            output << "*";
        }
        
    }
    else if (justification == Justification::center)
    {
        long left = ((width -writePhrase.length())/2);
        long right = ((width - writePhrase.length())-left);
        output << "\n" << selectedFrameChar << " "
        << string(left, ' ')
        << writePhrase << string(right, ' ') << " "
        << selectedFrameChar;
        if(frameType == FrameType::frameThree)
        {
            output << "*";
        }
        
    }
}
void FrameThePhrase::printWithDoubleLine(std::ostream& output, long width,
                                const std::string& writePhrase) const
{
    //method for the double line frame
    if(justification == Justification::right)
    {
        output << "\n" << selectedFrameChar
        << selectedFrameChar
        << " " << string(width-writePhrase.length(), ' ')
        << writePhrase << " " << selectedFrameChar
        << selectedFrameChar;
        if(frameType == FrameType::frameFour)
        {
            output << "#";
        }
        
    }
    else if (justification == Justification::left)
    {
        output << "\n" << selectedFrameChar << selectedFrameChar
        << " " << writePhrase
        << string(width-writePhrase.length(), ' ')
        << " " << selectedFrameChar
        << selectedFrameChar;
        if(frameType == FrameType::frameFour)
        {
            output << "#";
        }
        
    }
    else if (justification == Justification::center)
    {
        long left = ((width -writePhrase.length())/2);
        long right = ((width - writePhrase.length())-left);
        output << "\n" << selectedFrameChar << selectedFrameChar
        << " " << string(left, ' ')
        << writePhrase << string(right, ' ') << " "
        << selectedFrameChar << selectedFrameChar;
        if(frameType == FrameType::frameFour)
        {
            output << "#";
        }
        
    }
}

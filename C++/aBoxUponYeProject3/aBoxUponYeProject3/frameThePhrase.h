

#ifndef frameThePhrase_h
#define frameThePhrase_h

#include <iostream>
#include <vector>

//enums for the justification and frametype options
enum class Justification {left = 'l', right = 'r', 
    center ='c'};
enum class FrameType{regular = 'r', frameOne = '1',
    frameTwo = '2',frameThree= '3',frameFour = '4'};

class FrameThePhrase
{
    //attributes for the class
    std::vector<std::string> phrase;
    FrameType frameType = FrameType::regular;
    char selectedFrameChar = '|';
    Justification justification;
    //private function
    long calcFrameWidth() const;
    //using template so that don't have
    //to use switch/case in setters
    //to set the justification and frametypes
    template <typename EnumType>
    EnumType getCharToEnum(char getChar)
    {
        return static_cast<EnumType>(tolower(getChar));
    }
    
public:
    //constructors
    FrameThePhrase();
    
    FrameThePhrase(const std::string& newPhrase,
                   const char& newframeType,
                   const char& newFrameChar,
                   const char& newJustifictaion);
    //setters
    inline void setFrameChar(char frameChar)
    {
        if(checkValidFrameChar(frameChar))
        {
            selectedFrameChar = frameChar;
        }
        else
        {
            std::cerr << "Invalid frame character.\n";
        }
    }
    void setJustification(char newJustification);
    void setFrameType(char newFrameType);
    
    //check if valid frame char
    inline bool checkValidFrameChar(char frameChar) const
    { return std::isprint(static_cast<char>(frameChar)) != 0;}
    
    //setting the valid data to frame the phrase
    void setFrameThePhrase(const std::string& newPhrase,
                           const char& newframeType,
                           const char& newFrameChar,
                           const char& newJustification);
    //printing functions for different options
    void printThePhrase(std::ostream& output) const;
    void printTopBottomFrame(std::ostream& output,
                    long width, char getFrameType) const;
    void printWithSingleLine(std::ostream& output, long width,
                  const std::string& writePhrase) const;
    void printWithDoubleLine(std::ostream& output, long width,
                    const std::string& writePhrase) const;
    //overloading operators
    friend std::istream& operator >> (std::istream& input,
                                      FrameThePhrase& framePhrase);
    friend std::ostream& operator << (std::ostream& output,
                            const FrameThePhrase& framePhrase);
};

#endif

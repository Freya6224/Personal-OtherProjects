#include <iostream>
#include <fstream>
#include "check.h"

using namespace std;

//the function moved from the class
//based on suggestion
//arrange the checks from lowest to greatest
void sort(Check* check, std::size_t size);
//output function
void output(std::ostream & writeFile, Check* check,
            Money* deposit,
            Money &totalNotCashedChecks,
            Money &totalDeposits, Money &totalBalance,
            Money &newBalance, Money &diffBalance,
            Money &totalChecks, std::size_t numChecks,
            std::size_t numDeposits);

int main()

{
    //for the keyboard method add another input file
    //check for the file inputs
    long entryOpt;
    long numChecks = 0, numDeposits = 0;
    Check* check;
    Money* deposit;
    Money totalCashedChecks,totalNotCashedChecks,totalDeposits,
    totalBalance, newBalance, diffBalance,totalChecks;
    string inputFile, outputFile;
    ifstream readFile;
    ofstream writeFile;
    
    //ask for the preference on how to input the data
    cout << "Enter the prefered entry method "
    "(1 for keyboard / 2 for file): ";
    cin >> entryOpt;
    
    //check for correct inputs
    while (entryOpt != (1) && entryOpt != (2))
    {
        cout << "\nEnter the prefered entry method again"
        "(1 for keyboard / 2 for file): ";
        cin >> entryOpt;
    }
    
    if(entryOpt == 1)
    {
        /*
         if user selects to input data from keyboard than
         run this if statement and than ask of number
         of checks and deposits and than check for the
         correct inputs
         */
        cout << "\nEnter the number of checks: ";
        cin >> numChecks;
        
        while(numChecks < 0)
        {
            cout << "\nEnter the number of checks again: ";
            cin >> numChecks;
        }
        
        cout << "\nEnter the number of deposits: ";
        cin >> numDeposits;
        
        while(numDeposits < 0)
        {
            cout << "\nEnter the number of deposits again: ";
            cin >> numDeposits;
        }
        
        //assign the size
        //try&catch
        try
        {
            check = new Check[numChecks];
            deposit = new Money[numDeposits];
        }
        catch(const bad_alloc&a)
        {
            cerr << "Memory allocation error"
            << a.what() << endl;
        }
        
        //read the data and update the totals
        for(size_t i = 0; i < static_cast<size_t>(numChecks); i++)
        {
            check[i].inputKey();
            if(check[i].getCashOpt())
            {
                totalCashedChecks =
                totalCashedChecks.add(check[i].getAmount());
            }
            else
            {
                totalNotCashedChecks =
                totalNotCashedChecks.add(check[i].getAmount());
            }
            totalChecks =
            totalCashedChecks.add(totalNotCashedChecks);
        }
        
        for(size_t i = 0; i < static_cast<size_t>(numDeposits); i++)
        {
            cout << "\nEnter the deposit amount: ";
            deposit[i].input(cin);
            totalDeposits = totalDeposits.add(deposit[i]);
        }
        writeFile.open("balanceFileCopy.txt",ios::out);
        
    }
    else
    {
        /*
         if users selects to input the data from the file
         than ask for the input file and output file
         */
        cout << "\nEnter the data file name: ";
        cin >> inputFile;
        readFile.open(inputFile,ios::in);
        while(!(readFile.is_open()))
        {
            readFile.close();
            readFile.clear();
            cout << "I am sorry, I could not open "
            << inputFile << " Please enter another name: ";
            cin >> inputFile;
            readFile.open(inputFile);
        }
        
        //read the amount of checks and deposits
        readFile >> numChecks;
        readFile >> numDeposits;
        
        //assign the amount
        try
        {
            check = new Check[numChecks];
            deposit = new Money[numDeposits];
        }
        catch(const bad_alloc&a)
        {
            cerr << "Memory allocation error"
            << a.what() << endl;
        }
        
        
        //read the inputs and update the totals
        for(size_t i = 0; i < static_cast<size_t>(numChecks); i++)
        {
            check[i].input(readFile);
            //dived up the total for cashed and not cashed
            if(check[i].getCashOpt())
            {
                totalCashedChecks =
                totalCashedChecks.add(check[i].getAmount());
            }
            else
            {
                totalNotCashedChecks =
                totalNotCashedChecks.add(check[i].getAmount());
            }
            totalChecks =
            totalCashedChecks.add(totalNotCashedChecks);
        }
        //read the deposit data
        for(size_t i = 0; i < static_cast<size_t>(numDeposits); i++)
        {
            deposit[i].input(readFile);
            totalDeposits = totalDeposits.add(deposit[i]);
        }
        
        cout << "\nEnter the copy file name: ";
        cin >> outputFile;
        writeFile.open(outputFile,ios::out);
        writeFile.clear();
        
        while(!(writeFile.is_open()))
        {
            //if not opened than still close/clear
            writeFile.close();
            writeFile.clear();
            //error message printed
            cout << "I am sorry, I could not open "
            << outputFile << " Please enter another name: ";
            cin >> outputFile;
            writeFile.open(outputFile);
        }
        
        readFile.close();
    }
    
    writeFile.clear();
    
    //sort the checks according to the check number
    sort(check, numChecks);
    
    //pass all the parameters to disply the output in the file
    output(writeFile, check, deposit, totalNotCashedChecks,
           totalDeposits, totalBalance, newBalance, diffBalance,
           totalChecks, numChecks, numDeposits);
    cout << endl;
    //delete the memory
    delete [] deposit;
    delete [] check;
    
    //close the file
    writeFile.close();
    
    //success message printed
    cout << "\nSuccessfully copied the data!!\n\n";
    
    return 0;
}

//sort the data by getting the size and check
void sort(Check* check, size_t size)
{
    for(size_t i = 0; i < size-1; i++ )
    {
        for(size_t j = 0; j < size-1; j++)
        {
            if(check[j].getNumbers() > check[j+1].getNumbers())
            {
                Check temp = check[j];
                check[j] = check[j+1];
                check[j+1] = temp;
            }
        }
        
    }
}

/*
 the output function which will be used to read the data
 from both file and keyboard data -- added here so that
 main looks more organized
 */
void output(std::ostream & writeFile, Check* check,
            Money* deposit,
            Money &totalNotCashedChecks,
            Money &totalDeposits, Money &totalBalance,
            Money &newBalance, Money &diffBalance,
            Money &totalChecks, size_t numChecks,
            size_t numDeposits)
{
    //print the number of checks and deposits
    writeFile << "\nTotal no of checks: " << numChecks;
    writeFile << "\nTotal no deposits: " << numDeposits;
    
    //divide up the checks in lowest to highest check number
    //separatly depending cashed or not
    writeFile << "\n\nCashed checks:\n";
    bool flag = false;
    
    for(size_t i = 0; i < numChecks;i++)
    {
        if(check[i].getCashOpt())
        {
            writeFile << "Check #" << check[i].getNumbers()
            << ", Amount: ";
            check[i].getAmount().output(writeFile);
            writeFile << ", Cashed: " <<
            (check[i].getCashOpt() ? "Yes chashed\n" : "No chashed\n");
            flag = true;
        }
        
    }
    if(!flag)
    {
        writeFile << " None \n";
    }
    
    writeFile << "\n\nNot cashed checks:\n";
    
    flag = false;
    
    for(size_t i = 0; i < numChecks;i++)
    {
        if(!check[i].getCashOpt())
        {
            writeFile << "Check #" << check[i].getNumbers()
            << ", Amount: ";
            check[i].getAmount().output(writeFile);
            writeFile << ", Cashed: " <<
            (check[i].getCashOpt() ? "Yes chashed\n" : "No chashed\n");
            flag = true;
        }
        
    }
    if(!flag)
    {
        writeFile << " None \n";
    }
    
    for(size_t i = 0; i< numDeposits;i++)
    {
        writeFile << "\nDeposit of: ";
        deposit[i].output(writeFile);
    }
    
    //update the totalBalance and new balance
    totalBalance = totalBalance.add(totalDeposits.subtract(totalChecks));
    newBalance = totalBalance.add(totalNotCashedChecks);
    //could have also used negate() function
    diffBalance = totalBalance.subtract(newBalance);
    
    //write out the totals into file
    writeFile << "\n\nTotal of all checks: ";
    totalChecks.output(writeFile);
    writeFile << "\nTotal of all deposits: ";
    totalDeposits.output(writeFile);
    writeFile << "\nTotal balance: ";
    totalBalance.output(writeFile);
    writeFile << "\nNew Balance: ";
    newBalance.output(writeFile);
    writeFile << "\nThe difference: ";
    diffBalance.output(writeFile);
    
}

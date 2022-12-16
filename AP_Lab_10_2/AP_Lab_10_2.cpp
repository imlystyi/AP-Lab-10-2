// Якубовський Владислав, ІКНІ, РІ-11, АП, ЛР 10.2, варіант 24
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

string ChangeString(string stringToChange)
{
    bool isInternalOpenedBracket = false, isExternalOpenedBracket = false, isExternalClosedBracket = false;

    string changedString = "";

    for (int ii = 0; ii < stringToChange.length(); ii++)
    {
        if (stringToChange[ii] == '(')
        {
            if (!isExternalOpenedBracket)
                isExternalOpenedBracket = true;

            else isInternalOpenedBracket = true;
        }

        else if (stringToChange[ii] == ')')
        {
            if (isInternalOpenedBracket)
                isInternalOpenedBracket = false;

            else if (!isExternalClosedBracket)
                isExternalClosedBracket = true;
        }

        else if (isExternalOpenedBracket && isExternalClosedBracket)
        {
            isInternalOpenedBracket = false;
            isExternalOpenedBracket = false; isExternalClosedBracket = false;            
        }

        if (!isExternalOpenedBracket && !isExternalClosedBracket)
            changedString += stringToChange[ii];        
    }

    return changedString;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream readFromFile("t1.txt");
    ofstream writeInFile("t2.txt");

    string stringToWrite = "";

    while (getline(readFromFile, stringToWrite))
        readFromFile >> stringToWrite;

    stringToWrite = ChangeString(stringToWrite);

    int ii = 0;

    writeInFile << stringToWrite;

    readFromFile.close();
    writeInFile.close();
}

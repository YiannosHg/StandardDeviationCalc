#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include<math.h>

using namespace std;

// Functions prototypes
list<int> getValuesFromFile();
double calculateMean(list<int> values);
double calculateStandardDeviation(list<int> values, double meanValue);

int main()
{
    list<int> values = getValuesFromFile();
    double meanValue = calculateMean(values);
    double standardDeviation = calculateStandardDeviation(values, meanValue);

    cout << "Standard Deviation for values in year 2000: " << standardDeviation << endl;
}

/*
* Function to get the values from input file and store them in a list
*/
list<int> getValuesFromFile()
{
    const string InputFileName = "DEV-data.txt";
    const int specifiedYear = 2000;
    const int YrStartPos = 6;
    const int YrEndPos = 9;
    const int ValueStartPos = 12;

    fstream inputFile;
    string record;
    list<int> values;

    inputFile.open(InputFileName, ios::in);

    if (inputFile.fail())
    {
        cout << "File does not exist" << endl;
        exit;
    }
    else
    {
        int inputYear;
        int value;

        while (!inputFile.eof())
        {
            getline(inputFile, record);

            inputYear = stoi(record.substr(YrStartPos, YrEndPos)); // func stoi converts string to int

            if (specifiedYear == inputYear)
            {
                value = stoi(record.substr(ValueStartPos, record.length() - 1));
                values.push_back(value);
            }
        }
    }
    inputFile.close();

    return values;
}

/*
* Function to calculate mean value
*/
double calculateMean(list<int> values)
{
    double mean = 0;
    
    for (int v : values)
        mean += v;

    return mean / values.size();
}

/*
* Function to calculate standard deviation
*/
double calculateStandardDeviation(list<int> values, double meanValue)
{
    double standardDeviation = 0;

    for (int v : values)
        standardDeviation += pow((double)v-meanValue, 2.0);

    return standardDeviation / values.size();
}
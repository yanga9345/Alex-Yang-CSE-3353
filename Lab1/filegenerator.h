#ifndef FILEGENERATOR_H
#define FILEGENERATOR_H
#include <fstream>
#include <iostream>

//will generate all the files I need
class FileGenerator
{
private:
    //Random rand = new Random();
public:
    FileGenerator();
    void GenerateRandom(int size)
    {
        //const char* name = "Random - " + size;
        ofstream outFile("Random - " + size);

        for(int i = 0; i < size; i++)
        {
            outFile << rand()%(size * 5 / 10) << endl;
        }

        outFile.close();
    }

    void GenerateReverse(int size)
    {
        ofstream outFile("ReverseSorted - " + size);

        outFile.close();
    }

    void Generate20Unique(int size)
    {
        ofstream outFile("20% Unique - " + size);

        outFile.close();
    }

    void Generate30Random(int size)
    {
        ofstream outFile("30% Randomized - " + size);

        outFile.close();
    }

    //generates all 16 unique files
    void Run()
    {
        for(int i = 10; i <= 100000; i*= 10)
            if(i != 100)
            {
                GenerateRandom(i);
                GenerateReverse(i);
                Generate20Unique(i);
                Generate30Random(i);
            }
    }
};

#endif // FILEGENERATOR_H

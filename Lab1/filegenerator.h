#ifndef FILEGENERATOR_H
#define FILEGENERATOR_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//will generate all the files I need
class FileGenerator
{
private:
    //Random rand = new Random();
    std::vector<std::string> fileNames;

public:
    FileGenerator()
    {

    }

    void GenerateRandom(int size)
    {
        //const char* name = "Random - " + size;
        std::string filename = "Random - " + to_string(size);
        fileNames.push_back(filename);
        ofstream outFile(filename);
        for(int i = 0; i < size; i++)
        {
            outFile << rand()%(size * 4 / 10) + 1 << endl;
        }

        outFile.close();
    }

    void GenerateReverse(int size)
    {
        std::string filename = "ReverseSorted - " + to_string(size);
        fileNames.push_back(filename);
        ofstream outFile(filename);
        for(int i = size; i > 0; i--)
        {
            outFile << i << endl;
        }
        outFile.close();
    }

    void Generate20Unique(int size)
    {
        std::string filename = "20% Unique - " + to_string(size);
        fileNames.push_back(filename);
        ofstream outFile(filename);
        for(int i = 0; i < size; i++)
        {
            outFile << rand()%(size * 2/10) + 1 << endl;
        }
        outFile.close();
    }

    void Generate30Random(int size)
    {
        std::string filename = "30% Randomized - " + to_string(size);
        fileNames.push_back(filename);
        ofstream outFile(filename);
        for(int i = 0; i < size * 7 / 10; i++)
        {
            outFile << i+1 << endl;
        }
        for(int i = 0; i < size * 3/10; i++)
        {
            outFile << rand()%(size * 7 / 10)+1 << endl;
        }
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

    std::vector<std::string> getFileNames()
    {
        return fileNames;
    }
};

#endif // FILEGENERATOR_H

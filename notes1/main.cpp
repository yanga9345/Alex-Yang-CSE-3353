#include <iostream>
#include "algofactory.h"

#include "algorithm.h"
#include "sort.h"
#include "sortalgo.h"

using namespace std;

int main()
{
    Sort * factoryAlgo = (Sort *)(AlgoFactory::Create(AlgoFactory::SEARCH));

    factoryAlgo->setExecutionType(Sort::Configuration::ITERATIVE);
    factoryAlgo->setStorageType(Sort::Configuration::RECURSIVE);
    factoryAlgo->Select(0);
    factoryAlgo->getConfiguration();

    Sort *protoAlgo = (Sort *)(factoryAlgo->Clone());
    protoAlgo->getConfiguration();

    return 0;
}

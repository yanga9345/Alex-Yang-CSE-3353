#include "algofactory.h"
#include "sort.h"

Algorithm * AlgoFactory::Create(AlgoFactory::AlgorithmClass type)
{
    Algorithm * pAlgo; //pointer to algorithm object

    switch(type)
    {
        case AlgoFactory::AlgorithmClass::SORT :
        pAlgo = new Sort();
        break;
        case AlgoFactory::AlgorithmClass::SEARCH :

        break;

        case AlgoFactory::AlgorithmClass::HEURISTIC :

        break;

        defailt:
        pAlgo = nullptr;
    }
    return pAlgo;
}

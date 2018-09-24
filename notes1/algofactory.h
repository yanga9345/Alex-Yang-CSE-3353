#ifndef ALGOFACTOR_H
#define ALGOFACTOR_H

class Algorithm;

class AlgoFactory
{
public:
    enum AlgorithmClass
    {
        SORT = 0,
        SEARCH,
        HEURISTIC
    };

    static Algorithm * Create(AlgoFactory::AlgorithmClass type);
};

#endif // ALGOFACTOR_H

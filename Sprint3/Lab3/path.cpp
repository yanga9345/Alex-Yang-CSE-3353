#include "path.h"

Path::Path(vector<Node> &in)
{
    vec = in;

    distance = 0;
    for(unsigned int i = 0; i < vec.size()-1; i++)
    {
        distance += vec[i].getDistance(vec[i+1]);
    }
    distance += vec[0].getDistance(vec[vec.size()-1]);
}

vector<Node> Path::getPath()
{
    return vec;
}

float Path::getDistance()
{
    return distance;
}

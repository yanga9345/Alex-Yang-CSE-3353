#ifndef PATH_H
#define PATH_H

#include <vector>
#include "node.h"

class Path
{
private:
    vector<Node> vec;
    float distance;
public:
    Path(vector<Node> &in);
    vector<Node> getPath();
    float getDistance();
};

#endif // PATH_H

#include "read.h"

using std::vector;          using std::string;
using std::istream;

istream& read(istream& in, vector<string>& scrambled)
{
    string x;

    while(in >> x)
        scrambled.push_back(x);

    return in;
}

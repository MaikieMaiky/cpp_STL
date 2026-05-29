#ifndef __SPEAKER_H
#define __SPEAKER_H

#include <string>
using namespace std;

class speaker
{
public:
    speaker(string name) : _name(name), _score{0} {}
    ~speaker() {}

    string _name = "default";
    double _score[2] = { 0 };
};


#endif
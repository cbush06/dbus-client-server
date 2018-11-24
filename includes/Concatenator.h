#ifndef CONCATENATOR_H
#define CONCATENATOR_H

#include <string>
#include <vector>
#include <sdbus-c++/sdbus-c++.h>
#include "concatenator-server.h"

using namespace std;
using namespace sdbus;

class Concatenator : public Interfaces<org::sdbuscpp::Concatenator_adaptor> {
    public:
        Concatenator(IConnection& connection, string objectPath);
        ~Concatenator();
    
    protected:
        virtual string concatenate(const vector<int32_t>& numbers, const string& separator);
};
#endif
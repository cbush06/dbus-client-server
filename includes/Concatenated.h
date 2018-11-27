#ifndef CONCATENATED_H
#define CONCATENATED_H

#include <iostream>
#include <string>
#include <vector>
#include <sdbus-c++/sdbus-c++.h>
#include "concatenator-client.h"

using namespace std;
using namespace sdbus;

class Concatenated : public ProxyInterfaces<org::sdbuscpp::Concatenator_proxy>
{
  public:
    Concatenated(string destination, string objectPath) : sdbus::ProxyInterfaces<org::sdbuscpp::Concatenator_proxy>(move(destination), move(objectPath))
    {
    }

    ~Concatenated()
    {
    }

  protected:
    void onConcatenated(const string &concatenatedString) override
    {
        cout << printf("Concatenated: %s", concatenatedString) << endl;
    }
};

#endif

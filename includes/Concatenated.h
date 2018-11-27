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
    Concatenated(IConnection &connection, string destination, string objectPath) : ProxyInterfaces<org::sdbuscpp::Concatenator_proxy>(connection, move(destination), move(objectPath))
    {
    }

    ~Concatenated()
    {
    }

  protected:
    void onConcatenated(const string &concatenatedString) override
    {
        cout << printf("Concatenated: %s", concatenatedString.c_str()) << endl;
    }
};

#endif

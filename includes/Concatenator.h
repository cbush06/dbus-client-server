#ifndef CONCATENATOR_H
#define CONCATENATOR_H

#include <string>
#include <vector>
#include <sdbus-c++/sdbus-c++.h>
#include "concatenator-server.h"

using namespace std;
using namespace sdbus;

class Concatenator : public Interfaces<org::sdbuscpp::Concatenator_adaptor>
{
  public:
    Concatenator(IConnection &connection, string objectPath) : Interfaces<org::sdbuscpp::Concatenator_adaptor>(connection, move(objectPath))
    {
    }
    ~Concatenator() {}

  protected:
    string concatenate(const vector<int32_t> &numbers, const string &separator)
    {
        if (numbers.empty())
            throw Error("org.sdbuscpp.Concatenator.Error", "No numbers provided");

        string result;
        for (int32_t number : numbers)
        {
            result += (result.empty() ? string() : separator) + to_string(number);
        }

        concatenated(result);

        return result;
    }
};

#endif

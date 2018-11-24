#include <string>
#include <vector>
#include <sdbus-c++/sdbus-c++.h>
#include "dbus_schemas/concatenator-server.h"
#include "Concatenator.h"

using namespace std;
using namespace sdbus;

Concatenator::Concatenator(IConnection& connection, string objectPath) :
    Interfaces<org::sdbuscpp::Concatenator_adaptor>(connection, move(objectPath)) {
    }

Concatenator::~Concatenator(){}
    
string Concatenator::concatenate(const vector<int32_t>& numbers, const string& separator) {
    if(numbers.empty())
        throw Error("org.sdbuscpp.Concatenator.Error", "No numbers provided");
    
    string result;
    for(int32_t number : numbers) {
        result += (result.empty() ? string() : separator) + to_string(number);
    }

    concatenated(result);

    return result;
}
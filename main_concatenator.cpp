#include <iostream>
#include <sdbus-c++/sdbus-c++.h>
#include "Concatenator.h"

using namespace std;
using namespace sdbus;

int main(int argc, char* argv[]) {
    const char* serviceName = "org.sdbuscpp.Concatenator";
    auto connection = createSessionBusConnection(serviceName);

    cout << "Connection established..." << endl;

    const char* objectPath = "/org/sdbuscpp/concatenator";
    Concatenator concatenator(*connection, objectPath);

    connection->enterProcessingLoop();
}
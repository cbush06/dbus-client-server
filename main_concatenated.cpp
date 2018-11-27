#include <thread>
#include "Concatenated.h"

using namespace std;

int main(int argc, char* argv[]) {
    const char* destinationName = "org.sdbuscpp.Concatenator";
    const char* objectPath = "/org/sdbuscpp/concatenator";
    auto connection = createSessionBusConnection();

    Concatenated concatenated(*connection, destinationName, objectPath);

    vector<int32_t> numbers = {1, 2, 3, 4};
    string separator = ":";
    
    auto concatenatedString = concatenated.concatenate(numbers, separator);

    cout << "Concatenated: " << concatenatedString << endl;

    try {
        auto concatenatedString = concatenated.concatenate(vector<int32_t>{}, separator);
    } catch(Error& e) {
        cerr << "Error received..." << endl;
    }

    this_thread::sleep_for(50ms);

    return 0;
}
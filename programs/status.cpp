#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    std::cout << "Initially empty: "
              << (requests.IsEmpty() ? "yes" : "no") << '\n';

    PopulateSampleRequests(requests);
    std::cout << "Has requests: "
              << (requests.IsNotEmpty() ? "yes" : "no") << '\n';
    return 0;
}

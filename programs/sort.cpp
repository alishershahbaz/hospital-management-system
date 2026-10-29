#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    PopulateSampleRequests(requests);

    std::cout << "Sort by priority, then request ID:\n";
    requests.Sort();
    requests.Print();
    return 0;
}

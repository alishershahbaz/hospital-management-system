#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    PopulateSampleRequests(requests);

    std::cout << "Swap requests at indexes 0 and 2:\n";
    if (requests.Swap(0, 2))
        requests.Print();
    else
        std::cerr << "Could not swap requests: index out of range.\n";
    return 0;
}

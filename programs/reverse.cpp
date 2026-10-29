#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    PopulateSampleRequests(requests);

    std::cout << "Reverse the request list:\n";
    requests.Reverse();
    requests.Print();
    return 0;
}

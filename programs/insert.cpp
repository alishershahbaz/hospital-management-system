#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    PopulateSampleRequests(requests);

    std::cout << "Add a request at the head:\n";
    requests.Insert(CreateRequest(105, "Sara", "Science Block",
                                  "Water leakage", 1));
    requests.Print();
    return 0;
}

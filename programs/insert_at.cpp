#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    PopulateSampleRequests(requests);

    std::cout << "Insert a request at index 2:\n";
    requests.InsertAt(CreateRequest(105, "Sara", "Science Block",
                                    "Water leakage", 1), 2);
    requests.Print();
    return 0;
}

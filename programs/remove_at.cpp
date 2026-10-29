#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    PopulateSampleRequests(requests);

    std::cout << "Remove the request at index 1:\n";
    MaintenanceRequestNode* removed = requests.RemoveAt(1);
    DisplayRequest(removed);
    delete removed;
    requests.Print();
    return 0;
}

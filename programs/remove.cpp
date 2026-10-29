#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    PopulateSampleRequests(requests);

    std::cout << "Remove a request from the head:\n";
    MaintenanceRequestNode* removed = requests.Remove();
    DisplayRequest(removed);
    delete removed;
    requests.Print();
    return 0;
}

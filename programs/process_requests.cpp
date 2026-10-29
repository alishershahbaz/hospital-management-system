#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList requests;
    PopulateSampleRequests(requests);
    requests.Sort();

    std::cout << "Process requests in priority order:\n";
    int requestCounter = 1;
    while (requests.IsNotEmpty())
    {
        MaintenanceRequestNode* processed = requests.Remove();
        std::cout << requestCounter << ". ";
        DisplayRequest(processed);
        std::cout << "--------------------------------\n";
        delete processed;
        requestCounter++;
    }

    std::cout << "All requests processed. List empty: "
              << (requests.IsEmpty() ? "yes" : "no") << '\n';
    return 0;
}

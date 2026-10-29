#include "LinkedList.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "============================================\n";
    cout << "Campus Emergency Maintenance Request System\n";
    cout << "Singly Linked List Demonstration\n";
    cout << "============================================\n";
    cout << "A linked list can grow or shrink as requests are added or resolved.\n";

    LinkedList maintenanceRequests;
    maintenanceRequests.InsertAt(
        CreateRequest(101, "Ali", "Computer Lab 3", "Power failure", 3), 0);
    maintenanceRequests.InsertAt(
        CreateRequest(102, "Ahmed", "Main Hall", "Fire alarm issue", 1), 1);
    maintenanceRequests.InsertAt(
        CreateRequest(103, "Bilal", "Library", "Projector not working", 2), 2);
    maintenanceRequests.InsertAt(
        CreateRequest(104, "Hamza", "Engineering Block",
                      "Air conditioner issue", 1), 3);

    cout << "\nInitial maintenance requests:\n";
    maintenanceRequests.Print();

    cout << "\nInsert a request at index 2:\n";
    maintenanceRequests.InsertAt(
        CreateRequest(105, "Sara", "Science Block", "Water leakage", 1), 2);
    maintenanceRequests.Print();

    cout << "\nRemove the request at index 1:\n";
    MaintenanceRequestNode* removed = maintenanceRequests.RemoveAt(1);
    DisplayRequest(removed);
    delete removed;
    maintenanceRequests.Print();

    cout << "\nSwap requests at indexes 0 and 2:\n";
    if (maintenanceRequests.Swap(0, 2))
        maintenanceRequests.Print();

    cout << "\nSort by urgency (priority), then request ID:\n";
    maintenanceRequests.Sort();
    maintenanceRequests.Print();

    cout << "\nReverse the collection:\n";
    maintenanceRequests.Reverse();
    maintenanceRequests.Print();

    cout << "\nInsert a request at the head:\n";
    maintenanceRequests.Insert(
        CreateRequest(100, "Mariam", "Student Center",
                      "Broken entrance door", 2));
    maintenanceRequests.Print();

    cout << "\nRemove a request from the head:\n";
    removed = maintenanceRequests.Remove();
    DisplayRequest(removed);
    delete removed;

    cout << "\nCurrent collection status: "
         << (maintenanceRequests.IsNotEmpty() ? "not empty" : "empty")
         << '\n';
    maintenanceRequests.Print();

    cout << "\nProcess remaining requests in priority order:\n";
    maintenanceRequests.Sort();
    int requestCounter = 1;
    while (maintenanceRequests.IsNotEmpty())
    {
        MaintenanceRequestNode* processed = maintenanceRequests.Remove();
        cout << requestCounter << ". ";
        DisplayRequest(processed);
        cout << "--------------------------------\n";
        delete processed;
        requestCounter++;
    }

    cout << "All maintenance requests have been processed.\n";
    cout << "Collection is empty: "
         << (maintenanceRequests.IsEmpty() ? "yes" : "no") << '\n';
    return 0;
}

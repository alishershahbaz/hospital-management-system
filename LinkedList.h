#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "MaintenanceRequest.h"

class LinkedList
{
private:
    MaintenanceRequestNode* head;
    int count;

    MaintenanceRequestNode* GetNodeAt(int index) const;
    void CopyRequestData(MaintenanceRequestNode* first,
                         MaintenanceRequestNode* second);
    void SwapContents(LinkedList& other);

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();

    void Insert(MaintenanceRequestNode* request);
    MaintenanceRequestNode* Remove();
    bool IsEmpty() const;
    bool IsNotEmpty() const;
    void InsertAt(MaintenanceRequestNode* request, int index);
    MaintenanceRequestNode* RemoveAt(int index);
    bool Swap(int firstIndex, int secondIndex);
    void Sort();
    void Reverse();
    void Print() const;
};

#endif

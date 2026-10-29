#include "LinkedList.h"

#include <iostream>
#include <utility>

using namespace std;

MaintenanceRequestNode* LinkedList::GetNodeAt(int index) const
{
    MaintenanceRequestNode* current = head;
    for (int i = 0; i < index && current != nullptr; i++)
        current = current->next;
    return current;
}

void LinkedList::CopyRequestData(MaintenanceRequestNode* first,
                                 MaintenanceRequestNode* second)
{
    swap(first->requestID, second->requestID);
    swap(first->requesterName, second->requesterName);
    swap(first->location, second->location);
    swap(first->issueType, second->issueType);
    swap(first->priority, second->priority);
}

void LinkedList::SwapContents(LinkedList& other)
{
    swap(head, other.head);
    swap(count, other.count);
}

LinkedList::LinkedList() : head(nullptr), count(0)
{
}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr), count(0)
{
    LinkedList copy;
    MaintenanceRequestNode* current = other.head;

    while (current != nullptr)
    {
        copy.InsertAt(
            new MaintenanceRequestNode{
                current->requestID,
                current->requesterName,
                current->location,
                current->issueType,
                current->priority,
                nullptr
            },
            copy.count);
        current = current->next;
    }

    SwapContents(copy);
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this != &other)
    {
        LinkedList copy(other);
        SwapContents(copy);
    }
    return *this;
}

LinkedList::~LinkedList()
{
    while (!IsEmpty())
        delete Remove();
}

void LinkedList::Insert(MaintenanceRequestNode* request)
{
    if (request == nullptr)
        return;

    request->next = head;
    head = request;
    count++;
}

MaintenanceRequestNode* LinkedList::Remove()
{
    if (IsEmpty())
        return nullptr;

    MaintenanceRequestNode* request = head;
    head = head->next;
    request->next = nullptr;
    count--;
    return request;
}

bool LinkedList::IsEmpty() const
{
    return head == nullptr;
}

bool LinkedList::IsNotEmpty() const
{
    return head != nullptr;
}

void LinkedList::InsertAt(MaintenanceRequestNode* request, int index)
{
    if (request == nullptr)
        return;

    if (index < 0)
        index = 0;
    if (index > count)
        index = count;

    if (index == 0)
    {
        Insert(request);
        return;
    }

    MaintenanceRequestNode* previous = GetNodeAt(index - 1);
    request->next = previous->next;
    previous->next = request;
    count++;
}

MaintenanceRequestNode* LinkedList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    if (index < 0)
        index = 0;
    if (index >= count)
        index = count - 1;

    if (index == 0)
        return Remove();

    MaintenanceRequestNode* previous = GetNodeAt(index - 1);
    MaintenanceRequestNode* request = previous->next;
    previous->next = request->next;
    request->next = nullptr;
    count--;
    return request;
}

bool LinkedList::Swap(int firstIndex, int secondIndex)
{
    if (firstIndex < 0 || firstIndex >= count ||
        secondIndex < 0 || secondIndex >= count)
        return false;

    if (firstIndex != secondIndex)
        CopyRequestData(GetNodeAt(firstIndex), GetNodeAt(secondIndex));

    return true;
}

void LinkedList::Sort()
{
    for (MaintenanceRequestNode* i = head; i != nullptr; i = i->next)
    {
        for (MaintenanceRequestNode* j = i->next; j != nullptr; j = j->next)
        {
            if (i->priority > j->priority ||
                (i->priority == j->priority && i->requestID > j->requestID))
                CopyRequestData(i, j);
        }
    }
}

void LinkedList::Reverse()
{
    MaintenanceRequestNode* previous = nullptr;
    MaintenanceRequestNode* current = head;

    while (current != nullptr)
    {
        MaintenanceRequestNode* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

void LinkedList::Print() const
{
    if (IsEmpty())
    {
        cout << "No maintenance requests.\n";
        return;
    }

    cout << "\nIndex\tRequest ID\tRequester\tLocation"
         << "\t\tIssue\t\tPriority\n";
    cout << "----------------------------------------------------------------"
         << "--------------------------\n";

    MaintenanceRequestNode* current = head;
    int index = 0;
    while (current != nullptr)
    {
        cout << index << '\t'
             << current->requestID << "\t\t"
             << current->requesterName << "\t\t"
             << current->location << "\t\t"
             << current->issueType << "\t\t"
             << current->priority << '\n';
        current = current->next;
        index++;
    }

    cout << "Total requests: " << count << '\n';
}

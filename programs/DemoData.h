#ifndef DEMO_DATA_H
#define DEMO_DATA_H

#include "../LinkedList.h"

inline void PopulateSampleRequests(LinkedList& requests)
{
    requests.InsertAt(CreateRequest(101, "Ali", "Computer Lab 3",
                                    "Power failure", 3), 0);
    requests.InsertAt(CreateRequest(102, "Ahmed", "Main Hall",
                                    "Fire alarm issue", 1), 1);
    requests.InsertAt(CreateRequest(103, "Bilal", "Library",
                                    "Projector not working", 2), 2);
    requests.InsertAt(CreateRequest(104, "Hamza", "Engineering Block",
                                    "Air conditioner issue", 1), 3);
}

#endif

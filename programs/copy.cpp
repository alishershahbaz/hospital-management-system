#include "DemoData.h"

#include <iostream>

int main()
{
    LinkedList original;
    PopulateSampleRequests(original);

    LinkedList copied(original);
    std::cout << "Original list:\n";
    original.Print();
    std::cout << "\nCopied list:\n";
    copied.Print();
    return 0;
}

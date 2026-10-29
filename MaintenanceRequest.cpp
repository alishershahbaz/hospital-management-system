#include "MaintenanceRequest.h"

#include <iostream>

MaintenanceRequestNode* CreateRequest(int requestID,
                                      const std::string& requesterName,
                                      const std::string& location,
                                      const std::string& issueType,
                                      int priority)
{
    return new MaintenanceRequestNode{
        requestID, requesterName, location, issueType, priority, nullptr
    };
}

void DisplayRequest(const MaintenanceRequestNode* request)
{
    if (request == nullptr)
        return;

    std::cout << "Request ID: " << request->requestID << '\n';
    std::cout << "Requester: " << request->requesterName << '\n';
    std::cout << "Location: " << request->location << '\n';
    std::cout << "Issue Type: " << request->issueType << '\n';
    std::cout << "Priority: " << request->priority << '\n';
}

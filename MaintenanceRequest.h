#ifndef MAINTENANCE_REQUEST_H
#define MAINTENANCE_REQUEST_H

#include <string>

struct MaintenanceRequestNode
{
    int requestID;
    std::string requesterName;
    std::string location;
    std::string issueType;
    int priority;
    MaintenanceRequestNode* next;
};

MaintenanceRequestNode* CreateRequest(int requestID,
                                      const std::string& requesterName,
                                      const std::string& location,
                                      const std::string& issueType,
                                      int priority);
void DisplayRequest(const MaintenanceRequestNode* request);

#endif

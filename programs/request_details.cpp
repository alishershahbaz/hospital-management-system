#include "../MaintenanceRequest.h"

int main()
{
    MaintenanceRequestNode* request =
        CreateRequest(106, "Mariam", "Student Center",
                      "Broken entrance door", 2);
    DisplayRequest(request);
    delete request;
    return 0;
}

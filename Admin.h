#ifndef ADMIN_H
#define ADMIN_H

#include "ATM.h"
#include "Customer.h"
using namespace std;

class Admin : public ATM {
private:
    Customer* customerSystem;
public:
    Admin();
    void setCustomerSystem(Customer* clientRef);
    void run() override;
    void addAccount();
    void deleteAccount();
};

#endif

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ATM.h"
#include <ctime>
using namespace std;

class Customer : public ATM {
public:
    Customer();
    void run() override;
};

#endif

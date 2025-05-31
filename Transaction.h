#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
private:
    string type;
    double value;
    string timestamp;

public:
    Transaction();
    Transaction(const string& type, double value, const string& time);
    string getDetails() const;
};

#endif

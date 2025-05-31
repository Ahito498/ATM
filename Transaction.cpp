#include "Transaction.h"
#include <sstream>


Transaction::Transaction() : type(""), value(0.0), timestamp("") {}

Transaction::Transaction(const string& type, double value, const string& time)
    : type(type), value(value), timestamp(time) {}

string Transaction::getDetails() const {
    stringstream ss;
    ss << "[" << timestamp << "] " << type << ": " << value;
    return ss.str();
}

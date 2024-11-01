#include "Employee.h"

// Default constructor
Employee::Employee() : name(""), contactInfo(""), accessLevel("") {}

// Parameterized constructor
Employee::Employee(string n, string c, string a) : name(n), contactInfo(c), accessLevel(a) {}

// Getters
string Employee::getName() const { return name; }
string Employee::getContactInfo() const { return contactInfo; }
string Employee::getAccessLevel() const { return accessLevel; }

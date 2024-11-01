#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    string name;
    string contactInfo;
    string accessLevel;

public:
 Employee();
 Employee(string n, string c, string a);

    string getName() const;
    string getContactInfo() const;
    string getAccessLevel() const;
};

#endif // EMPLOYEE_H

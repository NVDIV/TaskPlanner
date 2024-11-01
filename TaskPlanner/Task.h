#ifndef TASK_H
#define TASK_H

#include <string>
#include "Employee.h"
using namespace std;

class Task {
private:
    string name;
    string description;
    string dueDate;
    int priority;
    Employee assignedTo; // Changed from string to Employee object
    string status;

public:
    Task();
    Task(string n, string d, string due, int p, Employee a, string s);

    string getName() const;
    string getDescription() const;
    string getDueDate() const;
    int getPriority() const;
    Employee getAssignedTo() const; // Updated to return Employee object
    string getStatus() const;

    void setDescription(string d);
    void setDueDate(string due);
    void setPriority(int p);
    void setAssignedTo(Employee a); // Updated to accept Employee object
    void setStatus(string s);
};

#endif // TASK_H

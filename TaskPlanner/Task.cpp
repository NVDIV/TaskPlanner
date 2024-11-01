#include "Task.h"
#include "Employee.h"

// Constructors
Task::Task() {}
Task::Task(string n, string d, string due, int p, Employee a, string s)
    : name(n), description(d), dueDate(due), priority(p), assignedTo(a), status(s) {}

// Getters
string Task::getName() const { return name; }
string Task::getDescription() const { return description; }
string Task::getDueDate() const { return dueDate; }
int Task::getPriority() const { return priority; }
Employee Task::getAssignedTo() const { return assignedTo; } // Updated to return Employee object
string Task::getStatus() const { return status; }

// Setters
void Task::setDescription(string d) { description = d; }
void Task::setDueDate(string due) { dueDate = due; }
void Task::setPriority(int p) { priority = p; }
void Task::setAssignedTo(Employee a) { assignedTo = a; } // Updated to accept Employee object
void Task::setStatus(string s) { status = s; }



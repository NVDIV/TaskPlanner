#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include "Task.h"
#include "Employee.h"
using namespace std;

class Project {
private:
    vector<Task> tasks;
    vector<Employee> teamMembers;

public:
    Project();

    void addTask(Task task);
    void removeTask(string taskName);
    Task* findTask(string taskName);
    void assignTask(string taskName, Employee Employee); // Updated to accept Employee object
    void updateTask(string taskName, Task updatedTask);
    vector<Task> filterTasks(string criteria, string value);
    void printTaskReport();

    void addTeamMember(Employee Employee);
    void removeTeamMember(string EmployeeName);
    Employee* findTeamMember(string EmployeeName);
    void printTeamMembers();

    vector<Task> getTasks() const;
    vector<Employee> getTeamMembers() const;
};

#endif // PROJECT_H

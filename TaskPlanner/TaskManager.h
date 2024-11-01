#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Project.h"
#include <vector>
#include <string>
using namespace std;

class TaskManager {
public:
    Project currentProject;

    TaskManager();

    void createTask(string name, string description, string dueDate, int priority, Employee assignedTo, string status);
    void editTask(string name, string newDescription, string newDueDate, int newPriority, Employee newAssignedTo, string newStatus);
    void deleteTask(string name);
    vector<Task> searchTasks(string criteria, string value);
    void distributeTasks();
    vector<Employee> getAvailableEmployees();
    Task* getTaskByName(const std::string& name);
};

#endif // TASKMANAGER_H

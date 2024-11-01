#include "Project.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructors
Project::Project() {}

// Methods to manage tasks
void Project::addTask(Task task) {
    tasks.push_back(task);
}

void Project::removeTask(string taskName) {
    tasks.erase(remove_if(tasks.begin(), tasks.end(),
                          [&taskName](Task& t) { return t.getName() == taskName; }),
                tasks.end());
}

Task* Project::findTask(string taskName) {
    auto it = find_if(tasks.begin(), tasks.end(),
                      [&taskName](Task& t) { return t.getName() == taskName; });
    if (it != tasks.end())
        return &(*it);
    return nullptr;
}

void Project::assignTask(string taskName, Employee user) {
    Task* task = findTask(taskName);
    if (task)
        task->setAssignedTo(user);
}

void Project::updateTask(string taskName, Task updatedTask) {
    Task* task = findTask(taskName);
    if (task) {
        task->setDescription(updatedTask.getDescription());
        task->setDueDate(updatedTask.getDueDate());
        task->setPriority(updatedTask.getPriority());
        task->setAssignedTo(updatedTask.getAssignedTo());
        task->setStatus(updatedTask.getStatus());
    }
}

vector<Task> Project::filterTasks(string criteria, string value) {
    vector<Task> filteredTasks;
    for (Task& task : tasks) {
        if ((criteria == "status" && task.getStatus() == value) ||
            (criteria == "assignedTo" && task.getAssignedTo().getName() == value) ||
            (criteria == "priority" && to_string(task.getPriority()) == value)) {
            filteredTasks.push_back(task);
        }
    }
    return filteredTasks;
}

void Project::printTaskReport() {
    for (const Task& task : tasks) {
        cout << "Task Name: " << task.getName() << endl;
        cout << "Description: " << task.getDescription() << endl;
        cout << "Due Date: " << task.getDueDate() << endl;
        cout << "Priority: " << task.getPriority() << endl;
        cout << "Assigned To: " << task.getAssignedTo().getName() << endl;
        cout << "Status: " << task.getStatus() << endl;
        cout << "----------------------------------" << endl;
    }
}

// Methods to manage team members
void Project::addTeamMember(Employee user) {
    teamMembers.push_back(user);
}

void Project::removeTeamMember(string userName) {
    teamMembers.erase(remove_if(teamMembers.begin(), teamMembers.end(),
                                [&userName](Employee& u) { return u.getName() == userName; }),
                      teamMembers.end());
}

Employee* Project::findTeamMember(string userName) {
    for (Employee& employee : teamMembers) {
        if (employee.getName() == userName) {
            return &employee;
        }
    }
    return nullptr;
}

void Project::printTeamMembers() {
    for (const Employee& user : teamMembers) {
        cout << "Employee Name: " << user.getName() << endl;
        cout << "Contact Info: " << user.getContactInfo() << endl;
        cout << "Access Level: " << user.getAccessLevel() << endl;
        cout << "----------------------------------" << endl;
    }
}

// Getters for tasks and team members
vector<Task> Project::getTasks() const {
    return tasks;
}

vector<Employee> Project::getTeamMembers() const {
    return teamMembers;
}

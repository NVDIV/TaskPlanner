#include "TaskManager.h"

// Constructor
TaskManager::TaskManager() {}

// Method to create a task
void TaskManager::createTask(string name, string description, string dueDate, int priority, Employee assignedTo, string status) {
    Task newTask(name, description, dueDate, priority, assignedTo, status);
    currentProject.addTask(newTask);
}

// Method to edit a task
void TaskManager::editTask(string name, string newDescription, string newDueDate, int newPriority, Employee newAssignedTo, string newStatus) {
    Task* task = currentProject.findTask(name);
    if (task) {
        task->setDescription(newDescription);
        task->setDueDate(newDueDate);
        task->setPriority(newPriority);
        task->setAssignedTo(newAssignedTo);
        task->setStatus(newStatus);
    }
}

// Method to delete a task
void TaskManager::deleteTask(string name) {
    currentProject.removeTask(name);
}

// Method to search for tasks based on criteria
vector<Task> TaskManager::searchTasks(string criteria, string value) {
    return currentProject.filterTasks(criteria, value);
}

// Method to distribute tasks
void TaskManager::distributeTasks() {
    vector<Employee> teamMembers = currentProject.getTeamMembers();
    vector<Task> tasks = currentProject.getTasks();

    size_t memberIndex = 0;
    for (Task& task : tasks) {
        if (teamMembers.empty()) return; // No team members to assign tasks to
        task.setAssignedTo(teamMembers[memberIndex]);
        memberIndex = (memberIndex + 1) % teamMembers.size();
    }
}

// Method to get available employees
vector<Employee> TaskManager::getAvailableEmployees() {
    return currentProject.getTeamMembers();
}

// Get task by name
Task* TaskManager::getTaskByName(const std::string& name) {
    return currentProject.findTask(name);
}
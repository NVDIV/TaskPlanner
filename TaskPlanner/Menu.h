#ifndef MENU_H
#define MENU_H

#include "TaskManager.h"
#include "Employee.h"
#include <vector>
#include <string>

class Menu {
public:
    Menu(TaskManager& taskManager, std::vector<Employee>& employees);
    void showMainMenu();
    void showTaskManagerMenu();
    void showEmployeeMenu();
    void addTask();
    void deleteTask();
    void modifyTask();
    void getAvailableEmployees();
    void assignTaskToEmployee();
    void viewMyTasks(const std::string& employeeName);
    void changeTaskStatus(const std::string& employeeName);

private:
    TaskManager& taskManager;
    std::vector<Employee>& employees;
};

#endif

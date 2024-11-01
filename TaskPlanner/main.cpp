#include "Task.h"
#include "Employee.h"
#include "Project.h"
#include "TaskManager.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    TaskManager taskManager;
    vector<Employee> employees = {
        Employee("Alice", "alice@example.com", "Standard"),
        Employee("Bob", "bob@example.com", "Standard"),
        Employee("Charlie", "charlie@example.com", "Standard")
    };

    Project project;

    for (const auto& employee : employees) {
        project.addTeamMember(employee);
    }

    Menu menu(taskManager, employees);
    menu.showMainMenu();

    return 0;
}

#include "Menu.h"
#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

Menu::Menu(TaskManager& tm, std::vector<Employee>& emps) : taskManager(tm), employees(emps) {}

void Menu::showMainMenu() {
    int userType;
    bool running = true;

    while (running) {
        std::cout << "Please select your user type:" << std::endl;
        std::cout << "1. Task Manager" << std::endl;
        std::cout << "2. Employee" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter choice (1-3): ";
        std::cin >> userType;

        switch (userType) {
            case 1:
                showTaskManagerMenu();
                break;
            case 2:
                showEmployeeMenu();
                break;
            case 3:
                running = false;
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

void Menu::showTaskManagerMenu() {
    int choice;
    bool back = false;

    while (!back) {
        std::cout << "\nTask Manager Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Delete Task" << std::endl;
        std::cout << "3. Modify Task" << std::endl;
        std::cout << "4. Assign Task to Employee" << std::endl;
        std::cout << "5. View Available Employees" << std::endl;
        std::cout << "6. Back to Main Menu" << std::endl;
        std::cout << "Enter choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                modifyTask();
                break;
            case 4:
                assignTaskToEmployee();
                break;
            case 5:
                getAvailableEmployees();
                break;
            case 6:
                back = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

void Menu::showEmployeeMenu() {
    int choice;
    bool back = false;

    while (!back) {
        std::cout << "\nEmployee Menu:" << std::endl;
        std::cout << "1. View My Tasks" << std::endl;
        std::cout << "2. Change Task Status" << std::endl;
        std::cout << "3. Back to Main Menu" << std::endl;
        std::cout << "Enter choice (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string employeeName;
                std::cout << "Enter your name: ";
                std::cin >> employeeName;
                viewMyTasks(employeeName);
                break;
            }
            case 2: {
                std::string employeeName;
                std::cout << "Enter your name: ";
                std::cin >> employeeName;
                changeTaskStatus(employeeName);
                break;
            }
            case 3:
                back = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

void Menu::addTask() {
    std::string name, description, dueDate, assignedToName;
    int priority, status;

    std::cout << "Enter task name: ";
    std::cin >> name;
    std::cout << "Enter task description: ";
    std::cin.ignore();  // Ignore newline left in buffer
    std::getline(std::cin, description);
    std::cout << "Enter task due date (YYYY-MM-DD): ";
    std::cin >> dueDate;

    // Check due date
    std::tm tm = {};
    std::istringstream ss(dueDate);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    std::time_t due_time = std::mktime(&tm);
    std::time_t now = std::time(nullptr);
    if (due_time < now) {
        std::cout << "Due date cannot be in the past. Task not added." << std::endl;
        return;
    }

    std::cout << "Enter task priority (1 - high, 2 - medium, 3 - low): ";
    std::cin >> priority;

    // Check task priority
    if (priority < 1 || priority > 3) {
        std::cout << "Invalid task priority. Task not added." << std::endl;
        return;
    }

    std::cout << "Enter employee name to assign task to: ";
    std::cin >> assignedToName;
    std::cout << "Enter task status (1 - not started, 2 - in progress, 3 - completed): ";
    std::cin >> status;

    // Check task status
    if (status < 1 || status > 3) {
        std::cout << "Invalid task status. Task not added." << std::endl;
        return;
    }

    Employee* assignedTo = nullptr;
    for (Employee& emp : employees) {
        if (emp.getName() == assignedToName) {
            assignedTo = &emp;
            break;
        }
    }

    if (assignedTo == nullptr) {
        std::cout << "Employee not found. Task not added." << std::endl;
        return;
    }

    std::string statusStr = std::to_string(status); // Convert status to string
    taskManager.createTask(name, description, dueDate, priority, *assignedTo, statusStr); // Pass status as string
}

void Menu::deleteTask() {
    std::string name;
    std::cout << "Enter task name to delete: ";
    std::cin >> name;

    Task* task = taskManager.getTaskByName(name);

    if (task == nullptr) {
        std::cout << "Task not found. Task not deleted." << std::endl;
        return;
    }

    taskManager.deleteTask(name);
}

void Menu::modifyTask() {
    std::string name;
    std::cout << "Enter task name to modify: ";
    std::cin >> name;

     Task* task = taskManager.getTaskByName(name);

    if (task == nullptr) {
        std::cout << "Task not found. Task not deleted." << std::endl;
        return;
    }

    int choice;
    bool back = false;

    while (!back) {
        std::cout << "\nModify Task Menu:" << std::endl;
        std::cout << "1. Modify Description" << std::endl;
        std::cout << "2. Modify Due Date" << std::endl;
        std::cout << "3. Modify Priority" << std::endl;
        std::cout << "4. Modify Assigned To" << std::endl;
        std::cout << "5. Modify Status" << std::endl;
        std::cout << "6. Back to Task Manager Menu" << std::endl;
        std::cout << "Enter choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string newDescription;
                std::cout << "Enter new description: ";
                std::cin.ignore();  // Ignore newline left in buffer
                std::getline(std::cin, newDescription);
                task->setDescription(newDescription);
                std::cout << "Description modified successfully." << std::endl;
                break;
            }
            case 2: {
                std::string newDueDate;
                std::cout << "Enter new due date (YYYY-MM-DD): ";
                std::cin >> newDueDate;

                // Check due date
                std::tm tm = {};
                std::istringstream ss(newDueDate);
                ss >> std::get_time(&tm, "%Y-%m-%d");
                std::time_t due_time = std::mktime(&tm);
                std::time_t now = std::time(nullptr);
                if (due_time < now) {
                    std::cout << "Due date cannot be in the past. Task not modified." << std::endl;
                    break;
                }

                task->setDueDate(newDueDate);
                std::cout << "Due date modified successfully." << std::endl;
                break;
            }
            case 3: {
                int newPriority;
                std::cout << "Enter new priority (1 - high, 2 - medium, 3 - low): ";
                std::cin >> newPriority;

                // Check task priority
                if (newPriority < 1 || newPriority > 3) {
                    std::cout << "Invalid task priority. Task not modified." << std::endl;
                    break;
                }

                task->setPriority(newPriority);
                std::cout << "Priority modified successfully." << std::endl;
                break;
            }
            case 4: {
                std::string newAssignedToName;
                std::cout << "Enter new employee name to assign task to: ";
                std::cin >> newAssignedToName;

                Employee* newAssignedTo = nullptr;
                for (Employee& emp : employees) {
                    if (emp.getName() == newAssignedToName) {
                        newAssignedTo = &emp;
                        break;
                    }
                }

                if (newAssignedTo == nullptr) {
                    std::cout << "Employee not found. Task not modified." << std::endl;
                    break;
                }

                task->setAssignedTo(*newAssignedTo);
                std::cout << "Assigned to modified successfully." << std::endl;
                break;
            }
            case 5: {
                int newStatus;
                std::cout << "Enter new status (1 - not started, 2 - in progress, 3 - completed): ";
                std::cin >> newStatus;

                // Check task status
                if (newStatus < 1 || newStatus > 3) {
                    std::cout << "Invalid task status. Task not modified." << std::endl;
                    break;
                }

                task->setStatus(std::to_string(newStatus)); // Convert newStatus to string
                std::cout << "Status modified successfully." << std::endl;
                break;
            }
            case 6:
                back = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

void Menu::getAvailableEmployees() {
    taskManager.getAvailableEmployees();
}

void Menu::assignTaskToEmployee() {
    std::string taskName, employeeName;
    std::cout << "Enter task name to assign: ";
    std::cin >> taskName;
    std::cout << "Enter employee name to assign to: ";
    std::cin >> employeeName;

    Employee* employee = nullptr;
    for (Employee& emp : employees) {
        if (emp.getName() == employeeName) {
            employee = &emp;
            break;
               }
    }

    if (employee == nullptr) {
        std::cout << "Employee not found. Task not assigned." << std::endl;
        return;
    }

    taskManager.currentProject.assignTask(taskName, *employee);
}

void Menu::viewMyTasks(const std::string& employeeName) {
    std::vector<Task> tasks = taskManager.currentProject.filterTasks("assignedTo", employeeName);
    if (tasks.empty()) {
        std::cout << "No tasks found for " << employeeName << "." << std::endl;
        return;
    }

    for (const Task& task : tasks) {
        std::cout << "Task: " << task.getName() << ", Description: " << task.getDescription()
                  << ", Due Date: " << task.getDueDate() << ", Priority: " << task.getPriority()
                  << ", Status: " << task.getStatus() << std::endl;
    }
}

void Menu::changeTaskStatus(const std::string& employeeName) {
    std::string taskName, newStatus;
    std::cout << "Enter task name to change status: ";
    std::cin >> taskName;
    std::cout << "Enter new status (1 - not started, 2 - in progress, 3 - completed): ";
    std::cin >> newStatus;

    std::vector<Task> tasks = taskManager.currentProject.filterTasks("assignedTo", employeeName);
    for (Task& task : tasks) {
        if (task.getName() == taskName) {
            // Check task status
            if (newStatus != "1" && newStatus != "2" && newStatus != "3") {
                std::cout << "Invalid task status. Task status not updated." << std::endl;
                return;
            }
            
            task.setStatus(newStatus);
            std::cout << "Task status updated." << std::endl;
            return;
        }
    }

    std::cout << "Task not found or not assigned to you." << std::endl;
}


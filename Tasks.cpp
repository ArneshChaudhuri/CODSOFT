#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string name;
    cout << "Enter task: ";
    getline(cin, name);
    if (name.empty()) {
        cout << "Task name cannot be empty.\n";
        return;
    }
    tasks.push_back({ name, false });
    cout << "Task added.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }
    cout << "\n";
    for (int i = 0; i < (int)tasks.size(); i++) {
        string status = tasks[i].completed ? "[Completed]" : "[Pending]  ";
        cout << i + 1 << ". " << status << " " << tasks[i].name << "\n";
    }
    cout << "\n";
}

void markCompleted() {
    if (tasks.empty()) {
        cout << "No tasks to mark.\n";
        return;
    }
    viewTasks();
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (cin.fail() || index < 1 || index >(int)tasks.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid task number.\n";
        return;
    }
    if (tasks[index - 1].completed) {
        cout << "Task is already marked as completed.\n";
        return;
    }
    tasks[index - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask() {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }
    viewTasks();
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (cin.fail() || index < 1 || index >(int)tasks.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid task number.\n";
        return;
    }
    cout << "Removed: " << tasks[index - 1].name << "\n";
    tasks.erase(tasks.begin() + index - 1);
}

void showMenu() {
    cout << "=== TO-DO LIST MANAGER ===\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choice: ";
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n\n";
            continue;
        }
        cout << "\n";
        switch (choice) {
        case 1: addTask();       break;
        case 2: viewTasks();     break;
        case 3: markCompleted(); break;
        case 4: removeTask();    break;
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Enter 1-5.\n";
        }
        cout << "\n";
    }
}
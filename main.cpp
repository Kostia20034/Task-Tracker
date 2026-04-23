#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include "task.h"
#include "task_manager.h"

using namespace std;

void displayUsage() {
    cout << "========================================" << endl;
    cout << "       🚀 TASK TRACKER CLI             " << endl;
    cout << "========================================" << endl;
    cout << "Usage:" << endl;
    cout << "  ./task_manager add <description>    - Add a new task" << endl;
    cout << "  ./task_manager list                 - List all tasks" << endl;
    cout << "  ./task_manager delete <id>          - Remove a task by ID" << endl;
    cout << "  ./task_manager modify <id> <status> - Update status (Todo, InProgress, Done)" << endl;
    cout << "========================================" << endl;
}

int main(int argc, char* argv[]) {
    // Initialize TaskManager with JSON persistence
    TaskManager taskManager("tasks.json");
    stringstream SS;

    // Check if enough arguments are provided
    if (argc < 2) {
        displayUsage();
        return 0;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            cout << "❌ Error: Please provide a task description." << endl;
            return 1;
        }
        for (int i = 2; i < argc - 1; i++) {
            SS << argv[i] << " ";
        }
        SS << argv[argc - 1];
        string taskName = SS.str();
        taskManager.addTask(taskName);
        cout << "✅ Task added successfully!" << endl;

    } else if (strcmp(argv[1], "list") == 0) {
        taskManager.listAll();

    } else if (strcmp(argv[1], "delete") == 0) {
        if (argc < 3) {
            cout << "❌ Error: Please provide a task ID to delete." << endl;
            return 1;
        }
        taskManager.deleteTask(stoi(argv[2]));

    } else if (strcmp(argv[1], "modify") == 0) {
        if (argc < 4) {
            cout << "❌ Error: Usage: ./task_manager modify <id> <status>" << endl;
            return 1;
        }
        taskManager.markTaskStatus(stoi(argv[2]), argv[3]);
        cout << "✅ Task " << argv[2] << " updated to " << argv[3] << endl;

    } else {
        cout << "❌ Unknown command: " << argv[1] << endl;
        displayUsage();
    }

    return 0;
}
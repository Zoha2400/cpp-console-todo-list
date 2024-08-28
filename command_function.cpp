#include "command_function.h"
#include <iostream>
#include <algorithm>


vector<Task> tasks;


void printTask(const Task& task) {
    int minLength = 52;
    int textLength = task.description.length();
    int borderLength = std::max(minLength, 54);

    string task_text = task.description;

    std::string border(75, '-');

    if (textLength > 40) {
        task_text = task_text.substr(0, 40) + "...";
        textLength = task_text.length();
    }

    int paddingLeft = (borderLength - textLength) / 2;
    int paddingRight = borderLength - textLength - paddingLeft;

    std::cout << "+" << border << "+" << std::endl;
    std::cout << "| " << task.id << " |  " << task.name << "  |  " << std::string(paddingLeft, ' ') << task_text << std::string(paddingRight, ' ') << "|  " << (task.isCompleted ? 1 : 0) << "  |" << std::endl;
    std::cout << "+" << border << "+" << std::endl;
}

int task_switching(char command) {
    switch (command) {
        case 'a': {
            string taskName, taskDescription;

            cout << "Enter task name: ";
            getline(cin, taskName);
            cout << "Enter task description: ";
            getline(cin, taskDescription);

            if (!taskName.empty() && !taskDescription.empty()) {
                int id = tasks.empty() ? 1 : tasks.back().id + 1;
                Task newTask = {id, taskName, taskDescription, false};
                tasks.push_back(newTask);
            } else {
                cout << "Invalid input. Task name and description must not be empty." << endl;
            }
            break;
        }
        case 'c': {
            cout << "================================\n"
                 << "Type the id of your task" << endl;
            int id;
            cin >> id;
            cin.ignore();

            if(id > 0 && id <= tasks.size()) {
                tasks[id - 1].isCompleted = !tasks[id - 1].isCompleted;
                cout << "Task with ID " << id << " has been " << (tasks[id - 1].isCompleted? "completed" : "uncompleted") << endl;
                cout << "Task deleted successfully. Type 't' to see all tasks" << endl;
            }
            break;
        }
        case 'v': {
            cout << "================================\n"
                 << "Type the id of your task" << endl;
            int id;
            cin >> id;
            cin.ignore();

            bool found = false;
            for (const auto& task : tasks) {
                if (task.id == id) {
                    cout << "Your task description:\n";
                    cout << "==========description===========\n";
                    cout << task.description << endl;
                    cout << "================================\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Task with ID " << id << " not found." << endl;
            }
            break;
        }
        case 'd': {
            cout << "================================\n"
                 << "Type the id of your task" << endl;
            int id;
            cin >> id;
            cin.ignore();

            if(id > 0 && id <= tasks.size()) {
                cout << "Deleting task with ID " << id << endl;
                tasks.erase(tasks.begin() + id - 1);
                cout << "Task deleted successfully. Type 't' to see all tasks" << endl;
            }
            break;
        }
        case 'q': {
            cout << "Quitting the program." << endl;
            return 0;
        }
        case 't': {
            cout << "Your tasks:\n";
            for (const auto& task : tasks) {
                printTask(task);
            }
            break;
        }
        default: {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    return 1;
}

#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Task {
    int id;
    string name;
    string description;
    bool isCompleted;
};

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

int main() {
    Task exampleTask = {1, "math", "First task", false};
    Task exampleTask2 = {2, "math","Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus lacinia odio vitae vestibulum vestibulum. Cras venenatis euismod malesuada. Nullam ac erat ante. Integer nec odio. Praesent libero. Sed cursus ante dapibus diam. Sed nisi. Nulla quis sem at nibh elementum imperdiet. Duis sagittis ipsum. Praesent mauris. Fusce nec tellus sed augue semper porta. Mauris massa. Vestibulum lacinia arcu eget nulla.", false};

    // Task in vector

    tasks.push_back(exampleTask);
    tasks.push_back(exampleTask2);

    cout << "\n\n";
    cout << "Welcome to your task manager \n";
    cout << "---------------------------\n";
    cout << "Your tasks \n";

    printTask(exampleTask);
    printTask(exampleTask2);

    cout << "\n \n";

    char command;
    cout << "Choose a command and type it\n"
            "================================\n"
            "a - add a task\n"
            "c - complete\n"
            "v - display a task's discription\n"
            "d - delete a task\n"
            "t - list tasks\n"
            "q - quit\n"
            "================================"
    << endl;
  while (true) {
        cout << "Enter command (a: add, c: complete, v: view, d: delete, t: list tasks ,q: quit): ";
        cin >> command;
        cin.ignore();

        switch (command) {
            case 'a': {
                string taskName, taskDescription;

                cout << "Enter task name: ";
                getline(cin, taskName);
                cout << "Enter task description: ";
                getline(cin, taskDescription);

                if (!taskName.empty() && !taskDescription.empty()) {
                    int id = tasks.back().id + 1;
                    Task newTask = {id, taskName, taskDescription, false};
                    tasks.push_back(newTask);
                } else {
                    cout << "Invalid input. Task name and description must not be empty." << endl;
                }
                break;
            }
            case 'c': {
                cout << command << endl;
                // Complete a task
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
                    cout << "Task deleted successfully. Type 't' to see all tasksd" << endl;
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
    }

    return 0;
}

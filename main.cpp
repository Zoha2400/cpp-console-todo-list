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

    vector<Task> tasks;

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
            "================================"
    << endl;

    cin >> command;
    cout << command;

    switch(command) {
        case 'a':
            cout << command;
            // Add a new task
            break;
        case 'c':
            cout << command;
            // Complete a task
            break;
        case 'v':
            cout << "================================\n"
                    "Type the id of your task"
            << endl;
            int id;
            cin >> id;

            for(int i = 0; i < tasks.size(); i++) {
                if(tasks[i].id == id) {
                    cout << "Your task description:\n";
                    cout << tasks[i].description << endl;
                    break;
                }
            }
            // View a task's description
            break;
        case 'd':
            cout << command;
            // Delete a task
            break;
        default:
            cout << "Invalid command. Please try again." << endl;
    }

    return 0;
}

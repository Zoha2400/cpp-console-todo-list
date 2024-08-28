#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "command_function.h"

using namespace std;




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

        int start_commands =  task_switching(command);

        if(start_commands == 0) {
            return 0;
        }

    }

    return 0;
}

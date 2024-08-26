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


    printTask(exampleTask);
    printTask(exampleTask2);

    return 0;
}

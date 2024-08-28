//
// Created by Zoxir on 8/29/2024.
//

#ifndef COMMAND_FUNCTION_H
#define COMMAND_FUNCTION_H

#include <string>
#include <vector>

using namespace std;

struct Task {
    int id;
    string name;
    string description;
    bool isCompleted;
};

extern vector<Task> tasks;

int task_switching(char command);
void printTask(const Task& task);

#endif //COMMAND_FUNCTION_H

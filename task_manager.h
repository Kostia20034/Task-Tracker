#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include <task.h>
#include <vector>
#include <string>
/*Load tasks from file

Save tasks to file

Add a task

Delete a task

Mark task as done / in-progress

List tasks (all / by status)

Generate unique IDs*/
using namespace std;

class TaskManager{

private:
  vector<Task> tasks;
  string fileName;
  void loadFromFile();
  void saveToFile();
public:
  TaskManager(const string &userFileName);
  void addTask(const string &taskContent);
  void listAll();
};

#endif
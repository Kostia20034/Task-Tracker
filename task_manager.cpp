#include <task_manager.h>
#include <task.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

TaskManager::TaskManager(const string &userfileName){
fileName = userfileName;
}
// read every line from the file separate variable create task and put it into the vector
void TaskManager::loadFromFile(){

}
//save the whole vector to the file line by line
void TaskManager::saveToFile(){

}
// add 1 task to the vector and then to the file ;
void TaskManager::addTask(const string &taskContent){
  loadFromFile(); // bc u need whole vector to get the unique index 
  Task task(tasks.size() + 1,taskContent);
  tasks.push_back(task);
  saveToFile();
}


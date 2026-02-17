#include "task_manager.h"
#include "task.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
    Status stringToEnum(const string &str){
      Status st;
      if(str == "ToDo"){return Status::Todo;}
      if(str == "InProgress"){return Status::InProgress;}
      return Status::Done;
    }
    string statusToString(Status st){
      if(st == Status::Done){return "Done";}
      if(st == Status::InProgress){return "InProgress";}
      return "ToDo";
    }
TaskManager::TaskManager(const string &userfileName){
fileName = userfileName;
loadFromFile();
}
// read every line from the file separate variable create task and put it into the vector
void TaskManager::loadFromFile(){
    ifstream FILE(fileName);

    if(!FILE.is_open()){
      cout << "file is not found" << endl;
      return;
    }
    if (FILE.peek() == EOF) return;

    json j;
    // try to download whole file to the json object;
    try{
      FILE >> j;
    }
    catch(json::parse_error& e){
      cout << "Error parsing JSON" << e.what() << endl;
      return;
    }
    // if (!j.is_array()) {
    //     cout << "JSON root is not an array. Starting with empty tasks.\n";
    //     return;
    // }
    tasks.clear();  // clean the array actualy no need bc every time program is restarted;
    // json obj is like a map so u just retrieve each key value and create new task from it ez;
    for(auto& item : j){
      int id = item["id"];
        string desc = item["description"];
        string createdAt = item["createdAt"];
        string updatedAt = item["updatedAt"];
        Status st = stringToEnum(item["status"]);
        tasks.push_back(Task(id, desc, createdAt, updatedAt, st));
    }
}
//save the whole vector to the file as key value pair
void TaskManager::saveToFile(){
  json j = json::array();

  for(auto & t1 : tasks){
  j.push_back({
    {"id",t1.getId()},
    {"description", t1.getDescription()},
    {"status", statusToString(t1.getStatus())},
    {"createdAt", t1.getCreationTime()},
    {"updatedAt", t1.getUpdateTime()}
  });
  }

    ofstream FILE(fileName);
  
    if(!FILE.is_open()){
      cout << "Cannot open file to save tasks" << endl;
      return;
    }
    FILE << j.dump(3);
}
// add 1 task to the vector and then to the file ;
void TaskManager::addTask(const string &taskContent){
  Task task(tasks.size() + 1,taskContent);
  tasks.push_back(task);
  saveToFile();
}
void TaskManager::TaskToString(Task t){
  cout << t.getId() << ": " 
             << t.getDescription() 
             << " [" << statusToString(t.getStatus()) << "]"
             << " Created: " << t.getCreationTime()
             << " Updated: " << t.getUpdateTime()
             << endl;
}
void TaskManager::listAll(){
  for(auto& t1 : tasks){
    TaskToString(t1);
  }
}

void TaskManager::deleteTask(int id){
  for(int i = 0; i < tasks.size(); i++){
    if(tasks[i].getId() == id){
       TaskToString(tasks[i]);
       cout << "was succesfully removed" << endl;
      tasks.erase(tasks.begin() + i);
      saveToFile();
      return;
    }
  }
  cout << "Task was not found" << endl;
}

void TaskManager::markTaskStatus(int id, string s){
  loadFromFile();
  for(auto& t : tasks){

    if(t.getId() == id){
      if(s == "Done"){
        t.markDone();
      }
      else{
        t.markInProgress();
      }
      TaskToString(t);
      cout  << "was succesfully modified" << endl;
      saveToFile();
      return;
    }
  }
  cout << "Task was not found" << endl;
}


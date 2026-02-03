#include "task_manager.h"
#include "task.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
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
}
// read every line from the file separate variable create task and put it into the vector
void TaskManager::loadFromFile(){
    ifstream FILE(fileName);

    if(!FILE.is_open()){
      cout << "file is not found" << endl;
      return;
    }

    string line;
    string sid, content, currTime, updateTime, status;
    while(getline(FILE,line)){
      stringstream ss(line);
      // need one more for status;
      getline(ss,sid,'|');
      getline(ss,content,'|');
      getline(ss,status,'|');
      getline(ss,currTime,'|');
      getline(ss,updateTime,'|');

      int id = stoi(sid);
      Status st = stringToEnum(status); 
      Task t1(id,content,currTime,updateTime,st);
      tasks.push_back(t1);
    }
}
//save the whole vector to the file line by line
void TaskManager::saveToFile(){
  ofstream FILE(fileName);
  
  if(!FILE.is_open()){
    return;
  }
  // need one more for status
  for(auto & t1 : tasks){
  FILE << t1.getId() << '|' << t1.getDescription() << '|' << statusToString(t1.getStatus()) << '|' << t1.getCreationTime() << '|' << t1.getUpdateTime() << endl;
  }
}
// add 1 task to the vector and then to the file ;
void TaskManager::addTask(const string &taskContent){
  loadFromFile(); // bc u need whole vector to get the unique index 
  Task task(tasks.size() + 1,taskContent);
  tasks.push_back(task);
  saveToFile();
}


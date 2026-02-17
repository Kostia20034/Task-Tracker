#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
#include "task.h"
#include "task_manager.h"

int main(int argc, char* argv[]){
  TaskManager taskManager("tasks.json");
  stringstream SS;
  string taskName;
  // ou shit i need function that will add task to the file;
      if(argc >= 2){
        if(strcmp(argv[1],"add") == 0){
          for(int i = 2; i < argc - 1; i++){
            SS << argv[i] << " ";
          }
          SS << argv[argc-1];
          string taskName = SS.str();
          taskManager.addTask(taskName);
          cout << "Nice";
        }
        else if(strcmp(argv[1], "list") == 0){
          taskManager.listAll();
        }
        else if(strcmp(argv[1], "delete") == 0){
          taskManager.deleteTask(stoi(argv[2]));
        }
        else if(strcmp(argv[1], "modify") == 0){
          taskManager.markTaskStatus(stoi(argv[2]), argv[3]);
        }
      }
      return 0;
}
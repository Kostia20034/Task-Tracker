#include <iostream>
#include <cstring>
using namespace std;
#include "task.h"
#include "task_manager.h"

int main(int argc, char* argv[]){
  TaskManager taskManager("tasks.txt");
  // ou shit i need function that will add task to the file;
      if(argc > 2){
        if(strcmp(argv[1],"add") == 0){
          taskManager.addTask(argv[2]);
          cout << "Nice";
        }
      }
      return 0;
}
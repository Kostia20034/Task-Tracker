#include <string>
#include <ctime>
using namespace std;
#include "task.h"
    string getCurrentTime(){
      time_t now = time(nullptr);
      string sttime = ctime(&now);
      sttime.pop_back(); 
      return sttime;
    }
    Task::Task(int userId, const string &userDescription){
      id = userId;
      description = userDescription;
      status = Status::Todo;
      createdAt = getCurrentTime();
      updatedAt = createdAt;
    }
    // constractor to load tasks from file
    Task::Task(int userId, const string &userDescription, const string &createTime, const string &updateTime, Status fileStatus){
      id = userId;
      description = userDescription;
      createdAt = createTime;
      updatedAt = updateTime;
      status = fileStatus;
    }
    int Task::getId() const { return id;}
    Status Task::getStatus() const { return status;}
    string Task::getDescription() const { return description;}
    string Task::getCreationTime() const { return createdAt;}
    string Task::getUpdateTime() const{ return updatedAt;}
    void Task::updateDescription(const string &userDescription){
      description = userDescription;
      updatedAt = getCurrentTime();
    }
    void Task::markInProgress(){
      status = Status::InProgress;
      updatedAt = getCurrentTime();
    }
    void Task::markDone(){
      status = Status::Done;
      updatedAt = getCurrentTime();
    }




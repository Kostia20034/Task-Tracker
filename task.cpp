#include <string>
#include <ctime>
using namespace std;
#include <task.h>
    string getCurrentTime(){
      time_t now = time(nullptr);
      return ctime(&now);
    }
    Task::Task(int userId, const string &userDescription = ""){
      description = userDescription;
      status = Status::Todo;
      createdAt = getCurrentTime();
      updatedAt = createdAt;
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




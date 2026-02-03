#ifndef TASK_H
#define TASK_H
#include <string>
#include <ctime>
using namespace std;
enum class Status{ Todo, InProgress, Done};
class Task{
private:
    int id;
    string description;
    Status status;
    string createdAt;
    string updatedAt;
// initial constructor set status 
public: 
    //constructor;
    Task(int userId, const string &userDescription = "");
    //getter
    int getId() const;
    Status getStatus() const;
    string getDescription() const;
    string getCreationTime() const;
    string getUpdateTime() const;

    //modifiers;
    void updateDescription(const string &userDescription);
    void markInProgress();
    void markDone();

    
    // Helper has to implement
    string statusToString() const;
};

#endif
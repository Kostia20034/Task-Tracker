# Task Tracker

A command-line task management tool built in C++ for organizing and tracking daily tasks with persistent storage.

## Features
- Create, update, and delete tasks
- Mark tasks as complete or in-progress
- Persistent storage via local file (tasks.txt)
- Clean modular architecture with separate task and manager classes

## Tech Stack
- Language: C++
- Concepts: OOP, file I/O, data structures
- Tools: Git, VS Code

## What I Built
I designed this project from scratch to practice real-world C++ application structure. The codebase is split into logical modules — `task.h/cpp` handles individual task objects, and `task_manager.h/cpp` handles the collection and operations. Data persists between runs using file I/O.

## How to Run
```bash
git clone https://github.com/Kostia20034/Task-Tracker
cd Task-Tracker
g++ main.cpp task.cpp task_manager.cpp -o task_manager
./task_manager
```

## What I Learned
- Structuring a multi-file C++ project
- Managing state with file persistence
- Designing clean interfaces between classes

## Contact
- Email: kostiantyn_pa@gmail.com
- LinkedIn: https://www.linkedin.com/in/kostiantynpavlyshyn/

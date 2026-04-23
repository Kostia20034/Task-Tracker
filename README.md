# 🚀 C++ Task Tracker CLI

A high-performance command-line productivity tool built in C++. This application manages daily workflows using local JSON persistence and features a professional terminal interface with real-time status tracking.

---

## 🖥️ Usage Demo
The application features a built-in help menu to ensure a smooth user experience. If run without arguments, it guides the user through available commands:

![Task Tracker Menu](image_fc0ee3.png)

### Quick Examples:
```bash
# 1. Add a new task
$ ./task_manager add "Complete GitHub README"

# 2. List all current tasks with timestamps
$ ./task_manager list

# 3. Update a task status (Todo, InProgress, Done)
$ ./task_manager modify 1 InProgress

# 4. Remove a task
$ ./task_manager delete 1
✨ Key Features

Professional CLI Menu: Guided user experience with built-in input validation.


JSON Persistence: Uses nlohmann/json to save and load tasks from tasks.json, ensuring data survives between sessions.

Automated Timestamps: Automatically records "Created" and "Updated" times for every task entry.

Error Handling: Robust checks for missing arguments or invalid IDs to prevent runtime crashes.

🛠️ Technical Stack
Language: C++17

Persistence: JSON Data Format

Tools: G++, Git, Linux/Unix Terminal

🧠 What I Learned
By building this project, I demonstrated the following engineering competencies:


Object-Oriented Design: Developed a modular architecture using Task and TaskManager classes for clean, maintainable code.

Data Integrity: Implemented logic to handle unique IDs and consistent state transitions (Todo → InProgress → Done).


User-Centric Engineering: Focused on a descriptive "Help" system to make the tool intuitive for technical and non-technical users alike.


🧪 Installation & Setup
Clone the repository:

Bash

git clone [https://github.com/Kostia20034/Task-Tracker.git](https://github.com/Kostia20034/Task-Tracker.git)
cd Task-Tracker
Compile the source:

Bash

g++ -o task_manager main.cpp task.cpp task_manager.cpp
Run the app:

Bash

./task_manager


Copied from: GitHub Profile Enhancement Guide - Google Gemini - <https://gemini.google.com/app/ec9d56894424e5f6>

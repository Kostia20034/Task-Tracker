 🚀 C++ Task Tracker CLI

A high-performance command-line tool for managing daily workflows. Built with C++17, it features local JSON persistence and a clean, logic-driven interface.

---

## 🖥️ Usage Demo
The application automatically displays a help menu to guide the user:

![Task Tracker Menu](image_fc0ee3.png)

### Quick Commands:
```bash
$./task_manager add "Finish Project"  # Add task$ ./task_manager list                 # View all
$./task_manager modify 1 Done        # Update status$ ./task_manager delete 1             # Remove task
✨ Highlights
Data Persistence: Uses nlohmann/json to ensure tasks survive between sessions.

Smart Tracking: Automatically logs Created and Updated timestamps for every entry.

Robust Logic: Handles input validation and error messaging to prevent runtime crashes.

Clean Architecture: Modular C++ design using separate classes for Tasks and Management.

🧠 Engineering Takeaways
OOP Mastery: Managed complex states (Todo/InProgress/Done) using enums and class methods.

File I/O: Gained experience in parsing and writing structured data (JSON) in C++.

UX Focus: Designed a CLI that provides immediate feedback and error guidance.

🧪 Setup
Bash

# Clone & Compile
git clone [https://github.com/Kostia20034/Task-Tracker.git](https://github.com/Kostia20034/Task-Tracker.git)
cd Task-Tracker
g++ -o task_manager main.cpp task.cpp task_manager.cpp

# Run
./task_manager


Copied from: GitHub Profile Enhancement Guide - Google Gemini - <https://gemini.google.com/app/ec9d56894424e5f6>

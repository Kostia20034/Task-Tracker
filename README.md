🖥️ C++ Task Tracker CLI
A high-performance command-line task manager built with C++17.
It provides local JSON persistence and a clean, logic-driven interface for managing daily workflows efficiently.

🚀 Features
📦 Persistent Storage – Tasks are saved locally using nlohmann/json, so nothing is lost between sessions
🧠 Smart Tracking – Automatically records Created and Updated timestamps
⚡ Robust Logic – Input validation + error handling to prevent crashes
🏗️ Clean Architecture – Modular design with separate Task and Manager classes
🎯 Simple CLI UX – Fast, minimal, and intuitive command structure
🖥️ Usage Demo
The application starts with an interactive help menu:

Task Tracker Menu

⚡ Quick Commands
# Add a task
./task_manager add "Finish Project"

# List all tasks
./task_manager list

# Modify task status
./task_manager modify 1 Done

# Delete task
./task_manager delete 1
🧠 Engineering Takeaways
Object-Oriented Design (OOP)
Modeled task states (Todo, InProgress, Done) using enums and class methods.
File I/O & Serialization
Worked with structured JSON data for persistent storage.
System Design Thinking
Separated concerns between logic (Task) and control (TaskManager).
User Experience Focus
Built a CLI that gives immediate feedback and clear error messages.
🧪 Setup
# Clone repository
git clone https://github.com/Kostia20034/Task-Tracker.git
cd Task-Tracker

# Compile
g++ -std=c++17 -o task_manager main.cpp task.cpp task_manager.cpp

# Run
./task_manager

# RTOS-Based-File-System-Monitor-in-C

## 🔍 Overview
This project simulates a real-time operating system (RTOS) behavior using C programming for Windows environments. It mimics a firmware-level system reacting to real-world events—here, file system changes. It uses WinAPI and multithreading to create concurrent tasks similar to embedded RTOS threads.

## 🎯 Project Goals
- Demonstrate C-level firmware logic in real-time settings.
- Emulate RTOS principles like task prioritization, preemption, and mutex-based protection.
- Run entirely on Windows with no hardware or microcontroller dependency.

## 🛠️ Key Features
- **Multithreaded RTOS Simulation**: Tasks with distinct priorities using `CreateThread`.
- **Real-Time File Monitoring**: File events caught using `ReadDirectoryChangesW`.
- **Mutex-Protected Logging**: Safe event logging using `CreateMutex`.
- **Thread-safe Console Output**: Clean debugging display using WinAPI.

## 💾 Requirements
- Windows OS (tested on Windows 10+)
- GCC via MinGW or MSVC compiler

## 🚀 Getting Started
1. Compile:
   ```bash
   gcc src/*.c -o build/RTOS_Monitor.exe -lws2_32
   ```
2. Run the program and trigger file changes in the current directory.
3. Check `logs/fs_events.log` for output.

## 📊 RTOS Task Diagram
```
 +------------------+           +--------------------+
 | File Watcher     |--------->| Signals Logger Task |
 | (High Priority)  |           +--------------------+
 +------------------+                     |
                                          v
                                 +----------------------+
                                 | Logs File Changes     |
                                 +----------------------+
```

## 🧪 Unit Test Suggestions

File: `tests/test_logger.c`
```c
#include "../include/rtos.h"
#include <assert.h>

int main() {
    init_logger();
    log_event("Unit test log entry.");
    shutdown_logger();
    printf("Logger test passed.\n");
    return 0;
}
```

## 📁 Folder Structure
```
RTOS_FileSystem_Monitor/
├── include/
├── src/
├── logs/
├── build/
└── README.md
```

## 🧠 Author
**Nikita Sinha** – M.S. in Electrical and Computer Engineering, Firmware Specialist  


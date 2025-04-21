
#include "rtos.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>

DWORD WINAPI logger_task(LPVOID lpParam) {
    while (1) {
        log_event("Logger Task Alive");
        Sleep(3000);
    }
    return 0;
}

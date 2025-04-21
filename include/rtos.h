
#ifndef RTOS_H
#define RTOS_H

#include <windows.h>

typedef struct {
    HANDLE threadHandle;
    DWORD threadId;
    int priority;
    const char* name;
} RTOSTask;

void create_task(RTOSTask* task, LPTHREAD_START_ROUTINE func, int priority, const char* name);
void log_event(const char* message);
void init_logger();
void shutdown_logger();

#endif

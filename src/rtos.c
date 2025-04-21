
#include "rtos.h"
#include <stdio.h>
#include <stdlib.h>

HANDLE logFileMutex;
FILE* logFile;

void create_task(RTOSTask* task, LPTHREAD_START_ROUTINE func, int priority, const char* name) {
    task->name = name;
    task->priority = priority;
    task->threadHandle = CreateThread(NULL, 0, func, NULL, 0, &task->threadId);
    SetThreadPriority(task->threadHandle, priority);
}

void init_logger() {
    logFile = fopen("logs/fs_events.log", "a");
    if (!logFile) {
        printf("Error opening log file!\n");
        exit(1);
    }
    logFileMutex = CreateMutex(NULL, FALSE, NULL);
}

void log_event(const char* message) {
    WaitForSingleObject(logFileMutex, INFINITE);
    fprintf(logFile, "%s\n", message);
    fflush(logFile);
    ReleaseMutex(logFileMutex);
}

void shutdown_logger() {
    fclose(logFile);
    CloseHandle(logFileMutex);
}

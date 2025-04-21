
#include "rtos.h"
#include <windows.h>
#include <stdio.h>

DWORD WINAPI file_watch_task(LPVOID lpParam) {
    char buffer[1024];
    DWORD bytesReturned;
    HANDLE dirHandle = CreateFile(
        ".", FILE_LIST_DIRECTORY,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL, OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED,
        NULL
    );

    if (dirHandle == INVALID_HANDLE_VALUE) {
        log_event("Error opening directory handle.");
        return 1;
    }

    while (1) {
        ReadDirectoryChangesW(dirHandle, &buffer, sizeof(buffer), TRUE,
            FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME |
            FILE_NOTIFY_CHANGE_LAST_WRITE, &bytesReturned, NULL, NULL);

        log_event("Filesystem change detected.");
        Sleep(100);
    }
    return 0;
}

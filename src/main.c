
#include "rtos.h"

int main() {
    RTOSTask fileWatcher, logger;

    init_logger();
    create_task(&fileWatcher, file_watch_task, THREAD_PRIORITY_HIGHEST, "FileWatcher");
    create_task(&logger, logger_task, THREAD_PRIORITY_NORMAL, "Logger");

    while (1) {
        Sleep(10000);
    }

    shutdown_logger();
    return 0;
}

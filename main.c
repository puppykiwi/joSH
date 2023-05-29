#include "mwendwa.h"

#define MAX_HISTORY_SIZE 10
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char commands[MAX_HISTORY_SIZE][MAX_COMMAND_LENGTH];
    int start;
    int count;
} CommandHistory;

void initCommandHistory(CommandHistory* history) {
    memset(history->commands, 0, sizeof(history->commands));
    history->start = 0;
    history->count = 0;
}

void addCommand(CommandHistory* history, const char* command) {
    int index = (history->start + history->count) % MAX_HISTORY_SIZE;
    strncpy(history->commands[index], command, MAX_COMMAND_LENGTH - 1);
    history->commands[index][MAX_COMMAND_LENGTH - 1] = '\0';
    
    if (history->count < MAX_HISTORY_SIZE) {
        history->count++;
    } else {
        history->start = (history->start + 1) % MAX_HISTORY_SIZE;
    }
}

void printCommandHistory(const CommandHistory* history) {
    int index = history->start;
    for (int i = 0; i < history->count; i++) {
        printf("%s\n", history->commands[index]);
        index = (index + 1) % MAX_HISTORY_SIZE;
    }
}

int main() {
    CommandHistory history;
    initCommandHistory(&history);
    
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';  // Remove newline character
        
        if (strcmp(command, "exit") == 0) {
            break;
        }
        
        addCommand(&history, command);
        printf("Command history:\n");
        printCommandHistory(&history);
    }
    
    return 0;
}

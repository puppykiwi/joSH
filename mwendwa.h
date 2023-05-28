#ifndef MWENDWA_H
#define MWENDWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DEFAULT_BUFFER_SIZE 1000
#define MAX_NUM_ARGS 20
#define MAX_ARG_LEN 20
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

// global variables
char* inputBuffer; 
bool prompt = true;
char* args[MAX_NUM_ARGS];

// function prototypes
char* getInput(bool prompt,char* inputBuffer);
void parseInput(char* inputBuffer, char* args[]);
void execute(char* args[]);
void cleanup(void);

//free memory
void cleanup(void){
    free(inputBuffer);
    for (int i = 0; i < MAX_NUM_ARGS; i++){
        free(args[i]);
    }
}

//clear the screen
void clearScreen() {
    printf("\033[2J\033[H"); // ANSI escape code
}

#endif
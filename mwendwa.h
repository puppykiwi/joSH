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

#endif
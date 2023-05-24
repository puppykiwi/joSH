#ifndef MWENDWA_H
#define MWENDWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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

#endif
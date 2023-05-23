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

// return shell input into the buffer
char* getInput(bool prompt,char* inputBuffer){

    // interactive mode
    //while(prompt){
        printf("joSH > ");
        fgets(inputBuffer, DEFAULT_BUFFER_SIZE, stdin);
        if ((strncmp(inputBuffer, "exit", 4) == 0) || (strncmp(inputBuffer, "q", 1) == 0)){prompt = false;}
        else{printf("You entered: %s", inputBuffer);}
    //}
    return inputBuffer;
}

// parse the input buffer into tokens
void parseInput(char* inputBuffer, char* args[]) {
    // Remove newline character
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

    char* token = strtok(inputBuffer, " ");
    int numArgs = 0;

    while (token != NULL && numArgs < MAX_NUM_ARGS - 1) {
        // Allocate memory for each argument
        args[numArgs] = malloc(MAX_ARG_LEN * sizeof(char));
        strncpy(args[numArgs], token, MAX_ARG_LEN - 1);
        args[numArgs][MAX_ARG_LEN - 1] = '\0';

        token = strtok(NULL, " ");
        numArgs++;
    }

    args[numArgs] = NULL; // Set the last element of the args array to NULL for execvp()
}


int main(int argc, char* argv[]){

    inputBuffer = (char*)malloc(sizeof(char) * DEFAULT_BUFFER_SIZE);
    // scanf("%s", inputBuffer); // for testing purposes

    //TODO: Get argv mode to work
    //pass all arguments to the input buffer or enter interactive mode 
    /*
    if (argc < 2){printf("No arguments were passed. \n");}
    else{
        for(int i=0; i < argc; i++){
            char *temp = argv[i];
            fgets(inputBuffer, sizeof(inputBuffer), *temp);
        }
    }
    */
   
    inputBuffer = getInput(prompt, inputBuffer); // return input into the buffer

    parseInput(inputBuffer, args); // parse the input buffer into args[]


    for (int i = 0; args[i] != NULL; i++){
        printf("args[%d]: %s\n",i, args[i]);

    }
    free(inputBuffer);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define DEFAULT_BUFFER_SIZE 1024

char* inputBuffer; 
bool prompt = true;

int main(int argc, char* argv[]){

    inputBuffer = (char*)malloc(sizeof(char) * DEFAULT_BUFFER_SIZE); // initialize the input buffer

    //TODO: implement argv mode
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

   // interactive mode
    while(prompt){
        printf("joSH > ");
        fgets(inputBuffer, DEFAULT_BUFFER_SIZE, stdin);
        if ((strncmp(inputBuffer, "exit", 4) == 0) || (strncmp(inputBuffer, "q", 1) == 0)){prompt = false;}
        else{printf("You entered: %s", inputBuffer);}
    }
    printf("%s", inputBuffer);

}
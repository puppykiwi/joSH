#include "mwendwa.h"

// return shell input into the buffer
char* getInput(bool prompt,char* inputBuffer){
    
    printf("\njoSH > ");
    fgets(inputBuffer, DEFAULT_BUFFER_SIZE, stdin);
    
    //else{printf("You entered: %s", inputBuffer);} // for testing purposes
    if(inputBuffer != NULL){return inputBuffer;}
    else{printf("Error: inputBuffer is NULL\n"); return NULL;}
}

// parse the input buffer into args[]
void parseInput(char* inputBuffer, char* args[]) {
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
    args[numArgs] = NULL;
    
    if (args == NULL) {
        printf("Error: args is NULL\n");
    }
}

// execute the command in args[]
void execute(char* args[]){
    int pid = fork();
    if (pid < 0){fprintf(stderr,"ERROR: Fork failed\n");}

    else if (pid == 0){
        //printf("** Child process created **\n"); // for testing purposes

        if(strncmp(args[0],"cd", 2) == 0){
            if (args[1] == NULL){fprintf(stderr,"ERROR: Dir not found\n");}
            else if(chdir(args[1]) != 0){fprintf(stderr,"ERROR: chdir failed\n");} 
            printf("Directory changed to %s\n", args[1]);
        }

        else if (strncmp(args[0],"exit",4) == 0){
            exit(0);
        }
        
        else{
            if (execvp(args[0], args) < 0);{
                fprintf(stderr,"ERROR: execvp failed\n");
                exit(1);
                }
        }
    }

    else {
        //printf("** Parent process waiting for completion **\n"); // for testing purposes
        wait(NULL);
        //printf("** Child process completed **\n"); // for testing purposes
    }
}

int main(int argc, char* argv[]){
    printf("Welcome to joSH!\n"); //banner

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
    while (prompt){
        inputBuffer = getInput(prompt, inputBuffer); // return input into the buffer
        //if ((strncmp(inputBuffer, "exit", 4) == 0) || (strncmp(inputBuffer, "q", 1) == 0)){prompt = false;}

        parseInput(inputBuffer, args); // parse the input buffer into args[]
        
        execute(args);
    }

    cleanup();
    return 0;
}
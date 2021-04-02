#include "dir_file.h"
#include "utils.h"

int open_file(char* fname, FILE** input) {
    if (access(fname, F_OK) == -1) {
        ERR_PRINT("The '%s' file does not exists\n", fname);
        return -1;
    }

    *input = fopen(fname, "r");
    if (input == NULL) {
        ERR_PRINT("Failed open '%s' file\n", fname);
        return -1;
    }

    return 1;
}

// This parse_str_to_list() split string to the tokens, and put the tokens in token_list.
// The value of return is the number of tokens.

//parse clear
int parse_str_to_list(const char* str, char** token_list) {
    /* Fill this function */
    char temp[MAX_BUFFER_SIZE];
    char temp_s[MAX_BUFFER_SIZE];
    char temp_a[MAX_BUFFER_SIZE];
    int i = 0;
    
    strcpy(temp, str);
    char *ptr = strtok(temp, "/");
    
    while(ptr != NULL){
        strcpy(temp_a, ptr);
        if(strcmp(temp_a, "\n") == 0){
            break;
        }
        token_list[i] = (char*) malloc(sizeof(char*) * MAX_TOKEN_NUM);
        
        strcpy(token_list[i], ptr);
        
        i++;
        ptr = strtok(NULL, "/");
    }
    
    if(ptr == NULL){
        strcpy(temp_s, token_list[i - 1]);
        temp_s[strlen(temp_s) - 1] = '\0';
        strcpy(token_list[i - 1], temp_s);
    }

    return i;
}

void free_token_list(char** token_list, int num_token) {
    int index;

    for (index = 0; index < num_token; index++) {
        free(token_list[index]);
    }

    free(token_list);
}

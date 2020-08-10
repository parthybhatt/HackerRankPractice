#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "testCase.txt"

int main() 
{
    int n;
    FILE* file = fopen(FILE_NAME,"r");
    fscanf(file, "%d", &n);
    size_t len = 0;
    printf("%d", n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        getline((arr+i), &len, file);  //scanf("%s", *(arr + i));
        char* c = strchr(*(arr+i), '\n');
        if(c)
            *c =0;
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
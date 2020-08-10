#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortStrings.h"
#define FILE_NAME "testCase.txt"

int main() 
{
    int n;
    #ifdef FILE_NAME
        FILE* file = fopen(FILE_NAME,"r");
        size_t len = 0;
        fscanf(file, "%d", &n);
        n = n+1;
    #else
        scanf("%d", &n);
    #endif
  
    char** arr;
    arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        #ifdef FILE_NAME
            getline((arr+i), &len, file);
            char* c = strchr(*(arr+i), '\n');
            if(c)
                *c ='\0';
        #else
            scanf("%s", *(arr+i));
        #endif
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    
    #ifdef FILE_NAME
        printf("%d", n);
        for(int i = 0; i < n; i++)
            printf("%s\n", arr[i]);
        printf("\n");
    #endif
    
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
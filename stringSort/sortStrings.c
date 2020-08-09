
#include <string.h>
#include <stdlib.h>
#include "sortStrings.h"

// static functions declaration
static int get_number_of_distinct_chacters(const char* a);

/*
Compares the ascii value of char pointed by a and b
if a is greater(a needs to be later in the array), function returns 1 else returns 0
*/
int lexicographic_sort(const char* a, const char* b)
{
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b)
{
    return strcmp(b,a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b)
{
    int tail = 0;
    if(get_number_of_distinct_chacters(a) > get_number_of_distinct_chacters(b))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int sort_by_length(const char* a, const char* b)
{
    if(strlen(a) > strlen(b))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    int i,j;
    for(j=len-1;j>0;j--)
    {
        for(i=0;i<j;i++)
        {
            if(cmp_func(arr[i], arr[j]) > 0)
            {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

static int get_number_of_distinct_chacters(const char* a)
{
    int tail = 0;
    char* temp = malloc(sizeof(a));
    memset(temp, 0, sizeof(temp));
    
    for(int i = 0; i < strlen(a); i++)
    {
        if(strchr(temp,a[i])==NULL)
        {
            temp[tail]= a[i];
            tail++;
        }
    }

    int distChars = strlen(temp);
    free(temp);
    return distChars;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    False = 0,
    True = 1
} bool;

int factorial(int n);
int calculatePermutations(int n, char **s);
int next_permutation(int n, char **s);

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}

int factorial(int n)
{
    int fact = 1;
    while(n)
    {
        fact *= n;
        n--;
    }
    return fact;
}

int calculatePermutations(int n, char **s)
{
    int nFactorial = factorial(n);
    int noOfPermutations = nFactorial;
    
    int divisor = 1;
    for(int i=0; i<(n-1); i++)
    {
        if(strcmp(*(s+i),*(s+i+1))==0)
        {
            //increment the divisor
            ++divisor;
        }
        //divide the noOfPermutations by divisor
        noOfPermutations = noOfPermutations/factorial(divisor);
        //set the divsor to 1
        divisor = 1;    
    }
    return noOfPermutations;
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    static bool calcPerm = False;
    static int numOfPermutations = 1;    //string will always have atleast one permutation
    static int index = 0;
    
    if(!calcPerm)
    {
        numOfPermutations = calculatePermutations(n, s) - 1;
        calcPerm = True;
    }
    if(numOfPermutations>0)
    {
        int nextIndex = (index+1)%n;
        while(strcmp(*(s+index), *(s+nextIndex))==0)
        {
            index = (index+1)%n;
            nextIndex = (index+1)%n;
        }
        char* temp;
        temp = s[index];
        s[index] = s[nextIndex];
        s[nextIndex] = temp;
        index = (index+1)%n;
        numOfPermutations--;
        return 1;
    }
    else
    {
        return 0;
    }
}

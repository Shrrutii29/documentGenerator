#include <stdio.h>

/*
Factorial function : to calculate the factorial of a number.
function uses recursion to multiply the current number (n)
by the factorial of (n-1) until it reaches the base case.
Note: This function does not handle negative numbers. 
*/
 
int factorial(int n) 
{
    /*Base case: If n is 0 or 1, 'return 1', Recursion stops when n is 1 or below. 
    */
	if (n <= 1) 
	{
		return 1;
    	} 
    	else 
    	{
		/*Recursive case: Multiply n by factorial(n-1), recursion continues until the base case is reached. 
		*/
		return n * factorial(n - 1);
    }
}

/*Main function to demonstrate factorial function, It takes input then calculates and prints the factorial.
 /*Note: Ensure the factorial function works for all positive integers only. */ 
 /*Avoid passing negative values as input, as it is not handled. */
*/

int main() 
{
	int num;
    
    	printf("\nEnter number to calculate factorial : ");
    	scanf("%d",&num);
    
    	int result = factorial(num);

    	printf("Factorial of %d is %d\n", num, result);

    	return 0;
}


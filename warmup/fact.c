#include "common.h"

int fact(int argc, char **args){
	/*Uses recursion to calculate and print the factorial of 
	the positive integer value (e.g., 5, 10, 030) passed in as 
	an argument to the program, or prints the line "Huh?" if no argument is passed in, 
	or if the first argument passed is not a positive integer 
	(e.g., 0, negative value, decimal value, or non-integer value). 
	If the value passed in exceeds 12, it prints "Overflow".*/

	if(argc == 1){

		printf("Huh?\n");
		return 0;

	} else {
		// check if args[1] is an integer i.e. only contains the following chars:
		// digits 0-9, and signs + and -
		int is_int = 1; // true
		int j = 0;
		while (args[1][j] != '\0'){
			if(!((args[1][j] >= '0' && args[1][j] <= '9') || args[1][j] == '+' || args[1][j] == '-')){
				is_int = 0; 
			}
			j++;
		}
		
		int n = atoi(args[1]);
		
		if(n <= 0 || is_int == 0){
			// atoi returns 0 for zero value or for non-numerical values
			
			printf("Huh?\n");
			return 0;

		} else {
			// argv[1] is a positive integer stored as an int in n
			
			if(n > 12){
				printf("Overflow\n");
				return 0;
			} else {
				// calculate factorial recursively

				int fact_recur(int x){
					if(x == 1){
						return 1; 
					} else {
						return x * fact_recur(x - 1);
					}
				}
				
				int res = fact_recur(n);
				printf("%d\n", res);
				return 0;
			}
		}
	}
}

int main(int argc, char **argv)
{
	fact(argc, argv);
	return 0;
}

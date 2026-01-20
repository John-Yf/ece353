#include "common.h"

int fact(int argc, char** args){
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
		int n = atoi(argv[1]);
		if(){

		} else if(n == 0 || n < 0 || ){

		}
	}

}

int main(int argc, char **argv)
{
	fact(argc, argv);
	return 0;
}

#include "common.h"

void words(int n, char **args){
	/* Prints each of the command line arguments on a new line.*/
	for(int i = 1; i < n; i++){
		printf("%s\n", args[i]);
	} 
}

int main(int argc, char **argv)
{
	words(argc, argv);
	return 0;
}

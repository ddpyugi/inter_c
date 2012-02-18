#include "tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <../src/tools.h>

void test_simple()

int main(int argc, char **argv)
{
	if(argc<2) {
		fprintf(stderr, "Miss test number");
		exit(EXIT_SUCCESS);
	}
	switch(atoi(argv[1])) {
	case 1: ;
	default: ;
	}
}



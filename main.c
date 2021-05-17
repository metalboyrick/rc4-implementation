#include "rc4.h"

int main(int argc, char* argv[]){
	if (argc > 1)
		generate_keystream(argv[1]);
	else
		printf("Please supply a key!\n");
	return 0;
}

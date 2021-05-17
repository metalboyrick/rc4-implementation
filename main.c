#include "rc4.h"

int main(int argc, char* argv[]){
	if (argc > 1)
		if(strcmp("-r", argv[1]) == 0)
			generate_random_keystream();
		else
			generate_keystream(argv[1]);
	else
		printf("Please supply a key!\n");
	return 0;
}

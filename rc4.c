#include "rc4.h"

// All lengths in bytes
#define KEY_LEN 128
#define STREAM_LEN 2000

uint8_t S[256]; // the permutation array
uint8_t T[256]; // contains mod results of S, to save time
uint8_t K[KEY_LEN]; // the key
bool random_flag = false;

/*
	Function to generate alphanumeric characters
	@params None
	@return (uint8_t) a single random alphanumeric character
*/
uint8_t gen_alphanum(){
	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    if(!random_flag){
    	srand( (unsigned) time(NULL) * getpid());
    	random_flag = true;
    }
    
    return alphanum[rand() % (sizeof(alphanum) - 1)];
}

/*
	Initialise S and T
*/
void init() {
	
	// initialise S and T
	for(int i = 0 ; i < 255; i++){
		S[i] = i;
		T[i] = K[i % KEY_LEN];
	}

	// scramble S
	int j = 0;
	for(int i = 0; i < 255; i++){
		j = (j + S[i] + T[i]) % 256;

		// swap
		uint8_t temp = S[i];
		S[i] = S[j];
		S[j] = temp;
	}
}

/*
	Interface function
*/
void generate_keystream(char* key){

	for(int i = 0 ; i < KEY_LEN; i++) K[i] = key[i];
	
	init();

	int i = 0, j = 0;
	printf("KEYSTREAM: ");
	for (int k = 0 ; k < STREAM_LEN; k++){
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;

		// swap
		uint8_t temp = S[i];
		S[i] = S[j];
		S[j] = temp;

		uint8_t out_key = S[(S[i] + S[j]) % 256];
		printf("%02x ", out_key);

	}
}
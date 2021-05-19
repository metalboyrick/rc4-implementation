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

	for(int i = 0 ; i < KEY_LEN; i++) K[i] = (uint8_t)key[i];

	uint8_t out_key_arr[STREAM_LEN];
	
	struct timespec start, end;

	// start timer 
	clock_gettime(CLOCK_REALTIME, &start);

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
		out_key_arr[k] = out_key;
	}



	// stop timer
	clock_gettime(CLOCK_REALTIME, &end);

	double time_spent = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / 1000.0;
	double speed = ( 16000 ) / (time_spent);

	for(int n = 0 ; n < STREAM_LEN; n++)
		printf("%02x ", out_key_arr[n]);

	// print the results
	printf("\nEncryption speed: %lf Megabits / second\n", speed);
}

void generate_random_keystream(){
	char random_key[KEY_LEN];

	for (int i = 0; i < KEY_LEN; i++) random_key[i] = gen_alphanum();

	printf("GENERATED KEY: ");
	for (int i = 0; i < KEY_LEN; i++) printf("%02x ", (uint8_t)random_key[i]);

	printf("\n=========================================================\n");
	

	
	generate_keystream(random_key);

	

}
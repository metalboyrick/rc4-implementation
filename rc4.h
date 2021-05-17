#ifndef RC4_H
#define RC4_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

extern void generate_keystream(char* key);
extern void generate_random_keystream();

#endif // RC4_H
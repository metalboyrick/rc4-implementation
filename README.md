# RC4 Implementation

This is a program that can generate RC4 keystream for a 128 byte key. 

# Usage instructions

## System requirements
- gcc 7.5.0
- GNU Make 4.1
- A linux bash

Both can be installed by using:
```
sudo apt install gcc
sudo apt install make
```

## Compiling the program
The program can be compiled by simply running the following command in the Linux Terminal.
```
make
```
If you are using ```cygwin``` or any Windows-based Linux capabilities, you can compile it into a Windows executable with:
```
make windows
```

## Running the program
Simply do :
```
./main.out <arg>
```
or
```
main.exe <arg>
```
- ```<arg>``` has two options:
	- ```-r```: key stream generation with a random 128 byte key.
	- Any 128 byte key.
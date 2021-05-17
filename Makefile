make_rc4: main.o rc4.o
	gcc -g main.o rc4.o -o main.out

windows: main.o rc4.o
	gcc -g main.o rc4.o -o main.exe

main.o: main.c
	gcc -g -c main.c

rc4.o: rc4.h rc4.c 
	gcc -g -c rc4.c

clean:
	rm -f *.out
	rm -f *.o
	rm -f *.exe
	rm -f *.exe.stackdump
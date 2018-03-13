app: main.o openDev.o getChoice.o readDev.o writeDev.o lseekDev.o
	gcc -o app main.o openDev.o getChoice.o readDev.o writeDev.o lseekDev.o

lseekDev.o: lseekDev.c header.h declaration.h
	gcc -c lseekDev.c
readDev.o: readDev.c header.h declaration.h
	gcc -c readDev.c
writeDev.o: writeDev.c header.h declaration.h
	gcc -c writeDev.c
openDev.o: openDev.c header.h declaration.h
	gcc -c openDev.c
getChoice.o: getChoice.c header.h declaration.h
	gcc -c getChoice.c
main.o: main.c header.h declaration.h
	gcc -c main.c

a.exe: grocery3_source.o grocery3_main.o
	gcc grocery3_source.o grocery3_main.o
grocery3_source.o: grocery3_source.c grocery3_header.h
	gcc -c grocery3_source.c
grocery3_main.o: grocery3_main.c grocery3_header.h 
	gcc -c grocery3_main.c

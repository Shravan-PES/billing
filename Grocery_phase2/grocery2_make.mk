a.exe: grocery2_source.o grocery2_main.o
	gcc grocery2_source.o grocery2_main.o
grocery2_source.o: grocery2_source.c grocery2_header.h
	gcc -c grocery2_source.c
grocery2_main.o: grocery2_main.c grocery2_header.h 
	gcc -c grocery2_main.c
a.exe: grocery_source.o grocery_main.o
	gcc grocery_source.o grocery_main.o
grocery_source.o: grocery_source.c grocery_header.h
	gcc -c grocery_source.c
grocery_main.o: grocery_main.c grocery_header.h 
	gcc -c grocery_main.c
a.exe: grocery_main.o grocery_source.o
	gcc grocery_main.o grocery_source.o
grocery_source.o: grocery_source.c grocery_header.h
	gcc -c grocery_source.c
grocery_main.o: grocery_main.c grocery_header.h 
	gcc -c grocery_main.c

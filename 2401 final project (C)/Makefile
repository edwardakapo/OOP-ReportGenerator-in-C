project:	main.o Datalist.o report1.o report2.o report3.o report4.o report5.o
	gcc -o project main.o Datalist.o report1.o report2.o report3.o report4.o report5.o



main.o:	main.c	defs.h
	gcc -c main.c

Datalist.o:	Datalist.c defs.h
	gcc -c Datalist.c

report1.o:	report1.c defs.h
	gcc -c report1.c

report2.o:	report2.c defs.h
	gcc -c report2.c

report3.o:	report3.c defs.h
	gcc -c report3.c

report4.o:	report4.c defs.h
	gcc -c report4.c

report5.o:	report5.c defs.h
	gcc -c report5.c

clean:
	rm -f *.o project

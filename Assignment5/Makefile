dbserver: dbserver.o
	gcc -o dbserver dbserver.o

dbserver.o: dbserver.c dbserver.h
	gcc -c dbserver.c
	
Task4: Task4.o
	gcc -o Task4 Task4.o

Task4.o: Task4.c Task4.h
	gcc -c Task4.c

clean:
	rm -rf *.o dbserver Task4

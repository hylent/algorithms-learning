main:
	gcc hashtable.c -c
	gcc hashtable.o -o hashtable.dll -shared
	gcc main.c -o main -I. -L. -lhashtable

clean:
	del *.o *.dll *.exe

philosophers_dining: philosophers_dining.o
	gcc $(CFLAGS) -pthread -o philosophers_dining philosophers_dining.o

philosophers_dining.o: philosophers_dining.c
	gcc $(CFLAGS) -c philosophers_dining.c

clean:
	rm -rf *.o  philosophers_dining

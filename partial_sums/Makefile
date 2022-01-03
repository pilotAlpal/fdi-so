CFLAGS  = -Wall -g -pthread

part_sum: part_sum.o
	gcc $(CFLAGS) -o part_sum part_sum.o
part_sum.o: part_sum.c
	gcc $(CFLAGS) -c part_sum.c
clean :
	-rm part_sum *.o

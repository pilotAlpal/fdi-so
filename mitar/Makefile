
mitar: mitar.o mitar_routines.o

mitar.o: mitar.c
mitar_routines.o: mitar_routines.c

.PHONY: clean
clean:
	-rm -rf mitar *.o

.PHONY: test
test: mitar test/test_tarball.sh
	-bash test/test_tarball.sh


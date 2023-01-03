CC = GCC
CFLAGS = -g -Wall -ansi -O3
LD = GCC
LDFLAGS = -lm
RM = /bin/rm -f
OBJS = stok1.o mie.o complex.o nrutil.o array.o subroutines.o mcRoutines.o saveDATs.o dataIN.o
PROG = iquv
DAT = *.dat

# top-level rule, to compile everything.
all: $(PROG)

# rule to link the program
$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)

# rule for file "stok1.o".
stok1R.o: stok1R.c
	$(CC) $(CFLAGS) -c stok1.c

# rule for file "mie.o".
mie.o: mie.c
	$(CC) $(CFLAGS) -c mie.c

# rule for file "nrutil.o".
nrutil.o: nrutil.c
	$(CC) $(CFLAGS) -c nrutil.c

# rule for file "complex.o".
complex.o: complex.c
	$(CC) $(CFLAGS) -c complex.c
	
# rule for file "array.o".
array.o: array.c
	$(CC) $(CFLAGS) -c array.c

# rule for file "subroutines.o".
subroutines.o: subroutines.c
	$(CC) $(CFLAGS) -c subroutines.c

# rule for file "mcRoutines.o".
mcRoutines.o: mcRoutines.c
	$(CC) $(CFLAGS) -c mcRoutines.c

# rule for file "saveDATs.o".
saveDATs.o: saveDATs.c
	$(CC) $(CFLAGS) -c saveDATs.c

# rule for file "dataIN.o".
dataIN.o: dataIN.c
	$(CC) $(CFLAGS) -c dataIN.c

# rule for cleaning re-compilable files.
clean:
	$(RM) $(PROG) $(OBJS)

# rule for cleaning data files
clean_dat:
	$(RM) $(DAT)

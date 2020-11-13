SRC=main.c other.c
OBJ=main.o other.o
PROG=main
HEADERS_PATH=/Users/hungly/VisualStudioCodeProjects/Advanced-C-Course/headers
CC=gcc
main:
	$(CC) $(SRC) -I $(HEADERS_PATH) -o $(PROG)

extern-c:
	$(CC) extern-var.c foo.c -o extern.var

clean:
	$(RM) main
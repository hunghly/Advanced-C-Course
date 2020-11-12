# comment
# (note: the <tab> in the command line is necessary for make to work)

SRC=main.c other.c
OBJ=main.o other.o
PROG=main
HEADERS_PATH=/Users/hungly/VisualStudioCodeProjects/Advanced-C-Course/headers
CC=gcc
main:
	$(CC) $(SRC) -I $(HEADERS_PATH) -o $(PROG)

# for example:
# #
# # target entry to build program executable from program and mylib 
# # object files 
# #
# program: program.o mylib.o
# 	gcc -o program program.o mylib.o
clean:
	$(RM) main
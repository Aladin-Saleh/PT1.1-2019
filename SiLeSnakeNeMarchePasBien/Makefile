CC = gcc



snake : programmeDeSecoursSiMakefileMarchePas.o
	$(CC) -o snake programmeDeSecoursSiMakefileMarchePas.o -lgraph


programmeDeSecoursSiMakefileMarchePas.o : programmeDeSecoursSiMakefileMarchePas.c
	$(CC) -o programmeDeSecoursSiMakefileMarchePas.o -c programmeDeSecoursSiMakefileMarchePas.c -lgraph





clean: 
	rm -rf *.o


cleanall: clean
	rm -rf snake

run : snake
	./snake 

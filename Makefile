PROJECT_NAME=socketcanx
CC=gcc

SOURCES=canxsend.c x/can/lib.c

all:
	$(CC) -o $(PROJECT_NAME) $(SOURCES) -Ix

clean:
	rm -f $(PROJECT_NAME) *.o

CC = g++

BIN_DIR = ../lib
BIN = $(BIN_DIR)/libthecore.a
INCLUDE = ../include
CFLAGS = -Wall -O2 -w -pipe -g -I$(INCLUDE)

LIBS = 

OBJFILES = socket.o fdwatch.o buffer.o signal.o log.o utils.o \
	kstbl.o hangul.o heart.o main.o tea.o des.o gost.o memcpy.o

default:
	$(MAKE) $(BIN)

$(BIN): $(OBJFILES)
	if [ ! -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

dep:
	$(CC) $(CFLAGS) -MM *.c > Depend

$(OBJFILES):
	$(CC) $(CFLAGS) -c $<

memcpy: memcpy.o utils.o log.o
	$(CC) $(CFLAGS) -c -D__MAIN__ memcpy.c
	$(CC) $(CFLAGS) -o memcpy memcpy.o utils.o log.o

include Depend

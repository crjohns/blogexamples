OBJS := likes

CC ?= gcc
CFLAGS = -g -lpthread -std=c99


all: $(OBJS)

clean:
	rm -f $(OBJS) *.o

$(OBJS) : %: %.o
	$(CC) $< -o $@

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

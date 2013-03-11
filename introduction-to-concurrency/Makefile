OBJS := likes likes-lock likes-atomic

CC ?= gcc
CFLAGS = -g -std=c99
LDFLAGS = -lpthread


all: $(OBJS)

clean:
	rm -f $(OBJS) *.o

$(OBJS) : %: %.o
	$(CC) $< -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

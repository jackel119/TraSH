CC      = gcc
CFLAGS  = -Wall -g -D_DEFAULT_SOURCE -std=c99 -Werror -pedantic -Iinclude

SOURCES = $(shell find $(basedir) -name '*.c') $(shell find ../utils -name '*.c')
OBJECTS = $(addprefix $(objdir)/, $(SOURCES:.c=.o))
HEADERS = $(shell find $(basedir) -name '*.h')

basedir = .
objdir 	= ../out/emulator

.SUFFIXES: .c .o

.PHONY: all clean

all: ../trash

../shell: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(objdir):
	$(MKDIR_P) $(objdir)

$(objdir)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(objdir)
	rm -f ../trash
	rm -f $(wildcard *.bin)

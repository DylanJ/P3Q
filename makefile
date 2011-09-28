CC=g++
CPPFLAGS=-Wall -Wextra -Wformat

MAINBIN=p3q
MAINLIBS=-pthread -llua
TESTBIN=test
TESTLIBS=-lcppunit -ldl
OBJDIR=obj
OUTDIR=bin

vpath %.cpp src tests
vpath %.h src tests

MAINOBJS = $(addprefix $(OBJDIR)/, Main.o Bot.o)
TESTOBJS = $(addprefix $(OBJDIR)/, Tests.o BotTest.o)

MAINHEADERS = $(Bot.h)
TESTHEADERS = $($(MAINHEADERS) BotTest.h)

all: bin test

bin: $(MAINOBJS)
	$(CC) $(CPPFLAGS) -g -o $(OUTDIR)/$(MAINBIN) $(MAINOBJS) $(MAINLIBS)

test: $(TESTOBJS)
	$(CC) $(CPPFLAGS) -g -o $(OUTDIR)/$(TESTBIN) $(TESTOBJS) $(TESTLIBS)

obj/%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -g -Isrc/ -o $@ $<

.PHONY: setup clean

setup:
	mkdir bin
	mkdir obj

clean:
	rm $(OBJDIR)/*
	rm $(OUTDIR)/$(MAINBIN)
	rm $(OUTDIR)/$(TESTBIN)


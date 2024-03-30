# Compiler flags. -g for debug, -03 for optimization
CFLAGS=-g -03

# First target is built by default
all: tokenizer

# Include file dependencies
history.o: history.h
tokenizer.o: tokenizer.h

#build tokenizer executable
tokenizer: history.o tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

#Compile uimain.c
uimain.o: uimain.c tokenizer.h
	cc -o $@ -c $< $(CFLAGS)

#Clean Up
clean:
	rm -f *.o tokenizer
run:
	./tokenizer


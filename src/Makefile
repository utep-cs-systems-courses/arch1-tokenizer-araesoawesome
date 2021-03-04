#Making files :D
all:uimain

#Creamof crab
uimain: uimain.o tokenizer.o history.o
	gcc -o uimain uimain.o tokenizer.o history.o

uimain.o:uimain.c history.h tokenizer.h

#bruh
tokenizer.o:tokenizer.h tokenizer.c

history.o:history.h history.c

clean:
	-rm *.o
	-rm *~
	-rm *.c#
	-rm uimain


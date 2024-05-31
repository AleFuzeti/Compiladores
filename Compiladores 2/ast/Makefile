FLEX=flex
BISON=bison
CC=gcc
CFLAGS=
LIBS=

PROGRAMA = dcmat
LEXICO = lexico.l
SINTATICO = sintatico.y

CC_FLAGS = -std=c99					\
		   -I.						\
		   -w						\
		   -lm

$(PROGRAMA): $(LEXICO) $(SINTATICO)
	$(FLEX) $(LEXICO)
	$(BISON) -d $(SINTATICO)
	$(CC) *.c $(CC_FLAGS) -o $(PROGRAMA)

clean:
	rm -f sintatico.tab.c sintatico.tab.h lex.yy.c $(PROGRAMA) 
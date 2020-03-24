.PHONY: ALL clean hangman
CC = gcc -Wall -masm=intel
debug += -g
noOpt += -O0
common_CC = $(CC) $(debug) $(noOpt)

ALL: hangman

%.o: %.c
	$(common_CC) -c $<

hangman: hangman.c cy_libs.c
	$(common_CC) -o $@ $^

clean:
	$(RM) *.o
	$(RM) hangman

# COMMENTS
# $@ target variable
# $< first dependency variable
# $^ all dependencies variable

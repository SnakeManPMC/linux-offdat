#
# Makefile --- pmcdsz log datafile (c) PMC 1999 - 2015
#

CC	= gcc
LIBDIR = /home/bbs/lib/
MAINDIR = /home/bbs/main/

CFLAGS = -I$(MAINDIR) -I$(LIBDIR) -DUNIX -Wall -pipe -fomit-frame-pointer

LIBS	= 

all:		log

clean:          rm log offdat

log:        	log.c
	        $(CC) -o $@ $<

offdat:        	offdat.c
	        $(CC) $(CFLAGS) -o $@ $< -L$(LIBDIR) -ldd

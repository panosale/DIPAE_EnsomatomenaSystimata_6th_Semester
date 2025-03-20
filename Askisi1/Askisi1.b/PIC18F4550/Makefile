###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = PIC18F4550
COMPILER = "CCS for PIC"
TARGET = Release
SHELL = C:\Windows\system32\cmd.exe

## Tools general options
CCFLAGS=-J +DF +ES -P -Z +O8 +CC +EXPORT +FH
LDFLAGS=-J -D +ES -P -Z +O8 +CC +FH

## Processing Tools
CC=ccsc.exe
LD=ccsc.exe
#  F:/Common/Programming/GitHub/DIPAE_EnsomatomenaSistimata_6th_Term/Askisi1.b/PIC18F4550/Release.hex: TOOL=LD
#     F:/Common/Programming/GitHub/DIPAE_EnsomatomenaSistimata_6th_Term/Askisi1.b/PIC18F4550/./main.o: TOOL=CC
#        F:/Common/Programming/GitHub/DIPAE_EnsomatomenaSistimata_6th_Term/Askisi1.b/PIC18F4550/main.c

# Build tree:
all:	Release

Release:	Release.hex
	cp "Release.hex" "F:/Common/Programming/GitHub/DIPAE_EnsomatomenaSistimata_6th_Term/Askisi1.b/PIC18F4550.hex"

Release.hex:	main.o 
	$(LD) $(LDFLAGS)  LINK="Release.hex=main.o"

main.o:	main.c 
	$(CC) $(CCFLAGS)  "main.c"

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf ./Release.esym
	rm -rf ./Release.sym
	rm -rf ./Release.lst
	rm -rf Release.err
	rm -rf ./main.esym
	rm -rf ./main.osym
	rm -rf ./main.err

# cleanup - delete all generated files
clean:	tidy
	rm -rf Release.hex
	rm -rf main.o

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
#  F:/Common/Programming/GitHub/DIPAE_EnsomatomenaSistimata_6th_Term/Askisi1.a/PIC18F4550/Release.hex: TOOL=LD

# Build tree:
all:	Release

Release:	Release.hex
	cp "Release.hex" "F:/Common/Programming/GitHub/DIPAE_EnsomatomenaSistimata_6th_Term/Askisi1.a/PIC18F4550.hex"

Release.hex:	
	$(LD) $(LDFLAGS)  LINK="Release.hex=%INFILES_DOS(,)%"

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf ./Release.esym
	rm -rf ./Release.sym
	rm -rf ./Release.lst
	rm -rf Release.err

# cleanup - delete all generated files
clean:	tidy

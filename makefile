# Flags
INC      = -I./inc/ 
LIB      = 
LIBS     = 
DEFFLAGS = -Wall -Wextra -O2 -std=gnu18  ${INC}

# directories
OBJ     = ./obj/
BIN     = ./bin/

#binary info
NAME    = libmsap
VERSION = 1.1
LIBOUT = ${BIN}/${NAME}.a


# presets
OUT = ${BIN}/${NAME}
# test out ${NAME}-${VER}_test
CC  = cc


# build test
all: message ${OUT}
	printf "\x1b[1;32m━━━SUCCESS━━━┛ Test Build\x1b[0m\n"

# build release
build: message clean_part ${LIBOUT}
	printf "\x1b[1;32m━━━SUCCESS━━━┛ \x1b[39mRelease Build\x1b[0m\n"

# clean section
clean_part:
	rm ${BIN}/* ${OBJ}/* -f
	printf "\x1b[1;35m━━━CLEANED━━━┫\x1b[0m\n"

# clean
clean: message clean_part
	printf "\x1b[1;32m━━━SUCCESS━━━┛\x1b[0m\n"


# generate new makefile
gen: message clean_part
	printf "\x1b[1;39m━━━━━━━━━━━━━┛\x1b[0m\n\n"

	hd -n libmsap -v 1.1 -m makefile -b ./bin/ -o ./obj/ -S  -s ./src/ -i ./inc/ -f -Wall -f -Wextra -f -O2 -f -std=gnu18 -T ./src/main.c
	printf "\x1b[1;32m\n━━━━━━━━━━━━━┓\nSUCCESS      ┃  \x1b[39mCreate new\x1b[35m MakeFile \x1b[32m\n━━━━━━━━━━━━━┛\x1b[0m\n"

# print settings
message:
	printf "\x1b[1;35m%s \x1b[39mV%s\n" ${NAME} ${VERSION}
	printf "\x1b[1;39mMakefile generated from \x1b[35mHD\x1b[39m\n"
	printf "\x1b[39m ━ \x1b[1;39mUnder the \x1b[32mMimik License 1.0\n"
	printf "\x1b[39m ━ \x1b[1;32mCopyright (c) 2022 Noah Arcouette\x1b[0m  ┃\n"
	printf "\x1b[39m━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┛\n"

ifndef VERBOSE
.SILENT:
endif

${OBJ}/gnitide.o: ./src//editing.c ./inc//msap.h 
	printf "\x1b[1;39m━━━━━━━━━━━━━┫\n\x1b[35mFILE         \x1b[39m┃  \x1b[39m %s\x1b[39m\n━━━━━━━━━━━━━┫\x1b[0m\n" ./src//editing.c
	${CC} -c ${DEFFLAGS} ${CFLAGS} -o ${OBJ}/gnitide.o ./src//editing.c

${OBJ}/noitaerc.o: ./src//creation.c ./inc//msap.h 
	printf "\x1b[1;39m━━━━━━━━━━━━━┫\n\x1b[35mFILE         \x1b[39m┃  \x1b[39m %s\x1b[39m\n━━━━━━━━━━━━━┫\x1b[0m\n" ./src//creation.c
	${CC} -c ${DEFFLAGS} ${CFLAGS} -o ${OBJ}/noitaerc.o ./src//creation.c

${OBJ}/gnidnif.o: ./src//finding.c ./inc//msap.h 
	printf "\x1b[1;39m━━━━━━━━━━━━━┫\n\x1b[35mFILE         \x1b[39m┃  \x1b[39m %s\x1b[39m\n━━━━━━━━━━━━━┫\x1b[0m\n" ./src//finding.c
	${CC} -c ${DEFFLAGS} ${CFLAGS} -o ${OBJ}/gnidnif.o ./src//finding.c

${OBJ}/niam.o: ./src//main.c ./inc//msap.h 
	printf "\x1b[1;39m━━━━━━━━━━━━━┫\n\x1b[35mFILE         \x1b[39m┃  \x1b[39m %s\x1b[39m\n━━━━━━━━━━━━━┫\x1b[0m\n" ./src//main.c
	${CC} -c ${DEFFLAGS} ${CFLAGS} -o ${OBJ}/niam.o ./src//main.c

${OUT}: ${OBJ}/gnitide.o ${OBJ}/noitaerc.o ${OBJ}/gnidnif.o ${OBJ}/niam.o
	${CC} ${CFLAGS} ${DEFFLAGS} ${LIB} -o ${OUT} ${OBJ}/gnitide.o ${OBJ}/noitaerc.o ${OBJ}/gnidnif.o ${OBJ}/niam.o ${LIBS}

${LIBOUT}: ${OBJ}/gnitide.o ${OBJ}/noitaerc.o ${OBJ}/gnidnif.o
	ar rcs ${LIBOUT} ${OBJ}/gnitide.o ${OBJ}/noitaerc.o ${OBJ}/gnidnif.o

CFLAGS =
CC     = cc -g -Wall -Wextra -O2 -std=gnu18 -I./inc ${CFLAGS}
OUT    = msap
TEST   = ./bin/${OUT}_TEST
LIB    = ./bin/lib${OUT}.a

all: ${TEST}
	${TEST}

build: clean ${LIB}


clean:
	rm *.gz -f
	rm ./bin/* ./obj/* *.stack-dump -f

configure:
	mkdir -p ./bin/ ./obj/

install: clean configure ${LIB}
	cp ${LIB} /lib/lib${OUT}.a
	cp ./inc/${OUT}.h /usr/include/${OUT}.h

	mkdir -p /etc/mimik/docs/LibMSAP
	cp ./doc/* /etc/mimik/docs/LibMSAP/

uninstall:
	rm /lib/lib${OUT}.a -f
	rm /usr/include/${OUT}.h -f

	rm /etc/mimik/docs/LibMSAP/ -rf

${TEST}: ./obj/main.o ./inc/msap.h ./obj/creation.o ./obj/editing.o ./obj/finding.o
	${CC} -o ${TEST} ./obj/*.o

${LIB}: ./obj/creation.o ./obj/editing.o ./obj/finding.o
	ar rcs ${LIB} ./obj/creation.o ./obj/editing.o ./obj/finding.o

./obj/main.o: ./inc/msap.h ./src/main.c
	${CC} -o ./obj/main.o -c ./src/main.c

./obj/creation.o: ./src/creation.c ./inc/msap.h
	${CC} -o ./obj/creation.o -c ./src/creation.c

./obj/editing.o: ./src/editing.c ./inc/msap.h
	${CC} -o ./obj/editing.o -c ./src/editing.c

./obj/finding.o: ./src/finding.c ./inc/msap.h
	${CC} -o ./obj/finding.o -c ./src/finding.c

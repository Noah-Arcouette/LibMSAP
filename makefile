CFLAGS =
CC     = cc -Wall -Wextra -O2 -std=gnu18 -I./inc ${CFLAGS}
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

${TEST}: ./obj/main.o ./obj/sa.o ./inc/msap.h
	${CC} -o ${TEST} ./obj/*.o

${LIB}: ./obj/sa.o
	ar rcs ${LIB} ./obj/sa.o

./obj/main.o: ./inc/msap.h ./src/main.c
	${CC} -o ./obj/main.o -c ./src/main.c

./obj/sa.o: ./src/sa.c ./inc/msap.h
	${CC} -o ./obj/sa.o -c ./src/sa.c

COMPILER = g++

main.out: main.o move.o password.o pck.o prt.o help.o nps.o add_object.o collisions.o
	${COMPILER} $^ -o $@

main.o: main.cpp
	${COMPILER} -c $^ -o $@

move.o: move.cpp
	${COMPILER} -c $^ -o $@

password.o: password.cpp
	${COMPILER} -c $^ -o $@

pck.o: pck.cpp
	${COMPILER} -c $^ -o $@

prt.o: prt.cpp
	${COMPILER} -c $^ -o $@

help.o: help.cpp
	${COMPILER} -c $^ -o $@

nps.o: nps.cpp
	${COMPILER} -c $^ -o $@

add_object.o: add_object.cpp
	${COMPILER} -c $^ -o $@

collisions.o: collisions.cpp
	${COMPILER} -c $^ -o $@

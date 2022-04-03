CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
OBJECTS = main.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a5chess

${EXEC}: ${OBJECTS} 
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

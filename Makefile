CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
OBJECTS = main.o subject.o observer.o board.o game.o piece.o player.o human.o textDisplay.o window.o graphicDisplay.o pawn.o king.o queen.o bishop.o rook.o knight.o blank.o movevisitor.o movecheck.o movestalemate.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = chess

${EXEC}: ${OBJECTS} 
	${CXX} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

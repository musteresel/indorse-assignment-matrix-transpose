SOURCES=src/main.cc src/transpose.cc src/adapter.cc
HEADERS=src/transpose.h


TARGET=transpose


DEPENDENCIES=Makefile ${SOURCES} ${HEADERS}
COMPILE_CMD=${CXX} ${CPPFLAGS} ${CXXFLAGS} -o $@ ${SOURCES}


${TARGET}: ${DEPENDENCIES}
	${COMPILE_CMD}


${TARGET}-silent: CPPFLAGS+=-DSILENT=1
${TARGET}-silent: ${DEPENDENCIES}
	${COMPILE_CMD}


.PHONY: clean
clean:
	${RM} ${TARGET} ${TARGET}-silent

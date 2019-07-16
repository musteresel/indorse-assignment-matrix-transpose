SOURCES=src/main.cc src/transpose.cc src/adapter.cc
HEADERS=src/transpose.h
TESTS=square1 square3 wide high
FAIL_TESTS=too_small too_large missing_column missing_data


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


.PHONY: test
test: ${TARGET}-silent
	@for f in ${TESTS}; \
	do \
	  ./${TARGET}-silent < tests/$$f.in | diff -ruh - tests/$$f.out; \
	done
	@for f in ${FAIL_TESTS}; \
	do \
	  (./${TARGET}-silent < tests/$$f.in 2>&1 || true) | grep -i error > /dev/null || echo "FAILED: $$f"; \
	done

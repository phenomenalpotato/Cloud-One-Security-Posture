LIBS = -lcurl
exe = cosp
sfile = cospo.cpp
COMP = g++

all:
	@echo "Compiling..."
	${COMP} -std=c++11 -Wall -Wextra -pedantic -Werror -Isingle_include ${sfile} $(LIBS) -o ${exe}

execute: 
	@echo "Executing the program with no Arguments..."
	@./${exe}

delete:
	@echo "Deleting the executable cosp..."
	rm -f ${exe}

debug:
	@echo "Will Debug the connection..."
	@${COMP} -D 'DEBUG' -std=c++11 -Isingle_include ${sfile} ${LIBS} -o ${exe}

env-var:
	@echo $$api

LIBS = -lcurl
exe = cosp
sfile = cospo.cpp
COMP = g++

all:
	@echo "Compiling..."
	${COMP} -std=c++11 -Isingle_include ${sfile} $(LIBS) -o ${exe}

execute: 
	@echo "Executing the program with no Arguments..."
	#@./${exe} | jq .
	@./${exe}

delete:
	@echo "Deleting the executable cosp..."
	rm -f ${exe}

debug:
	@echo "Will Debug the connection..."
	@${COMP} -D 'DEBUG' -std=c++11 -Isingle_include ${sfile} ${LIBS} -o ${exe}

env-var:
	@echo $$api


	#@echo $$url_l
	#@echo $$url_c
	#@echo $$url_e

#cc_list_accounts:
	#@./${exe} l | jq .
#	@./${exe} l | jq .

#cc_all_accounts_checks:
#	@./${exe} c | jq .

#cc_list_all_events:
#	@./${exe} e | jq .

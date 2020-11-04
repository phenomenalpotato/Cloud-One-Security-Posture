LIBS = -lcurl
exe = cosp
sfile = cospo.c 

all:
	@echo "Compiling..."
	gcc ${sfile} $(LIBS) -o ${exe}

execute: 
	@echo "Executing the program with no Arguments..."
	@./${exe} | jq .


delete:
	@ echo "Deleting the executable cosp..."
	rm -f ${exe}

debug:
	@echo "Will Debug the connection..."
	@gcc -D 'DEBUG' ${sfile} ${LIBS} -o ${exe}

env-var:
	@echo $$api
	@echo $$url_l
	@echo $$url_c
	@echo $$url_e

cc_list_accounts:
	@./${exe} l | jq .

cc_all_accounts_checks:
	@./${exe} c | jq .

cc_list_all_events:
	@./${exe} e | jq .
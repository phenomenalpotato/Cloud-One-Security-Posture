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
	@echo "Debuging the connection..."
	@gcc -D 'DEBUG' ${sfile} ${LIBS} -o ${exe} && ./${exe}

env-var:
	@echo $$api
	@echo $$url

list_accounts:
	@./${exe} l | jq .
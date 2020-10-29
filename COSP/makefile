LIBS = -lcurl
exe = cosp
sfile = cospo.c 

all:
	@echo "Compiling..."
	gcc ${sfile} $(LIBS) -o ${exe}

execute:
	@echo "Executing the program..."
	@./${exe}

delete:
	@ echo "Deleting the executable cosp"
	rm -f ${exe}
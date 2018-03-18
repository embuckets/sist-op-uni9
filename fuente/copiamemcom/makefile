#Make para compilar copiamemcom
COMPILADOR=gcc

FUENTE = opsemmemcom.c escritormemcom.c copiamemcom.c lectormemcom.c inimemcom.c $(RUTA_CLAVESIPC)clavesipc.c 
 #$(RUTA_UTIL)error.c 

OBJS=$(FUENTE:.c=.o)

HEADER1= clavesipc.h 
HEADER2= memcom.h 
#error.h

PROG= $(RUTA_BIN)copiamemcom
#HEADER=sem.h
#PROG=$(RUTA_BIN)pruebasemaforos

CC: $(OBJS)
	$(COMPILADOR) $(OBJS) -o $(PROG)
	#$(COMPILADOR) $(OBJS) -lm -o $(PROG)
	@- echo "Compilación terminada"
LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado"
BORRA:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado"
.c.o:
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o
$(OBJS): $(RUTA_INCL)$(HEADER1) $(RUTA_INCL)$(HEADER2)
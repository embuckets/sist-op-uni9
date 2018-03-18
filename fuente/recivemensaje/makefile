#Make para compilar copiamemcom
COMPILADOR=gcc

FUENTE = recivemensaje.c

OBJS=$(FUENTE:.c=.o)

HEADER=fifo.h 

PROG= $(RUTA_BIN)recivemensaje

CC: $(OBJS)
	$(COMPILADOR) $(OBJS) -o $(PROG)
	@- echo "Compilación terminada"
LIMPIA:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado"
BORRA:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado"
.c.o:
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o
$(OBJS): $(RUTA_INCL)$(HEADER)
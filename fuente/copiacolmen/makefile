#Make para compilar copiacolmen
COMPILADOR=gcc
FUENTE=opsemcolmen.c enviadorcolmen.c copiacolmen.c receptorcolmen.c inicolmen.c $(RUTA_CLAVESIPC)clavesipc.c 
#$(RUTA_UTIL)error.c  
OBJS=$(FUENTE:.c=.o) 
HEADER1= colmen.h 
HEADER2= clavesipc.h 
PROG=$(RUTA_BIN)copiacolmen 

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
$(OBJS): $(RUTA_INCL)$(HEADER1) $(RUTA_INCL)$(HEADER2)
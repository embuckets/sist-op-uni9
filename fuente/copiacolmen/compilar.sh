#!/bin/bash
#Shell Script de compilación de copiacolmen
ACTUAL=$PWD
cd ../../bin
BIN=`pwd`
cd $ACTUAL
cd ../incl
INCL=`pwd`
#cd $ACTUAL
#cd ../util
#UTIL=`pwd` 
cd $ACTUAL
cd ../clavesipc
CLAVESIPC=`pwd`
cd $ACTUAL
make $* RUTA_BIN=$BIN/ RUTA_INCL=$INCL/ RUTA_UTIL=$UTIL/ RUTA_CLAVESIPC=$CLAVESIPC/ 
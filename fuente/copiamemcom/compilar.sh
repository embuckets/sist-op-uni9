#!/bin/bash
#Shell Script de compilación de copiamemcom
ACTUAL=$PWD
cd ../../bin
BIN=`pwd`
cd $ACTUAL
cd ../incl
INCL=`pwd`
#INCL=$PWD
#cd $ACTUAL
#cd ../util
#UTIL=$PWD/
cd $ACTUAL
cd ../clavesipc
CLAVESIPC=`pwd`
cd $ACTUAL
make $* RUTA_BIN=$BIN/ RUTA_INCL=$INCL/ RUTA_CLAVESIPC=$CLAVESIPC/
#\RUTA_UTIL=$UTIL/ 
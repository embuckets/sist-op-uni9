#!/bin/bash
#Shell Script de compilación de recibemensaje
ACTUAL=$PWD
cd ../../bin
BIN=`pwd`
cd $ACTUAL
cd ../incl
INCL=`pwd`
cd $ACTUAL
make $* RUTA_BIN=$BIN/ RUTA_INCL=$INCL/ 
#!/bin/sh
clear
echo "Compilando ****************************************"
g++ main.cpp  simuladorBolsa/simulador.cpp Broker/broker.cpp  Binarios/binario.cpp Individuo/indiv.cpp  -o  main

echo "Ejecutando ****************************************"
./main

echo "Compilando Para visualizar****************************************"
g++ main.cpp  simuladorBolsa/simulador.cpp Broker/broker.cpp  Binarios/binario.cpp Individuo/indiv.cpp  -o  main

echo "Fin ****************************************"
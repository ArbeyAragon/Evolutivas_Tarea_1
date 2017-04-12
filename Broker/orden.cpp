#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <cstdlib> 
#include <ctime> 
#include <vector>
#include <stdio.h>  
#include <time.h>  
#include <math.h> 
#include <algorithm>

#include "orden.h"

using namespace std;


Orden::Orden(int orden, double precio){
    ordenEnviada=orden;
    precioEnviado=precio;
};

virtual Orden::~Orden(){ };


VectorOrdenes::VectorOrdenes(){};

void VectorOrdenes::AddOrdenes(int orden, double precio){
    Orden tem = Orden(orden,precio);
    VecOrdenes.push_back(tem);
};

virtual VectorOrdenes::~VectorOrdenes(){
    VecOrdenes.clear();
    vector<Orden>().swap(VecOrdenes);
};




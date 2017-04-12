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

#include "broker.h"
//#include "orden.h"
#include "../simuladorBolsa/simulador.h"
#include "../Binarios/binario.h"

using namespace std;


/*
class Orden{
public:
    Orden(int orden, double precio){
        ordenEnviada=orden;
        precioEnviado=precio;
    };

    virtual ~Orden(){   };
private:
    int ordenEnviada;
    double precioEnviado;
};




class VectorOrdenes{
public:
    VectorOrdenes(){};
    void AddOrdenes(int orden, double precio){
        Orden tem = Orden(orden,precio);
        VecOrdenes.push_back(tem);
    };

    virtual ~VectorOrdenes(){
        VecOrdenes.clear();
        vector<Orden>().swap(VecOrdenes);
    };
private:
    vector<Orden> VecOrdenes;
};

/**/



simulador* broker::sim = simulador::getInstance();

broker::broker(){
    clearReset();
    cout<<"broker creado"<<endl;
};


double* broker::getData(int aDec, int bDec, int cDec){return sim->getDataSum(index, aDec, bDec, cDec);};//retorna valor actual, retorno logaritmico, valores de las 3 medias moviles  

bool broker::getOrdenActivada(){ return ordenActivada; };

void broker::sendOrder(int orden, double datoAct){
    if((orden==1)||(orden==2)){ordenActivada=true;}else{ordenActivada=false;}
    

};

bool broker::HasNext(){
    bool salida=(index < sim->getMaxLen());
    return salida;
};

void broker::Next(){index++;};

double broker::getRetorno(){return Retorno;};
double broker::getOmegaRatio(){return OmegaRatio;};

void broker::clearReset(){
    index=0;
    OmegaRatio=0;
    Retorno=0;
    ordenActivada = false;
};



broker::~broker(){};////////////////////
/**/
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

#include "indiv.h"
#include "../simuladorBolsa/simulador.h"
#include "../Binarios/binario.h"
#include "../Broker/broker.h"

using namespace std;



class MyFILE
{
public:
    MyFILE(){
        doc = fopen("mejor_indiv.txt","w");
    };
    void addDouble(double a){fprintf(doc,"%5.5f,",a);};
    void addInt(int a){fprintf(doc,"%d",a);};
    void addSpace(){fprintf(doc,"\n");};
    void addLine(double a,double x,double y,double z,int orden){fprintf(doc,"%5.5f,%5.5f,%5.5f,%5.5f,%d\n",a,x,y,z,orden);};

    virtual ~MyFILE(){fclose(doc);};
private:
    FILE * doc;
};



int indiv::mapBit[10]={4,4,4,4,5,5,9,9,9,10};
//broker* indiv::brTem = new broker::broker();
int indiv::permut[6][3]= {{0, 1, 2},{0, 2, 1},{1, 2, 0},{1, 0, 2},{2, 1, 0},{2, 0, 1}};


void indiv::loadConf(){ 
    binario::initRandom();
};


indiv::indiv(long long int binario){
    bin=binario;
    brTem = new broker();
    fitnessCalc();
};

indiv::indiv(){
    bin=binario::vectorRandBin(mapBit, len);
    brTem = new broker();
    fitnessCalc();
};

void indiv::setBin(long long int binario){
    bin=binario;
    brTem->clearReset();
    fitnessCalc();
};


long long int indiv::getBin(){return bin;};

double indiv::getFitness(){return fitness;};

void indiv::printBinario(){binario::printBin(bin);};


void indiv::print(){
    printf("\nfitness: %5.4f  Bin: ",fitness);
    printBinario();
};

indiv::~indiv(){};






bool indiv::cross(double* a,double* b){
	if((((b[1]-a[1])>0) && ((b[0]-a[0])<0)) || (((b[1]-a[1])<0) && ((b[0]-a[0])>0)) ){
		return true;
	}
	return false;
}


bool indiv::crossMult(double* a,double* b,double* c){
	int cont=0;
	if(cross(a,b)){cont=cont+1;}
	if(cross(b,c)){cont=cont+1;}
	if(cross(a,c)){cont=cont+1;}
	if(cont>=2){return true;}
	return false;
}

int indiv::ordenCond(int* orden ,double* a,double* b,double* c){
	//none 0, sell 1, buy 2
	if(((a[1]==b[1])&&(b[1]==c[1]))){
		//printf("\n**1\n");
		return orden[0];
	}

	if(((a[1]==b[1])&&(b[1]>c[1]))){
		//printf("\n**2\n");
		return orden[1];
	}

	if(((a[1]==b[1])&&(b[1]<c[1]))){
		//printf("\n**3\n");
		return orden[2];
	}

	if(crossMult(a,b,c)){
		//printf("\n**4\n");
		return orden[0];
	}

	if(cross(a,b) && (b[1]>c[1])){
		//printf("\n**5\n");
		return orden[1];
	}
	if(cross(a,b) && (b[1]<c[1])){
		//printf("\n**6\n");
		return orden[2];
	}	
	//printf("\n**7\n");
	return -1;
}





double indiv::fitnessCalc(){
    brTem->clearReset();
    int* CodigoTraducido = binario::vectorBinToInt(bin, mapBit, len);

    if((CodigoTraducido[2]==CodigoTraducido[3]) || (CodigoTraducido[3]==CodigoTraducido[4]) || (CodigoTraducido[2]==CodigoTraducido[3])){
		return -100;
	}

    for(int i = 0 ; i<len ; i++){
        cout<<CodigoTraducido[i]<<" "<< pow(2,mapBit[i]) << " " << i << endl;
    }

    //MyFILE * f = new MyFILE();
    double* b = new double[3*2];
    int perm=0;
    int* orden;
    double* x;
    double* y;
    double* z;
    int ordenPedida;
    for(int j = 0; brTem->HasNext(); j++){
        dato=brTem->getData( CodigoTraducido[6], CodigoTraducido[7], CodigoTraducido[8]);
        if(j!=0){
            /*
            for(int i = 0 ; i<5  ; i++){
                cout<<dato[i]<<" "<< datoAnt[i] << " " << i << endl;
            }
            cout<<endl;/**/
            for(int i = 0 ; i<3  ; i++){
                b[i*2+0]=datoAnt[2+i];
                b[i*2+1]=dato[2+i];
            }

            
            orden = new int[3];
            perm=(int)CodigoTraducido[4]*6.0/32.0;

            orden[0]=permut[perm][0];
            orden[1]=permut[perm][1];
            orden[2]=permut[perm][2];
            
            x=new double[2];
            y=new double[2];
            z=new double[2];

            perm=(int)CodigoTraducido[5]*6.0/32.0;
            x[0]=b[permut[perm][0]*2+0];
            x[1]=b[permut[perm][0]*2+1];
            y[0]=b[permut[perm][1]*2+0];
            y[1]=b[permut[perm][1]*2+1];
            z[0]=b[permut[perm][2]*2+0];
            z[1]=b[permut[perm][2]*2+1];

            ordenPedida=ordenCond(orden,x,y,z);

            //f->addLine(dato[0],dato[2],dato[3],dato[4],ordenPedida);

            delete[] x;
            delete[] y;
            delete[] z;
            delete[] orden;

            if((ordenPedida==-1)&&(brTem->getOrdenActivada())){


            }

            brTem->sendOrder(ordenPedida, dato[0]);

            delete[] datoAnt;
        }
        datoAnt=dato;
        brTem->Next();
    }
    delete[] b;
    //delete f;
    return 0;
}
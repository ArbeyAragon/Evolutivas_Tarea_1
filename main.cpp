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

#include "simuladorBolsa/simulador.h"
#include "Individuo/indiv.h"
#include "Binarios/binario.h"
#include "Broker/broker.h"

using namespace std;


int main()
{	


    /*
    simulador* sim = simulador::getInstance();

    double* jajaj=new double[5];
    for(int j = 0; j < sim->getMaxLen(); j++){
       jajaj=sim->getDataSum(j, 0, 5, 200);
        cout<<jajaj[0]<<" "<<jajaj[1]<<" "<<jajaj[2]<<" "<<jajaj[3]<<" "<<jajaj[4]<<endl;

    }/**/


    indiv* id;

    for(int i = 0 ; i<2;i++){
        id = new indiv();
        //cout<<i<<" "<<endl;
        delete id;
    }



    //broker* tem = new broker();


/*

    int* tem;

    cout<<"---"<<endl;
    tem = binario::vectorRandInt(mapBit, num);
    for(int i = 0 ; i<num;i++){
        cout<<i<<" "<<tem[i]<<endl;
    }
    cout<<"-------"<<endl;
    long long int indBin = binario::vectorIntToBin(tem , mapBit, num);
    binario::printBin(indBin);
    cout<<endl;


    int* tem1;
    tem1 = binario::vectorBinToInt(indBin, mapBit, num);


    for(int i = 0 ; i<num;i++){
        cout<<i<<" "<<tem1[i]<<endl;
    }

    /**/

    cout<<"jaja"<<endl;



    return 0;
}

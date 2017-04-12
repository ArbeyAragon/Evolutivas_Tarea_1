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

#include "simulador.h"

using namespace std;

simulador* simulador::instance=0;

simulador* simulador::getInstance(){
    if(instance==0){
        instance = new simulador(); 
    }
    return instance;
};



simulador::simulador(){
    loadData();
    mediasMov();
    retornosCalc();
    cout<<"Bolsa creada"<<endl;
}; 



void simulador::loadData(){
    data = new double[maxLenData];
	ifstream fe;
	fe.open("simuladorBolsa/valor.txt");
	char cadena[128];
	int count=0; 
	double tem;
	for(int i = 0; count < maxLenData;i++)
	{
	   fe >> cadena;
	   if(i%3==2){
		data[count]=atof(cadena);
		//printf("%5.3f\n",data[count]);
		count=count+1;
	   }
	}
	fe.close();	
};



double simulador::getSumHist(int index, int len){
    //printf("%5.3f++++++++\n",data[index]);
    double sum = 0 ;
    double count = 0;
    for(int i = (index-len+1) ; i <= index ; i++){
        sum=sum+data[i];
        count=count+1;
		//printf("%5.3f\n",data[i]);
    }
    return sum/count;
};



void simulador::mediasMov(){
    cout<<"Calculo medias"<<endl;
    mediasMovData = new double*[maxSum];
    for(int i = 0; i < maxSum; i++){ mediasMovData[i] = new double[maxLenData-puntoInicio]; }
    for(int i = 0; i < maxSum; i++){   
        for(int j = puntoInicio; j < maxLenData; j++){   
            mediasMovData[i][j-puntoInicio]=getSumHist(j,i+minSum);
        }
    }
};


void simulador::retornosCalc(){
    retornos = new double[maxLenData];
    retornos[0]=0;
	for(int i = 1 ; i < maxLenData ; i++ )
	{
		retornos[i]=log(data[i]/data[i-1]);
	}	
};


double simulador::getData(int index){
    return data[index+puntoInicio];
};


int simulador::getMaxLen(){
    return maxLenData-puntoInicio;
};

double* simulador::getDataSum(int index, int aDec, int bDec, int cDec){
    double* dataTem = new double[5];
    dataTem[0]=data[index+puntoInicio];
    dataTem[1]=retornos[index+puntoInicio];
    dataTem[2]=mediasMovData[aDec][index];
    dataTem[3]=mediasMovData[bDec][index];
    dataTem[4]=mediasMovData[cDec][index];
    return dataTem;
};

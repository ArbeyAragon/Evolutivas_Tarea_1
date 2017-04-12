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
#include <bitset>

#include "binario.h"

using namespace std;

void binario::initRandom(){srand(time(0));}

void binario::printBin(long long int num){cout<<bitset<64>(num)<<endl;}

int binario::randInt(int min, int max){
   int r;
   r = (rand()%max)+min;
   return r;
}

int* binario::vectorRandInt(int* mapBit, int len){ 
	int* ind = new int[len];
	for (int pass = 0; pass < len; pass++){ 
		ind[pass] = randInt(0, pow(2, mapBit[pass]));
	}
	return ind;
}


long long int binario::vectorIntToBin(int* vector, int* mapBit, int len){
    long long int indBin = 0;
	for (int pass = 0; pass < len; pass++){ 
		indBin=(indBin << mapBit[pass]) | vector[pass];
        //printBin(indBin);
	}
	return indBin;
}

long long int binario::vectorRandBin(int* mapBit, int len){
	return vectorIntToBin(vectorRandInt(mapBit, len), mapBit, len);
}


int binario::subBitsToInt(long long int tem,int mask0,int delta){
	long long int mask = mask0;	
	long long int tem2;
	tem2 = (mask << delta);
	tem2=(tem & tem2);	
	tem2 = (tem2 >> delta);
    //printBin(tem2);
	int salida = tem2;
	return salida;
}

int* binario::vectorBinToInt(long long int indBin, int* mapBit, int len){
	int* vector = new int[len];
    int sum=0;
	for (int pass = 0; pass < len; pass++){
		vector[len-pass-1]=subBitsToInt(indBin,pow(2, mapBit[len-pass-1])-1, sum);
        //cout<<vector[len-pass-1]<<endl;
        sum = sum + mapBit[len-pass-1]; 
	}
	return vector;
}


/////////////////////////////////////////////////////////////Geneticos
long long int binario::mutacion(long long int tem){
	long long int indBin = tem;
	for (int pass = 0; pass < 15; pass++){ 
		indBin ^= (1u << randInt(0, 32));	
	}
	return indBin;
}

long long int* binario::cruce(long long int* padres){
	long long int* hijos= new long long int[2];
	long long int tem=0;
	int ibit;
		
	hijos[0]=padres[0];
	hijos[1]=padres[1];

	
	for (int pass = 0; pass < 45; pass++){ 	
		tem |= (1u << randInt(0, 32));
	}

	hijos[0] = ((padres[0] & (tem)) | (padres[1] & ~(tem)));
	hijos[1] = ((padres[1] & (tem)) | (padres[0] & ~(tem)));	
	return hijos;
}

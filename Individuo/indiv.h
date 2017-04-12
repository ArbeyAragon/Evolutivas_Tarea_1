#ifndef INDIV_H
#define INDIV_H

#include "../simuladorBolsa/simulador.h"
#include "../Binarios/binario.h"
#include "../Broker/broker.h"

class indiv{
	private:
		broker* brTem; 
		double fitness;
		long long int bin;
		static int permut[6][3];
		//////////////Var temp
		double* dato;
		double* datoAnt;
		//////////////


		int lendIndiv;
		double fitnessCalc();
		
	public:

		static const int len = 10;
		static int mapBit[10];
		
		static void loadConf();

		indiv(long long int binario);
		indiv();

        double getFitness();
		void setBin(long long int binario);
		long long int getBin();

		void print();
		void printBinario();

		bool cross(double* a,double* b);
		bool crossMult(double* a,double* b,double* c);
		int  ordenCond(int* orden ,double* a,double* b,double* c);



		void guarda();
		~indiv();

};


#endif
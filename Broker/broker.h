#ifndef BROKER_H
#define BROKER_H

//#include "orden.h"
#include "../simuladorBolsa/simulador.h"

class broker
{
    private:
        static simulador* sim;
        int index;
        double OmegaRatio;
        double Retorno;
        
        bool ordenActivada;

    public:
        broker();

        double* getData(int aDec, int bDec, int cDec);//retorna valor actual, retorno logaritmico, valores de las 3 medias moviles 
        void sendOrder(int orden, double datoAct);

        bool HasNext();
        void Next();

        bool getOrdenActivada();
        double getRetorno();
        double getOmegaRatio();

        void clearReset();
        ~broker();
};

#endif
#ifndef SIMULADOR_H
#define SIMULADOR_H


class simulador
{
    private:
        static simulador* instance;
        simulador();

        double* data;
        double* retornos;
        double** mediasMovData;

        double getSumHist(int index, int len);

    public:

        static const int minSum=2;
        static const int maxSum=513;
        static const long int maxLenData=1000;
        static const int puntoInicio=518;

        static simulador* getInstance();

        void loadData();
        void mediasMov();
        void retornosCalc();
        
        double getData(int index);
        int getMaxLen();
        double* getDataSum(int index, int a, int b, int c);
};

#endif
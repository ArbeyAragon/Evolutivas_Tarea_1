#ifndef BINARIO_H
#define BINARIO_H


class binario
{
    private:
        static int subBitsToInt(long long int tem,int mask0,int delta);
    public:
        static void initRandom();
        static void printBin(long long int bin);
        static int randInt(int min, int max);
        static int* vectorRandInt(int* map, int len);
        static long long int vectorIntToBin(int* vector, int* map, int len);
        static int* vectorBinToInt(long long int indBin, int* mapBit, int len);
        static long long int vectorRandBin(int* mapBit, int len);

        /////////////////Geneticos
        static long long int mutacion(long long int tem);
        static long long int* cruce(long long int* padres);

};
#endif
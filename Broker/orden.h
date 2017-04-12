#ifndef VORBEN_H
#define VORBEN_H

#include <vector>

class Orden{
public:
    Orden(int orden, double precio);
    virtual ~Orden();
private:
    int ordenEnviada;
    double precioEnviado;
};



class VectorOrdenes{
public:
    VectorOrdenes(){};
    void AddOrdenes(int orden, double precio);
    virtual ~VectorOrdenes();
private:
    vector<Orden> VecOrdenes;
};



#endif
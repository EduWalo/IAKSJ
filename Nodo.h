#ifndef NODO_H
#define NODO_H
#include "Tablero.h"

#include <limits>       // std::numeric_limits
                        // std::numeric_limits<int>::min()
                        // std::numeric_limits<int>::max()

class Nodo
{
private:
    Nodo* padre;
    
    int tipo; // 1 ,max, 2 min
    int profundidad;
    int utilidad;
    int typeF;
    int colorF;
    int prfMax=2;
    Tablero estado;


public:
    int* posij;
    int colH=0; //color del hijo
    Tablero estadoMinMax;
    bool changed = false;

    Nodo(int tipo,int colorF,int tipoF, int profundidad,Tablero estado);
    ~Nodo();

    int calculateUtility();
    void printNodo();
};



#endif
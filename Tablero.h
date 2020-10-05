#ifndef TABLERO_H
#define TABLERO_H

class Tablero
{
private:
    int tabla[8][8] = {};
    int fichas[8][8][2] = {};

    void printLine();
    void printTopL();
    void printBotL();
    void printMidL();
    void printFicha(int, int, int, int);

    int getSellColor(int);
    int getPiceType(int);
    int getPiceColor(int);
    int setSellColor(int );

public:
    
    Tablero();
    ~Tablero();
    void printTablero();
    int mover(int,int,int,int);
    int* getIJficha(int,int);
    int* enbaleMov(int i, int j, int dir,int cant);
    bool winState();
    int getUtility();
    int getValFichas(int i, int j, int z);
    int getValTabla(int i, int j);
    void showRequiredColor(int);
};



#endif
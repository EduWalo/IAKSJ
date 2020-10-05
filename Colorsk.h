#ifndef COLORSK_H
#define COLORSK_H

#include <windows.h>//colores

class Colorsk
{
private:
    
public:

    enum COLORESDEF {
        AMARILLO = 224, 
        //CIAN = 176, ROJO = 192, GRIS = 128, 
        CIAN = 111, ROJO = 192, GRIS = 79, 

        VERDE = 160, AZUL = 144, 
        //MORADO = 80, 
        MORADO = 95,
        FUCSIA = 208,
        BCKBGWFG = 240
        };
    enum COLORESFG {
        FGAMARILLO = 14, 
        //FGCIAN = 11, FGROJO = 12, FGGRIS = 8,
        FGCIAN = 6, FGROJO = 12, FGGRIS = 4,
        FGVERDE = 10, FGAZUL = 9, FGMORADO = 5, FGFUSCIA = 13
    };

    static void sclr(int);//set color
    static void sclr(int, int);//set color
    

};
///////////////
/***                 B   N
 * naranja - cian  176-191  (176) |  |  |
 * amarillo         224 |  |  |
 * verde            160 |  |  |
 * rojo             192 |  |  |
 * azul             144 |  |  |
 * morado           80  |  |  |
 * fuxia            208 |  |  |
 * cafe - gris      128 |  |  |
*/


// print Line

#endif
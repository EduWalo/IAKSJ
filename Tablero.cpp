#include "Tablero.h"

#include "Colorsk.h"

#include <iostream>
#include <limits>       // std::numeric_limits
                        // std::numeric_limits<int>::min()
                        // std::numeric_limits<int>::max()


using namespace std;


Tablero::Tablero()
{
    int count =1; // es el contador de celda para el seteo de los colores
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            this->tabla[i][j] = this->setSellColor(count);
            count++;// contador
        }
        
    }

    //COLOR colores {1,2,3,4,5,6,7,8} 0  si no hay 
    //TIPO ficha negras o blancas {1,2} 0 si no hay

    //fichas [i][j][Tipo = 0]
    //fichas [i][j][COLOR = 1]

    //tabla [i][j] -> color 

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(i == 0 )   //ficahs negras
            {
                this->fichas[0][j][0] = 1;
                this->fichas[0][j][1] = j+1;
            }else if ( i == 7) //ficahs blancas
            {
                this->fichas[7][j][0] = 2;
                this->fichas[7][j][1] = 8-j;
            }
        }        
    }
    
}

Tablero::~Tablero()
{
}


/**
 * mueve una ficha y retorna el color de la casilla donde se movio
*/
int Tablero::mover(int vi, int vj,int ni,int nj)
{

    //cambio de posiciones
    this->fichas[ni][nj][0] =this->fichas[vi][vj][0];
    this->fichas[ni][nj][1] =this->fichas[vi][vj][1];

    //limpio vieja coordenada
    this->fichas[vi][vj][0] =0;
    this->fichas[vi][vj][1] =0;

    //retornar color

    return this->tabla[ni][nj];
}


/**
 * get the win state 
 * return true if the state is win 
 * return false if state is not win
*/
bool Tablero::winState()
{
    bool winState = false;

    for (int i = 0; i < 8; i+=7)
    {
         for (int j = 0; j < 8; j++)
        {
            //verificacion de llegada de la fiucha al otro lado
            if (this->fichas[i][j][0] == 1)// negra
            {
                if (i == 7)// se llego al otro lado
                {
                    return true;
                }
            }
            else if (this->fichas[i][j][0] == 2) //blanca  
            {
                if (i == 0)// se llego al otro lado
                {
                    return false;
                }
            }
        }
    }

    return winState;    
}


/**
 * this function rerun the utility 
 * just to black 
*/

int Tablero::getUtility()
{
    int utilityT = 0;
    int blackU=0, whiteU=0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (fichas[i][j][0] == 1 )// es una negras
            {
                
                if(i == 7) //llego al otro lado, la utilidad se retorna como la maxima
                {
                    return std::numeric_limits<int>::max();
                }
                else // acomular las distancias restantes 
                {
                    blackU+= i;
                }
            }
            else if (fichas[i][j][0] == 2)// es una blancas
            {

                if(i == 0) //llego al otro lado, la utilidad se retorna como la minima ganancia
                {
                    return std::numeric_limits<int>::min();
                }
                else // acomular las distancias restantes 
                {
                    whiteU+= (7-i);
                }
                
            }
        }
        
    }

    // se resta la utilidad de las negras con el de las blancas, así si las blancas posee 
    // más utilidad devolverá negativo
    utilityT = blackU - whiteU;

    return utilityT;
}


/**
 * this afunction return val od Fichas [i][j]
*/
int Tablero::getValFichas(int i, int j, int z)
{
    return this->fichas[i][j][z];
}

/**
 * 
 *Search the i j piece
 */

int* Tablero::getIJficha(int color,int tipo)
{
    int vi=-1,vj=-1;
    int * vij = new int[2];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(
                this->fichas[i][j][0]  == tipo &&
                this->fichas[i][j][1] == color
                )
            {
                vij[0] = i;
                vij[1] = j;
            }
        }
    }

    return vij;
}

/**
 * dice si es posible o no el moovimiento
*/

int* Tablero::enbaleMov(int i, int j, int dir, int cant)
{
    bool result = true;
    
    int * resint = new int[2];
    resint[0] = -1;
    switch (dir)
    {
    case 1:// left
        // solo se merma j
        while (cant != 0)
        {
            //desvorde 
            if (j > 7 || j < 0)
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "Movimiento fuera de Rango\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
            //aumento de la posición en j
            j--;
            cant--;
            //salto de ficha
            if (this->fichas[i][j][0] != 0)
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "No puede avanzar saltando otras fichas\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
        }
        
            
        break;
    case 2:// left up
        //se resta j y se aumenta i
        while (cant != 0)
        {
            //desvorde 
            if ((j > 7 || j < 0 ) || (i > 7 || i < 0 ))
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "Movimiento fuera de Rango\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
            //cambio j e i 
            j--;
            i--;
            cant--;
            //salto de ficha
            if (this->fichas[i][j][0] != 0)
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "No puede avanzar saltando otras fichas\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
        }
        
            
        break;
    case 3:// up 
        // solo se aumenta i
        while (cant != 0)
        {
            //desvorde 
            if (i > 7 || i < 0)
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "Movimiento fuera de Rango\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
            //aumento de la posición en i
            i--;
            cant--;
            //salto de ficha
            if (this->fichas[i][j][0] != 0)
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "No puede avanzar saltando otras fichas\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
        }
        
        break;
    case 4://rigth up
         //se aumenta j y se aumenta i
        while (cant != 0)
        {
            //desvorde 
            if ((j > 7 || j < 0 ) || (i > 7 || i < 0 ))
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "Movimiento fuera de Rango\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
            //cambio j e i 
            j++;
            i--;
            cant--;
            //salto de ficha
            if (this->fichas[i][j][0] != 0)
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "No puede avanzar saltando otras fichas\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
        }
        
        break;
    case 5://rigth
         //se aumenta j 
        while (cant != 0)
        {
            //desvorde 
            if (j > 7 || j < 0 )
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "Movimiento fuera de Rango\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
            //cambio j 
            j++;
            
            cant--;
            //salto de ficha
            if (this->fichas[i][j][0] != 0)
            {
                result = false;
                Colorsk::sclr(12);
                std::cout << "No puede avanzar saltando otras fichas\n";
                std::system("pause");
                Colorsk::sclr(7);
                break;
            }
        }
        
        break;
    
    default:
        std::cout << "error to dir ";
        std::system("pause");
        
        
        return resint;
        break;
    }
    
    
    if (result)
    {
        resint[0] =  i;
        resint[1] =  j;
    }
    
    
    return resint;
}

/**
 * get the shell color to print
*/

int Tablero::setSellColor(int shell)
{
    if(
        shell == 1 || shell == 10 || shell == 19 || 
        shell == 28 || shell == 37 || shell == 46 || shell == 55 || shell == 64  )
    {
        // return Colorsk::CIAN;
        return 1;
    }
    else if (
        shell == 2 || shell == 13 || shell == 24 || shell == 27 || shell == 38 || 
        shell == 41 || shell == 52|| shell == 63 
    )
    {
        // return Colorsk::AZUL;
        return 2;
    }
    else if(
        shell == 3 || shell == 16 || shell == 21 || shell == 26 || shell == 39 ||
        shell == 44 || shell == 49 || shell == 62
    )
    {
        // return Colorsk::MORADO;
        return 3;
    }
    else if(
        shell == 4 || shell == 11  || shell == 18 || shell == 25 || 
        shell == 40 || shell == 47 || shell == 54 || shell == 61 
    )
    {
        // return Colorsk::FUCSIA;
        return 4;
    }
    else if(
        shell == 5 || shell == 14 || shell == 23 || shell == 32 || shell == 33 ||
        shell == 42 || shell == 51 ||  shell == 60
    )
    {
        // return Colorsk::AMARILLO;
        return 5;
    }
    else if (
        shell == 6 || shell == 9 || shell == 20 || shell == 31 || shell == 34 || 
        shell == 45 || shell == 56 || shell == 59
    )
    {
        // return Colorsk::ROJO;
        return 6;
    }
    else if(
        shell == 7 || shell == 12 || shell == 17 ||  shell == 30 || shell == 35 || 
        shell == 48 || shell == 53 || shell == 58 
    )
    {
        // return Colorsk::VERDE;
        return 7;
    }
    else if(
        shell == 8 || shell == 15 || shell == 22 || shell == 29 || 
        shell == 36 || shell == 43 || shell == 50 || shell == 57 
    )
    {
        // return Colorsk::GRIS;
        return 8;

    }

    return -1;
}

/*devuelve blanco o negro*/
int Tablero::getPiceType(int num)
{
    if (num == 1)
    {
        return 0;
    }
    else
    {
        return 112;
    }
}

/**
 * recibe el numero del color para la pieza 
 * o ficha y devuelve el color 
 */
int Tablero::getPiceColor(int num){
    switch (num)
    {
    case 1:
        return Colorsk::FGCIAN;
        break;
    case 2:
        return Colorsk::FGAZUL;
        break;
    case 3:
        return Colorsk::FGMORADO;
        break;
    case 4:
        return Colorsk::FGFUSCIA;
        break;
    case 5:
        return Colorsk::FGAMARILLO;
        break;
    case 6:
        return Colorsk::FGROJO;
        break;
    case 7:
        return Colorsk::FGVERDE;
        break;
    case 8:
        return Colorsk::FGGRIS;
        break;
    default:
        return -1;
        break;
    }
}

/**
 * le estra el numero seteado en la matriz y retorna el color asociado para pintarlo en la 
 * celda
 */
int Tablero::getSellColor(int num){
    switch (num)
    {
    case 1:
        return Colorsk::CIAN;
        break;
    case 2:
        return Colorsk::AZUL;
        break;
    case 3:
        return Colorsk::MORADO;
        break;
    case 4:
        return Colorsk::FUCSIA;
        break;
    case 5:
        return Colorsk::AMARILLO;
        break;
    case 6:
        return Colorsk::ROJO;
        break;
    case 7:
        return Colorsk::VERDE;
        break;
    case 8:
        return Colorsk::GRIS;
        break;
    default:
        return -1;
        break;
    }
}

//////////// ///////////////////////////////ptinr
void Tablero::printTablero()
{
    printTopL();

    for (int i = 0; i < 8; i++)
    {
        for (int lineP = 1; lineP <= 5; lineP++)
        {
            if(lineP != 2 && lineP != 4)
            {
               std::cout << char(179);
                for (int j = 0; j < 8; j++)
                {
                    this->printFicha(i,j,0,lineP);
                   std::cout << char (179) ;
                    
                }
                //std::cout << "  " <<i <<endl;
                
               std::cout <<endl;
               std::cout.flush();
            }
            
        }

        if (i < 7){
            printMidL();
        }
    }
    
    printBotL();
    // for (int i = 0; i < 8; i++)
    // {
    //     cout <<"  "<<i<<"   ";
    // }
    // cout << endl;


    
}

void Tablero::printTopL()
{
    Colorsk::sclr(240);
    //top line
   std::cout << char(218) ;
    printLine();
    for(int i =0; i<7 ;i++){
       std::cout << char(194) ;
        printLine();
    }   
   std::cout << char(191) <<endl;
}

void Tablero::printMidL()
{
    Colorsk::sclr(240);
    //top line
   std::cout << char(195) ;
    printLine();
    for(int i =0; i<7 ;i++){
       std::cout << char(197) ;
        printLine();
    }   
   std::cout << char(180) <<endl;
}

void Tablero::printBotL()
{
    Colorsk::sclr(240);
    //top line
   std::cout << char(192) ;
    printLine();
    for(int i =0; i<7 ;i++){
       std::cout << char(193) ;
        printLine();
    }   
   std::cout << char(217) << endl;
}

void Tablero::printLine()
{
   std::cout  << char(196)  << char(196) << char(196) << char(196) << char(196)  ;
}

//print the piece 
void Tablero::printFicha(int i, int j, int point, int line)
{
    
    
    switch (line)
    {
    case 1:
        Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
        //std::cout << char(201) << char(196) << char(196) << char(196) << char(196) << char(196) << char(187) ;   
        std::cout << char(201)  << char(196) << char(196) << char(196) << char(187) ;   
        Colorsk::sclr(240);
        break;
    case 2:
        Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
        std::cout << char(179) ;

        if(this->fichas[i][j][0] != 0)
        {
            if(this->fichas[i][j][0] == 1)
            {
                Colorsk::sclr(240);
            }
            else 
            {
                Colorsk::sclr(8);
            }
            
            std::cout << char(219) << char(219) << char(219) << char(219) << char(219) ;
        }
        else 
        {
            Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
            std::cout << "     ";
        }

        Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
        std::cout << char(179); 
        Colorsk::sclr(240);
        break;
    case 3:
        Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
        std::cout << char(179) ;

        if(this->fichas[i][j][0] != 0)
        {
            if(this->fichas[i][j][0] == 1)
            {
                Colorsk::sclr(240);
            }
            else 
            {
                Colorsk::sclr(7);
            }
            
            //std::cout << char(219) << char(219);
            std::cout << char(219) ;

            Colorsk::sclr(
                this->getPiceType(this->fichas[i][j][0]),
                this->getPiceColor(this->fichas[i][j][1])
                );
            std::cout << char(245) ;

            if(this->fichas[i][j][0] == 1)
            {
                Colorsk::sclr(240);
            }
            else 
            {
                Colorsk::sclr(7);
            }
            // std::cout << char(219) << char(219) ;
            std::cout << char(219) ;
        }
        else 
        {
            Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
            std::cout << "   ";
        }
        
        Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
        std::cout << char(179) ;
        Colorsk::sclr(240); 
        break;
    case 4:
        Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
        std::cout << char(179) ;

        if(this->fichas[i][j][0] != 0)
        {
            if(this->fichas[i][j][0] == 1)
            {
                Colorsk::sclr(240);
            }
            else 
            {
                Colorsk::sclr(7);
            }
            
            std::cout << char(219) << char(219) << char(219) << char(219) << char(219) ;
        }
        else 
        {
            Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
            std::cout << "     ";
        }
        
        
        Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
        std::cout << char(179) ;
        Colorsk::sclr(240); 
        break;
    case 5:
        Colorsk::sclr(this->getSellColor(this->tabla[i][j]));
        std::cout << char(200) << char(196) << char(196) << char(196) << char(188) ;
        Colorsk::sclr(240); 
        break;
   
    }

    
     
}


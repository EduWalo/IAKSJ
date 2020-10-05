#include "Nodo.h"

#include <limits>       // std::numeric_limits
                        // std::numeric_limits<int>::min()
                        // std::numeric_limits<int>::max()

#include <iostream>
/**
 * Constructors
*/


Nodo::Nodo(int tipo,int colorF, int tipoF, int profundidad,Tablero estado)
{
    this->tipo = tipo;
    this->colorF = colorF;
    this->typeF = tipoF;
    this->profundidad = profundidad;
    this->estado = estado;
    this->posij = new int[2];

    //inicialización de los nodos
    if(this->tipo == 1)//max
    {
        this->utilidad = std::numeric_limits<int>::min();
    }
    else //min 
    {
        this->utilidad = std::numeric_limits<int>::max();
    }
}
Nodo::~Nodo()
{
}


/**
 * this function calculate the internal utility
*/

int Nodo::calculateUtility()
{
    // se extrae la posición de la ficha a mover de manera obligatoria con el color 
    // ingresado en el nodo

    posij = estado.getIJficha(this->colorF, this->typeF);

    //this->printNodo();
    
    //  se verifica que no se exeda el limite de espanción
    if (this->profundidad == this->prfMax)// se devuelve la utilidad 
    {
        this->utilidad = this->estado.getUtility();
        //std::cout<< "}\n";
        return this->utilidad;
    }

    
    
    //se verifica si es un estado de victoria 
    if (this->estado.winState())
    {
        this->utilidad = this->estado.getUtility();
        //std::cout<< "}\n";
        return this->utilidad;
    }

    

    //ahora sedebe reccorres posibilidad por posibilidad extrayendo 
    // la utilidad que beneficie el tipo de nodo que es

    //el tipo de los nodos que serán hijos son contrarios al mosmo
    if(this->tipo ==1) //max
    {
        ///////////////////////7DIRECTION
        //left j--
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[1] - i < 0)
                break; 
            else if (this->estado.getValFichas(posij[0],posij[1] - i,0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0],posij[1]-i);
            // genero el nodo
            // * 2 -_> es de tipo min
            // * colorHijo, como color obligatorio generado por el mov
            // * 2, poruqe para los de min debe ser blancas
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(2, colorHijo, 2, this->profundidad + 1, tempState); 

            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0]<<"-"<<posij[1]-i<<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();

            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad < tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }
        
        //left j-- up i++ 
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[0] + i > 7 ||posij[1] - i < 0)
                break; 
            else if (this->estado.getValFichas(posij[0] + i,posij[1] - i,0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0] + i,posij[1]-i);
            // genero el nodo
            // * 2 -_> es de tipo min
            // * colorHijo, como color obligatorio generado por el mov
            // * 2, poruqe para los de min debe ser blancas
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(2, colorHijo, 2, this->profundidad + 1, tempState); 

            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0] + i <<"-"<<posij[1]-i<<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();
            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad < tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }
        
        //up i++
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[0] + i > 7 )
                break; 
            else if (this->estado.getValFichas(posij[0] + i,posij[1],0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0] + i,posij[1]);
            // genero el nodo
            // * 2 -_> es de tipo min
            // * colorHijo, como color obligatorio generado por el mov
            // * 2, poruqe para los de min debe ser blancas
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(2, colorHijo, 2, this->profundidad + 1, tempState); 

            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0] + i <<"-"<<posij[1] <<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();
            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad < tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }
        
        //rigth j++ up i++
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[0] + i > 7 || posij[1] + i > 7 )
                break; 
            else if (this->estado.getValFichas(posij[0] + i,posij[1] + i,0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0] + i,posij[1] + i);
            // genero el nodo
            // * 2 -_> es de tipo min
            // * colorHijo, como color obligatorio generado por el mov
            // * 2, poruqe para los de min debe ser blancas
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(2, colorHijo, 2, this->profundidad + 1, tempState); 

            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0] + i <<"-"<<posij[1] + i <<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();
            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad < tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }
        
        //rigth j++
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[1] + i > 7 )
                break; 
            else if (this->estado.getValFichas(posij[0] ,posij[1] + i,0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0] ,posij[1] + i);
            // genero el nodo
            // * 2 -_> es de tipo min
            // * colorHijo, como color obligatorio generado por el mov
            // * 2, poruqe para los de min debe ser blancas
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(2, colorHijo, 2, this->profundidad + 1, tempState); 

            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0] <<"-"<<posij[1] + i <<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();
            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad < tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }   

    }
    else // min 
    {
        
        ///////////////////////7DIRECTIONS
        //left j--
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[1] - i < 0)
                break; 
            else if (this->estado.getValFichas(posij[0],posij[1] - i,0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0],posij[1]-i);
            // genero el nodo
            // * 1 -_> es de tipo max
            // * colorHijo, como color obligatorio generado por el mov
            // * 1, poruqe para los de max debe ser negras
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(1, colorHijo, 1, this->profundidad + 1, tempState); 
            
            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0]<<"-"<<posij[1]-i<<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();

            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad > tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }

        //left j-- up i--
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[1] - i < 0 || posij[1] - i < 0)
                break; 
            else if (this->estado.getValFichas(posij[0] - i,posij[1] - i,0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0]-i,posij[1]-i);
            // genero el nodo
            // * 1 -_> es de tipo max
            // * colorHijo, como color obligatorio generado por el mov
            // * 1, poruqe para los de max debe ser negras
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(1, colorHijo, 1, this->profundidad + 1, tempState); 
            
            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0]-i<<"-"<<posij[1]-i<<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();

            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad > tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }
        
        //up i--
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[0] - i < 0)
                break; 
            else if (this->estado.getValFichas(posij[0]-i,posij[1],0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0]-i,posij[1]);
            // genero el nodo
            // * 1 -_> es de tipo max
            // * colorHijo, como color obligatorio generado por el mov
            // * 1, poruqe para los de max debe ser negras
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(1, colorHijo, 1, this->profundidad + 1, tempState); 
            
            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0]-i<<"-"<<posij[1]<<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();

            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad > tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }
        
        //rigth j++ up i--
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[0] - i < 0 || posij[1] + i > 7)
                break; 
            else if (this->estado.getValFichas(posij[0]-i,posij[1] + i,0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0]-i,posij[1]+i);
            // genero el nodo
            // * 1 -_> es de tipo max
            // * colorHijo, como color obligatorio generado por el mov
            // * 1, poruqe para los de max debe ser negras
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(1, colorHijo, 1, this->profundidad + 1, tempState); 
            
            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0]-i<<"-"<<posij[1]+i<<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();

            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad > tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }
        
        //rigth j ++
        for (int i = 1; i < 8; i++)
        {
            //verificar desbolrde
            if(posij[1] + i > 7)
                break; 
            else if (this->estado.getValFichas(posij[0],posij[1]+i,0) != 0)// verificar si esta ocupado
            {
                break;
            }

            /////////////////// se puede realizar el movimiento

            //copio el estado
            Tablero tempState = this->estado;
            // realizo el movimiento respectivo en el estado temporal
            // guardo el color obligatorio para la siguiente profundidad
            int colorHijo = tempState.mover(posij[0],posij[1],posij[0],posij[1]+i);
            // genero el nodo
            // * 1 -_> es de tipo max
            // * colorHijo, como color obligatorio generado por el mov
            // * 1, poruqe para los de max debe ser negras
            // * tempEstate es el tablero recalculado
            Nodo tempNodo = Nodo(1, colorHijo, 1, this->profundidad + 1, tempState); 
            
            //imprimir coordenadas de testeo
            //std::cout << "("<<posij[0]<<"-"<<posij[1]+i<<") ";
            // guardo la utilidad que me genera el hijo
            int tempUtility = tempNodo.calculateUtility();

            // verifico la instancia para el guardado de la utilidad 
            // como es max, solo guardo si la utilidad obtenida es mayor a la que tengo 
            if (this->utilidad > tempUtility  || (!this->changed) )
            {
                this->changed =true;
                //debo cambiar la utilidad para poder generar ese movimiento como el movimiento con
                //maxima utilidad
                this->utilidad = tempUtility;
                this->estadoMinMax = tempNodo.estado;// se iguala el estado que genera esa jugada
            }
        }
        
       
    }

    

    //std::cout << "}\n";
    
    return this->utilidad;
}


/**
 * Print the nod interno
*/
void Nodo::printNodo()
{
    for (int i = 0; i < this->profundidad; i++)
    {
        std::cout << "\t";
    }
    
    std::cout << "->" ;
    if (this->tipo == 1)
        std::cout<<"MAX->";
    else 
        std::cout<<"MIN->";
    
    std:: cout << this->profundidad << " ["<<this->posij[0]<<"-"<<this->posij[1]<<"] {\n";
}




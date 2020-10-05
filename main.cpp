#include <windows.h>//colores
#include <iostream>// cout 

#include "Tablero.h"
#include "Colorsk.h"

#include "Nodo.h"

using namespace std;


int main(int argc, char const *argv[])
{
	// for (int colour = 0; colour < 256; colour ++)
	// {
	// 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour);
	// 	cout << "hellow word " << colour << endl;
	// }
	


	int turno=2; // 1 negras 2 blancas
	int colorSeleced ;
	int colorobligatorio = -1;
	int direction = -1; //
	int numCasillas = -1;
	int px,py;

	system("mode 80,9999");
	system("cls ");
	cout<<endl<<endl
	<<"\t"<<"------------------------------------------------------------------\n"
	<<"\t"<<"------------------------------------------------------------------\n"
	<<"\t"<< char (219)<< char (219)<< char (187)<< char (32)<< char (32)<< char (219)<< char (219)<< char (187)<< char (32)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (187)<< char (32)<< char (219)<< char (219)<< char (219)<< char (187)<< char (32)<< char (32)<< char (32)<< char (219)<< char (219)<< char (219)<< char (187)<< char (219)<< char (219)<< char (187)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (187)<< char (32)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (187)<< char (32)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (187)<< char (32)<< char (32)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (187)<< char (32) <<endl
	<<"\t"<< char (219)<< char (219)<< char (186)<< char (32)<< char (219)<< char (219)<< char (201)<< char (188)<< char (219)<< char (219)<< char (201)<< char (205)<< char (205)<< char (219)<< char (219)<< char (187)<< char (219)<< char (219)<< char (219)<< char (219)<< char (187)<< char (32)<< char (219)<< char (219)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (201)<< char (205)<< char (205)<< char (205)<< char (205)<< char (188)<< char (219)<< char (219)<< char (201)<< char (205)<< char (205)<< char (219)<< char (219)<< char (187)<< char (219)<< char (219)<< char (201)<< char (205)<< char (205)<< char (219)<< char (219)<< char (187)<< char (219)<< char (219)<< char (201)<< char (205)<< char (205)<< char (205)<< char (219)<< char (219)<< char (187)<<endl
	<<"\t"<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (201)<< char (188)<< char (32)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (201)<< char (219)<< char (219)<< char (219)<< char (219)<< char (201)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (187)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (32)<< char (32)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (32)<< char (32)<< char (32)<< char (219)<< char (219)<< char (186)<<endl
	<<"\t"<< char (219)<< char (219)<< char (201)<< char (205)<< char (219)<< char (219)<< char (187)<< char (32)<< char (219)<< char (219)<< char (201)<< char (205)<< char (205)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (200)<< char (219)<< char (219)<< char (201)<< char (188)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (200)<< char (205)<< char (205)<< char (205)<< char (205)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (201)<< char (205)<< char (205)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (32)<< char (32)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (32)<< char (32)<< char (32)<< char (219)<< char (219)<< char (186)<<endl
	<<"\t"<< char (219)<< char (219)<< char (186)<< char (32)<< char (32)<< char (219)<< char (219)<< char (187)<< char (219)<< char (219)<< char (186)<< char (32)<< char (32)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (32)<< char (200)<< char (205)<< char (188)<< char (32)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (186)<< char (32)<< char (32)<< char (219)<< char (219)<< char (186)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (201)<< char (188)<< char (200)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (219)<< char (201)<< char (188)<<endl
	<<"\t"<< char (200)<< char (205)<< char (188)<< char (32)<< char (32)<< char (200)<< char (205)<< char (188)<< char (200)<< char (205)<< char (188)<< char (32)<< char (32)<< char (200)<< char (205)<< char (188)<< char (200)<< char (205)<< char (188)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (200)<< char (205)<< char (188)<< char (200)<< char (205)<< char (188)<< char (200)<< char (205)<< char (205)<< char (205)<< char (205)<< char (205)<< char (205)<< char (188)<< char (200)<< char (205)<< char (188)<< char (32)<< char (32)<< char (200)<< char (205)<< char (188)<< char (200)<< char (205)<< char (205)<< char (205)<< char (205)<< char (205)<< char (188)<< char (32)<< char (32)<< char (200)<< char (205)<< char (205)<< char (205)<< char (205)<< char (205)<< char (188)<< char (32)<<endl
	<<"\t"<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<< char (32)<<endl
	<<"\t"<<"------------------------------------------------------------------\n"
	<<"\t"<<"------------------------------------------------------------------\n"
	;
	system("pause");                                                           
	system("cls ");
	
	
	
	
	Tablero tablerito ; //tablero

	while (true)
	{
		//print turno
		if (turno == 2){
			
			
			//print tablero como está paradecidir la jugada
			tablerito.printTablero();
			Colorsk::sclr(15);
			cout << "TURNO DE LAS BLANCAS \n\n ----------------------------------------------------\n";

			//select color
			while (colorobligatorio == -1)
			{
				//seleccione el color
				Colorsk::sclr(7);
				cout << "[1]  ";
				Colorsk::sclr(Colorsk::CIAN);
				cout <<"DORADO   \n";
				Colorsk::sclr(15);

				Colorsk::sclr(7);
				cout << "[2]  ";
				Colorsk::sclr(Colorsk::AZUL);
				cout <<"AZUL     \n";
				Colorsk::sclr(15);

				Colorsk::sclr(7);
				cout << "[3]  ";
				Colorsk::sclr(Colorsk::MORADO);
				cout << "MORADO   \n";
				Colorsk::sclr(15);

				Colorsk::sclr(7);
				cout << "[4]  ";
				Colorsk::sclr(Colorsk::FUCSIA);
				cout << "FUCSIA   \n";
				Colorsk::sclr(15);

				Colorsk::sclr(7);
				cout << "[5]  ";
				Colorsk::sclr(Colorsk::AMARILLO);
				cout << "AMARILLO \n";
				Colorsk::sclr(15);

				Colorsk::sclr(7);
				cout << "[6]  ";
				Colorsk::sclr(Colorsk::ROJO);
				cout << "ROJO     \n";
				Colorsk::sclr(15);

				Colorsk::sclr(7);
				cout << "[7]  ";
				Colorsk::sclr(Colorsk::VERDE);
				cout << "VERDE    \n";
				Colorsk::sclr(15);

				Colorsk::sclr(7);
				cout << "[8]  " ;
				Colorsk::sclr(Colorsk::GRIS);
				cout << "CAFE     \n";
				Colorsk::sclr(15);

				Colorsk::sclr(7);
				cout << "Seleccione el color \n>";
				
				cin >> colorSeleced;

				if (colorSeleced >7 || colorSeleced < 1)
				{
					cout << "error-opt selecione del 1 al 7\n";
					system("pause");
					system("cls");
					tablerito.printTablero();
				}
				else
					break;
			}


			//mov select
			int continuar = true;
			while (continuar)
			{	
				// select direction 
				while (true)
				{
					cout << "Seleccione la dirección a moverse \n";
					cout << "[1] Iquierda                  <" << char(196)  << endl;
					cout << "[2] Diagonal izquierda Arriba \\ \n"  ;
					cout << "[3] Arriba                     | \n"  ;
					cout << "[4] Diagonal Derecha Arriba   /\n" ;
					cout << "[5] Derecha                   " << char(196) << ">\n" ;
					
					
					cin >> direction;

					if(direction < 1 || direction > 5)
					{
						cout << "error-opt Seleccione del 1-5\n";
						system("pause");
						system("cls");
						tablerito.printTablero();
					}else 
						break ;
				}
				
				// numero de casillas a moverse 
				while (true)
				{
					cout << "Ingrese la cantidad de casillas que desaea moverse \n";
					cin >> numCasillas;

					if(direction < 0 || direction > 8)//SI ESTA FUERA DE RANGO
					{
						cout << "error-opt Seleccione del 0 - 8\n";
						system("pause");
						system("cls");
						tablerito.printTablero();
					}
					else 
					{
						int* vij ;
						//SI SE PUEDE REALIZAR EL MOVIMIENTO
						if (colorobligatorio == -1) // el color aún no a sido obligado
						{
							vij = tablerito.getIJficha(colorSeleced,turno);
						}
						else // el color si fue definido 
						{
							vij = tablerito.getIJficha(colorobligatorio,turno);
						}
						
						int* nij = tablerito.enbaleMov(vij[0],vij[1],direction,numCasillas);
						
						if(nij[0] != -1)
						{
							// realizar movimiento
							colorobligatorio = tablerito.mover(vij[0],vij[1],nij[0],nij[1]);
							continuar = false;
							
						}
						break;
					}
				}
			}
			
			system("cls ");
			tablerito.printTablero();
			system("pause");
			system("cls ");
			
		}
		else 
		{
			std::cout << "TURNO DE LAS NEGRAS \n\n ----------------------------------------------------\n";
			Nodo aiAttempt = Nodo(1,colorobligatorio,turno,0,tablerito);
			aiAttempt.calculateUtility();

			//si no se hizo cambios se calcula
			if(aiAttempt.changed)
			{
				tablerito = aiAttempt.estadoMinMax;
				cout<<"Jugada de la IA:\n";
				tablerito.printTablero();
				system("pause");
			}
			else
			{
				cout <<"Pasa!!\n";
				system("pause");
				system("cls ");
			}
			

			
			
		}

		
		//mirar victori
		if(tablerito.winState())
		{
			if(turno == 1)
			{
				Colorsk::sclr(Colorsk::AZUL);
				cout <<"\n\nHa ganado la IA\n\n";
				system("Pause");
				Colorsk::sclr(15);
				break;
			}else 
			{
				Colorsk::sclr(Colorsk::AZUL);
				cout <<"\n\nHa ganado la el jugador humano\n\n";
				system("Pause");
				Colorsk::sclr(15);
				break;
			}
		}

		//cambiar de turno
		if (turno == 1)
			turno = 2;
		else 
			turno = 1;
		
		//muestra de acciones
		
		
		
		
	}
	
	cout<< "color ->" << colorobligatorio;
	
	return 0;
}

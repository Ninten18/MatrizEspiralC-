#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void tituloPrincipal()
{
   int i;

   cout<<"===============================================================================\n";
   cout<<"    		  	MATRIZ ESPIRAL         		    "<<endl;
   cout<<"===============================================================================\n"<<endl;
    cout<<"'1' Insertar "<<endl;   
    cout<<"'2' Mostrar"<<endl;
    cout<<"'3' Desea salir del Programa"<<endl;       
   i = 0;
   putchar('\n');
   for (; i < 80; i++) {
      putchar('_');
   }
   cout<<endl;
}

class Matriz_Espiral
{
	private:
		int Matriz[50][50];
		
	public:

		void Matriz_Relleno(int n);
		void Mostrar(int n);
};

void Matriz_Espiral::Mostrar(int n)
{
	cout<<endl<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"\t"<<Matriz[i][j];
			}
			cout<<endl<<endl;
		}
}

void Matriz_Espiral::Matriz_Relleno(int n)
{	
	int verificacion = n % 2;
	int x=0;
	int lim_derecha = 1;
	int lim_izquierda = 2;
	int lim_arriba = 2;
	int lim_abajo = 1;	
	int veces;
	int i,j;

	if(verificacion == 0)
	{
		cout<<endl;
		cout<<"No es una matriz IMPAR";
	}
	else
	{
		int valor;
		int cantidad = n*n;
		int centro = n/2;
		i = centro;
		j = centro;
		cout<<"Digite el dato de la Matriz ["<<(i+1)<<"],["<<(j+1)<<"] :";
		cin>>valor;
		Matriz[i][j] = valor;
		x++;

		while(x<cantidad)
		{
			veces=0;					//lim_derecha=1,3,5,  "6"-> es un caso especial
			while(veces < lim_derecha)
			{
				j++;
				cout<<"Digite el dato de la Matriz ["<<(i+1)<<"],["<<(j+1)<<"] :";
				cin>>valor;
				Matriz[i][j] = valor;
				veces++;
				x++;
			}

			veces=0;
			while(veces < lim_abajo)
			{
				i++;
				cout<<"Digite el dato de la Matriz ["<<(i+1)<<"],["<<(j+1)<<"] :";
				cin>>valor;
				Matriz[i][j] = valor;
				veces++;
				x++;
			}

			veces=0;
			while(veces < lim_izquierda)
			{
				j--;
				cout<<"Digite el dato de la Matriz ["<<(i+1)<<"],["<<(j+1)<<"] :";
				cin>>valor;
				Matriz[i][j] = valor;
				veces++;
				x++;
			}

			veces=0;
			while(veces < lim_arriba)
			{
				i--;
				cout<<"Digite el dato de la Matriz ["<<(i+1)<<"],["<<(j+1)<<"] :";
				cin>>valor;
				Matriz[i][j] = valor;
				veces++;
				x++;
			}


			veces=0;
			if((lim_izquierda == n-1 ) || (lim_arriba == n-1))
			{
				while(veces < n-1)
				{
					j++;
					cout<<"Digite el dato de la Matriz ["<<(i+1)<<"],["<<(j+1)<<"] :";
					cin>>valor;
					Matriz[i][j] = valor;
					veces++;
					x++;
				}
			}

			lim_derecha = lim_derecha + 2;
			lim_arriba = lim_arriba + 2;
			lim_izquierda = lim_izquierda + 2;
			lim_abajo = lim_abajo + 2;

		}

	}	
}

void main()
{
	system("COLOR 0A");
	Matriz_Espiral Prueba;
	int n=0;	
	int opcion;	
	while(opcion != 3)
	{
		tituloPrincipal();
		cout<<"Opcion:";
		cin>>opcion;
		clrscr();
		switch(opcion)
		{
			case 1:
			{
				tituloPrincipal();
				cout<<"Digite la proporcion de la matriz cuadrada :";
				cin>>n;
				cout<<endl;
				Prueba.Matriz_Relleno(n);
				cout<<"\n\nPulse enter"<<endl;
	            getch();
	            clrscr(); 
				break;
			}
			case 2:
			{
				tituloPrincipal();
				if((n % 2 == 0) || (n == 0))
				{
					cout<<"No existe la matriz"<<endl;
				}
				else
				{
					cout<<"Matriz de "<<n<<" x "<<n<<":"<<endl;
					cout<<endl;
					Prueba.Mostrar(n);
				}
				cout<<"\n\nPulse enter"<<endl;
	            getch();
	            clrscr(); 
				break;
			}
		}
	}
	
	cout<<endl<<endl;
	system("PAUSE");
}

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>



using namespace std;
using namespace chrono;

int minimoMoedas(int moedas[], int m, int V) 
{ 
   //caso base 
   if (V == 0) return 0; 
  
   //inicializando o resultado
   int resultado = INT_MAX; 
  
   // tente todas as moedas com o valor menor que V
   for (int i = 0; i < m; i++) 
   { 
     if (moedas[i] <= V) 
     { 
         int segundoR = minimoMoedas(moedas, m, V-moedas[i]); 
  
         if (segundoR != INT_MAX && segundoR + 1 < resultado) 
            resultado = segundoR + 1; 
    	} 
	}
   	return resultado; 
} 

int main() 
	{	 
	
		milliseconds timem[50];
		int moedas[] =  {1, 3, 4, 25}; 
		int m = sizeof(moedas)/sizeof(moedas[0]); 
	
		for(int i = 0 ; i <= 40 ; i++){
			
	    	auto start = std::chrono::steady_clock::now(); 
		 	int rest =  minimoMoedas(moedas, m, i);
		   	auto end = steady_clock::now();
		   	timem[i] = duration_cast<milliseconds>(end - start);
		   	cout << "Valor do troco:"<< i << "\t Tempo: " << timem[i].count() << " milliseconds" << endl;
		
	   	}
	
		FILE *sv = fopen("Min_data.txt","w");
		for(int i = 1 ; i<=40;i++){
				fprintf(sv,"%d\t%lli \n",i,timem[i].count());
		}
		fclose(sv);
	
		//Salvando script de plot- recursivo sem memorizacao
		FILE *sc = fopen("scriptMin_gnu.plt", "w");
		fprintf(sc,"set title \"Minimo moedas\"\n ");
		fprintf(sc,"set grid \n ");
		fprintf(sc,"set xlabel \"Qtd troco\"\n ");
		fprintf(sc,"set ylabel \"Tempo gasto (milliseconds)\"\n ");
		fprintf(sc,"plot \"Min_data.txt\" with linespoints lc 1 \n ");
		fclose(sc);

		system("start scriptMin_gnu.plt");
    	return 0; 
	}	 




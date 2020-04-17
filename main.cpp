#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* 
	Trabalho de Analise e Complexidade de Algoritmos -FEI
	
	Guilherme Henrique Moreira
	Victor Milani
	
	
	Analise 1
	-----------------------------------------------------------
	Este programa calcula todos os numeros da serie de fibonacci de 1 a 44, 
	conometrando o tempo de excucao de cada numero calculado.
	
	O tempo eh salvo em um arquivo "fib_data.txt" e plotado pelo arquivo "script_gnu.plt"
 */


//Funcao de fibonacci
int fib (int n){
   if(n==1  || n==2){
       return 1;
    }
   else{
       return fib(n-1) + fib(n-2);
  	}	
}


int main(int argc, char** argv) {	
	//Vetores de tempo e resultado 
	int b [45];
	clock_t time [45];

	//Loop de iteracoes dos vetores
	for(int i = 1 ; i<45;i++){
		time[i] = clock();				//Grava clock atual
		b[i] = fib(i);					//Calculo de Fibonacci
		time[i] = clock() - time[i];	//Clock atual - Clock antigo (tempo de execução da linha 43)
		
		//Prints no prompt
		printf("\n Fib de %d = %d \t",i,b[i]);
		printf("Tempo:%1.lf",((double)time[i])/((CLOCKS_PER_SEC/1000)));
	}
	
	//Salvando dados em arquivos
	FILE *sv = fopen("fib_data.txt","w");
	for(int i = 1 ; i<45;i++){
		fprintf(sv,"%d\t%lf\n",b[i],(double)time[i]);
	}
	fclose(sv);

	//Salvando script de plot
	FILE *sc = fopen("script_gnu.plt", "w");
	fprintf(sc,"set title \"Ordenação Insertion Sort\"\n ");
	fprintf(sc,"set grid \n ");
	fprintf(sc,"set xlabel \"Quantidade de itens no vetor\"\n ");
	fprintf(sc,"set ylabel \"Tempo gasto para ordenar\"\n ");
	fprintf(sc,"plot \"fib_data.txt\" with linespoints lc 1 \n ");
	fclose(sc);
	
	//chamada do script de plot
	system("start script_gnu.plt");
	
	return 0;
}

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
   if(n==0  || n==1){
       return n;
    }
   else{
       return fib(n - 2) + fib(n - 1);
  	}	
}

//Funcao de fibonacci utilizando programacao dinamica
int fibDin(int n){
	
	int st = 0;
	int nd = 1;
	if(n <= 1){
		return n;
	}
	
	int ans = st + nd;	
	for(int i = 2; i <= n ; i++){
		ans = st + nd;
		st = nd;
		nd = ans;
	}
	
	return ans;
}



int main(int argc, char** argv) {	
	//Vetores de tempo e resultado 
	int b [45];
	clock_t timeb [45];
	double d [500];
	clock_t timed [500];

	//Loop de iteracoes dos vetores
	for(int i = 1 ; i<45;i++){
		timeb[i] = clock();				//Grava clock atual
		b[i] = fib(i);					//Calculo de Fibonacci
		timeb[i] = clock() - timeb[i];	//Clock atual - Clock antigo (tempo de execução da linha 43)
		
		//Prints no prompt
		printf("\n Fib de %d = %d \t",i,b[i]);
		printf("Tempo:%4.lf",((double)timeb[i])/((CLOCKS_PER_SEC/1000)));
	}
	
	//Salvando dados em arquivos
	FILE *sv = fopen("fib_data.txt","w");
	for(int i = 1 ; i<45;i++){
		fprintf(sv,"%d\t%lf\n",i,(double)timeb[i]/1000);
	}
	fclose(sv);

	//Salvando script de plot
	FILE *sc = fopen("script_gnu.plt", "w");
	fprintf(sc,"set title \"Sequencia De Fibonacci Recursivo\"\n ");
	fprintf(sc,"set grid \n ");
	fprintf(sc,"set xlabel \"Num da Sequencia de Fib\"\n ");
	fprintf(sc,"set ylabel \"Tempo gasto para ordenar (Segundos)\"\n ");
	fprintf(sc,"plot \"fib_data.txt\" with linespoints lc 1 \n ");
	fclose(sc);


	//Fib Dinamico
	//Loop de iteracoes dos vetores
	for(int i = 1 ; i<45;i++){
		timed[i] = clock();				//Grava clock atual
		d[i] = fibDin(i);				//Calculo de Fibonacci
		timed[i] = clock() - timed[i];	//Clock atual - Clock antigo (tempo de execução da linha 43)
		
		//Prints no prompt
		printf("\n Fib Dinamico de %d = %d \t",i,d[i]);
		printf("Tempo:%4.lf",((double)timed[i])/((CLOCKS_PER_SEC/1000)));
	}
	
	//Salvando dados em arquivos
	sv = fopen("fibDin_data.txt","w");
	for(int i = 1 ; i<45;i++){
		fprintf(sv,"%d\t%lf\n",i,(double)timed[i]/1000);
	}
	fclose(sv);

	//Salvando script de plot
	sc = fopen("scriptDin_gnu.plt", "w");
	fprintf(sc,"set title \"Sequencia De Fibonacci Dinamica\"\n ");
	fprintf(sc,"set grid \n ");
	fprintf(sc,"set xlabel \"Num da Sequencia de Fib\"\n ");
	fprintf(sc,"set ylabel \"Tempo gasto para ordenar (Segundos)\"\n ");
	fprintf(sc,"plot \"fibDin_data.txt\" with linespoints lc 1 \n ");
	fclose(sc);
	
	
	//chamada dos scripts de plot
	system("start script_gnu.plt");
	system("start scriptDin_gnu.plt");
	
	return 0;
}

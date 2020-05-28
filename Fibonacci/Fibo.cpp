#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
/* 
	Trabalho de Analise e Complexidade de Algoritmos -FEI
	
	Guilherme Henrique Moreira
	Victor Milani
	
	
	Analise 1
	-----------------------------------------------------------
	Este programa calcula todos os numeros da serie de fibonacci de 1 a 500,
	com excecao do algoritmo recursivo SEM memorização (pois iria demorar muito tempo).
	 
	Foi conometrado o tempo em nanosegundos de cada algoritmo utilizando a bibilioteca chrono.
	
	O tempo eh salvo em um arquivo "fib_data.txt", "fibMem_data.txt" "fibDin_data.txt"  
	e plotado pelo arquivo "script_gnu.plt", "scriptM_gnu.plt", "scriptDin_gnu.plt"
 */
 
using namespace std;
using namespace chrono;

//Funcao de fibonacci recursivo sem memorização
int fib (int n){
   if(n==0  || n==1){					//Caso Base
       return n;
    }
   else{
       return fib(n - 2) + fib(n - 1);	//Caso Recursivo
  	}	
}

//Funcao de fibonacci recursivo com memorização
long long int mem[500]; 		//Vetor de memorizacao
long long int fibMem (int n){
   if(n==0 || n==1){			//Caso base
       return n;
	}
   else{
   		if(mem[n] != 99){		//Caso recursivo aonde ja foi memorizado
   			return mem[n];
		   }
		else if(mem[n] == 99){	//Caso recursivo aonde nao foi memorizado
			mem[n-2]= fibMem(n-2);
			mem[n-1]= fibMem(n-1);
			mem[n] = mem[n-2] + mem[n-1];
			return mem[n];
		}
  	}
}

//Funcao para resetar o vetor entre as chamadas de fibMem();
void resetmem(){
	for(int i = 0; i<500;i++){
		mem[i]=99;				//Utilizado um valor que nao esta presente na sequencia de fibonacci
	}
	//Casos base pre inseridos
	mem[0]=0;
	mem[1]=1;
}


//Funcao de fibonacci utilizando programacao dinamica
long long int fibDin(int n){
	
	long long int st = 0;		//Primeiro indice
	long long int nd = 1;		//Segundo indice
	if(n <= 1){					//Caso n <= 1 retorna n;
		return n;
	}
	
	long long int ans = st + nd;	//Resposta = indice1 + indice2
	for(int i = 2; i <= n ; i++){	//For iterativo ate N
		ans = st + nd;				//Calculo da proxima resposta
		st = nd;					//Indice1 passa a ser Indice2
		nd = ans;					//Indice2 passa a ser a Resposta 
	}
	
	return ans;
}



int main(int argc, char** argv) {	


	//Vetores de tempo e resultado do algoritmo recursivo sem memorizacao
	int b [45];				
	nanoseconds timeb [45];
	
	//Vetores de tempo e resultado do algoritmo recursivo com memorizacao
	long long int m [500];
	nanoseconds timem [500];
	
	//Vetores de tempo e resultado do algoritmo dinamico
	long long int d [500];
	nanoseconds timed [500];
	
	//Ponteiros para os arquivos
	FILE *sv;
	FILE *sc;
	

	//Fib recursivo -----------------------------------------------------------------------------------------
	//Loop de iteracoes dos vetores
	for(int i = 1 ; i<45;i++){
		auto start = std::chrono::steady_clock::now(); 
	 	b[i]=fib(i);
	   	auto end = steady_clock::now();
	   	timeb[i] = duration_cast<nanoseconds>(end - start);
	   	
	  	cout <<"Fib Recursivo de: " << i << "\t Tempo: "  
		<< timeb[i].count() << " nanoseconds" << std::endl;
	}
	
	//Fib Recursivo com memorizacao -----------------------------------------------------------------------------------------
	//Loop de iteracoes dos vetores
	
	for(int i = 1 ; i<500;i++){
		resetmem();
		auto start = std::chrono::steady_clock::now(); 
	 	m[i]=fibMem(i);
	   	auto end = steady_clock::now();
	   	timem[i] = duration_cast<nanoseconds>(end - start);
	   	
	  	cout <<"Fib c Memorizacao de: " << i << "\t Tempo: " 
	    << timem[i].count() << " nanoseconds" << std::endl;
	}
	
	//Fib Dinamico -----------------------------------------------------------------------------------------
	//Loop de iteracoes dos vetores
	for(int i = 1 ; i<500;i++){
		auto start = std::chrono::steady_clock::now(); 
	 	d[i]=fibDin(i);
	   	auto end = steady_clock::now();
	   	timed[i] = duration_cast<nanoseconds>(end - start);
	   	
	  	cout <<"Fib dinamico de: " << i << "\t Tempo: " 
	    << timed[i].count() << " nanoseconds" << std::endl;
	}
	
	//SAVE DATA -----------------------------------------------------------------------------------------
	//Salvando dados em arquivo- recursivo sem memorizacao
	sv = fopen("fib_data.txt","w");
	for(int i = 1 ; i<45;i++){
		fprintf(sv,"%d\t%lli \n",i,(long long int)timeb[i].count());
	}
	fclose(sv);
	
	//Salvando dados em arquivo- recursivo com memorizacao
	sv = fopen("fibM_data.txt","w");
	for(int i = 1 ; i<500;i++){
			fprintf(sv,"%d\t%lli \n",i,timem[i].count());
	}
	fclose(sv);
	
	//Salvando dados em arquivo- dinamico
	sv = fopen("fibDin_data.txt","w");
	for(int i = 1 ; i<500;i++){
		fprintf(sv,"%d\t%lli\n",i,timed[i].count());
	}
	fclose(sv);


	//Salvando script de plot- recursivo sem memorizacao
	sc = fopen("script_gnu.plt", "w");
	fprintf(sc,"set title \"Sequencia De Fibonacci Recursivo SEM memorizacao\"\n ");
	fprintf(sc,"set grid \n ");
	fprintf(sc,"set xlabel \"Num da Sequencia de Fib\"\n ");
	fprintf(sc,"set ylabel \"Tempo gasto para ordenar (Nanosegundos)\"\n ");
	fprintf(sc,"plot \"fib_data.txt\" with linespoints lc 1 \n ");
	fclose(sc);
	
	//Salvando script de plot- recursivo com memorizacao
	sc = fopen("scriptM_gnu.plt", "w");
	fprintf(sc,"set title \"Sequencia De Fibonacci Recursivo com Memorizacao\"\n ");
	fprintf(sc,"set grid \n ");
	fprintf(sc,"set xlabel \"Num da Sequencia de Fib\"\n ");
	fprintf(sc,"set ylabel \"Tempo gasto para ordenar (Nanosegundos)\"\n ");
	fprintf(sc,"plot \"fibM_data.txt\" with linespoints lc 1 \n ");
	fclose(sc);
	
	//Salvando script de plot- dinamico
	sc = fopen("scriptDin_gnu.plt", "w");
	fprintf(sc,"set title \"Sequencia De Fibonacci Dinamica\"\n ");
	fprintf(sc,"set grid \n ");
	fprintf(sc,"set xlabel \"Num da Sequencia de Fib\"\n ");
	fprintf(sc,"set ylabel \"Tempo gasto para ordenar (Nanosegundos)\"\n ");
	fprintf(sc,"plot \"fibDin_data.txt\" with linespoints lc 1 \n ");
	fclose(sc);
	

	//chamada dos scripts de plot
	system("start script_gnu.plt");
	system("start scriptM_gnu.plt");
	system("start scriptDin_gnu.plt");
	
	return 0;
}

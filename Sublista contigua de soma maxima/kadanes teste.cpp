#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
 
using namespace std;
using namespace chrono;

long long int kadane(vector<int> &vet){
	
	long long int max_atual = 0, max_total = -1;
	long long int size_vet = vet.size();
	
	for(int i = 0; i < size_vet; i++)
	{
	
		max_atual = max_atual + vet[i];
		
		if(max_atual < 0)
			max_atual = 0;
		if(max_atual > max_total)
			max_total = max_atual;
 	
	}	
	return max_total;
}

int main(int argc, char** argv) {
	printf("Inserir um vetor manualmente, ou utilizar vetores padroes?\n");
	printf("Digite: \n 1- Inserir manualmente \n 2- Utilizar vetores padroes \n");
	int ch =0;
	cin >> ch;
	
	if(ch == 2){
		printf(" [ - ] ------------------------ [ - ] \n");
		nanoseconds timeb [6];
		//-------------------------------------------
		long long int rest100=0;
		vector<int> vet100(100);
		for(int i =0; i < 100; i++){
			vet100[i] = (rand() % 10000) - 5000;
		}
		auto start = std::chrono::steady_clock::now(); 	
		rest100=kadane(vet100);
		auto end = steady_clock::now();
		timeb[0] = duration_cast<nanoseconds>(end - start);
		cout << "Soma maxima vetor[100]: " << rest100 
		<< "\t Tempo:"<< timeb[0].count() << " ns "<<endl;
		
		//-------------------------------------------
		long long int rest500=0;
		vector<int> vet500(500);
		for(int i =0; i < 500; i++){
			vet500[i] = (rand() % 10000) - 5000;
		}
		start = std::chrono::steady_clock::now(); 	
		rest500=kadane(vet500);
		end = steady_clock::now();
		timeb[1] = duration_cast<nanoseconds>(end - start);
		cout << "Soma maxima vetor[500]: " << rest500 	
		<< "\t Tempo:"<< timeb[1].count() << " ns "<<endl;
		
		//-------------------------------------------
		long long int rest1000=0;
		vector<int> vet1000(1000);
		for(int i =0; i < 1000; i++){
			vet1000[i] = (rand() % 10000) - 5000;
		}
		start = std::chrono::steady_clock::now(); 	
		rest1000=kadane(vet1000);
		end = steady_clock::now();
		timeb[2] = duration_cast<nanoseconds>(end - start);
		cout << "Soma maxima vetor[1000]: " << rest1000 	
		<< "\t Tempo:"<< timeb[2].count() << " ns "<<endl;
		
		//-------------------------------------------
		long long int rest1500=0;
		vector<int> vet1500(1500);
		for(int i =0; i < 1500; i++){
			vet1500[i] = (rand() % 10000) - 5000;
		}
		start = std::chrono::steady_clock::now(); 	
		rest1500=kadane(vet1500);
		end = steady_clock::now();
		timeb[3] = duration_cast<nanoseconds>(end - start);
		cout << "Soma maxima vetor[1500]: " << rest1500 
		<< "\t Tempo:"<< timeb[3].count() << " ns "<<endl;
		
		//-------------------------------------------
		long long int rest2000=0;
		vector<int> vet2000(2000);
		for(int i =0; i < 2000; i++){
			vet2000[i] = (rand() % 10000) - 5000;
		}
		start = std::chrono::steady_clock::now(); 	
		rest2000=kadane(vet2000);
		end = steady_clock::now();
		timeb[4] = duration_cast<nanoseconds>(end - start);
		cout << "Soma maxima vetor[2000]: " << rest2000 	
		<< "\t Tempo:"<< timeb[4].count() << " ns "<<endl;
		
		//-------------------------------------------
		long long int rest4000=0;
		vector<int> vet4000(4000);
		for(int i =0; i < 4000; i++){
			vet4000[i] = (rand() % 10000) - 5000;
		}
		start = std::chrono::steady_clock::now(); 	
		rest4000=kadane(vet4000);
		end = steady_clock::now();
		timeb[5] = duration_cast<nanoseconds>(end - start);
		cout << "Soma maxima vetor[4000]: " << rest4000 
		<< "\t Tempo:"<< timeb[5].count() << " ns "<<endl;
		
		//-------------------------------------------
		long long int rest8000=0;
		vector<int> vet8000(8000);
		for(int i =0; i < 8000; i++){
			vet8000[i] = (rand() % 10000) - 5000;
		}
		start = std::chrono::steady_clock::now(); 	
		rest8000=kadane(vet8000);
		end = steady_clock::now();
		timeb[6] = duration_cast<nanoseconds>(end - start);
		cout << "Soma maxima vetor[8000]: " << rest8000 
		<< "\t Tempo:"<< timeb[6].count() << " ns "<<endl;
		
		
		
		FILE *sv = fopen("kadanes_data.txt","w");
			fprintf(sv,"%d\t%lli\n",100,timeb[0]);
			fprintf(sv,"%d\t%lli\n",500,timeb[1]);
			fprintf(sv,"%d\t%lli\n",1000,timeb[2]);
			fprintf(sv,"%d\t%lli\n",1500,timeb[3]);
			fprintf(sv,"%d\t%lli\n",2000,timeb[4]);
			fprintf(sv,"%d\t%lli\n",4000,timeb[5]);
			fprintf(sv,"%d\t%lli\n",8000,timeb[6]);				
		fclose(sv);
	
		//Salvando script de plot
		
		FILE *sc = fopen("scriptKada_gnu.plt", "w");
			fprintf(sc,"set title \"Soma maxima kadanes\"\n ");
			fprintf(sc,"set grid \n ");
			fprintf(sc,"set xlabel \"Tamanho do vetor\"\n ");
			fprintf(sc,"set ylabel \"Tempo de execucao(nanosegundos)\"\n ");
			fprintf(sc,"plot \"kadanes_data.txt\" with linespoints lc 2 \n ");
		fclose(sc);
		
		system("start scriptKada_gnu.plt");
	}else if( ch == 1){
		printf(" [ - ] ------------------------ [ - ] \n ");
		nanoseconds timee;
		int tam = 0;
		printf("\n Digite o tamanho do vetor : ");
		cin >> tam;
		vector<int> vet(tam);
		for(int i =0;i<tam;i++){
			printf("\n Digite a posicao %d do vetor:", i);
				cin >> vet[i];
		}
		long long int rest = 0;
		auto start = std::chrono::steady_clock::now(); 	
		rest=kadane(vet);
		auto end = steady_clock::now();
		timee = duration_cast<nanoseconds>(end - start);
		cout << "\n Soma maxima = " << rest << endl;
		cout << "\n Tempo de execucao = " << timee.count() << " ns "<<endl;
		
	}else if(ch != 0 || ch != 1){
		printf("Opcao invalida!!");
	}
	
	return 0;
}

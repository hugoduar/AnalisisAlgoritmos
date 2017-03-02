#include <stdio.h>
#include <stdlib.h>

void shellSort(int Data[], int dataLenght){
	int k = dataLenght/2;
	while(k>=1){
		int v,j;
		for(int i=k; i<dataLenght; i++){
			v= Data[i];
			j= i - k;
			while(j>=0 && Data[j]>v){
				Data[j+k] = Data[j];
				j-=k;
			}
			Data[j + k] = v;
		}
		k/=2;
	}
}

void printAnswer(int Data[], int dataLenght){
	for(int i=0; i<dataLenght; i++){
		printf("%d ", Data[i]);
	}
}

int main(int argc, char const *argv[]){
	int dataLenght = 0;
	freopen("numeros10millones.txt","r",stdin);
	if(argc!=0){
		dataLenght = atoi(argv[1]);
		int Data[dataLenght];
		for(int i = 0; i<dataLenght; i++){
			scanf("%d", &Data[i]);
		}
		shellSort(Data, dataLenght);
		//printAnswer(Data, dataLenght);
	}
	return 0;
}


//gcc-4.9 shellSort.c -o shellSort -std=c11 && ./shellSort 10000





#include <stdio.h>
#include <stdlib.h>


void swap(int *greaterData, int *smallerData){
	int temporary =*greaterData;
	*greaterData = *smallerData;
	*smallerData = temporary;
}

void simpleBubbleSort(int Data[], int dataLenght){
	for(int i=0; i<dataLenght; i++){
		for(int j=0; j<dataLenght-1; j++){
			if(Data[j] > Data[j+1]){
				swap(&Data[j],&Data[j+1]);
			}
		}
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
		simpleBubbleSort(Data, dataLenght);
		//printAnswer(Data, dataLenght);
	}
	return 0;
}

//gcc-4.9 bubbleSort.c -o bubbleSort -std=c11 && ./bubbleSort 10000

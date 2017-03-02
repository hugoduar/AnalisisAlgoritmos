#include <stdio.h>
#include <stdlib.h>


void swap(int *greaterData, int *smallerData){
	int temporary =*greaterData;
	*greaterData = *smallerData;
	*smallerData = temporary;
}

void optimizedBubbleSort(int Data[], int dataLenght){
	for(int i=0; i<dataLenght; i++){
		for(int j=0; j<i; j++){
			if(Data[i] < Data[j]){
				swap(&Data[j],&Data[i]);
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
		optimizedBubbleSort(Data, dataLenght);
		//printAnswer(Data, dataLenght);
	}
	
	return 0;
}


//gcc-4.9 bubbleOptimizedSort.c -o bubbleOptimizedSort -std=c11 && ./bubbleOptimizedSort 10000



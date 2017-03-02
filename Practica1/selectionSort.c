#include <stdio.h>
#include <stdlib.h>

void swap(int *greaterData, int *smallerData){
	int temporary =*greaterData;
	*greaterData = *smallerData;
	*smallerData = temporary;
}

void selectionSort(int Data[], int dataLenght){
	for( int k=0; k<dataLenght; k++){
		int p= k;
		for(int i=k+1; i<dataLenght; i++){
			if(Data[i]<Data[p]){
				p=i;
			}
		}
		if(p!=k){
			swap(&Data[p], &Data[k]);
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
		selectionSort(Data, dataLenght);
		//printAnswer(Data, dataLenght);
	}
	return 0;
}

//gcc-4.9 selectionSort.c -o selectionSort -std=c11 && ./selectionSort 10000



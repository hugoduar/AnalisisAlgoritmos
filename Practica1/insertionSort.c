#include <stdio.h>
#include <stdlib.h>


void insertionSort(int Data[], int dataLenght){
	int previousValue;
	for(int i=1; i<dataLenght; i++){
		int temporary = Data[i];
		previousValue=i-1;
		while((Data[previousValue]>temporary) && (previousValue>=0)){
			Data[previousValue+1] = Data[previousValue];
			previousValue--;
		}
		Data[previousValue+1] = temporary;
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
		insertionSort(Data, dataLenght);
		//printAnswer(Data, dataLenght);
	}
	return 0;
}


//gcc-4.9 insertionSort.c -o insertionSort -std=c11 && ./insertionSort 10000

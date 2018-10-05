#include<stdio.h>
#include<stdlib.h>

int *setUpFrequencyTable(char* data, int data_size) {
	
	int* frequency_table = (int *)  calloc(127,sizeof(int));
	
	int frequency_table_size;
	for (int i=0; i<data_size; i++){
		printf("%ld\n", data[i]);
		
		if((int)data[i] >= 0 && (int)data[i] <= 127){
			
			frequency_table[(int)data[i]]++;
			printf("frequencia: %d\n\n", frequency_table[(int)data[i]]);
		}
	}
	
}

int main(int argc, char *argv[]) {
	FILE* arq;
	int result;
	
	arq = fopen(argv[1], "rb");
	if (arq == NULL) {
		printf("Problemas na abertura do arquivo\n");
		return 0;
	}
	
	char vet[100];
	
	result = fread (&vet, sizeof(char), 100, arq);
	printf("Nro de elementos lidos: %d\n", result);
    
    setUpFrequencyTable(vet, result);
    fclose(arq);
	
	}

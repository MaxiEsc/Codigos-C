#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define N 10

bool array_is_sorted(int a[], unsigned int length){
	bool orden = true;
	int j = 0;
	
	while(j < (length) - 1 ){
		
		if (a[j] < a[j + 1]){
			
			orden = orden && true;
		
		}else{
		
			orden = orden && false;
		}
		j = j + 1;
	}
	return orden;
}

bool goes_before(int x, int y){
	bool before = true ;
	
	if(x < y){
		before = ( before && true );
	}else{
		
		before = ( before && false );
	}
	
	return before;
}

void swap(int a[], unsigned int i,unsigned int j){		
	
	int temporal;
	temporal = a[i];
	a[i] = a[j];
	a[j] = temporal;
	
}	

static void insert(int a[], unsigned int i) {
	
	int j;
	j = i;
	
	while( j > 0 && goes_before(a[j],a[j - 1])){
		swap(a,j,j-1);
		j = j - 1;
	}
}


void insertion_sort(int a[], unsigned int length) {
	
	for (unsigned int i = 0; i < length; ++i) {
		
		insert(a, i);
		
	}
	assert(array_is_sorted(a,length));
}

void mostrar(int a[],unsigned int tam){
	
	printf("\n");
	for(int i = 0; i < tam; i++){
		printf("| %d | ", a[i]);
	}
	printf("\n");
}

int main(){
	
	int arr[N] = {12,4,5,6,8,9,3,13,-9,34};
	mostrar(arr,N);
	insertion_sort(arr,N);
	mostrar(arr,N);
	
	return 0;
}

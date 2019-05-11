#include <stdio.h>

void insertionSort(int *A, int num){
	int i, j;

	for(i=1; i<num; i++){
		int curElement = A[i];
		j = i-1;
		while(j >= 0 && A[j] > curElement){
			A[j+1] = A[j];
			j--;
		}

		A[j+1] = curElement;
	}
}

int main(){
	int i, j, num;

    printf("\nInsertion Sort\n");
    printf("===========================================================================\n");
    printf("Enter the no. of elements : ");
    scanf("%d", &num);

    int arr[num];
    
    for(i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, num);
    
    printf("The elements in accending order : \n");
    for(i=0; i<num; i++){
        printf("%d\t", arr[i]);   
    }
    printf("\n");

	return 0;
}

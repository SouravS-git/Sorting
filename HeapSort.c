#include <stdio.h>

int num;

void maxHeapify(int *A, int root){
    int left = 2*root;
    int right = left+1;
    int max;

    if(left <= num && A[left] > A[root]){
        max = left;
    }else{
        max = root;
    }

    if(right <= num && A[right] > A[max]){
        max = right;
    }

    if(root != max){
        A[root] = A[max] + A[root];
        A[max] = A[root] - A[max];
        A[root] = A[root] - A[max];

        maxHeapify(A, max);
    }
}

void buildMaxHeap(int *A){
    int i;
    int lastNonLeaf = (num/2);
    
    for(i=lastNonLeaf; i>=1; i--){
        maxHeapify(A, i);
    }
}

void heapSort(int *A){
    buildMaxHeap(A);

    int i;
    while(num>1){
        A[1] = A[num] + A[1];
        A[num] = A[1] - A[num];
        A[1] = A[1] - A[num];

        num--;

        maxHeapify(A, 1);
    }
}

int main(){
	int i, j;

    printf("\nHeap Sort\n");
    printf("===========================================================================\n");
    printf("Enter the no. of elements : ");
    scanf("%d", &num);
    int n = num;

    int arr[num+1];
    
    for(i=1; i<=num; i++){
        scanf("%d", &arr[i]);
    }

    heapSort(arr);
    
    printf("The elements in accending order : \n");
    for(i=1; i<=n; i++){
        printf("%d\t", arr[i]);   
    }
    printf("\n");

	return 0;
}

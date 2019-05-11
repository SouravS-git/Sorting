#include <stdio.h>
#include <math.h>

void merge(int *A, int p, int q, int r){
    int i, j, k;
    int n1 = (q-p)+1;
    int n2 = (r-q);
    int L[n1];
    int R[n2];
    
    for(i=0; i<n1; i++)
        L[i] = A[p+i];
        
    for(i=0; i<n2; i++)
        R[i] = A[q+1+i];
    
    i = 0, j = 0;

    for(k=p; k<=r; k++){
        if(i < n1 && j < n2){
            if(L[i] < R[j]){
                A[k] = L[i];
                i++;
            }else{
                A[k] = R[j];
                j++;
            }
        }else{
            while(i < n1 && k <= r){
                A[k++] = L[i++];
            }

            while(j < n2 && k <= r){
                A[k++] = R[j++];
            }
        }
    }
}

void mergeSort(int *A, int p, int r){
    if(r>p){
        int q = (p+r)/2;
        
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int i, j, num;

    printf("\nMerge Sort\n");
    printf("===========================================================================\n");
    printf("Enter the no. of elements : ");
    scanf("%d", &num);
    
    int arr[num];
    
    for(i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, num-1);
    
    printf("The elements in accending order : \n");
    for(i=0; i<num; i++){
        printf("%d\t", arr[i]);   
    }
    printf("\n");

    return 0;
}
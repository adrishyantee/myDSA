#include<stdio.h>

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition(int arr[], int l, int h, int res[]) 
{ 
    int x = arr[h]; 
    int i = (l - 1); 
    for (int j = l; j <= h - 1; j++) { 
        if (arr[j] <= x) { 
            i++; 
            swap(&arr[i], &arr[j]);
            swap(&res[i], &res[j]);
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    swap(&res[i + 1], &res[h]);
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high, int res[]) 
{ 
    int stack[high - low + 1]; 
    int top = -1; 
    stack[++top] = low; 
    stack[++top] = high; 
    while (top >= 0) { 
        high = stack[top--]; 
        low = stack[top--]; 
        int p = partition(arr, low, high, res); 
        if (p - 1 > low) { 
            stack[++top] = low; 
            stack[++top] = p - 1; 
        } 
        if (p + 1 < high) { 
            stack[++top] = p + 1; 
            stack[++top] = high; 
        } 
    } 
} 

int main() {
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int arr[n],j,res[n];
        for(j=0;j<n;j++){
            scanf("%d",&arr[j]);
            res[j] = j+1;
        }
        quickSort(arr, 0, n-1,res);
        for(int j=n-1;j>=0;j--){
            printf("%d ",res[j]);
        }
        printf("\n");
    }
}

#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int partition(int arr[], int l, int h) 
{ 
    int x = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++) { 
        if (arr[j] <= x) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 
void quickSort(int A[], int l, int h) 
{ 
    if (l < h) { 
        int p = partition(A, l, h); 
        quickSort(A, l, p - 1); 
        quickSort(A, p + 1, h); 
    } 
} 
int main(){
    int T;
    cin>>T;
    while(T>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i =0;i<n;i++)
        {
            cin>>arr[i];
        }
        quickSort(arr, 0, n-1); 
        cout<<arr[n-1]-arr[1]+arr[n-1]-arr[0]+arr[1]-arr[0]<<endl;;
      T--;
    }
      return 0;
}
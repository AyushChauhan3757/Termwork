//By Ayush Chauhan Btech CST 21021257
//Question 1
#include <stdio.h>
#include <stdlib.h>

void positiveToRight(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>=0 && arr[j+1]<0){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    printf("By Ayush Chauhan Btech CST 21021257\n");
    int x;
    printf("Enter value of n: ");
    scanf("%d", &x);
    const int n = x;
    int arr[n];
    
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    positiveToRight(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}

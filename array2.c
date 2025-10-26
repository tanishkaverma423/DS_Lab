#include<stdio.h>
#include<conio.h>
void main(){
    int n;
    printf("enter size of array ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter value at index %d \n", i);
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    getch();
}
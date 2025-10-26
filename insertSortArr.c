#include <stdio.h>
int main()
{
    int arr[100];
    int val;
    printf("enter no of elements ");
    int n;
    scanf("%d", &n);
    printf("enter %d elements", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }
    printf("input a number to insert");
    scanf("%d", &val);
    for (int i = n; i >= 0; i--)
    {
        if (arr[i] > val)
        {
            arr[i + 1] = arr[i];
            arr[i] = val;
        }
    }
    n++;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
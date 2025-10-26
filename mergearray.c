#include <stdio.h>
int main()
{
    int n, m;
    printf("input size of array 1 and array 2 \n");
    scanf("%d%d", &n, &m);
    int a[n];
    int b[m];
    int c[n + m];
    int i, j, k = 0;
    printf("input array 1 \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("input array 2 \n");
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &b[j]);
    }
    i = 0;
    j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    for (k = 0; k < n + m; k++)
    {
        printf("%d ", c[k]);
    }
    return 0;
}
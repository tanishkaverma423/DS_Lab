#include <stdio.h>

int main()
{
    int n, m;
    printf("Input size of set 1 and set 2: ");
    scanf("%d %d", &n, &m);

    int a[n], b[m];
    int unionset[n + m];
    int intersect[(n < m) ? n : m]; 
    int diff[n];
    int i, j, k;

    printf("Input set 1 (sorted): ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Input set 2 (sorted): ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    
    // UNION

    i = j = k = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            unionset[k++] = a[i];
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            unionset[k++] = a[i++];
        }
        else
        {
            unionset[k++] = b[j++];
        }
    }

    while (i < n)
        unionset[k++] = a[i++];
    while (j < m)
        unionset[k++] = b[j++];

    printf("Union: ");
    for (int x = 0; x < k; x++)
        printf("%d ", unionset[x]);
    printf("\n");

    
    // INTERSECTION
    
    i = j = k = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            intersect[k++] = a[i];
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }

    printf("Intersection: ");
    for (int x = 0; x < k; x++)
        printf("%d ", intersect[x]);
    printf("\n");

    
    // DIFFERENCE (A - B)
    
    i = j = k = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            diff[k++] = a[i++];
        }
        else
        {
            j++;
        }
    }
    while (i < n)
        diff[k++] = a[i++];

    printf("Difference (A - B): ");
    for (int x = 0; x < k; x++)
        printf("%d ", diff[x]);
    printf("\n");

    return 0;
}

#include <stdio.h>

int k;

void fun(char arr[], int x, int n)
{
    if (x == n - 1)
    {
        printf("%s\n", arr);
        k--;
        return;
    }
    
    for (int i = x; i < n; i++)
    {
        int j;
        char swap = arr[i];
        char arr2[26];
        for(j=0; j<x; j++)
        {
            arr2[j] = arr[j];
        }
        
        for(j=i; j>x; j--)
        {
            arr2[j] = arr[j-1];
        }
        arr2[j] = swap;
        
        for(j=i+1; j<n; j++) arr2[j] = arr[j];
        arr2[j] = '\0';
        if(k > 0) fun(arr2, x+1, n);
    }
}

int main()
{
    int n, j, t;

    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d:\n", i);
        char arr[26];
        for(j=0; j<n; j++) arr[j] = 'A' + j;
        arr[j]='\0';
        fun(arr, 0, n);
    }
}

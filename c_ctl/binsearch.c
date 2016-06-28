#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int v[] = {1,2,3,4,5,6,9};
    int x = 1;
    int n = 7;
    printf("pos:%d\n", binsearch(x, v, n));
}

//折半查找
int binsearch(int x, int v[], int n)
{
    int mid;
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
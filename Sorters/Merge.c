#include <stdio.h>
#include <sys/time.h>
//Loop Invariant: A[p..k-1] has the smallest elements k-p of L[1..n1+1]
//& R[1..n2+1] sorted. L & R are the smallest elements not copied back into A.
void merge(int *list, int p, int q, int r)
{//Init: A[p..k-1] is initially empty. k-p=0 making L&R the smallest elements
    int list2[100000];
    int list3[100000];
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    
    for(i = 0 ; i < n1 ; i++)
    {
        list2[i] = list[p + i];
    }
    for(i = 0 ; i < n2 ; i++)
    {
        list3[i] = list[q + i + 1];
    }
//Maintenance: Initially L <= R. L is has smallest. Else L > R.
    list2[n1] = 100000;
    list3[n2] = 100000;
    i = 0;
    j = 0;

    for (k = p ; k <= r ; k++)
    {
        if(list2[i] < list3[j])
        {
            list[k] = list2[i];
            i++;
        }
        else
        {
            list[k] = list3[j];
            j++;
        } 
    }
}//Termination: k=r+1. A[p..k-1] is k-p=r-p+1. Smallest elements of
//L[1..n1+1] & R[1..n2+1] in sorted order. The two last large lists
//are copied back into A.
void mergesort(int *list, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        mergesort(list, p, q);
        mergesort(list, q + 1, r);
        merge(list, p, q, r);
    }
}


int printer(int *list, int len)
{
    int k = 0;
    for (k = 0 ; k < len ; k++)
    {
    printf("%d\n", list[k]);
    }   
}


int main(void)
{
    int list[100000], i = 0, j, k, len;
    while ((scanf("%d", &j) >= 0 ) && (i < 100000))
    {
        list[i++] = j;
    }

    len = i;
    
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    mergesort (list, 0, len - 1);
    gettimeofday(&stop, NULL);
    printer(list, len);
    double time;
    time = (int)(stop.tv_sec-start.tv_sec) + (stop.tv_usec - start.tv_usec)/1000000.0;
    printf("\nMerge Sort, Items: %d, Time: %f\n\n", len, time);
}
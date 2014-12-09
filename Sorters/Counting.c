#include <stdio.h>
#include <sys/time.h>


void counting(int *list, int k, int len)
{
    int i, j;
    int list2[100000], list3[10000];
    for (i = 0; i <= k; i++)
        list3[i] = 0;
    for (j = 1; j <= len; j++)
        list3[list[j]] = list3[list[j]] + 1;
    for (i = 1; i <= k; i++)
        list3[i] = list3[i] + list3[i-1];
    for (j = len; j >= 1; j--)
    {
        list2[list3[list[j]]] = list[j];
        list3[list[j]] = list3[list[j]] - 1;
    }
    for (i = 1; i <= len; i++)
    printf("%d\n", list2[i]);
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
    counting(list, 100000, len);
    gettimeofday(&stop, NULL);
	double time;
	time = (int)(stop.tv_sec-start.tv_sec) + (stop.tv_usec - start.tv_usec)/1000000.0;
	printf("\nCounting Sort, Items: %d, Time: %f\n\n", len, time);
}
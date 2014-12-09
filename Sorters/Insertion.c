#include <stdio.h>
#include <sys/time.h>
//Loop Invariant:
//Each for loop in A[1...j-1] is in sorted order.
void insertion(int *list, int len)
{//Init: A[1] is already sorted. Therefore, j can equal 2 and the invariant holds.
	int j, key, i;
	for (j = 1; j<len ; j++)
	{//Maintenance: A[1…j-1] sorted + A[j] -> A[1…j] sorted 
		key = list[j];
		i = j - 1;
		while (i >= 0 && list[i] > key)
		{
			list[i+1] = list[i];
			i = i - 1;
		}
	list[i+1] = key;
	}
}//Termination: j = n + 1. list[1..n] has original elements as initial list[1..n] but sorted.


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
    insertion (list, len);
    gettimeofday(&stop, NULL);
    printer(list, len);
	double time;
	time = (int)(stop.tv_sec-start.tv_sec) + (stop.tv_usec - start.tv_usec)/1000000.0;
	printf("\nInsertion Sort, Items: %d, Time: %f\n\n", len, time);
}
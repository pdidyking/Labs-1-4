#include <stdio.h>
#include <sys/time.h>
//Loop Invariant:
//For each iteration i, A[1..i] is sorted & elements A[i+1..A.size] are = or >= A[1..i].
void bubble(int *list, int len)
{//Init: A[0] is sorted.
	int j, i;
	for(j = 0; j < len; j++)
	{//Maintenance: A[1..n-1] is smaller than A[n..A.size], A[1..n] is sorted.
		for(i = 0; i < len - 1; i++)
		{
			if(list[i] > list[i + 1])
			{						
				int temp = list[i + 1];
				list[i + 1] = list[i];
				list[i] = temp;
			}
		}
	}
}//Termination: A[1..A.size-1] is sorted. 
 //A[A.size-1..A.size] > A[1..A.size-1], so A[1..A.size is sorted.]

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
    bubble (list, len);
    gettimeofday(&stop, NULL);
    printer(list, len);
	double time;
	time = (int)(stop.tv_sec-start.tv_sec) + (stop.tv_usec - start.tv_usec)/1000000.0;
	printf("\nBubble Sort, Items: %d, Time: %f\n\n", len, time);
}
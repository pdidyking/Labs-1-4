#include <stdio.h>
#include <sys/time.h>


void quick (int *list, int len) 
{   
    if (len < 2)
        return;
    int p = list[len / 2];
    int *l = list;
    int *r = list + len - 1;
    while (l <= r)
    {
        if (*l < p)
        {
            l++;
        }
        else if (*r > p) 
        {
            r--;
        }
        else 
        {
            int t = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
    quick(list, r - list + 1);
    quick(l, list + len - l);
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
    quick(list, len);
    gettimeofday(&stop, NULL);
    printer(list, len);
	double time;
	time = (int)(stop.tv_sec-start.tv_sec) + (stop.tv_usec - start.tv_usec)/1000000.0;
	printf("\nQuick Sort, Items: %d, Time: %f\n\n", len, time);
}
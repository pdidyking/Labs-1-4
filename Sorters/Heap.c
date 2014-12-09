#include <stdio.h>
#include <sys/time.h>
//Loop Invariant:
//i+1, i+2,..,n is the root of the max-heap
int heapsize;

void heapify(int *list, int i)
{//init: i=floor(n/2)....n/2+1+2 is a leaf node.
    int l = 2 * i, r = 2 * i + 1, largest, temp;
    if(l <= heapsize && list[l] > list[i])
        largest = l;
    else
        largest = i;
    if(r <= heapsize && list[r] > list[largest])
        largest = r;
}


void buildheap(int *list, int len)
{
    int i;  
    heapsize = len;    
    for(i = len / 2; i >= 0; i--)
        heapify(list, i);
}
//Maintenance: Goal is to keep i as max-heap root. i+1, i+2,.., n are all roots of max-heap.
void heapsort(int *list, int len)
{
	int i, temp; 
    buildheap(list, len);
    for(i = len - 1; i >= 1; i--)
    {
        temp = list[0];
        list[0]= list[i];
        list[i] = temp;
        heapsize--;         
        heapify(list, 0);   
    }
}//Termination: i=0. 1,2,..,n is the root of max-heap. node is 1.


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
    heapsort(list, len);
    gettimeofday(&stop, NULL);
    printer(list, len);
	double time;
	time = (int)(stop.tv_sec-start.tv_sec) + (stop.tv_usec - start.tv_usec)/1000000.0;
	printf("\nHeap Sort, Items: %d, Time: %f\n\n", len, time);
}
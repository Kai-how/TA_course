#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <ctime>
using namespace std;

const int Max = 1000000;

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b= temp;
}
//InsertionSort
void InsertionSort(int *array, int size){
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (array[j] > key && j >= 0) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    	
    	/*printf("InsertionSort結束:\n");
		for (int i = 0; i < size; i++)
		{			
		printf("%d\n",arraytempt[i]);
		}*/
}
//SelectionSort 
void SelectionSort(int *array, int n){	
	/*printf("進入SelectionSort:\n");
	for (int i = 0; i < n; i++)
	{			
		printf("%d\n",array[i]);
	} */
	for (int i = 0; i < n; i++) 
	{		
        for(int j =i+1; j < n;j++)
		{
        	if (array[j]< array[i])
        	swap(array[j],array[i]);	      		
		}	
    }   
    delete array;
}
//QuickSort
int Partition(int *array, int begin, int end)
{
    int pivot = array[end];
    int i = begin -1;
    for (int j = begin; j <= end; j++)
	{
        if (array[j] < pivot) 
		{
            i++;
            swap(&array[i], &array[j]);
        }
    }
    i++;
    swap(&array[i], &array[end]);
    return i;
}
void QuickSort(int *array, int begin, int end)
{

    if (begin < end) 
	{
        int pivot = Partition(array, begin, end);
        QuickSort(array, begin, pivot - 1);
        QuickSort(array, pivot + 1, end);
    }
}
//MergeSort
#define sentinel RAND_MAX    // define sentinel 為 RAND_MAX 值 
void Merge(int *array,int p,int q,int r)
{       
	int n1 = q-p+2;
    int n2 = r-q+1;
    int l_array[n1];
    int r_array[n2];
    for(int i=0;i<n1-1;i++) 
        l_array[i]=array[p+i];
	l_array[n1-1]=sentinel;
    for(int i=0;i<(n2-1);i++)
        r_array[i]=array[q+1+i];

    r_array[n2-1]=sentinel;
    int k=0;
    int j=0;
    for(int i=p;i<1+r;i++)
    {       
		if(l_array[j]<r_array[k])
        {       
			array[i]=l_array[j];
                j++;
        }
        else
        {       
			array[i]=r_array[k];
           		k++;
        }
	}
}

void  MergeSort(int *array,int p,int r)
{      
	/*printf("進入Sort:\n");
	for (int i = p; i < r; i++)
	{			
		printf("%d\n",array[i]);
	} */
	if(p<r)
	{
        int q=(p+r)/2;
        MergeSort(array,p,q);
        MergeSort(array,q+1,r);
        Merge(array,p,q,r);
    }

}
/* debug */ 
void ISdebug(int *array, int n)
{
	unsigned seed;
    seed = (unsigned)time(NULL); 
    srand(seed);
	for (int i = 0; i < n; i++)
		array[i] = rand();
	for (int i = 0; i < n; i++)
	{
		printf("%d ",array[i]);
		if(i%5==4)
		printf("\n");	}
	InsertionSort(array,n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ",array[i]);
		if(i%5==4)
		printf("\n");	}
}

void SSdebug(int *array, int n)
{
	unsigned seed;
    seed = (unsigned)time(NULL); 
    srand(seed);
	for (int i = 0; i < n; i++)
		array[i] = rand();
	for (int i = 0; i < n; i++)
	{
		printf("%d ",array[i]);
		if(i%5==4)
		printf("\n");	}
	SelectionSort(array,n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ",array[i]);
		if(i%5==4)
		printf("\n");	}
}

void QSdebug(int *array, int end)
{
	unsigned seed;
    seed = (unsigned)time(NULL); 
    srand(seed);
	for (int i = 0; i < end; i++)
		array[i] = rand();
	for (int i = 0; i < end; i++)
	{
		printf("%d ",array[i]);
		if(i%5==4)
		printf("\n");	}
		
	QuickSort(array,0,end-1);
	printf("\n");
	for (int i = 0; i < end; i++)
	{
		printf("%d ",array[i]);
		if(i%5==4)
		printf("\n");	}
}

void MSdebug(int *array, int r)
{
	unsigned seed;
    seed = (unsigned)time(NULL); 
    srand(seed);
	for (int i = 0; i < r; i++)
		array[i] = rand();
	for (int i = 0; i < r; i++)
	{
		printf("%d ",array[i]);
		if(i%5==4)
		printf("\n");	}
	MergeSort(array,0,r-1);
	printf("\n");
	for (int i = 0; i < r; i++)
	{
		printf("%d ",array[i]);
		if(i%5==4)
		printf("\n");	}
}

/* main program */ 
int main(void){
	int c;	
	printf("enter 0 : debug.\n");
	printf("enter 1 : sort.\n");
	printf("Please input the number:");
	printf("other numbers : end.\n");
	scanf("%d",&c);
	switch(c)
	{
		case 0:
			{	
				int a,n;
				int array[n];
				printf("enter 1 : debug insertionsort.\n");
				printf("enter 2 : debug selectionsort.\n");
				printf("enter 3 : debug quicksort.\n");
				printf("enter 4 : debug mergesort.\n");
				printf("other numbers : skip.\n");
				printf("Please input the number that you want to debug:");
				scanf("%d",&a);
				switch(a)
				{
					case 1:
						{
							ISdebug(array,20);
							break;
						}
					case 2:
						{
							SSdebug(array,20);
							break;
						}
					case 3:
						{
							QSdebug(array,20);
							break;
						}
					case 4:
						{
							MSdebug(array,20);
							break;
						}
					default :
						{
							printf("skip \n");
							break;
						}
				}
			break;
			}	
		case 1:
			{		
				int n;
				printf("\nInput sorted array size:");
				scanf("%d",&n);
				int *array = new int[n];
				unsigned seed;
    			seed = (unsigned)time(NULL); 
   	 			srand(time(NULL));
   	 			/*printf("原array:\n"); */
				for (int i = 0; i < n; i++)
				{
					array[i] = rand();				
				/*printf("%d\n",array[i]);*/
				}
	
				clock_t x,y;
    			x = clock();
    			InsertionSort(array,n);
    			y = clock();
    			printf("Start1 time:%lu\n",x);
    			printf("End1 time:%lu\n",y);
    			printf("using time:%lu(ms)\n",(y-x));
    
    			x = clock();
    			SelectionSort(array,n);
    			y = clock();
    			printf("Start2 time:%lu\n",x);
    			printf("End2 time:%lu\n",y);
    			printf("using time:%lu(ms)\n",(y-x));
    
  			  	int *arraytempt = new int[n];
				for(int i = 0; i < n ;i++)	
				{
					arraytempt[i]=array[i];
				}
   			 	x = clock();
   	 			QuickSort(arraytempt,0,n);
   			 	y = clock();
    			printf("Start3 time:%lu\n",x);
    			printf("End3 time:%lu\n",y);
    			printf("using time:%lu(ms)\n",(y-x));
    			delete arraytempt;
    
    
				for(int i = 0; i < n ;i++)	
				{
					arraytempt[i]=array[i];
				}
    			x = clock();
    			MergeSort(arraytempt,0,n);
    			y = clock();
    			printf("Start4 time:%lu\n",x);
    			printf("End4 time:%lu\n",y);
    			printf("using time:%lu(ms)\n",(y-x));
    			delete arraytempt;
    			break;
			}
			break;
		default :
			{
				printf("end \n");
				break;
			}
	}
}

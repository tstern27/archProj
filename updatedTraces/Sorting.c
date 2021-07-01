// Sort Array in Ascending Order
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int Size = 190;
	double Array[Size];
    int i; 
    int j;
    double temp; 


    srand((unsigned)time(NULL));
	for (i = 0; i < Size; i++)
	{
		Array[i] = (double)rand()/(double)(RAND_MAX);
    }     
	for (i = 0; i < Size; i++)
	{
		for (j = i + 1; j < Size; j++)
		{
			if(Array[i] > Array[j])
			{
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
			
		}
	}
	printf("\n **** Array of Elemenst in Ascending Order are : ****\n");
	for (i = 0; i < Size; i++)
	{
		printf("%f\t", Array[i]);
	}
	
	return 0;
}

/* The following functions sorts a randomly generated array of n size, with n being a value inputted
 * from the user. The functions are timed to determine which has the best time efficiency. The two 
 * sorts used is selection sort and bubble sort. 
 */
#include "sort.h"

void selection(int num)
{
	int i, j, temp;
	int userArray[num];
	int currentMin = 0;
	clock_t  start, end;
	double averageTime, bestTime;

	/* generates the random array of n size */
	for(i = 0; i < num; i++){
		userArray[i] = rand();
	}	
	start = clock();
	for(i = 0; i < num-1; i++)
	{
		for(j = i+1; j < num; j++)
		{
			if(userArray[j] < userArray[currentMin])
			{
				currentMin = j;
			}
		}
		if(currentMin != i)
		{
			temp = userArray[i];
			userArray[i] = userArray[currentMin];
			userArray[currentMin] = temp;
		}
	}

	end = clock();
	averageTime = (((double) (end - start)) / CLOCKS_PER_SEC ) * 1000;

	start = clock();
	for(i = 0; i < num; i++)
	{
		for(j = i+1; j < num; j++)
		{
			if(userArray[j] < userArray[currentMin])
			{
				currentMin = j;
			}
		}
		if(currentMin != i)
		{
			temp = userArray[i];
			userArray[i] = userArray[currentMin];
			userArray[currentMin] = temp;
		}
	}

	end = clock();
	bestTime = (((double) (end - start)) / CLOCKS_PER_SEC ) * 1000;

	if(num <= 50)
	{
		printf("\nHere is the sorted array in an ascending order: \n");
		for(i = 0; i < num; i++)
		{
			printf("%d\t", userArray[i]);
		}
	}

	printf("\n\nArray_Size\tAlgorithm\tAverage\t\tBest\n");
	printf("\t%d\tSelection\t%f\t%f\n",  num, averageTime, bestTime);
}

void bubble(int num)
{
	int i, temp;
	int userArray[num];
	bool swapped;
	clock_t start, end;
	double averageTime, bestTime;

	for(i = 0; i < num; i++)
	{
		userArray[i] = rand();
	}

	start = clock();
	do
	{
		swapped = false;
		for(i = 1; i < num; i++)
		{
			if(userArray[i] < userArray[i-1])
			{
				temp = userArray[i];
				userArray[i] = userArray[i-1];
				userArray[i-1] = temp;
				swapped = true;
			}
		}
	} while(swapped == true);
	end = clock();
	averageTime = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;

	start = clock();
	do
	{
		swapped = false;
		for(i = 1; i < num; i++)
		{
			if(userArray[i] < userArray[i-1])
			{
				temp = userArray[i];
				userArray[i] = userArray[i-1];
				userArray[i-1] = temp;
				swapped = true;
			}
		}
	} while(swapped == true);
	end = clock();
	bestTime = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;

	if(num <= 50) 
	{
		printf("\nHere is the sorted array in an ascending order: \n");
		for(i = 0; i < num; i++)
		{
			printf("%d\t", userArray[i]);
		}
	}

	printf("\n\t%d\tBubble\t\t%f\t%f\n", num, averageTime, bestTime);

}


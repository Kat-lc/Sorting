/* Main function for project one */
#include "sort.h"

int main()
{
	bool validInput = true;

	while(validInput)
	{
		int n = 0;

		printf("Please input the size of the array: ");
		scanf("%d", &n);

		if(n > 1)
		{
			selection(n);
			bubble(n);
		}else
		{
			validInput = false;
		}	
	}

	return 0;
}

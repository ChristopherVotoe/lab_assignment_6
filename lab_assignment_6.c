#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value)
{
	int mid = low + (high - low) / 2;
	if (numbers[mid] > value)
	{
		return search(numbers, low, mid, value);
	}
	else if (numbers[mid] < value)
	{
		return search(numbers, mid, high, value);
	}
	else if (numbers[mid] == value)
	{
		return mid;
	}

	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array: ");
	for (i = 0; i < sz; ++i)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	float average;
	int value;
	int index;
	int *numArray = NULL;
	int countOfNums;
	FILE *inFile = fopen("c:/Users/Potat/OneDrive/Desktop/lab_assignment_6/input.txt", "r");

	if (inFile == NULL)
	{
		fprintf(stderr, "Failed to open the file.\n");
		return 1;
	}

	fscanf(inFile, "%d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, "%d\n", &countOfNums);

		if (countOfNums <= 0)
		{
			fprintf(stderr, "Invalid number of inputs.\n");
			continue; // Skip this iteration and proceed to the next one
		}

		numArray = (int *)malloc(countOfNums * sizeof(int));
		if (numArray == NULL)
		{
			fprintf(stderr, "Memory allocation failed.\n");
			return 1; // or handle the error appropriately
		}

		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile, "%d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);

		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);

		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n", value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);

	return 0;
}
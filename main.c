#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int displayCells(int array_width, int array_height, int layer, int cell_array[array_width][array_height][2])
{
	int each_row, each_col;
	printf("\n");
	printf("Generation \n");
	for (each_col = 0; each_col < array_width; each_col++ ) {
		for (each_row = 0; each_row < array_height; each_row++ ) {
			printf("%c", cell_array[each_col][each_row][layer]);
		}
		printf("\n");
	}
}	

int getLiveNeighbours(int current_col, int current_row, int array_width, int array_height, int layer, int cell_array[array_width][array_height][2])
{

	printf("Inside getLiveNeighbours() \n");
	displayCells(array_width, array_height, 0, cell_array);
	int live_neighbours = 0;


	// It would be nice to figure out a way to perform this check only once instead of every time the func is called

	// Checks the top row of surrounding neighbours where applicable
	if (current_row > 0)
	{
		if (current_col > 0)
		{
			if (cell_array[current_col - 1][current_row - 1][layer] == "+")
			{
				live_neighbours++;
			}
		}

		if (cell_array[current_col][current_row - 1][layer] == "+")
		{
			live_neighbours++;
		}

		if (current_col < array_width - 1)
		{
			if (cell_array[current_col + 1][current_row - 1][layer] == "+")
			{
				live_neighbours++;
			}
		}
	}

	if (current_col > 0)
	{
		if (cell_array[current_col - 1][current_row][layer] == "+")
		{
			live_neighbours++;
		}
	}

	if (current_col < array_width - 1)
	{
		/*
		printf("Co-ords \n");
		printf("current_col: %d \n",current_col);
		printf("current_row: %d \n",current_row);
		printf("layer: %d \n",layer);
		printf("Cell %c \n",cell_array[current_col + 1][current_row][layer]);
		*/
		if (cell_array[current_col + 1][current_row][layer] == "+")
		{
			live_neighbours++;
		}
	}

	cell_array[4][5][0] = "+";
	cell_array[4][6][0] = "+";
	// Checks the bottom row of surrounding neighbours where applicable
	if (current_row < array_height - 1)
	{
		if (current_col > 0)
		{
			if (cell_array[current_col - 1][current_row + 1][layer] == "+")
			{
				live_neighbours++;
			}
		}

		printf("Co-ords \n");
		printf("current_col: %d \n",current_col);
		printf("current_row: %d \n",current_row);
		printf("layer: %d \n",layer);
		printf("Cell '%c' \n",cell_array[current_col][current_row + 1][layer]);
		if (cell_array[current_col][current_row + 1][layer] == "+")
		{
			live_neighbours++;
			printf("Live neighbours is not set to %d \n",live_neighbours);
		}

		if (current_col < array_width - 1)
		{
			if (cell_array[current_col + 1][current_row + 1][layer] == "+")
			{
				live_neighbours++;
			}
		}
	}

	printf("Live %d \n",live_neighbours);
	return live_neighbours;
}

int main()
{

	const int cells_width = 10;
	const int cells_height = 10;

	int cells[cells_width][cells_height][2];

	int current_layer = 1;

	int loop = 1;

	int row, col;

	int neighbours; // Remove once getLiveNeighbours has been tested

	//Instantiate cells array
	for (int each_col = 0; each_col < cells_width; each_col++){
		for (int each_row = 0; each_row < cells_height; each_row++) {
			cells[each_col][each_row][0] = '-';
			cells[each_col][each_row][1] = '-';
		}
	}

	
	displayCells(cells_width, cells_height, 0, cells);

	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);

	// Iterates onto the next generation
	while (loop == 1)
	{

		// Confirm this is the fastest way to iterate through the array, rather than row-wise
		for (col = 0; col < cells_width; col++)
		{
			for (row = 0; row < cells_height; row++)
			{
				// printf("Hello \n");
			}
		}

		neighbours = getLiveNeighbours(4,5,cells_width,cells_height,0,cells);
		printf("%d \n",neighbours);

		// Output current generation
		displayCells(cells_width, cells_height, current_layer, cells);

		//Swap the working layer
		current_layer = 1 - current_layer;

		loop = 0; //Remove
	}

	clock_gettime(CLOCK_REALTIME, &end);
	long seconds = end.tv_sec - begin.tv_sec;
	long nanoseconds = end.tv_nsec - begin.tv_nsec;
	double elapsed = seconds + nanoseconds * 1e-9;

	printf("Time measured: %.3f seconds. \n elapsed");

	return 0;
}

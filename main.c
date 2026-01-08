#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int displayCells(int array_width, int array_height, int layer, int cell_array[array_width][array_height][2], int generation)
{
	int each_row, each_col;
	printf("\n");
	printf("Generation %d\n",generation);
	for (each_col = 0; each_col < array_width; each_col++ ) {
		for (each_row = 0; each_row < array_height; each_row++ ) {
			printf("%d", cell_array[each_row][each_col][layer]);
		}
		printf("\n");
	}
}

int getLiveNeighbours(int current_col, int current_row, int array_width, int array_height, int layer, int cell_array[array_width][array_height][2])
{
	int live_neighbours = 0;

	// It would be nice to figure out a way to perform this check only once instead of every time the func is called

	// Checks the top row of surrounding neighbours where applicable
	if (current_row > 0)
	{
		if (current_col > 0)
		{
			if (cell_array[current_col - 1][current_row - 1][layer] == 1)
			{
				live_neighbours++;
			}
		}

		if (cell_array[current_col][current_row - 1][layer] == 1)
		{
			live_neighbours++;
		}

		if (current_col < array_width - 1)
		{
			if (cell_array[current_col + 1][current_row - 1][layer] == 1)
			{
				live_neighbours++;
			}
		}
	}

	if (current_col > 0)
	{
		if (cell_array[current_col - 1][current_row][layer] == 1)
		{
			live_neighbours++;
		}
	}

	if (current_col < array_width - 1)
	{
		if (cell_array[current_col + 1][current_row][layer] == 1)
		{
			live_neighbours++;
		}
	}
	// Checks the bottom row of surrounding neighbours where applicable
	if (current_row < array_height - 1)
	{
		if (current_col > 0)
		{
			if (cell_array[current_col - 1][current_row + 1][layer] == 1)
			{
				live_neighbours++;
			}
		}

		if (cell_array[current_col][current_row + 1][layer] == 1)
		{
			live_neighbours++;
		}

		if (current_col < array_width - 1)
		{
			if (cell_array[current_col + 1][current_row + 1][layer] == 1)
			{
				live_neighbours++;
			}
		}
	}

	//printf("Live neighbours %d \n",live_neighbours);
	return live_neighbours;
}

int main()
{

	const int cells_width = 50;
	const int cells_height = 50;
	int cells[cells_width][cells_height][2];

	int current_layer = 0;
	int opposite_layer = 1;

	int loop = 100;

	int row, col;
	int gen = 1;

	int neighbours;

	//Instantiate cells array
	for (int each_col = 0; each_col < cells_width; each_col++){
		for (int each_row = 0; each_row < cells_height; each_row++) {
			cells[each_col][each_row][0] = 0;
			cells[each_col][each_row][1] = 0;
		}
	}

	//Test configuration - "Blinker"
	cells[4][5][0] = 1;
	cells[4][6][0] = 1;
	cells[4][7][0] = 1;

	//Test configuration - "Toad"
	cells[7][25][0] = 1;
	cells[7][26][0] = 1;
	cells[7][27][0] = 1;
	cells[8][26][0] = 1;
	cells[8][27][0] = 1;
	cells[8][28][0] = 1;
	
	//Test configuration - "Glider"
	cells[11][9][0] = 1;
	cells[11][10][0] = 1;
	cells[11][11][0] = 1;
	cells[10][11][0] = 1;
	cells[9][10][0] = 1;

	//Test configuration - Edge Case
	cells[0][0][0] = 1;
	cells[0][1][0] = 1;
	cells[0][2][0] = 1;

	//Displays initial configuration of cells
	displayCells(cells_width, cells_height, current_layer, cells, gen);

	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);

	// Iterates onto the next generation
	while (loop > 1)
	{
		// Confirm this is the fastest way to iterate through the array, rather than row-wise
		for (col = 0; col < cells_width; col++)
		{
			for (row = 0; row < cells_height; row++)
			{
				neighbours = getLiveNeighbours(col,row,cells_width,cells_height,current_layer,cells);
				//If a live cell has 2 or 3 live neighbours, it is sustained to the next generation
				
				if (cells[col][row][current_layer] == 1){
					if (neighbours == 2 || neighbours == 3) {
						cells[col][row][opposite_layer] = 1;
					} else {
						//Otherwise it dies by over/underpopulation
						cells[col][row][opposite_layer] = 0;
					}
				} else {
					//If a dead cell is surrounded by exactly three live cells, it becomes live
					if (neighbours == 3) {
						cells[col][row][opposite_layer] = 1;
					} else {
						cells[col][row][opposite_layer] = 0;
					}
				}
			}
		}

		//Swap the working layer
		current_layer = 1 - current_layer;
		opposite_layer = 1 - opposite_layer;

		// Displays the cells after they have been modified according to their configuration
		displayCells(cells_width, cells_height, current_layer, cells, gen);

		loop = loop - 1;
		gen++;
	}

	clock_gettime(CLOCK_REALTIME, &end);
	long seconds = end.tv_sec - begin.tv_sec;
	long nanoseconds = end.tv_nsec - begin.tv_nsec;
	double elapsed = seconds + nanoseconds * 1e-9;

	printf("Time measured: %.3f seconds. \n", elapsed);

	return 0;
}

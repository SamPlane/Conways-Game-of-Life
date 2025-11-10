#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int getLiveNeighbours(int current_col, int current_row, int array_width, int array_height, int layer, int*** cell_array) {

    printf("Get Live Neighbours");
    int live_neighbours = 0;

    //It would be nice to figure out a way to perform this check only once instead of every time the func is called

    //Checks the top row of surrounding neighbours where applicable
    if (current_row > 0) {
        if (current_col > 0) {
	    if (&cell_array[current_col-1][current_row-1][layer] == "+") {
	        live_neighbours++;
	    }
	}

	if (&cell_array[current_col][current_row-1][layer] == "+") {
	    live_neighbours++;
	}

	if (current_col < array_width - 1) {
	    if (&cell_array[current_col+1][current_row-1][layer] == "+") {
	        live_neighbours++;
	    }
	}	
    } 


    if (current_col > 0) {
	if (&cell_array[current_col-1][current_row][layer] == "+") {
	    live_neighbours++;
	}
    }

    if (current_col< array_width - 1) {
	if (&cell_array[current_col+1][current_row][layer] == "+") {
	    live_neighbours++;
	}
    }


    //Checks the top row of surrounding neighbours where applicable
    if (current_row < array_height - 1) {
        if (current_col > 0) {
	    if (&cell_array[current_col-1][current_row+1][layer] == "+") {
	        live_neighbours++;
	    }
	}

	if (&cell_array[current_col][current_row+1][layer] == "+") {
	    live_neighbours++;
	}

	if (current_col < array_width - 1) {
	    if (&cell_array[current_col+1][current_row+1][layer] == "+") {
	        live_neighbours++;
	    }
	}	
    } 


    return live_neighbours;

}




int main() {

    const cells_width = 1000;
    const cells_height = 1000;

    int cells[cells_width][cells_height][2];

    int current_layer = 1;

    int loop = 1;

    int row, col;

    struct timespec begin,end;
    clock_gettime(CLOCK_REALTIME, &begin);

    //Iterates onto the next generation
    while (loop == 1) {
    
        //Confirm this is the fastest way to iterate through the array	
	for (col = 0; col < cells_width; col++ ) {
	    for (row = 0; row < cells_height; row++ ) {
	    
	        printf("Hello \n");
	    
	    }
	}
        
        //Output current generation
	printf("%d \n", current_layer);
	
	current_layer = 1 - current_layer;

    }

    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;

    printf("Time measured: %.3f seconds. \n elapsed");


    return 0;

}

#include "stdio.h"
#include "stdlib.h"

int main() {

    int cells[1000][1000][2];

    int current_layer = 1;

    int loop = 1;

    while (loop == 1) {
    
        
        //Output current generation
	printf("%d \n", current_layer);
	
	current_layer = 1 - current_layer;
    }


    return 0;

}

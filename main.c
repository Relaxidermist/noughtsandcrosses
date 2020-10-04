#include<stdio.h>
#include<stdlib.h>


#define GRIDSIZE 5

int main()
{
    char **rows, *columns;

    // Allocate memory for rows in grid pointers to pointers,
    // this is because this is a 1D array which will point to 
    // other 1D arrays
    rows = (char**)malloc(GRIDSIZE*sizeof(char*));
    // Fill array with values and print
    for(int i=0; i<GRIDSIZE; i++)
    {
        // Allocate memory for 1D array for this array index in rows[i]
        // rows[i] is a char pointer pointer type
        rows[i] = (char*)malloc(GRIDSIZE*sizeof(char));

        for(int j=0; j<GRIDSIZE; j++)
        {
            // assign columns char pointer type the address of the allocated
            // array for the point point array.
            columns = rows[i];

            // put some values into the columns
            columns[j] = GRIDSIZE*j*i;
        }
    }

    for(int i=0; i<GRIDSIZE; i++)
    {
        // index through row pointer pointer array to get value for columns array
        columns = rows[i];
        for(int j=0; j<GRIDSIZE; j++)
        {
            printf("%d\n", *(columns + j));
        }
    }

    free(columns);
    free(rows);

    return 0;
}
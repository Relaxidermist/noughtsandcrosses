/*NOUGHTS AND CROSSES
TODO: Ensure that player place entries are placed
into gameplay tracking grid - verify this by priting
out 2D array representing gameplay.

verify that GRID SIZE for gameplay should not break
game if broken - application should account for changing
grid size.

Update grid needs to point back to original grid
*/

#include<stdio.h>
#include<stdlib.h>

#define GRIDHEIGHT 18
#define GRIDWIDTH 36
#define SPACEHEIGHT 6
#define SPACEWIDTH 12


// Scan User input from the terminal to determine next move.
void *userinput(char *place);

// Assign user moves to a grid to track gameplay.
void updategrid(char *place, char grid[][3]);

// Main program function occurs here
int main()
{
    // Local functions
    char  **rows,     // Point to row pointers which store ascii grid/
          *columns,   // Point to arrays which store ascii grid/
          place[2],   // Representation of play move in 1D array - formay x,y
          grid[3][3] = {0,0,0,0,0,0,0,0,0}; // Representation of gameplay grid used to track pieces

    int   stop,       // stop flag for application
          i;          // interfation counter for application

    while(stop!=1)
    {

        updategrid(place, grid);

        // Allocate memory for rows in grid pointers to pointers,
        // this is because this is a 1D array which will point to
        // other 1D arrays
        rows = (char**)malloc(GRIDHEIGHT*sizeof(char*));
        // Fill array with values and print
        for(int i=0; i<GRIDHEIGHT; i++)
        {
            // Allocate memory for 1D array for this array index in rows[i]
            // rows[i] is a char pointer pointer type
            rows[i] = (char*)malloc(GRIDWIDTH*sizeof(char));

            for(int j=0; j<GRIDWIDTH; j++)
            {
                // assign columns char pointer type the address of the allocated
                // array for the point point array.
                columns = rows[i];

                if(i % SPACEHEIGHT == 0)
                {
                    columns[j] = '#';
                }
                else if(j % SPACEWIDTH == 0)
                {
                    columns[j] = '#';
                }
                else
                {
                    columns[j] = ' ';
                }

            }
        }

        for(int i=0; i<GRIDHEIGHT; i++)
        {
            // index through row pointer pointer array to get value for columns array
            columns = rows[i];
            for(int j=0; j<GRIDWIDTH; j++)
            {
                printf("%c", *(columns + j));
            }
            printf("\n");
        }

        userinput(place);

        free(rows);
    }


    return 0;
}


/* This function gets the user input from the terminal and parses it
* to determine how to move
*/
void *userinput(char *place)
{

   int i = 0;     // Set array iterator to 0.
   char move[20], // Array to store user input from stdin
        c;        // char read in from stdin

   printf("Player select next move in format xy (i.e. 23) : ");
   scanf("%s", move);

   // index through user input and print until end of string
   // populate place array
    do
    {
        c = move[i];

        place[i] = c;

        printf("%c\n",move[i]);

        i++;

    } while(c != '\0');
}

// Update grid array with new user place to track gameplay - this function indexes
// through place to extract the values which are used to update the grid array
// indicating that a piece is present
void updategrid(char *place, char grid[][3])
{
    int i,
        n,
        m;

    // Execute block if not empty string - indicated by end-of-string in place[0]
    if(place[0]!='\0')
    {

        // iterate over the place array, so while i<2 as place is a 1D array with
        // size 2.
        while(i<2)
        {
            // Only two cases to be handled as 0<=i<2 this structure sets the indexes
            // for the gameplay grid which should be changed.
            switch(i){
                case 0:
                    n = place[i];
                    break;
                case 1:
                    m = place[i];
                    break;
                default:
                    printf("exceeded input size\n");
            }
            i++;
        }

        // Print out indexes to verify assignment
        printf("n = %c m = %c \n", n, m);

        // set gameplay grid at indexes to 1 to indicate piece is present.
        grid[n][m] = 1;

        // Print grid value at indexes to verify that grid value is correct
        printf("User Input!: %d\n", grid[n][m]);

        // Iterate over rows and columns of gameplay grid to show all values
        // of index in the grid.
        // How to reference array indexes in 2D arrays?
        for(n = 0; n<=2; n++)
        {
            for(m = 0; m<=2; m++)
            {
                // Print value at grid index n, m
                printf("grid[%d][%d] = %c\n", n, m, grid[n][m]);
            }
        }
    }
}

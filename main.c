#include<stdio.h>
#include<stdlib.h>

#define GRIDHEIGHT 18
#define GRIDWIDTH 36
#define SPACEHEIGHT 6
#define SPACEWIDTH 12

void *userinput(char *place);
void updategrid(char *place, char *grid);

int main()
{
    char **rows, *columns, place[2], grid[2][2];
    int stop, i;

    while(stop!=1)
    {

        updategrid(place, *grid);

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

void *userinput(char *place)
{
    /* This function gets the user input from the terminal and parses it
    * to determine how to move
    */
   int i;
   char move[20], c;

   printf("Player select next move in format xy (i.e. 23) : ");
   scanf("%s", move);

   i = 0;

    do 
    {
        c = move[i];

        place[i] = c;

        printf("%c\n",move[i]);

        i++;

    } while(c != '\0');
}

void updategrid(char *place, char *grid)
{
    int i, n, *m;
    
    if(place[0]!='\0')
    {

        while(i<2)
        {
            switch(i){
                case 0:
                    n = place[i];
                    break;
                case 1:
                    *m = place[i];
                    break;
                default:
                    printf("exceeded input size\n");
            }
            i++;
        }
        printf("n = %c m = %c \n", n, *m);
        grid[n][m] = 1;
        printf("User Input!: %d\n", grid[n][m]);
    }
}
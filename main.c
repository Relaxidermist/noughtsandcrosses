#include<stdio.h>
#include<stdlib.h>

#define GRIDHEIGHT 18
#define GRIDWIDTH 36
#define SPACEHEIGHT 6
#define SPACEWIDTH 12

int main()
{
    char **rows, *columns;
    char move[20];
    char c;
    int stop, i;

    while(stop!=1)
    {
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
        
        printf("Player Select Move in format xy i.e. '23': ");
        scanf("%s", move);

        printf("Size of: %d\n", sizeof(move));

        i = 0;
        do
        {
            c = move[i];
            printf("%c\n",move[i]);
            i++;
        }  while(c != '\0');

        free(columns);
        free(rows);
    }
        

    return 0;
}
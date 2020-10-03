#include<stdio.h>
#include<stdlib.h>

// This is a simple program that plays noughts and crosses in the bash shell
int draw();
int welcome();
char *makegrid();

char choice;

#define GRIDSIZE 3

int main()
{

    choice=welcome();

    if(choice=='y')
    {
        //Play the game
        printf("\nLets play!\n");
        printf("\nPress q to if you would like to quit\n");


        while(getchar()!='q')
        {
            draw(1);
        }

    }
    else if(choice=='n')
    {
        printf("\nQuitting\n");
    } 
    return 0;
}

int welcome(){
    
    char key;
    int select = 1;
    
    printf("\nWelcome to noughts and crosses!\n");
    printf("\nPress Y to continue, press N to quit:\n");
    
    while(select){
        key = getchar();

        if(key=='y')
        {
            select = 0;
        }
        else if(key=='n')
        {
            select = 0;
        }
    }
    return key;
}

int draw(int init)
{
    
    char *pg;

    if(init==1)
    {
        char *rows, *columns;
        
        pg = makegrid(rows, columns);

        for(int i=0; i<GRIDSIZE; i++)
        {

            printf("%x\n",pg + i);

        }
    }

}

char *makegrid(char *rows, char *columns)
{
    //This function returns a pointer to an array containing a grid
    rows = (char*)malloc(GRIDSIZE*sizeof(char));

    for(int i=0;i<GRIDSIZE;i++)
    {   
        columns = (char*)malloc(GRIDSIZE*sizeof(char));

        for(int j=0;j<GRIDSIZE;j++)
        {
            printf("%x\n", &columns[j]);
        }

        rows[i] = columns;
        printf("%x\n",&rows[i]);
    }
    return rows;
}





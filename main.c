#include<stdio.h>
#include<string.h>

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

int draw(int init){
    
    char *pg;

    if(init==1)
    {
        pg = makegrid();

        for(int i=0; i<GRIDSIZE; i++)
        {
            printf("%d\n",*(pg+i));
        }
    }

}

char *makegrid()
{
    //This function returns a pointer to an array containing a grid
    static char grid[10];

    for(int i=0;i<GRIDSIZE;i++)
    {
        printf("hello\n");
        grid[i] = i;
    }
    return grid;
}


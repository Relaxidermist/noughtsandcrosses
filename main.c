#include<stdio.h>

// This is a simple program that plays noughts and crosses in the bash shell
int draw();
int welcome();
int *makegrid();

char choice;

#define GRIDSIZE 2

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
    int *pg;

    if(init==1){
        pg = makegrid(GRIDSIZE);
    }

}

int *makegrid(int size)
{
    int grid[size];

    for(int i=0;i<size;i++)
    {
        for (int j=0; j<size;j++)
        {
            grid[i] = i;
        }
        

    }
    return grid;
}


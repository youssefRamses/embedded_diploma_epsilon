#include <stdio.h>
#include <stdlib.h>
#include "car.h"

int main()
{
    display();
    while(1)
    {
        if(getch()=='s')
        {
            race_mode();
        }

        while(getch()=='w')
        {

            acc();

        }
        while(getch()=='a')
        {

            breaks();

        }
        if (getch()=='q')
        {
            gup();
        }
        if (getch()=='z')
        {
            gdwn();
        }


    }
}


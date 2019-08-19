#include "car.h"
#include<stdlib.h>
#include<stdio.h>
void display(void); //function that displays the state of the car
void race_mode(void);
struct vehicle
{
    int speed;
    int speed_level;
    int gear;
    int race;
} lanos;    // structure of a car with it's speed and speed level and gears and the name of the car is Lanos
//acceleration function when you press 'w' the car starts moving and starts accelerating
void acc()
{
    while(lanos.speed<lanos.speed_level)
    {
        lanos.speed++;
        system("CLS");
        display();
        if(lanos.race==1)
        {
            for(int i=0; i<10000000; i++);
        }
        else
        {
            for(int j=0; j<10000000; j++)
                ;
        }

    }
}
//when you press 'a' the car starts breaking
void breaks()
{
    if (lanos.speed>0)
    {
        lanos.speed--;
        system("CLS");
        display();
    }
}
//this function sets the speed level of the gear
void setlev(int x)
{
    switch(x)
    {
    case 1:
    {
        lanos.speed_level=50;
        break;
    }
    case 2:
    {
        lanos.speed_level=100;
        break;
    }
    case 3:
    {
        lanos.speed_level=150;
        break;
    }
    case 4:
    {
        lanos.speed_level=200;
        break;
    }
    case -1:
    {
        lanos.speed_level=30;
        break;
    }
    }
}
//this function changes the gear to a higher one
void gup()
{
    if(lanos.gear<4)
    {
        lanos.gear++;
        setlev(lanos.gear);
    }
    system("cls");
    display();
}
//this function changes the gear to a lower one
void gdwn()
{
    if(lanos.gear>-1)
    {
        lanos.gear--;
        setlev(lanos.gear);
    }
    system("CLS");
    display();

}

void display()
{
    if(lanos.race==1)
    {
        printf("RACE MODE ON\n");
    }
    else if(lanos.race==0)
    {

        printf("RACE MODE OFF\n");
    }
    printf("Gear \t\t Speed\n");
    if(lanos.gear==0)
    {
        printf("N");
    }
    else if (lanos.gear==-1)
    {
        printf("R");
    }
    else
    {
        printf("%d",lanos.gear);
    }
    printf("\t \t %d Km/h",lanos.speed);

}
void race_mode(void)
{
    if(lanos.race==0)
    {
        lanos.race=1;

    }
    else if(lanos.race==1)
    {
        lanos.race=0;
    }

}

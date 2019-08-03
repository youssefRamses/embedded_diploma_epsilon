#include <stdio.h>
typedef unsigned char u8;
u8 a[12]={1,2,2,2,3,4,5,1,2,2,2,8};

u8 find_twos(u8 *a, u8 size ){
u8 counter=0;

for(int i=0;i<size;i++){
        printf("%d\n",*a);
 if (*a==2) {

        counter++;

 }
 a++;
}
return counter;
}

int main()
{
double x;
printf("Number %d\n",sizeof(a));
 u8 number= find_twos(a,12);
 printf("Number of twos is %d \n",number);

}


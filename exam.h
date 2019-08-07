#include <stdio.h>
#include <stdlib.h>

//program 6
#define set_bit(register,bit) a=a|(1<<bit)
#define get_bit(register,bit) (register>>bit)&1
//
int func1(int x);
int func2(void);
int func3(int *a,int n);
int func4(int *a, int n);
int func5(int *a,int n);
int func7(int *R1,int *R2,int b1,int b2);
void func8(void);
int func9(int *a,int n);
int func10(void);

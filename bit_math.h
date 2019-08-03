#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED

#define set_bit(register,bit) a=a|(1<<bit);
#define clear_bit(register,bit) a=a&(~(1<<bit));
#define read_bit(register,bit) (register>>bit)&1;
#define toggle(register,bit) (register^(1<<bit));
#endif // BIT_MATH_H_INCLUDED

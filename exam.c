int func1(float x){

    while(x!=0){

   x = (int) x/2;
     if(x/10!=0){
        printf("1\n");
     }
      else if(x/10==0){
        printf("0\n");
      }

    }

}
int func2(void){
int n=1;
for(int i=3;i<100;i++){
 for(int j=1;j<=i-1;j++){
    if(i%j!=0){
        break;
    }
    else n++;
 }
}
printf("Number of prime numbers from 0-100 is %d",&n);
}
int func3(int *a,int n){

int max1=0,max2=0;

for(int i=0;i<n;i++){
 if(a[i]>max1){
    max1=a[i];
 }}
 for(int i=0;i<n;i++){
while(max1>max2){
if(a[i]>max2){
max2=a[i];
}

}}
printf("max 1 is: %d\t max 2 is: %d\n",max1,max2);

}
int func4(int *a, int n){
for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
     if(a[i]<a[j]){
        int temp=0;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
     }
    }
}
}
int func5(int *a,int n){
int x=5,y=5;
int e[x];
int o[y];
for(int i=0;i<n;i++){
 if(a[i]%2==0){
    e[x]=a[i];
  e++;
     }
 else{
        o[0]=a[i];
        o++;
 }
}
printf("Even:\n");
for(int i=0;i<x;i++){
    printf("%d\n",e[i]);
}
printf("odd:\n");
for(int i=0;i<y;i++){
    printf("%d\n",o[i]);
}
}
int func10(void){
for(int j=7;j>0;j--){
        printf("*");
    }
    printf("\n");printf(" ");
for(int j=5;j>0;j--){
        printf("*");
}   printf("\n");
printf("  ");
for(int j=3;j>0;j--){
        printf("*");
}   printf("\n");printf("   ");
for(int j=1;j>0;j--){
        printf("*");
}   printf("\n");printf("  ");
for(int j=0;j<3;j++){
        printf("*");
}   printf("\n");printf(" ");
for(int j=0;j<5;j++){
        printf("*");
}   printf("\n");
for(int j=0;j<7;j++){
        printf("*");
}   printf("\n");
}
int func7(int *R1,int *R2,int b1,int b2){

get_bit(*R1,b1);
get_bit(*R2,b2);
set_bit(*R1,b1);
set_bit(*R2,b2);

}
void func8(void){
head=(struct node *)malloc(sizeof(struct  node));
head->next=NULL;
struct node * image_ptr;
    image_ptr=head;
    for(int i=0;i<4;i++){if(image_ptr->next==NULL){break;}
        image_ptr=image_ptr->next;
}
    image_ptr->next={struct node *}malloc(sizeof(struct  node));
    image_ptr->next->next=NULL;
}


int func9(int *a,int n){
int pairs=0;
for(int i=0;i<n;i++){
 for(int j=1;j<n;j++){
    if(a[i]==a[j]){
      pairs++;
       a[j]=rand()%100+2;
        break;
    }
 }
}
}

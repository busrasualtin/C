#include <stdio.h>
void faktoriyeltoplami(int *a, int b);
int main()
{
     int a[] = {1,2,3,4,5};
    
    faktoriyeltoplami(a,5);
    
    
    
    
    
    
   /* int a[] = {1,2,3,4,5,6,7,8};  // a -> {1,2,3,4,5,6,7,8}
    int *p;// boslukta ?
    p = &a[3]; // p -> {4,5,6,7,8}; 
    

    printf(" %d", *a);//1
    printf(" %d", *(a+1));//2
    printf(" %d", *(a+2));//3

    printf("\n %d", p[0]);//4
    printf(" %d",p[1]); //5
    printf(" %d", p[2]);//6
    
    printf("\n %d", *p); //4
    printf(" %d", *(p+1)); //5
    printf(" %d ", *(p+2)); //6
    
    
    
    p = p+1; // p -> {5,6,7,8}; 
    
     printf("\n %d", p[0]);///5
    printf(" %d",p[1]); //6
    printf(" %d", p[2]);//7
    
    printf("\n %d", *p); //5
    printf(" %d", *(p+1)); //6
    printf(" %d ", *(p+2)); //7
    
    
    // p -> {5,6,7,8}; ------ p -> {5,5,5,5}
    
    *p =5;
    *(p+1)=5;
    p[2]=5;
    p[3]=5;
    
    printf("\n %d", p[0]);
    printf(" %d",p[1]); 
    printf(" %d", p[2]);
    printf(" %d", p[3]);
    
    
    printf("\n %d", a[4]);
    printf(" %d",a[5]); 
    printf(" %d", a[6]);
    printf(" %d", a[7]);*/

}


void faktoriyeltoplami(int *a, int b){
int toplam =0;
    for(int i=0; i<b; i++){
        int faktoriyelibuluncak =*(a+i);
        int faktoriyel=1 ;
            for(int j=1; j<=faktoriyelibuluncak; j++){
                faktoriyel = faktoriyel * j; 
            }
        printf("%d nin faktoriyeli: %d\n", faktoriyelibuluncak, faktoriyel);
        toplam +=faktoriyel;
    }
    
    printf("\n TOPLAM : %d", toplam);
}











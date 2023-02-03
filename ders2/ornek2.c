#include <stdio.h>

#define PI 3.14

int main()
{
   //float p = 3.14;
  
    float r , cevre, alan ;
    
    printf("Yaricapi girin :");
    
    scanf("%f", &r);
    
    
    cevre=2*PI*r;
    
    alan=PI*r*r;
    
    printf ("Cevre olcusu : %.2f Alan olcusu : %.3f \n"  , cevre, alan );
           
}
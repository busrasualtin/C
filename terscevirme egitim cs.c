#include <stdio.h>
#include <string.h>
void terscevirici(char kelime[], char yenikelime[]);
int main()
{

 char cumle[40];
 gets(cumle);
 
 //programlama cok zevkli birsey
 
 char kelime1[20];
 char kelime2[20];
 char kelime3[20];
 char kelime4[20];
 char yenikelime[20];
 sscanf(cumle, "%s %s %s %s", kelime1,kelime2,kelime3,kelime4);
 printf("%s\n",kelime1);
terscevirici(kelime1,yenikelime);

 
 printf("%s ", yenikelime);
 
 return 0;
}

void terscevirici(char kelime[],char yenikelime[]){
    
    char kelimeyeni[strlen(kelime)];
    for(int i=0; i<strlen(kelime); i++){
        strncpy(&yenikelime[i],&kelime[11-i-1],1);
        
    }
    
}










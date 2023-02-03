#include <stdio.h>
#include <string.h>
#define UZUNLUK 5

int main(){

    char metin[1000] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam imperdiet accumsan mattis. In hac habitasse platea dictumst. Nam ac risus arcu.";
    char kelimeler[UZUNLUK][20] = {"ipsum", "mehaba", "selam", "hac", "risus"};

    char *ptr = strtok(metin, " ");
    
    while(ptr != NULL){
        for(int i = 0; i < UZUNLUK; i++){
            if(!strcmp(ptr, kelimeler[i])){
                printf("%s\n", kelimeler[i]);
            }
        }
		ptr = strtok(NULL, " ");
	}

    return 0;
}
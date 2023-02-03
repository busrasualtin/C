#include <stdio.h>
#include <string.h>

struct kitaplar{
    char ad[20];
    char yazar[20];
    int id;
}kitap[10];

int main(void){
    strcpy(kitap[0].ad, "Kitap 1");
    strcpy(kitap[0].yazar, "Yazar 1");
    kitap[0].id = 1;

    strcpy(kitap[1].ad, "Kitap 2");
    strcpy(kitap[1].yazar, "Yazar 2");
    kitap[1].id = 2;

    for(int i = 0; i < 2; i++){
        printf("ID: %d, Yazar: %s, Kitap: %s\n", kitap[i].id, kitap[i].yazar, kitap[i].ad);
    }
    return 0;
}
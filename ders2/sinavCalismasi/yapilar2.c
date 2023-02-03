#include <stdio.h>

struct yap{
    char adi[20];       // Adı
    char soyadi[20];    // Soyadı
    char memleketi[20]; // Memleketi
    int yasi;
};

int main(void)
{
    struct yap yd = { "Caner", "Ates", "Izmir", 21 };
    printf("%s %s %s %d", yd.adi, yd.soyadi, yd.memleketi, yd.yasi);

    return 0;
}
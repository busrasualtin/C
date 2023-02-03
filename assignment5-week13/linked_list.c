#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Temel Dugum Yapimiz
struct node{
    int sayi;
    struct node* sonraki;
};

//Baslangic Dugumunu tutan Dugum
struct node* baslangic = NULL;

//Yeni bir dugum olusturmak icin hafizadan alan ayirir
//Daha sonra olusturdugu dugumu return eder
struct node* Olustur(int sayi)
{
    struct node* YeniDugum = (struct node*)malloc(sizeof(struct node));
    YeniDugum->sayi = sayi;
    YeniDugum->sonraki = NULL;

    return YeniDugum;
}

//Tek yonlu bagli liste sonuna eleman ekler
void SonaEkle(int sayi)
{
    struct node* SonaEklenecek = Olustur(sayi);

    if(baslangic == NULL)
    {
        baslangic = SonaEklenecek;
    }
    else
    {
        struct node* temp = baslangic;
        while(temp->sonraki != NULL)
        {
            temp = temp->sonraki;
        }
        temp->sonraki = SonaEklenecek;
    }
}

//Basa eleman ekleme fonksiyonu
void BasaEkle(int sayi)
{
    struct node* BasaEklenecek = Olustur(sayi);

    if(baslangic == NULL)
    {
        baslangic = BasaEklenecek;
        return;
    }

    struct node* EskiBirinci = baslangic;
    baslangic = BasaEklenecek;
    baslangic->sonraki = EskiBirinci;
}

// (Pozisyona Göre) Araya eleman ekleme fonksiyonu
void ArayaEkle(int pos, int sayi)
{
    struct node* ArayaEklenecek = Olustur(sayi);

    if(pos == 0)
    {
        BasaEkle(sayi);
        return;
    }

    struct node* temp = baslangic;
    int counter = 0;

    while(temp != NULL)
    {
        if(counter == pos-1)
            break;
        temp = temp->sonraki;
        counter++;
    }

    if(counter + 1 != pos)
    {
        printf("\n Boyle bir pozisyon yok...");
        return;
    }
    if(temp->sonraki == NULL)
    {
        SonaEkle(sayi);
        return;
    }

    struct node* SonrakiGecici = temp->sonraki;
    temp->sonraki = ArayaEklenecek;
    ArayaEklenecek->sonraki = SonrakiGecici;
}

//Sondan dugum siler
void SondanSil()
{
    if(baslangic == NULL)
    {
        printf("\n Zaten hic Eleman yok ...");
        return;
    }
    struct node* temp = baslangic;
    if(temp->sonraki == NULL)
    {
        BastanSil();
        return;
    }
    while(temp->sonraki->sonraki != NULL)
        temp = temp->sonraki;


    free(temp->sonraki);
    temp->sonraki = NULL;
}

//Bastan dugum siler
void BastanSil()
{
    if(baslangic == NULL)
    {
        printf("\n Zaten hic eleman yok ... ");
        return;
    }
    if(baslangic->sonraki == NULL)
    {
        baslangic = NULL;
        return;
    }

    struct node* Ikinci = baslangic->sonraki;
    free(baslangic);
    baslangic = Ikinci;
}

//(pozisyona göre aradan eleman siler
void AradanSil(int pos)
{
    struct node* temp = baslangic;
    int counter = 0;

    if(pos == 0)
    {
        BastanSil();
        return;
    }

    while(temp != NULL)
    {
        if(counter == pos - 1)
            break;
        temp = temp->sonraki;
        counter++;
    }

    if(counter + 1 != pos)
    {
        printf("\n Belirttiginiz indis bulunmuyor...");
        return;
    }

    if(temp->sonraki == NULL)
    {
        SondanSil();
    }

    struct node* Gecici = temp->sonraki->sonraki;
    free(temp->sonraki);
    temp->sonraki = Gecici;
}

//Kullanicinin verdigi elemani siler
void AradanElemanSil(int eleman)
{
    if(baslangic == NULL)
    {
        printf("\n Zaten hic eleman yok...");
        return;
    }

    if(baslangic->sayi == eleman)
    {
        BastanSil();
        return;
    }

    struct node* temp = baslangic;
    int flag = 0;
    while(temp->sonraki != NULL)
    {
        if(temp->sonraki->sayi == eleman)
        {
            flag = 1;
            break;
        }

        temp = temp->sonraki;
    }
    if(flag == 0)
    {
        printf("\n Aradiginiz eleman bulunamadi ...");
        return;
    }
    struct node* Gecici = temp->sonraki->sonraki;
    free(temp->sonraki);
    temp->sonraki = Gecici;
}

//Bagli listeyi iterative olarak ters cevirir
void TersCevirIterative()
{
    /*
    1 => 2 => 7 => 19 => NULL
    NULL <= 1 <= 2 <= 7 <= 19 =>

        mevcut, sonraki, onceki
    */
    struct node* mevcut = baslangic;
    struct node* onceki = NULL;
    struct node* sonraki = NULL;

    while(mevcut != NULL)
    {
        sonraki = mevcut->sonraki;
        mevcut->sonraki = onceki;

        /* temp = temp->sonraki */
        onceki = mevcut;
        mevcut = sonraki;
    }
    baslangic = onceki;
}

/*
10 => 20 => 30 => 40 => NULL
            30 <= 40
*/

//Bagli listeyi recursive olarak ters cevirir
struct node* TersCevirRecursive(struct node* MEVCUT)
{
    Bekle(3);
    if(MEVCUT == NULL)
        return;
    /* BASE CASE */
    if(MEVCUT->sonraki == NULL)
    {
        baslangic = MEVCUT;
        printf("\n En son dugum bulundu, Baslangic dugumu olarak guncellendi %d", MEVCUT->sayi);
        Bekle(3);
        return MEVCUT;
    }

    printf("\n Recursive cagrim gerceklesiyor: %d", MEVCUT->sonraki->sayi);
    struct node* DUGUM = TersCevirRecursive(MEVCUT->sonraki);
    printf("\n Return Edilen Dugum: %d",  DUGUM->sayi);
    Bekle(2);
    DUGUM->sonraki = MEVCUT;
    printf("\n %d => %d yapisi olusturuldu",  DUGUM->sayi, MEVCUT->sayi);
    Bekle(2);
    MEVCUT->sonraki = NULL;

    printf("\n Ana Fonksiyon Return Ediliyor %d", MEVCUT->sayi);
    return MEVCUT;

}

//Bagli liste elemanlarini yazdirir
void Yazdir()
{
    struct node* temp = baslangic;

    printf("\n");
    printf("\n");
    printf("\n*******************************");
    printf("\n");
    while(temp != NULL)
    {
        printf(" %d => ", temp->sayi);
        temp = temp->sonraki;
    }

    printf("\n*******************************");
    printf("\n");
    printf("\n");

}

//Bekleme fonksiyonu (sadece yardimci bir fonksiyon)
void Bekle(int Saniye)
{
    int MiliSaniye = 1000 * Saniye;
    clock_t start_time = clock();
    while (clock() < start_time + MiliSaniye)
        ;
}

int main()
{
    int secim, sayi, pos;

    while(1)
    {
        printf("\n ****** Ekleme Islemleri ****** ...");
        printf("\n 1- Sona Eleman Ekle ...");
        printf("\n 2- Basa Eleman Ekle ...");
        printf("\n 3- Araya Eleman Ekle ...");
        printf("\n");
        printf("\n ****** Silme Islemleri ****** ...");
        printf("\n 4- Sondan Sil ...");
        printf("\n 5- Bastan Sil ...");
        printf("\n 6- Aradan Sil (pozisyona gore)...");
        printf("\n 7- Aradan Sil (elemana gore)...");
        printf("\n 8- Ters Cevir (Iterative)...");
        printf("\n 9- Ters Cevir (Recursive)...");
        printf("\n Yapmak istediginiz islemi secin ...");
        scanf("%d", &secim);

        switch(secim)
        {
        case 1:
            printf("\n Hangi elemani ekleyeceksiniz? ... ");
            scanf("%d", &sayi);
            SonaEkle(sayi);
            Yazdir();
            break;
        case 2:
            printf("\n Hangi elemani ekleyeceksiniz? ... ");
            scanf("%d", &sayi);
            BasaEkle(sayi);
            Yazdir();
            break;
        case 3:
            printf("\n Hangi elemani ekleyeceksiniz? ... ");
            scanf("%d", &sayi);
            printf("\n Hangi pozisyona ekleyeceksiniz? ... ");
            scanf("%d", &pos);
            ArayaEkle(pos, sayi);
            Yazdir();
            break;
        case 4:
            SondanSil();
            Yazdir();
            break;
        case 5:
            BastanSil();
            Yazdir();
            break;
        case 6:
            printf("\n Hangi pozisyondan sileceksiniz? ... ");
            scanf("%d", &pos);
            AradanSil(pos);
            Yazdir();
            break;
        case 7:
            printf("\n Hangi elemani sileceksiniz? ... ");
            scanf("%d", &sayi);
            AradanElemanSil(sayi);
            Yazdir();
        case 8:
            TersCevirIterative();
            Yazdir();
            break;
        case 9:
            printf("\n Baslangic Dugumunden Baslaniyor %d", baslangic->sayi);
            Bekle(2);
            TersCevirRecursive(baslangic);
            Yazdir();
            break;

        }
    }
}

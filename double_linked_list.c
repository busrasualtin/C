#include <stdio.h>

/*NULL <= 10 <=> 20 <=> 30 => NULL*/

struct node
{
    int sayi;
    struct node* sonraki;
    struct node* onceki;
};

struct node* bas = NULL;
struct node* son = NULL;

struct node* Olustur(int sayi)
{
    struct node* YeniDugum = (struct node*)malloc(sizeof(struct node));
    YeniDugum->sayi = sayi;
    YeniDugum->sonraki = NULL;
    YeniDugum->onceki = NULL;

    return YeniDugum;
}

void SonaEkle(int sayi)
{
    struct node* SonaEklenecek = Olustur(sayi);

    if(bas == NULL)
    {
        bas = SonaEklenecek;
        return;
    }

    struct node* Temp = bas;
    while(Temp->sonraki != NULL)
    {
        Temp = Temp->sonraki;
    }
    Temp->sonraki = SonaEklenecek;
    SonaEklenecek->onceki = Temp;
    return;
}

void BasaEkle(int sayi)
{
    struct node* BasaEklenecek = Olustur(sayi);
    if(bas == NULL)
    {
        bas = BasaEklenecek;
        return;
    }

    /* 10 20 30 40 (5)*/
    struct node* Eski = bas;
    bas = BasaEklenecek;

    bas->sonraki = Eski;
    Eski->onceki = bas;
    return;
}

void ArayaEkle(int indis, int sayi)
{
    struct node* ArayaEklenecek = Olustur(sayi);

    if(indis == 0)
    {
        BasaEkle(sayi);
        return;
    }

    if(bas == NULL && indis > 0)
    {
        printf("\n Bu konum uygun degil ... ");
        return;
    }

    int counter = 0;
    struct node* Temp = bas;
    int flag = 0;
    while(Temp != NULL)
    {
        if(counter == indis)
        {
            flag = 1;
            break;
        }

        Temp = Temp->sonraki;
        counter++;
    }
    if(flag == 0)
    {
        printf("\n Boyle pozisyon  yok...");
        return;
    }

    if(Temp->sonraki == NULL)
    {
        SonaEkle(sayi);
        return;
    }

    /* 10 20 (777) 30 40 (777)*/
    struct node* OncekiDugum = Temp->onceki;
    OncekiDugum->sonraki = ArayaEklenecek;
    ArayaEklenecek->onceki = OncekiDugum;
    ArayaEklenecek->sonraki = Temp;
    Temp->onceki = ArayaEklenecek;
}

void SondanSil()
{
    if(bas == NULL)
        return;
    if(bas->sonraki == NULL)
    {
        //BastanSil()
        return;
    }

    struct node* temp = bas;
    while(temp->sonraki != NULL)
        temp = temp->sonraki;

    struct node* Onceki = temp->onceki;
    Onceki->sonraki = NULL;
    free(temp);
}

void BastanSil()
{

    if(bas == NULL)
        return;
    if(bas->sonraki == NULL)
    {
        bas = NULL;
        return;
    }

    struct node* Ikinci = bas->sonraki;
    Ikinci->onceki = NULL;
    free(bas);
    bas = Ikinci;

}


void AradanSilPos(int indis)
{
    if(indis == 0)
    {
        if(bas != NULL)
        {
            BastanSil();
            return;
        }
    }

    struct node* temp = bas;
    int counter = 0;
    int flag = 0;
    while(temp != NULL)
    {
        if(counter == indis)
        {
            flag = 1;
            break;
        }
        temp = temp->sonraki;
        counter++;
    }
    if(flag == 0)
    {
        printf("\n Boyle bir konum bulunmuyor ... ");
        return;
    }


    if(temp->sonraki == NULL)
    {
        SondanSil();
        return;
    }
    struct node* Onceki = temp->onceki;
    struct node* Sonraki = temp->sonraki;

    Onceki->sonraki = Sonraki;
    Sonraki->onceki = Onceki;
    free(temp);
}

void Yazdir(struct node* Bas, int ileri)
{
    struct node* temp = Bas;
    printf("\n\n******* Mevcut Liste Yapisi *******\n");
    while(temp != NULL)
    {
        printf(" %d ", temp->sayi);
        if(ileri == 1)
            temp = temp->sonraki;
        else
            temp = temp->onceki;
    }
    printf("\n***********************************");
}

int main()
{
    int secim, sayi, indis;

    while(1)
    {
        printf("\n\n\n ****** Ekleme Islemleri ****** ...");
        printf("\n 1- Sona Eleman Ekle ...");
        printf("\n 2- Basa Eleman Ekle ...");
        printf("\n 3- Araya Eleman Ekle ...");
        printf("\n");
        printf("\n ****** Silme Islemleri ****** ...");
        printf("\n 4- Sondan Sil ...");
        printf("\n 5- Bastan Sil ...");
        printf("\n 6- Aradan Sil (pozisyona gore)...");
        printf("\n Yapmak istediginiz islemi secin ...");
        scanf("%d", &secim);

        switch(secim)
        {
        case 1:
                printf("\n Eklemek istediginiz sayiyi girin ...");
                scanf("%d", &sayi);
                SonaEkle(sayi);
                Yazdir(bas, 1);
            break;
        case 2:
                printf("\n Eklemek istediginiz sayiyi girin ...");
                scanf("%d", &sayi);
                BasaEkle(sayi);
                Yazdir(bas, 1);
            break;
        case 3:
                printf("\n Eklemek istediginiz sayiyi girin ...");
                scanf("%d", &sayi);
                printf("\n Hangi Konuma Ekleyeceksiniz ...");
                scanf("%d", &indis);
                ArayaEkle(indis, sayi);
                Yazdir(bas, 1);
                break;

        case 4:
                SondanSil();
                Yazdir(bas, 1);
            break;
        case 5:
                BastanSil();
                Yazdir(bas, 1);
            break;
        case 6:
                printf("\n Hangi indisteki degeri sileceksiniz");
                scanf("%d", &sayi);
                AradanSilPos(sayi);
                Yazdir(bas, 1);
            break;


        }
    }

}

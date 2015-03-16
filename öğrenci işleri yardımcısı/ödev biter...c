#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ogr_no,ders_say,ders_kredi,ders_not,i,top_kredi,ust60_not=0,ders3_alti=0,basari_say=0;
    int sayac,max_not_no,max_not_top_kredi,max_burs_no,max_burs_top_kredi,burs_buyuk_300=0,aile_basari=0,yurt_basari=0,ev_basari=0,basarisiz_ikamet;
    int basarili_erkek=0,basarili_kiz=0,erk_say=0,kiz_say=0,not_35_alt=0,not_85_ust=0,sayac60;
    char cinsiyet,ikamet;
    float not_ort,burs_mik,max_not_burs,max_not_ort=0,max_burs=100,max_burs_not_ort,erkek_not_ort,kiz_not_ort,okul_ort,tum_kredi_top=0;
    float erkek_yuzde,kiz_yuzde,top_burs_mik=0,yuzde_35,yuzde_85,ust60_yuzde,kiz_top_ort=0,erkek_top_ort=0;

    printf("Ogrenci numarasi girin(0 ya da negatif deger veri girisinin bittigini belirtir):\n");
    scanf("%d",&ogr_no);


    while (ogr_no>0)

    {
        do
        {
            printf("Cinsiyeti girin(E/e:Erkek,K/k:Kiz:\n");
            fflush(stdin);/*Tamponlanmis bolgeyi siliyoruz*/
            cinsiyet=getchar();/*Cinsiyeti dogru girildigi halde ust uste sormamasý icin*/
        }
        while (cinsiyet!='e' && cinsiyet!='E' && cinsiyet!='k' && cinsiyet!='K');

        if (cinsiyet=='k' || cinsiyet=='K')
            kiz_say++;

        if (cinsiyet=='e' || cinsiyet=='E')
            erk_say++;

        do
        {
            printf("Ikameti yerini girin(A/a:Ailesiyle,E/e:Evde,Y/y:Yurtta):\n");
            fflush(stdin);
            ikamet=getchar();
        }
        while (ikamet!='e' && ikamet!='E' && ikamet!='y' && ikamet!='Y' && ikamet!='a' && ikamet!='A');

        do
        {
            printf("Ders sayisini girin(1-10):\n");
            scanf("%d",&ders_say);
        }
        while (ders_say<1 || ders_say>10);

        if(ders_say<=3)
            ders3_alti++;/*Aldigi ders sayisi 3 ve altinda olan ogrencileri sayar*/

        sayac=0;
        top_kredi=0;
        not_ort=0;
        sayac60=0;

        for (i=1; i<=ders_say; i++)
        {
            do
            {
                printf("Dersin kredisini girin(1-10):\n");
                scanf("%d",&ders_kredi);
            }
            while (ders_kredi<1 || ders_kredi>10);

            do
            {
                printf("Dersin notunu girin(0-100):\n");
                scanf("%d",&ders_not);
            }
            while (ders_not<0 || ders_not>100);

            if(ders_not>=60)
                sayac60++;/*bir ogrenci icin notu 60 ve 60 dan buyuk ders sayisini sayar*/

            sayac=ders_not*ders_kredi+sayac;/*Her ders icin ders notu ve ders kredisinin
            carpimlarini toplar*/
            top_kredi=top_kredi+ders_kredi;/*Bir ogrencinin aldigi derslerin kredilerini toplar*/

        }
        tum_kredi_top=tum_kredi_top+top_kredi;/*Butun ogrencilerin kredi toplamlarini toplar*/
        not_ort=(float)sayac/top_kredi;

        if(sayac60==ders_say)
            ust60_not++;/*Tum derslerinin notlari 60 ve 60 dan buyuk olanlari sayar*/
        if(cinsiyet=='k'||cinsiyet=='K')
            kiz_top_ort=kiz_top_ort+not_ort;/*Butun kizlarin agirlikli not ortalamalarinin toplami*/
        if(cinsiyet=='E'||cinsiyet=='e')
            erkek_top_ort=erkek_top_ort+not_ort;/*Butun erkeklerin agirlikli not ortalamalarinin
            toplami*/

        if(not_ort>=60)
        {
            if (cinsiyet== 'e' || cinsiyet== 'E')
                basarili_erkek++;

            else if(cinsiyet== 'k' || cinsiyet== 'K')
                basarili_kiz++;
        }

        printf("ogrenci numaraniz:%d\n",ogr_no);
        printf("toplam kredi:%d\n",top_kredi);
        printf("agirlikli not ortalamaniz:%.2f\n",not_ort);

        if (not_ort<35)
        {
            not_35_alt=not_35_alt+1;/*Agirlikli not ortalamasi 35 in altinda olan ogrencileri sayar*/
        }
        if (not_ort>85)
        {
            not_85_ust=not_85_ust+1;/*Agirlikli not ortalamasi 85 in ustunde olan ogrencileri sayar*/
        }
        if (not_ort<60)
        {
            burs_mik=100;
        }
        else if (not_ort<70)
        {
            burs_mik=(float)140+not_ort*12/10;
        }
        else if (not_ort<80)
        {
            burs_mik=(float)170+not_ort*13/10;
        }
        else if (not_ort<90)
        {
            burs_mik=(float)190+not_ort*15/10;
        }
        else
            burs_mik=(float)200+not_ort*18/10;

        if (ikamet=='A' || ikamet=='a')
        {
            burs_mik=burs_mik;/*Ailesinin yaninda kalan ogrenciler icin burs miktari degismez*/
            printf("Bursunuz:%.2f TL\n",burs_mik);
        }
        else if (ikamet=='E' || ikamet=='e')
        {
            burs_mik=burs_mik*3/2;/*Ayri evde kalan ogrenciler icin burs miktari 1.5 katina cikar*/
            printf("Bursunuz:%.2f TL\n",burs_mik);
        }
        else if(ikamet=='Y' || ikamet=='y')
        {
            burs_mik=burs_mik*13/10;/*Yurtta kalan ogrenciler icin burs miktari 1.3 katina cikar*/
            printf("Bursunuz:%.2f TL\n",burs_mik);
        }
        top_burs_mik=top_burs_mik+burs_mik;/*Butun ogrencilerin burslarini toplatir*/

        if (burs_mik>300)
            burs_buyuk_300=burs_buyuk_300+1;/*Aldigi burs miktari 300 TL den fazla olan ogrencileri
            sayar*/

        if (not_ort>max_not_ort)/*Okul birincisi icin istenen verileri bulmak icin*/
        {
            max_not_ort=not_ort;
            max_not_burs=burs_mik;
            max_not_no=ogr_no;
            max_not_top_kredi=top_kredi;
        }

        if (burs_mik>max_burs)/*En cok bursu alan ogrenci icin istenen verileri bulmak icin*/
        {
            max_burs=burs_mik;
            max_burs_no=ogr_no;
            max_burs_not_ort=not_ort;
            max_burs_top_kredi=top_kredi;
        }
        if(not_ort>=60)
        {
            basari_say++;
            if(ikamet=='e'||ikamet=='E')
                ev_basari++;/*Evde kalip basarili olan ogrencileri sayar*/

            else if(ikamet=='y'||ikamet=='Y')
                yurt_basari++;/*Yurtta kalip basarili olan ogrencileri sayar*/
            else if(ikamet=='a'||ikamet=='A')
                aile_basari++;/*Ailesiyle kalip basarili olan ogrencileri sayar*/
        }

        if(ev_basari<yurt_basari && ev_basari<aile_basari)
            basarisiz_ikamet=ev_basari;
        else if(yurt_basari<aile_basari)
            basarisiz_ikamet=yurt_basari;
        else
            basarisiz_ikamet=aile_basari;

        kiz_yuzde=(float)(basarili_kiz*100)/kiz_say;/*basarili kiz yuzdesi*/
        erkek_yuzde=(float)(basarili_erkek*100)/erk_say;/*basarili erkek yuzdesi*/
        yuzde_35=(float)(100*not_35_alt)/(kiz_say+erk_say);/*not ortalamasi 35 in altinda olan
        ogrencilerin yuzdesi*/
        yuzde_85=(float)(100*not_85_ust)/(kiz_say+erk_say);/*not ortalamasi 85 in ustunde olan
        ogrencilerin yuzdesi*/
        ust60_yuzde=(float)(100*ust60_not)/(erk_say+kiz_say);/*Hicbir dersi 60 in altinda olmayan
        ogrencileri yuzdesi*/
        erkek_not_ort=(float)erkek_top_ort/erk_say;/*Tum erkeklerin agirliki not ortalamasi*/
        kiz_not_ort=(float)kiz_top_ort/kiz_say;/*Tum kizlarin agirlikli not ortalamasi*/
        okul_ort=(float)(erkek_top_ort+kiz_top_ort)/(erk_say+kiz_say);//Genel agirlikli not ortalamasi

        printf("Ogrenci no gir:");
        scanf("%d",&ogr_no);
    }
    printf("basarili kiz yuzdesi: %.2f\n",kiz_yuzde);
    printf("basarili erkek yuzdesi: %.2f\n",erkek_yuzde);
    printf("Genel basari yuzdesi: %.2f\n",(float)(100*basari_say)/(erk_say+kiz_say));
    printf("\n");
    printf("Kizlarin agirlikli not ortalamasi: %.2f\n",kiz_not_ort);
    printf("Erkeklerin agirlikli not ortalamasi: %.2f\n",erkek_not_ort);
    printf("Genel agirlikli not ortalamasi: %.2f\n",okul_ort);
    printf("\n");
    printf("Ogrencilerin aldigi derslerin kredi ortalamasi: %.2f\n",(float)tum_kredi_top/(erk_say+kiz_say));
    printf("Aldigi ders sayisi 3 ve altinda olan ogrencilerin sayisi: %d\n",ders3_alti);
    printf("Hicbir dersinin notu 60 in altinda olmayan ogrencilerin sayisi: %d\n",ust60_not);
    printf("Hicbir dersinin notu 60 in altinda olmayan ogrenci yuzdesi: %.2f\n",ust60_yuzde);
    printf("\n");
    printf("Agirlikli not ortalamasi 35 in altinda olan ogrencilerin sayisi: %d\n",not_35_alt);
    printf("Agirlikli not ortalamasi 35 in altinda olan ogrencilerin yuzdesi: %.2f\n",yuzde_35);
    printf("Agirlikli not ortalamasi 85 in ustunde olan ogrencilerin sayisi: %d\n",not_85_ust);
    printf("Agirlikli not ortalamasi 85 in ustunde olan ogrencilerin yuzdesi: %.2f\n",yuzde_85);
    printf("\n");
    printf("Burs miktari 300 TL den fazla olan ogrencilerin sayisi: %d\n",burs_buyuk_300);
    printf("\n");
    printf("Okul birincisi olan ogrencinin numarasi: %d\n",max_not_no);
    printf("Okul birincisi olan ogrencinin aldigi derslerin toplam kredisi: %d\n",max_not_top_kredi);
    printf("Okul birincisi olan ogrencinin agirlikli not ortalamasi: %.2f\n", max_not_ort);
    printf("Okul birincisi olan ogrencinin burs miktari: %.2f\n",max_not_burs);
    printf("\n");
    printf("En cok burs alacak olan ogrencinin numarasi: %d\n",max_burs_no);
    printf("En cok burs alacak olan ogrencinin aldigi derslerin toplam kredisi: %d\n",max_burs_top_kredi);
    printf("En cok burs alacak olan ogrencinin agirlikli not ortalamasi: %.2f\n",max_burs_not_ort);
    printf("En cok burs alacak olan ogrencinin burs miktari: %.2f\n",max_burs);
    printf("Ogrencilere sonraki donem her ay odenecek toplam burs miktari: %.2f\n",top_burs_mik);

    if(basarisiz_ikamet==ev_basari)
        printf("basarili ogrencilerin yuzdesinin en dusuk oldugu ikamet yeri: EV\n");
    else if(basarisiz_ikamet==yurt_basari)
        printf("basarili ogrencilerin yuzdesinin en dusuk oldugu ikamet yeri: YURT\n");
    else if(basarisiz_ikamet==aile_basari)
        printf("basarili ogrencilerin yuzdesinin en dusuk oldugu ikamet yeri: AILE\n");

    return 0;
}

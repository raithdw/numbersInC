#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int optiune;

int main()
{

    do{
    printf("<1> Se citeste un numar natural n. "
           "Se introduc de la tastatura n numere intregi. Programul afiseaza numarul maxim dintre cele n citite.\n");
    printf("\n<2> Se citeste un numar natural n. Sa se afiseze toate numerele prime mai mici sau egale cu n.\n");
    printf("\n<3> Se citeste un numar natural n. Sa se afiseze descompunerea sa in factori primi.\n");
    printf("\n<4> Se citesc doua numere: a si b.\n"
           "Sa se afiseze cel mai mare divizor comun al numerelor. Sa se afiseze cel mai mic multiplu comun al numerelor.\n");
    printf("\n<5> Se citeste un numar natural n. Sa se afiseze suma cifrelor sale. Sa se afizeze cifra de control a numarului.\n");
    printf("\n<6> Se citesc doua numere naturale n si b (b<10). Sa se reprezinte numarul n in baza b.\n");
    printf("\n<7> Se citesc doua numere naturale n si b (b!=10). Se considera ca numarul n este scris in baza b. Sa se afiseze valoarea lui n in baza 10.\n");
    printf("\n<8> Sa se scrie un program care citeste numarul natural n si determina suma S=1+1*2+1*2*3+...+1*2*...*n.\n");
    printf("\n<9> Se citesc numere de la tastatura pana la aparitia lui zero. Sa se determine cate perechi de elemente citite consecutiv se termina cu aceeasi cifra.\n");
    printf("\n<10> Sa se afiseze primele n numere din sirul lui Fibbonacci. (f1=0, f2=1)\n");
    printf("\n<11> Parasirea programului.\n");

    printf("\n********************************************************************************");
    printf("Selecteaza optiunea: ");
    scanf("%d", &optiune);
     switch(optiune){

        case 1: maxim(); break;
        case 2: prime(); break;
        case 3: factoriPrimi(); break;
        case 4: cmmdc(); break;
        case 5: cifraControl(); break;
        case 6: baza(); break;
        case 7: baza10(); break;
        case 8: suma(); break;
        case 9: perechi(); break;
        case 10: fibo(); break;
        case 11: iesire(); break;


    }
    }while(optiune);




    return 0;
}

void maxim(int n)

{
    int i, maxx = 0, nr;


    printf("Introduceti numarul de cifre: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
            printf("\nIntroduceti numarul %d: ", i+1);
            scanf("%d", &nr);
        if(nr > maxx)
            maxx = nr;
    }
    printf("\nNumarul maxim dintre cele %d numere citite este: %d", n, maxx);
    printf("\n********************************************************************************\n");
}

void prime(int n){

    int i, j, prim;

    printf("Dati n = ");
    scanf("%d", &n);
    printf("Numerele prime mai mici sau egale cu %d sunt: ", n);
    for (i = 2; i <= n; i++){
        prim = 1;
        for (j = 2; j <= i/2; j++)
        if(i % j == 0)
            prim = 0;
        if (prim == 1)
            printf("%d ", i);
    }
    printf("\n********************************************************************************\n");
}

void factoriPrimi(int n){

    int d = 2, p;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    while (n > 1){
        p = 0;
        while(n % d == 0){
            ++p;
            n /= d;
        }
    if(p)
        printf("Factorul este %d iar puterea este %d ", d, p);
    ++d;
    if ((n >1) && (d * d > n))
        d = n;

    }
    printf("\n********************************************************************************\n");


}

void cmmdc(){

    int a, b, c, x, y, cmmmc;
    printf("Dati a = ");
    scanf("%d", &a);
    printf("Dati b = ");
    scanf("%d", &b);
    x = a; // x si y memoreaza copia numerelor a si b
    y = b;
    while(b > 0){
        c = a % b;
        a = b;
        b = c;
    }
    if(a == 0 && b == 0)
        printf("-1");
    else
       printf("cmmdc este %d ", a);

    cmmmc = (x * y)/ a; //calculez cmmmc in functie de cmmdc cu aceasta formula
    printf("si cmmmc este %d ", cmmmc);
    printf("\n********************************************************************************\n");
}

void cifraControl(int n){
    printf("Introduceti n = ");
    scanf("%d", &n);
    while(n > 9){
        int s = 0;
        while(n >0){
            s = s + n % 10;
            n = n / 10;
        }
        n = s;
    }
    printf("Cifra de control este %d ", n);
    printf("\n********************************************************************************\n");

}

void baza(){
    int n, b, x, y, r, nr =0, p = 1;
    printf("Dati n = ");
    scanf("%d", &n);
    x = n;
    printf("Dati b = ");
    scanf("%d", &b);
    y = b;
    while(n != 0){
        r = n % b;
        n = n / b;
        nr = nr + r * p;
        p = p * 10;

    }
    printf("Numarul %d in baza %d este %d", x, y, nr);
    printf("\n********************************************************************************\n");
}

void baza10(){
    int n, b, x, y, r, nr =0, p = 1;
    printf("Dati n = ");
    scanf("%d", &n);
    x = n;
    printf("Dati b = ");
    scanf("%d", &b);
    y = b;
    while(n != 0){
        r = n % 10;
        n = n / 10;
        nr = nr + r * p;
        p = p * b;

    }
    printf("Numarul %d in baza %d este %d in baza 10", x, y, nr);
    printf("\n********************************************************************************\n");
}

void suma(int n){

    long long i, s = 0, p = 1;
    printf("Introduceti numarul ");
    scanf("%llu", &n);
    for(i = 1; i <= n; i++){
        p *= i;
        s += p;

    }
    printf("Suma este %llu ", s);
    printf("\n********************************************************************************\n");
}

void perechi(){

    int perechi = 0, nrAnterior, nr;
    printf("Introduceti numerele: \n");
    scanf("%d", &nrAnterior);
    while( scanf("%d", &nr) && nr != 0){
        if(nr % 10 == nrAnterior % 10)
            perechi++;
        nrAnterior = nr;

    }
    printf("Numarul de perechi este: %d",perechi);
    printf("\n********************************************************************************\n");
}

void fibo(int n){

    int f1 = 0, f2 = 1, i;
    printf("Introduceti n = ");
    scanf("%d", &n);
    printf("%d %d ", f1, f2);
    for(i = 3; i <= n; i++){
        f2 += f1;
        f1 = f2 - f1;
        printf("%d ", f2);
    }
    printf("\n********************************************************************************\n");
}

void iesire(){

    optiune = 0;
}









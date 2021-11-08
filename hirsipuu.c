#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void tulosta_kuva(int virheet);
void tyhjennaPuskuri(void);

int main(void){
    char sana[50] = {0};
    char arvaus[50] = {0};
    int ran = 0, pituus = 0, virheet = 0, i = 0;
    int vertaus, ohi;
    char kirjain;

    srand(time(NULL));
    FILE* tiedosto;
    tiedosto = fopen("sanat.txt" , "r");
    //etsitaan sana
    for(; fgets(sana , sizeof(sana) , tiedosto) ; i++)
          ;
    ran = rand() % i;
    rewind(tiedosto);
    for(i = 0 ; i < ran ; i++){
        fgets(sana , sizeof(sana) , tiedosto);
        if(sana[strlen(sana)-1] == '\n')
            sana[strlen(sana)-1] = '\0';
    }

    pituus = strlen(sana);

    while(1){
        ohi = 0;
        printf("\nArvaa kirjain: >\n");
        scanf("%c", &kirjain);
        for(int i = 0; i < pituus; i++){
            if(kirjain == sana[i]){
                arvaus[i] = kirjain;
            }
            else
                ohi++;
        }
        if(ohi == pituus){
            virheet++;
            tulosta_kuva(virheet);
        }
        else{
            for(int i = 0; i < pituus; i++){
                if(arvaus[i] == sana[i])
                    printf("%c", arvaus[i]);
                else
                    printf("_");
            }
            printf("\n");
        }
        if((vertaus = strcmp(arvaus, sana)) == 0)
            break;
        else if(virheet == 8)
            break;
        tyhjennaPuskuri();
    }
    
    if(virheet == 8)
        printf("Arvattava sana oli: %s\n", sana);
    else
        printf("Hienoa, arvasit oikein!\n");
    return 0;
}

void tulosta_kuva(int virheet){
    char *kuvat[] = {"",
                    "-------\n",

                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "-------\n",
                    "   ____\n"
                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "-------\n",

                    "   _____\n"
                    "   |   |\n"
                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "-------\n",
                    
                    "   _____\n"
                    "   |   |\n"
                    "   |   0\n"
                    "   |   \n"
                    "   |   \n"
                    "   |   \n"
                    "-------\n",

                    "   _____\n"
                    "   |   |\n"
                    "   |   0\n"
                    "   |   |\n"
                    "   |   \n"
                    "   |   \n"
                    "-------\n",

                    "   _____\n"
                    "   |   |\n"
                    "   |   0\n"
                    "   |  /|\\ \n"
                    "   |   \n"
                    "   |   \n"
                    "-------\n",

                    "   _____\n"
                    "   |   |\n"
                    "   |   0\n"
                    "   |  /|\\ \n"
                    "   |  / \\ \n"
                    "   |   \n"
                    "-------\n",
                    };
    printf("%s", kuvat[virheet]);
}

void tyhjennaPuskuri(void){
    while(getchar() != '\n');
}
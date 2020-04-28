#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
char tab[3][3][2];
int main()
{   int x,elc_usu,Cord_X,Cord_Y;
    gotoxy(1,40);
    //textcolor(RED);
    llenado();
    printf("TA TE TI");
    gotoxy(3,3);
    printf("Ingrese 5 numeros (segun las cooderdenadas, primero las x y luego los 0 )  para que el bot determine un Jugada:\n");
    for (x=0;x<3;x++) //toma los numeros ingresados por el usuario y los tranforma en coordenadas x e y para colocar las x en la matriz.
    {
          do {
                printf("numX%d:\t",x+1);
                scanf("%d",&elc_usu);
            }while (elc_usu<0 || elc_usu>9);

            if(elc_usu>=1 && elc_usu<=3)
            {
                Cord_X=elc_usu-1;Cord_Y=0;
            }
            if(elc_usu>=4 && elc_usu<=6)
            {
                Cord_X=elc_usu-4;Cord_Y=1;
            }
            if(elc_usu>=7 && elc_usu<=9)
            {
                Cord_X=elc_usu-7;Cord_Y=2;
            }
       strcpy(tab[Cord_Y][Cord_X],"X");

    }
    for (x=0;x<2;x++) //toma los numeros ingresados por el usuario y los tranforma en coordenadas x e y para colocar las 0 en la matriz.
    {
          do {
                printf("numO%d:\t",x+1);
                scanf("%d",&elc_usu);
            }while (elc_usu<0 || elc_usu>9);

            if(elc_usu>=1 && elc_usu<=3)
            {
                Cord_X=elc_usu-1;Cord_Y=0;
            }
            if(elc_usu>=4 && elc_usu<=6)
            {
                Cord_X=elc_usu-4;Cord_Y=1;
            }
            if(elc_usu>=7 && elc_usu<=9)
            {
                Cord_X=elc_usu-7;Cord_Y=2;
            }
       strcpy(tab[Cord_Y][Cord_X],"O");

    }tablero();



    return 0;
}


void tablero()// dibuja el tablero con las respectivas  posiciones
{
    int x,y;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            printf("%s\t",tab[x][y]);
        }
        printf("\n");
    }
}
void llenado()// dibuja el tablero con las respectivas  posiciones
{
    int x,y;
    printf("\n");
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            strcpy(tab[y][x],"-");
        }

    }
}

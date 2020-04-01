#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
int tab[3][3];
int main()
{   int x,elc_usu;
    char    tab[3][3];
    gotoxy(1,40);
    textcolor(RED);
    printf("TA TE TI");
    gotoxy(3,3);
    printf("Ingrese 5 numeros (segun las cooderdenadas, primero las x y luego los 0 )  para que el bot determine un Jugada:");
    for (x=0;x<3;x++) //toma los numeros ingresados por el usuario y los tranforma en coordenadas x e y para colocar las x en la matriz.
    {  do {
       printf("num%d: /n",x);
       scanf("%d",&elc_usu);
            }while (elc_usu>=1 || elc_usu<=9)
       fila(elc_usu);
       col();
       strcpy(tab[fila()][col()],"x");

    }
    for (x=0;x<2;x++)//toma los numeros ingresados por el usuario y los tranforma en coordenadas x e y para colocar las 0 en la matriz.
    {
       do{
       printf("num%d: /n",x);
       scanf("%d",&elc_usu);
       }while (elc_usu>=1 || elc_usu<=9)
       fila(elc_usu);
       col();
      strcpy(tab[fila()][col()],"0");

    }


    return 0;
}
int fcv(int elc_usu) //tranforma un numero del 1 al 9 que da el usuario en un numero del 0 al 8
{

    return elc_usu -1;
}
int fila (int elc_usu)
{
    return elc_usu/3;
}
int col (int fila)
{
    return elc_usu-fila*3;
}
void ia()
{  int  tiros=0;

        defensa();// intenta evitar que el jugador de la x gane
        ataque(); // intenta ganar

    if(tiros=0)
    {
        Iarandom(); // ubicaria los simbolos si es que no hayy una chance o de ganar o de bloquear
    }
}
void ataque()
{
    int x,tiros;
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
            if (strcmp(tab[x][0],"0")==0 && strcmp(tab[x][1],"0")==0)
            {
                if (strcmp(tab[x][2]," ")==0)
                {
                    strcpy (tab[x][2],"0");
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[x][0],"0")==0 && strcmp(tab[x][2],"0")==0)
            {
                if (strcmp(tab[x][1]," ")==0)
                {
                    strcpy (tab[x][1],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[x][1],"0")==0 && strcmp(tab[x][2],"0")==0)
            {
                if (strcmp(tab[x][0]," ")==0)
                {
                    strcpy (tab[x][0],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[0][x],"0")==0 && strcmp(tab[1][x],"0")==0)
            {
                if (strcmp(tab[2][x]," ")==0)
                {
                    strcpy (tab[2][x],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[1][x],"0")==0 && strcmp(tab[2][x],"0")==0)
            {
                if (strcmp(tab[0][x]," ")==0)
                {
                    strcpy (tab[0][x],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[0][x],"0")==0 && strcmp(tab[2][x],"0")==0)
            {
                if (strcmp(tab[1][x]," ")==0)
                {
                    strcpy (tab[1][x],"0")
                    tiros=1;
                }
            }
        }
    }
}
void defensa()
{

    int x;
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
            if (strcmp(tab[x][0],"x")==0 && strcmp(tab[x][1],"x")==0)
            {
                if (strcmp(tab[x][2]," ")==0)
                {
                    strcpy (tab[x][2],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[x][0],"x")==0 && strcmp(tab[x][2],"x")==0)
            {
                if (strcmp(tab[x][1]," ")==0)
                {
                    strcpy (tab[x][1],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[x][1],"x")==0 && strcmp(tab[x][2],"x")==0)
            {
                if (strcmp(tab[x][0]," ")==0)
                {
                    strcpy (tab[x][0],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[0][x],"x")==0 && strcmp(tab[1][x],"x")==0)
            {
                if (strcmp(tab[2][x]," ")==0)
                {
                    strcpy (tab[2][x],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[1][x],"x")==0 && strcmp(tab[2][x],"x")==0)
            {
                if (strcmp(tab[0][x]," ")==0)
                {
                    strcpy (tab[0][x],"0")
                    tiros=1;
                }
            }
        }
    }
    if (tiros==0)
    {
        for (x=0;x<3;x++)
        {
              if (strcmp(tab[0][x],"x")==0 && strcmp(tab[2][x],"x")==0)
            {
                if (strcmp(tab[1][x]," ")==0)
                {
                    strcpy (tab[1][x],"0")
                    tiros=1;
                }
            }
        }
    }
}



void tablero()// dibuja el tablero con las respectivas  posiciones

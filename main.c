#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
char tab[3][3][2];
int movimiento=0;
int main()
{   int x,elc_usu,Cord_X,Cord_Y;
    gotoxy(1,40);
    //textcolor(RED);
    Inicializar_tablero();//invoca a la funcion para llenar el tablero de " "
    printf("TA TE TI           Jockel");
    gotoxy(3,3);
    printf("Ingrese 5 numeros (segun las cooderdenadas, primero las x y luego los 0 )  para que el bot determine un Jugada:\n");
    for (x=0;x<3;x++) //toma los numeros ingresados por el usuario y los tranforma en coordenadas x e y para colocar las x en la matriz.
    {
          do {
                printf("numX%d:\t",x+1);//notifica al usuario el numero de la ficha que va a colocar
                scanf("%d",&elc_usu);
            }while (elc_usu<0 || elc_usu>9); //evita que el numero de casilla no sobrepase los limites

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
       strcpy(tab[Cord_Y][Cord_X],"X");//coloca la ficha(caracter)basado en la posicion de tablero

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

    }
    Movimiento_ia();////invoca la funcion de la "ia" para que ejecute su movimiento
    Dibujar_tablero();// invoca la funcion para mostrar tablero



    return 0;
}


void Dibujar_tablero()// dibuja el tablero con las respectivas  posiciones
{
    system("cls");///limpia la pantalla
    gotoxy(1,2);
    ///////dibuajdo de tablero con los caracteres ASCII y libreria Conio2.h
    printf("  %s   %c   %s   %c   %s \n",tab[0][0],179,tab[0][1],179,tab[0][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",tab[1][0],179,tab[1][1],179,tab[1][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",tab[2][0],179,tab[2][1],179,tab[2][2]);
}
void Inicializar_tablero()// llena el tablero de espacios vacios(" ")
{
    int x,y;
    printf("\n");
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            strcpy(tab[y][x]," ");
        }

    }
}
int validar_espacio(int randx,int randy) /// valida que el espacio no este ocupado por alguna otra ficha
{
    if (strcmp((tab[randx][randy])," ")==0)
    {
        return 0;
    }
    else if (strcmp((tab[randx][randy]),"O")==0 || strcmp((tab[randx][randy]),"X")==0)
    {
        return 1;
    }

}
void Movimiento_ia()
{
    Atacar();                         //si puede ganar lo va a hacer
    if(movimiento==0)
    {
        Defender();                   //si no puede ganar intenta defenderse de otra jugada
    }
    if(movimiento==0)
    {
          //movimiento_ia_ran();       //si no puede ganar o denegar coloca una ficha random
    }
    movimiento=0;
}
int movimiento_rand_ia() ///coloca una ficha en un espacio aleatorio si las posibilidades de ganar son nulas
{ int ia_rand_x, ia_rand_y;
   do{
   ia_rand_x=rand()%(3-1+0)+1;///posicion random en x para armar las coordenadas de la ficha
   ia_rand_y=rand()%(3-1+0)+1;///posicion random en y para armar las coordenadas de la ficha
   }while(validar_espacio(ia_rand_x,ia_rand_y)); /// repite la creacion de coodernadas hasta que la posicion este libre
   Dibujar_ficha(ia_rand_x,ia_rand_y);/// dibuja la ficha en las coordenadas dadas

}
void Dibujar_ficha(int randx,int randy) ///dibuja una ficha O en la variable que se le entrega
{
    strcpy (tab[randx][randy],"O");
}
int Atacar() // busca la 3ra psocicion restante en un conjunto de posibles jugadas pre establecidas(esto es poco esficiente)
{
    int x;
    {
            for(x=0;x<3;x++)
            {
                if(strcmp(tab[x][0],"O")==0 && strcmp(tab[x][1],"O")==0)
                {
                    if(strcmp(tab[x][2]," ")==0)
                    {
                        strcpy(tab[x][2],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }



            for(x=0;x<3;x++)
            {
                if(strcmp(tab[x][0],"O")==0 && strcmp(tab[x][2],"O")==0)
                {
                    if(strcmp(tab[x][1]," ")==0)
                    {
                        strcpy(tab[x][1],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


           for(x=0;x<3;x++)
            {
                if(strcmp(tab[x][1],"O")==0 && strcmp(tab[x][2],"O")==0)
                {
                    if(strcmp(tab[x][0]," ")==0)
                    {
                        strcpy(tab[x][0],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


    }
    {

            for(x=0;x<3;x++)
            {
                if(strcmp(tab[0][x],"O")==0 && strcmp(tab[1][x],"O")==0)
                {
                    if(strcmp(tab[2][x]," ")==0)
                    {
                        strcpy(tab[2][x],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


           for(x=0;x<3;x++)
            {
                if(strcmp(tab[1][x],"O")==0 && strcmp(tab[2][x],"O")==0)
                {
                    if(strcmp(tab[0][x]," ")==0)
                    {
                        strcpy(tab[0][x],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


          for(x=0;x<3;x++)
            {
                if(strcmp(tab[0][x],"O")==0 && strcmp(tab[2][x],"O")==0)
                {
                    if(strcmp(tab[1][x]," ")==0)
                    {
                        strcpy(tab[1][x],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


    }
    ////diagonal
     if(strcmp(tab[0][0],"O")==0 && strcmp(tab[1][1],"O")==0)
            {
                if(strcmp(tab[2][2]," ")==0)
                {
                    strcpy(tab[2][2],"O");
                    movimiento=1;
                    return 0;
                }
            }

            if(strcmp(tab[1][1],"O")==0 && strcmp(tab[2][2],"O")==0)
            {
                if(strcmp(tab[0][0]," ")==0)
                {
                    strcpy(tab[0][0],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(tab[0][0],"O")==0 && strcmp(tab[2][2],"O")==0)
            {
                if(strcmp(tab[1][1]," ")==0)
                {
                    strcpy(tab[1][1],"O");
                    movimiento=1;
                    return 0;
                }
            }

}
int Defender()
{
    int x;
    {
            for(x=0;x<3;x++)
            {
                if(strcmp(tab[x][0],"X")==0 && strcmp(tab[x][1],"X")==0)
                {
                    if(strcmp(tab[x][2]," ")==0)
                    {
                        strcpy(tab[x][2],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }



            for(x=0;x<3;x++)
            {
                if(strcmp(tab[x][0],"X")==0 && strcmp(tab[x][2],"X")==0)
                {
                    if(strcmp(tab[x][1]," ")==0)
                    {
                        strcpy(tab[x][1],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


           for(x=0;x<3;x++)
            {
                if(strcmp(tab[x][1],"X")==0 && strcmp(tab[x][2],"X")==0)
                {
                    if(strcmp(tab[x][0]," ")==0)
                    {
                        strcpy(tab[x][0],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


    }
    {

            for(x=0;x<3;x++)
            {
                if(strcmp(tab[0][x],"X")==0 && strcmp(tab[1][x],"X")==0)
                {
                    if(strcmp(tab[2][x]," ")==0)
                    {
                        strcpy(tab[2][x],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


           for(x=0;x<3;x++)
            {
                if(strcmp(tab[1][x],"X")==0 && strcmp(tab[2][x],"X")==0)
                {
                    if(strcmp(tab[0][x]," ")==0)
                    {
                        strcpy(tab[0][x],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


          for(x=0;x<3;x++)
            {
                if(strcmp(tab[0][x],"X")==0 && strcmp(tab[2][x],"X")==0)
                {
                    if(strcmp(tab[1][x]," ")==0)
                    {
                        strcpy(tab[1][x],"O");
                        movimiento=1;
                        return 0;
                    }
                }
            }


    }
    ////diagonal
     if(strcmp(tab[0][0],"X")==0 && strcmp(tab[1][1],"X")==0)
            {
                if(strcmp(tab[2][2]," ")==0)
                {
                    strcpy(tab[2][2],"O");
                    movimiento=1;
                    return 0;
                }
            }

            if(strcmp(tab[1][1],"X")==0 && strcmp(tab[2][2],"X")==0)
            {
                if(strcmp(tab[0][0]," ")==0)
                {
                    strcpy(tab[0][0],"O");
                    movimiento=1;
                    return 0;
                }
            }
            if(strcmp(tab[0][0],"X")==0 && strcmp(tab[2][2],"X")==0)
            {
                if(strcmp(tab[1][1]," ")==0)
                {
                    strcpy(tab[1][1],"O");
                    movimiento=1;
                    return 0;
                }
            }

}

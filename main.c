#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
char tab[9];
int movimiento=0;
int Turno_Maquina (char tab);
int Ganar_Maquina(char tab[], char simbolo, int a, int b, int c);
int Vacio (char tab[], int a, int b, int c );


int const Hilera[0][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
int main()
{   int x,elc_usu;
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


       strcpy(tab[elc_usu],"X");//coloca la ficha(caracter)basado en la posicion de tablero

    }
    for (x=0;x<2;x++) //toma los numeros ingresados por el usuario y los tranforma en coordenadas x e y para colocar las 0 en la matriz.
    {
          do {
                printf("numO%d:\t",x+1);
                scanf("%d",&elc_usu);
            }while (elc_usu<0 || elc_usu>9);


       strcpy(tab[elc_usu],"O");

    }
while (Final_partida(tab)==0){
    Movimiento_ia();////invoca la funcion de la "ia"
    Dibujar_tablero();// invoca la funcion par mostrar tablero
}


    return 0;
}
int Final_partida(char tab[])
{
return (Ganador(tab) || Empate(tab));
}

int Ganador(char tab[])
{
   for (int i= 0; i<8; i++){
          if (Suma(tab, 'O', Hilera[i][0], Hilera[i][1], Hilera[i][2])== 3)
                 return 0;
          if (Suma(tab,'X', Hilera[i][0], Hilera[i][1], Hilera[i][2])== 3)
                 return 0;
                              }
return 1;
}
int Empate(char tab[])
{
   for (int i=0; i<9; i++)
      if (Espacio_vacio(tab, i))
          return 1;
return 0; 
}

void Dibujar_tablero()// dibuja el tablero con las respectivas  posiciones
{
    system("cls");///limpia la pantalla
    gotoxy(1,2);
    ///////dibujado de tablero con los caracteres ASCII y libreria Conio2.h
  printf("\n");
  printf("\t  %c  |  %c  |  %c\n" tab[0], tab[1], tab[2]);
  printf("\t---|---|---\n");
  printf("\t  %c  |  %c  |  %c\n" tab[3], tab[4], tab[5]);
  printf("\t---|---|---\n");
  printf("\t  %c  |  %c  |  %c\n" tab[6], tab[7], tab[8]);
  printf("\t---|---|---\n");
}
void Inicializar_tablero()// llena el tablero de espacios vacios(" ")
{
    int x;
    printf("\n");
    for(x=0;x<9;x++)
    {
            strcpy(tab[x]," ");
    }
}
int validar_espacio(int x) /// valida que el espacio no este ocupado por alguna otra ficha
{
    if (strcmp((tab[x])," ")==0)
    {
        return 0;
    }
    else if (strcmp((tab[x]),"O")==0 || strcmp((tab[x]),"X")==0)
    {
        return 1;
    }

}
void Movimiento_ia() 
{
    Turno_Maquina(char tab[])             //si puede ganar lo va a hacer
    Defensa_Maquina();                   //si no puede ganar intenta defenderse de otra jugada
     movimiento_ia_ran();       //si no puede ganar o denegar coloca una ficha random
 
}
int movimiento_rand_ia() ///coloca una ficha en un espacio aleatorio si las posibilidades de ganar son nulas
{ int ia_rand_x, ia_rand_y;
   do{
   ia_rand_x=rand()%(9-1+0)+1;///posicion random en x para armar las coordenadas de la ficha
   }while(validar_espacio(ia_rand_x)); /// repite la creacion de coodernadas hasta que la posicion este libre
   Dibujar_ficha(ia_rand_x);

}
void Dibujar_ficha(int x) ///dibuja una ficha O en la variable que se le entrega
{
    strcpy (tab[x],"O");
}

int Turno_Maquina(char tab[]){
    for(int x=0;x<9;x++){
        if(Ganar_Maquina(Tablero, 'O', Hileras[X][0], Hileras[X][1], Hileras[X][2])==1){
            printf("Turno Maquina");
            return Espacio_vacio(tab, Hileras[X][0], Hileras[X][1], Hileras[X][1]);
        }
    }
}


int Ganar_Maquina(char tab[], char simbolo, int a, int b, int c){
    if((Suma_simbolos(tab, simbolo, a, b, c)==2) && (Suma_simbolos(tab, ' ', a, b, c)==1))
        return 1;
    else
        return 0;
}
int Defensa_Maquina (char tab[]){
for(int x=0;x<9;x++){
        if(Ganar_Maquina(Tablero, 'X', Hileras[X][0], Hileras[X][1], Hileras[X][2])==1){
            printf("Turno Maquina");
            return Espacio_vacio(tab, Hileras[X][0], Hileras[X][1], Hileras[X][1]);
        }
    }

}

int Espacio_vacio(char tab[], int a, int b, int c){
    if(tab[a]==' ')
        return a;
    if(tab[b]==' ')
        return b;
    return c;
}
int Suma_simbolos(char tab[],char simbolo, int a, int b, int c){
    int Suma=0;
    if(tab[a]==simbolo)Suma++;
    if(tab[b]==simbolo)Suma++;
    if(tab[c]==simbolo)Suma++;
    return Suma;
}

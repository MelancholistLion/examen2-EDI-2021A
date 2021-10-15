#include <stdio.h>
#include <string.h>
#define N 5
#define cadena 20

void leeArr(int clave[],char nombre[][cadena],float estaturaSueldo[][N],int x);
void empleadoAlto(float estaturaSueldo[][N],int nombre[],int x);
int bsq(int arr[][N],int tam);
void seleccion(float estaturaSueldo[][N],int clave[],char nombre[][cadena],int x);
void imprime(int clave[N],char *nombre[][cadena],float estaturaSueldo[][N],int x);

int main()
{
    int i,j,empleados;

    printf("Cuantos empleados hay?");
    scanf("%d",&empleados);

    int clave[empleados];
    char nombre[empleados][cadena];
    float estaturaSueldo[2][empleados];

    leeArr(clave,nombre,estaturaSueldo,empleados);
    //empleadoAlto(estaturaSueldo,nombre,empleados);
    //seleccion(estaturaSueldo,clave,nombre,empleados);
    imprime(clave,nombre,estaturaSueldo,empleados);


    return 0;
}

void leeArr(int clave[],char nombre[][cadena],float estaturaSueldo[][N],int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        printf("Clave: ");
        scanf("%d",&clave[i]);

        printf("Nombre: ");
        scanf("%s",&nombre[i][cadena]);

        printf("Estatura: ");
        scanf("%f",&estaturaSueldo[1][i]);

        printf("Sueldo: ");
        scanf("%f",&estaturaSueldo[2][i]);
    }
}

void empleadoAlto(float estaturaSueldo[][N],int nombre[],int x)
{
    int i,pos;
    pos = bsq(estaturaSueldo,x);
    printf("El que tiene la mayor estatura es %s con %f",nombre[pos],estaturaSueldo[1][pos]);

}

int bsq(int arr[][N],int tam)
{
   int pos,i;
    pos = 0;

    for(i=0;i<tam;i++)
    {

        if(pos < arr[1][i])
        {
            pos = i;
        }
    }
    return pos;
}

void seleccion(float estaturaSueldo[][N],int clave[],char nombre[][cadena],int x)
{
    int i,pos;

    int aux;
    char aux1[cadena];
    float aux2;

   for (i=0;i<x;i++)
    {
        for(pos=i;pos<N;pos++)
        {
            if(estaturaSueldo[2][i]>estaturaSueldo[2][pos])
            {
                aux2=estaturaSueldo[1][i];
                estaturaSueldo[1][i]=estaturaSueldo[1][pos];
                estaturaSueldo[1][pos]=aux2;

                aux2=estaturaSueldo[2][i];
                estaturaSueldo[2][i]=estaturaSueldo[2][pos];
                estaturaSueldo[2][pos]=aux2;

                aux=clave[i];
                clave[i]=clave[pos];
                clave[pos]=aux;

                aux=estaturaSueldo[1][i];
                estaturaSueldo[1][i]=estaturaSueldo[1][pos];
                estaturaSueldo[1][pos]=aux;

                memcpy(aux1, nombre[i], cadena);
                memcpy(nombre[i][cadena], nombre[pos][cadena], cadena);
                memcpy(nombre[pos][cadena], aux1, cadena);
            }
        }
    }
}

void imprime(int clave[N],char *nombre[][cadena],float estaturaSueldo[][N],int x)
{
    int i;
    printf("Clave ");
    printf("Nombre ");
    printf("Estatura ");
    printf("Sueldo \n");
    for(i=0;i<x;i++)
    {
        printf("%d ",clave[i]);
        printf("%s ",nombre[i][cadena]);
        printf("%f ",estaturaSueldo[1][i]);
        printf("%f ",estaturaSueldo[2][i]);
    }
}

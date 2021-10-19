//PD: Al imprimir no me sale desde el nombre y por lo tanto no termina el ciclo hasta que lo cierro manualmente

#include <stdio.h>
#include <string.h>
#define N 3

void capEmp(int key[N],char name[N][20],float data[N][2]);
int empHeight(float datos[N][2]);
void orderEmpSal(int key[N],char name[N][20],float data[N][2]);
void printing(int key[N],char name[N][20],float data[N][2]);

int main()
{
    int key[N];
    char name[N][20];
    float data[N][2];

    int hPos;

    capEmp(key,name,data);

    orderEmpSal(key,name,data);
    
    hPos = empHeight(data);

    printing(key,name,data);

    printf("El nombre del empleado más alto es %s\n",name[hPos]);
    printf("Y su estatura es %f m \n",data[hPos][0]);
    
    return 0;
}

void printing(int key[N],char name[N][20],float data[N][2])
{
    int i;
    
    printf("Clave     Nombre     Estatura     Sueldo \n");

    for(i=0;i<N;i++)
    {
        printf("%d ",key[i]);
        printf("%s ",name[i][20]);
        printf("%f ",data[i][0]);
        printf("%f\n",data[i][1]);
    }
}

void orderEmpSal(int key[N],char name[N][20],float data[N][2])
{
    int i,j;
    float aux;
    int auxKey;
    char auxName[20];

    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(data[j][1] < data[j+1][1])
            {
                auxKey = key[j];
                key[j] = key[j+1];
                key[j+1] = auxKey;

                strcpy(auxName,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],auxName);
                
                aux = data[j][0];
                data[j][0]=data[j+1][0];
                data[j+1][0] = aux;

                aux = data[j][1];
                data[j][1]=data[j+1][1];
                data[j+1][1] = aux;
            }
        }
    }
}

int empHeight(float d[N][2])
{
    int i;
    float mayor = d[0][0];
    int pos = 0;

    for(i=0;i<N;i++)
    {
        if(d[i][0] > mayor)
        {
            mayor = d[i][0];
            pos = i;
        }
    }
    return pos;
}

void capEmp(int key[N],char name[N][20],float data[N][2])
{
    int i;

    for(i=0;i<N;i++)
    {
        printf("Empleado numero %d \n",i);
        printf("Clave: ");
        scanf("%d",&key[i]);
        printf("Nombre: ");
        scanf("%s",name[i]);
        printf("Estatura: ");
        scanf("%f",&data[i][0]);
        printf("Sueldo: ");
        scanf("%f",&data[i][1]);
    }
}
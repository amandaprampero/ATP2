#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
  //Variáveis
  int n, m, op, i, j;
  double X, Y, Z;
  double x1, x2, y1, y2, z1, z2;
  char nome1[21], nome2[21], nome3[21], nome4[21];
  double dist, peso;
  
  //Dados dos planetas
  typedef struct {
     double x, y, z;
     double w;
     char nome[21];
  }Tplanetas;
  Tplanetas planeta[n];

  //Entrada
  scanf("%d", &n);
  scanf("%d", &m);

  for(i=0; i<n; i++)
  {
     scanf("%s", planeta[i].nome);
     scanf("%lf", &planeta[i].w);
     scanf("%lf %lf %lf", &planeta[i].x, &planeta[i].y, &planeta[i].z); 
  }
  for(j=0; j<m; j++)
  {

     scanf("%d", &op);
     if(op==1)
     {
         scanf("%s", nome1);
         scanf(" %s", nome2);
         for(i=0; i<n; i++)
         {
          if(strcmp(nome1, planeta[i].nome)==0)
          {
              x1 = planeta[i].x;
              y1 = planeta[i].y;
              z1 = planeta[i].z;
          }
          if(strcmp(nome2,planeta[i].nome)==0)
          {
              x2 = planeta[i].x;
              y2 = planeta[i].y;
              z2 = planeta[i].z;
          }
         }
         dist = sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))+((z2-z1)*(z2-z1)));
         printf("%.2lf\n", dist);
      }
      if(op==2)
      {
           scanf("%s", nome3);
           for(i=0; i<n; i++)
           {
            if(strcmp(nome3, planeta[i].nome)==0)
            {
                 X = planeta[i].x;
                 Y = planeta[i].y;
                 Z = planeta[i].z;
            }
           }
            printf("%.0lf %.0lf %.0lf\n", X, Y, Z);   
      }
       if(op==3)
       {
             scanf("%s", nome4);
             for(i=0; i<n; i++)
             {
              if(strcmp(nome4, planeta[i].nome)==0)
              {
                 peso = planeta[i].w;
              }
             }
             printf("%.2lf\n", peso);  
       }
  }
  
  return 0;
}
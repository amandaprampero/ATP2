#include <stdio.h>
#include <string.h>

int romano_decimal(char*rom){
  int j, valor, tam, decimal=0; 
  tam=strlen(rom);
  for(j=0; j<tam; j++)
    {
      if(rom[j]=='I')
      {
        if(rom[j+1]=='X')
        {
          valor = 9;
          j++;
        } else if(rom[j+1]=='V')
        {
          valor = 4;
          j++;
        } else if(rom[j+1]=='L')
        {
          valor = 49;
          j++;
        } else if(rom[j+1]=='C')
        {
          valor = 99;
          j++;
        } else if(rom[j+1]=='D')
        {
          valor = 499;
          j++;
        } else if(rom[j+1]=='M')
        {
          valor = 999;
          j++;
        } else{
          valor = 1;
        }
      }
        
      else if(rom[j]=='V')
      {
        valor = 5;
      }
        
      else if(rom[j]=='X')
      {
        if(rom[j+1]=='C')
        {
          valor = 90;
          j++;
        } else if(rom[j+1]=='L')
        {
          valor = 40;
          j++;
        } else{
          valor = 10;
        }
      }
        
      else if(rom[j]=='L')
      {
          valor = 50;
      }
        
      else if(rom[j]=='C')
      {
        if(rom[j+1]=='D')
        {
          valor = 400;
          j++;
        } else if(rom[j+1]=='M')
        {
          valor = 900;
          j++;
        } else{
          valor = 100;
        }
      }
        
      else if(rom[j]=='D')
      {
        valor = 500;
      }
        
      else if(rom[j]=='M')
      {
        valor = 1000;
      }

      decimal = decimal + valor;
    }
  
  return decimal;
}

void decimal_romano(int *decimal){
  int j, a, b, c, d;
  char val1[5], val2[5], val3[5], val4[5], resp[100];

  for(j=0; j<5; j++)
    {
      val1[j] = '\0';
      val2[j] = '\0';
      val3[j] = '\0';
      val4[j] = '\0';
      resp[j] = '\0';
    }

  a = *decimal/1000;
  b = (*decimal%1000)/100;
  c = (*decimal%100)/10;
  d = *decimal%10;

  if(a==1 || a==2)
  {
    for(j=0; j<a; j++)
      {
        strcat(val1, "M");
      }
  }

  strcat(resp, val1);

  if(b==1||b==2||b==3)
  {
    for(j=0;j<b;j++)
      {
        strcat(val2, "C");
      }
  } else if(b==4){
    strcat(val2, "CD");
  } else if(b==5){
    strcat(val2, "D");
  } else if(b==6||b==7||b==8){
    strcat(val2,"D");
    for(j=0;j<(b-5); j++){
      strcat(val2,"C");
    }
  } else if(b==9){
    strcat(val2, "CM");
  }

  strcat(resp, val2);

  if(c==1||c==2||c==3)
  {
    for(j=0;j<c;j++){
      strcat(val3,"X");
    }
  } else if(c==4){
    strcat(val3,"XL");
  } else if(c==5){
    strcat(val3,"L");
  } else if(c==6||c==7||c==8){
    strcat(val3,"L");
    for(j=0;j<(c-5);j++){
      strcat(val3,"X");
    }
  } else if(c==9){
    strcat(val3,"XC");
  }

  strcat(resp,val3);

  if(d==1||d==2||d==3){
    for(j=0;j<d;j++){
      strcat(val4, "I");
    } 
  } else if(d==4){
    strcat(val4, "IV");
  } else if(d==5){
    strcat(val4, "V");
  } else if(d==6||d==7||d==8){
    strcat(val4, "V");
    for(j=0;j<(d-5);j++){
      strcat(val4,"I");
    }
  } else if(d==9){
    strcat(val4,"IX");
  }

  strcat(resp, val4);

  printf("%s\n", resp);
}

int main(void) {
  long int N; 
  int i, decimal=0;
  char romano[100];
  int C, soma=0, dec;

  scanf("%ld", &N);
  for(i=0; i<N; i++)
    {
      scanf("%d", &C);
      if(C==1) 
      { decimal=0;
        scanf("%s", romano);
        decimal = romano_decimal(romano);
        printf("%d\n", decimal);
        soma += decimal;
      }
      else if(C==2) 
      {
        scanf("%d", &dec);
        decimal_romano(&dec);
      }
    }
    printf("%d\n", soma);
  
  return 0;
}
#include <stdio.h>
#include <math.h>

float So = 0;

void mru_dist(float v, float t){
  float S;
  S = v * t;
  printf("%.2f\n", S);
}

void mru_vel(float s, float t){
  float V;
  V = s/t;
  printf("%.2f\n", V);
}

void mru_t(float s, float v){
  float T;
  T = s/v;
  printf("%.2f\n", T);
}

void mruv_dist(float v, float a, float t){
  float S;
  S = (v * t) + (a * t*t)/2;
  printf("%.2f\n", S);
}

void mruv_vf(float v, float a, float t){
  float Vf;
  Vf = v + (a*t);
  printf("%.2f\n", Vf);
}

void mruv_vi(float s, float a, float t){
  float Vi;
  Vi = (s - (a*t*t)/2)/t;
  printf("%.2f\n", Vi);
}

void mruv_tt(float s, float v, float a){
  float tt, vf;
  vf = sqrt((v*v)+(2*a*s));
  tt = (vf - v)/a;
  printf("%.2f\n", tt);
}

int main(void) {
  int N, O, i;
  float S=0, T, V=0, A;
  scanf("%d", &N);
  for(i=0; i<N; i++)
    {
      scanf("%d", &O);
      switch (O){
        case 1: 
          scanf("%f %f", &V, &T);
          mru_dist(V, T);
        break;
        
        case 2: 
          scanf("%f %f", &S, &T);
          mru_vel(S, T);
        break;
        
        case 3: 
          scanf("%f %f", &S, &V);
          mru_t(S, V);
        break;
        
        case 4: 
          scanf("%f %f %f", &V, &A, &T);
          mruv_dist(V, A, T);
        break;
        
        case 5: 
          scanf("%f %f %f", &V, &A, &T);  
          mruv_vf(V, A, T);
        break;
        
        case 6: 
          scanf("%f %f %f", &S, &A, &T); 
          mruv_vi(S, A, T);
        break;
        
        case 7: 
          scanf("%f %f %f", &S, &V, &A);
          mruv_tt(S, V, A);
        break;
      }
    }
  
  return 0;
}
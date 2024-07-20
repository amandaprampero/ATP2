#include <stdio.h>
#include <stdlib.h>

int quan_p;
int quan_t;

typedef struct aula{
int num;
char data[11];
int horas;
char conteudo[256];
}Aula;

typedef struct aluno{
int num;
char nome[51];
float nota_aval;
float aval_final;
char pres;
FILE *pa;
FILE *na;
}Aluno;

typedef struct prova_trabalho{
char nome_aval[51];
char tipo;
char data[11];
int peso;
FILE *pav;
}Avali;

typedef struct disciplinas{
char codigo[11];
char nome[30];
int ano;
int semestre;
int quan_alunos;
int quan_provas;
int quan_trab;
int carga_prev;
int carga_real;
int nota_min;
int percentual_min;
FILE *p;
}Disc;
//disc[i]->p
int main(void) {
  FILE *pr= fopen("prof", "a+");
  FILE *d1 = fopen("Disciplina1", "a+");
  FILE *d2 = fopen("Disciplina2", "a+");
  FILE *d3 = fopen("Disciplina3", "a+");
  FILE *d4 = fopen("Disciplina4", "a+");
  FILE *d5 = fopen("Disciplina5", "a+");
  Disc disciplina[5];
  disciplina[0].p = d1;
  disciplina[1].p = d2;
  disciplina[2].p = d3;
  disciplina[3].p = d4;
  disciplina[4].p = d5;
  Aula aula;
  Aluno aluno[5];
  FILE *a1 = fopen("Alunos1", "a+");
  FILE *a2 = fopen("Alunos2", "a+");
  FILE *a3 = fopen("Alunos3", "a+");
  FILE *a4 = fopen("Alunos4", "a+");
  FILE *a5 = fopen("Alunos5", "a+");
  aluno[0].pa = a1;
  aluno[1].pa = a2;
  aluno[2].pa = a3;
  aluno[3].pa = a4;
  aluno[4].pa = a5;
  aula.horas = 2;
  Avali avaliacao[5];
  FILE *av1 = fopen("AvalicaoDisc1", "a+");
  FILE *av2 = fopen("AvalicaoDisc2", "a+");
  FILE *av3 = fopen("AvalicaoDisc3", "a+");
  FILE *av4 = fopen("AvalicaoDisc4", "a+");
  FILE *av5 = fopen("AvalicaoDisc5", "a+");
  avaliacao[0].pav = av1;
  avaliacao[1].pav = av2;
  avaliacao[2].pav = av3;
  avaliacao[3].pav = av4;
  avaliacao[4].pav = av5;
  FILE *n1 = fopen("NotasDisc1", "a+");
  FILE *n2 = fopen("NotasDisc2", "a+");
  FILE *n3 = fopen("NotasDisc3", "a+");
  FILE *n4 = fopen("NotasDisc4", "a+");
  FILE *n5 = fopen("NotasDisc5", "a+");
  aluno[0].na = n1;
  aluno[1].na = n2;
  aluno[2].na = n3;
  aluno[3].na = n4;
  aluno[4].na = n5;
  
  
  char nome[51], resp;
  int quan_disc, i, j, k, l, p, quan_aval, op, acao, n=3, quan_aulas, peso[100], peso_media[5];
  float soma_notas[5][200], notas, media[200], aval_final, media_final[200];

  
  //considerando que só um professor vai acessar
  printf("É o primeiro acesso?(S ou N)");
  scanf("%c", &resp);
  
  if(resp == 'S' || resp == 's'){ //se for o primeiro acesso, o usuário informa os atributos da disciplina apenas uma vez
    printf("Nome do professor: ");
    scanf(" %[^\n]s", nome);
    printf("\nQuantidade de disciplinas: ");
    scanf("%d", &quan_disc);
    
    fprintf(pr, "%s %d" , nome, quan_disc);

    for(i=0;i<quan_disc;i++){
      printf("Nome da disciplina: ");
      scanf(" %s", disciplina[i].nome);
      fprintf(disciplina[i].p,"%s ",disciplina[i].nome);
      printf("\nCódigo da disciplina: ");
      scanf(" %s", disciplina[i].codigo);
      fprintf(disciplina[i].p,"%s ",disciplina[i].codigo);
      printf("\nAno: ");
      scanf("%d", &disciplina[i].ano);
      fprintf(disciplina[i].p,"%d ",disciplina[i].ano);
      printf("\nSemestre: ");
      scanf("%d", &disciplina[i].semestre);
      fprintf(disciplina[i].p,"%d ",disciplina[i].semestre);
      printf("\nQuantidade de alunos matriculados: ");
      scanf("%d", &disciplina[i].quan_alunos);
      fprintf(disciplina[i].p,"%d ",disciplina[i].quan_alunos);
      printf("\nQuantidade de provas: ");
      scanf("%d", &disciplina[i].quan_provas);
      quan_p = disciplina[i].quan_provas;
      fprintf(disciplina[i].p,"%d ",disciplina[i].quan_provas);
      printf("\nQuantidade de trabalhos: ");
      scanf("%d", &disciplina[i].quan_trab);
      quan_t = disciplina[i].quan_trab;
      fprintf(disciplina[i].p,"%d ",disciplina[i].quan_trab);
      printf("\nCarga horária prevista: ");
      scanf("%d", &disciplina[i].carga_prev);
      fprintf(disciplina[i].p,"%d ",disciplina[i].carga_prev);
      printf("\nCarga horária realizada: ");
      scanf("%d", &disciplina[i].carga_real);
      fprintf(disciplina[i].p,"%d ",disciplina[i].carga_real);
      printf("\nNota mínima para aprovação: ");
      scanf("%d", &disciplina[i].nota_min);
      fprintf(disciplina[i].p,"%d ",disciplina[i].nota_min);
      printf("\nPercentual mínimo de frequência para aprovação: ");
      scanf("%d", &disciplina[i].percentual_min);
      fprintf(disciplina[i].p,"%d ", disciplina[i].percentual_min);
      quan_aval = quan_p+quan_t;

      
      printf("\nDADOS DAS AVALIAÇÕES(PROVAS E TRABALHOS)\n");
      for(j=0;j<quan_aval;j++){
      printf("\nNome da avaliação: ");
      scanf(" %s", avaliacao[i].nome_aval);
      fprintf(avaliacao[i].pav,"%s ", avaliacao[i].nome_aval);
      printf("\nTipo da avaliação(P/T/E): ");
      scanf("%c", &avaliacao[i].tipo);
      fprintf(avaliacao[i].pav,"%c ", avaliacao[i].tipo);
      printf("\nData da avaliação: ");
      scanf(" %s", avaliacao[i].data);
      fprintf(avaliacao[i].pav,"%s ", avaliacao[i].data);
      printf("\nPeso: ");
      scanf("%d", &avaliacao[i].peso);
      fprintf(avaliacao[i].pav,"%d ", avaliacao[i].peso);
    }

      for(j =0; j < disciplina[i].quan_alunos; j++)
        {
          printf("\nNumero do aluno: ");
          scanf("%d", &aluno[i].num);
          fprintf(aluno[i].pa, "%d ", aluno[i].num);
          printf("\nNome: ");
          scanf(" %s", aluno[i].nome);
          fprintf(aluno[i].pa, "%s ", aluno[i].nome);
        
          for(k=0;k<disciplina[i].carga_real / aula.horas;k++){
            printf("\nPresenca(P/F): ");
            scanf("%c", &aluno[i].pres);
            fprintf(aluno[i].pa, "%c ", aluno[i].pres);
          }
        }
    }
  }
  else{
    printf("\nContinue.");
  }

  fscanf(pr, "%s %d" , nome, &quan_disc);

  for(i=0;i<quan_disc;i++){
    fscanf(disciplina[i].p, "%s %s %d %d %d %d %d %d %d %d %d", disciplina[i].nome, disciplina[i].codigo, &disciplina[i].ano, &disciplina[i].semestre, &disciplina[i].quan_alunos, &disciplina[i].quan_provas, &disciplina[i].quan_trab, &disciplina[i].carga_prev, &disciplina[i].carga_real, &disciplina[i].nota_min, &disciplina[i].percentual_min);
    quan_aval = disciplina[i].quan_provas + disciplina[i].quan_trab;

    p = 0;
      do
        {
          printf("Numero de ordem: ");
          scanf("%d", &aula.num);
          printf("Data: ");
          scanf(" %s", aula.data);
          printf("Horas associadas: ");
          scanf("%d", &aula.horas);
          printf("Conteudo: ");
          scanf(" %s", aula.conteudo);
          p++;
        }while(j < (disciplina[i].carga_real / aula.horas));
    quan_aulas = p;
  }

  for(i=0;i<5;i++){
    for(j=0;j<200;j++){
      soma_notas[i][j] = 0;
    }
  }
  for(i=0;i<5;i++){
    peso_media[i] = 0;
  }

  printf("\nEscolha uma opção: ");
  printf("\n1.Dados da aula\n2.Avaliações\n3.Final de semestre(médias e frequência)\n4.Recuperação\n");
  scanf("%d", &op);
  switch(op){
    case 1: 
        for(i=0;i<quan_disc;i++){
          printf("\nNumero de ordem: ");
          scanf("%d", &aula.num);
          printf("\nData: ");
          scanf(" %s", aula.data);
          printf("\nHoras associadas: ");
          scanf("%d", &aula.horas);
          printf("\nConteudo: ");
          scanf(" %s", aula.conteudo);
          for(k=0;k<disciplina[i].quan_alunos;k++){
            printf("\nPresenca(P/F): ");
            scanf(" %c", &aluno[i].pres);
            fprintf(aluno[i].pa, "%c ", aluno[i].pres);
          }
        }
      break;
    case 2: 
        for(i=0;i<quan_disc;i++){
          printf("\nNumero de ordem: ");
          scanf("%d", &aula.num);
          printf("\nData: ");
          scanf(" %s", aula.data);
          printf("\nHoras associadas: ");
          scanf("%d", &aula.horas);
          printf("\nConteudo: ");
          scanf(" %s", aula.conteudo);
          printf("\nControle de frequencia e notas: ");
          for(k=0;k<disciplina[i].quan_alunos;k++){
            printf("\nPresenca(P/F): ");
            scanf(" %c", &aluno[i].pres);
            fprintf(aluno[i].pa, "%c ", aluno[i].pres);
            printf("\nNota das avaliacoes: ");
            scanf("%f", &aluno[i].nota_aval);
            fprintf(aluno[i].na, "%.1f ", aluno[i].nota_aval);
          }
        }
      break;
    case 3:
      l=0;
      for(i=0;i<quan_disc;i++){
        while(!feof(avaliacao[i].pav)){
          fscanf(avaliacao[i].pav, "%s %c %s %d", avaliacao[i].nome_aval, &avaliacao[i].tipo, avaliacao[i].data, &avaliacao[i].peso);
          peso[l] = avaliacao[i].peso;
          l++;
        }
      }
      l=0;
      for(i=0;i<quan_disc;i++){
        while(!feof(aluno[i].na)){
          for(j=0;j<disciplina[i].quan_alunos;j++){
          fscanf(aluno[i].na, "%f", &notas);
          soma_notas[i][j] += (peso[l] * notas);
          }
          l++;
        }
        quan_aval = disciplina[i].quan_provas + disciplina[i].quan_trab;
        for(k=0;k<quan_aval;k++){
          peso_media[i] += avaliacao[k].peso;
        }
      }
      for(i=0;i<quan_disc;i++){
        for(j=0;j<disciplina[i].quan_alunos;j++){
          media[j] = soma_notas[i][j]/peso_media[i];
        }
      }
      break;
    case 4: for(i=0;i<quan_disc;i++){
        for(j=0;j<disciplina[i].quan_alunos;j++){
          if(media[j] < disciplina[i].nota_min){
            printf("\nAluno %d da disciplina %d precisa de recuperação.", j, i);
            printf("\nNota obtida no exame: ");
            scanf("%f", &aval_final);
            media_final[j] = (media[j] + aval_final)/2;
            printf("\n%.1f", media_final[j]);
          }
        }
      }
      break;
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

void ajuda() {
  printf("Ajuda para executar o programa: \n\n");
  printf("Utilize a linha de comando da seguinte forma: ");
  printf("\n\t./prob n p m0 m1 algoritmo\n aonde:\n\t");
  printf("- n: parametro n da distribuicao;\n\t");
  printf("- p: parametro p da distribuicao;\n\t");
  printf("- m0: menor abcissa da curva de probabilidade;\n\t");
  printf("- m1: maior abcissa da curva de probabilidade;\n\t");
  printf("- algoritmo: seleciona o algoritmo da probabilidade `1` para binomial ou `2` para normal.\n");
  printf("\n");
}

int entrada(int c, char **v, double *n, double *p, double *m_0, double *m_1, int *a) {
  if((c < 5) || (atoi(v[5]) != 1 && atoi(v[5]) != 2)) { // não contém o número suficiente de parâmetros
    ajuda();
    return 0;
  } else {  // faz leitura da entrada
    *n    = atof(v[1]);
    *p    = atof(v[2]);
    *m_0  = atof(v[3]);
    *m_1  = atof(v[4]);
    *a    = atoi(v[5]);
    return 1;
  }
}

void debug(double n, double p, double m_0, double m_1, int algoritmo) {
  printf("%lf %lf %lf %lf %d \n", n, p, m_0, m_1, algoritmo);
}

void binomial(double n, double p, double m_0, double m_1) {
}
void normal(double n, double p, double m_0, double m_1) {
}

int main(int argc, char **argv) {
  
  double n, p, m_0, m_1;
  int algoritmo;
  if(!entrada(argc, argv, &n, &p, &m_0, &m_1, &algoritmo))
    return EXIT_SUCCESS;

  if(algoritmo == 1)
    binomial(n, p, m_0, m_1);
  else if(algoritmo == 2)
    normal(n, p, m_0, m_1);

  return EXIT_SUCCESS;
}
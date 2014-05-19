#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ajuda() {
  printf("Ajuda para executar o programa: \n\n");
  printf("Utilize a linha de comando da seguinte forma: ");
  printf("\n\t./prob n p m0 m1 algoritmo\n aonde:\n\t");
  printf("- n: parametro n da distribuicao;\n\t");
  printf("- p: parametro p da distribuicao (0 < p < 1);\n\t");
  printf("- m0: menor abcissa da curva de probabilidade;\n\t");
  printf("- m1: maior abcissa da curva de probabilidade;\n\t");
  printf("- algoritmo: seleciona o algoritmo da probabilidade `1` para binomial ou `2` para normal.\n");
  printf("\n");
}

int fatorial(int n) {
  int ret = 1, i = 0;
  for(i = 1; i <= n; ++i)
    ret *= i;
  return ret;
}

int selecao(int n, int m) {
  if (n < m) return 0;
  return (fatorial(n))/(fatorial(m)*(fatorial(n-m)));
}

int entrada(int c, char **v, double *n, double *p, double *m_0, double *m_1, int *a) {
  if( // validação de parâmetros
      (c < 5)                               || 
      (atoi(v[5]) != 1 && atoi(v[5]) != 2)  ||
      (atof(v[2]) < 0 || atof(v[2]) > 1)
    ) {
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

double binomial(double n, double p, double r) {
  return selecao(n, r) * pow(p, r) * pow((1 - p), (n - r));
}

double aplica_binomial_intervalo(double n, double p, double m_0, double m_1) {
  int i;
  double acum = 0;
  for(i = m_0; i <= m_1; i += 1)
    acum += binomial(n, p, i);
  return acum;
}

void aplica_binomial(double n, double p, double m_0, double m_1) {
  printf(" ## Distribuição Binomial ## \n");
  printf("Valores: \t\t%lf\n", n);
  printf("Probabilidade: \t\t%lf\n", p);
  printf("Intervalo: \t\t[%lf, %lf]\n", m_0, m_1);
  printf("###### Valor calculado: %lf\n", aplica_binomial_intervalo(n, p, m_0, m_1));
}

void normal(double n, double p, double m_0, double m_1) {
}

int main(int argc, char **argv) {
  
  double n, p, m_0, m_1;
  int algoritmo;
  
  if(!entrada(argc, argv, &n, &p, &m_0, &m_1, &algoritmo))
    return EXIT_SUCCESS;

  if(algoritmo == 1)
    aplica_binomial(n, p, m_0, m_1);
  else if(algoritmo == 2)
    normal(n, p, m_0, m_1);

  return EXIT_SUCCESS;
}
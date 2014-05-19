#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/* Coefficients in rational approximations. */
static const double a[] = {
  -3.969683028665376e+01,
   2.209460984245205e+02,
  -2.759285104469687e+02,
   1.383577518672690e+02,
  -3.066479806614716e+01,
   2.506628277459239e+00
};
static const double b[] = {
  -5.447609879822406e+01,
   1.615858368580409e+02,
  -1.556989798598866e+02,
   6.680131188771972e+01,
  -1.328068155288572e+01
};
static const double c[] = {
  -7.784894002430293e-03,
  -3.223964580411365e-01,
  -2.400758277161838e+00,
  -2.549732539343734e+00,
   4.374664141464968e+00,
   2.938163982698783e+00
};
static const double d[] = {
  7.784695709041462e-03,
  3.224671290700398e-01,
  2.445134137142996e+00,
  3.754408661907416e+00
};

#define LOW 0.02425
#define HIGH 0.97575

double ltqnorm(double p) {
  double q, r;
  errno = 0;

  if (p < 0 || p > 1) {
    errno = EDOM;
    return 0.0;
  }
  else if (p == 0) {
    errno = ERANGE;
    return -HUGE_VAL /* minus "infinity" */;
  }
  else if (p == 1) {
    errno = ERANGE;
    return HUGE_VAL /* "infinity" */;
  }
  else if (p < LOW) {
    /* Rational approximation for lower region */
    q = sqrt(-2*log(p));
    return (((((c[0]*q+c[1])*q+c[2])*q+c[3])*q+c[4])*q+c[5]) /
      ((((d[0]*q+d[1])*q+d[2])*q+d[3])*q+1);
  }
  else if (p > HIGH) {
    /* Rational approximation for upper region */
    q  = sqrt(-2*log(1-p));
    return -(((((c[0]*q+c[1])*q+c[2])*q+c[3])*q+c[4])*q+c[5]) /
      ((((d[0]*q+d[1])*q+d[2])*q+d[3])*q+1);
  }
  else {
    /* Rational approximation for central region */
    q = p - 0.5;
    r = q*q;
    return (((((a[0]*r+a[1])*r+a[2])*r+a[3])*r+a[4])*r+a[5])*q /
      (((((b[0]*r+b[1])*r+b[2])*r+b[3])*r+b[4])*r+1);
  }
}

void    ajuda() {
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

int     fatorial(int n) {
  int ret = 1, i = 0;
  for(i = 1; i <= n; ++i)
    ret *= i;
  return ret;
}

int     selecao(int n, int m) {
  if (n < m) return 0;
  return (fatorial(n))/(fatorial(m)*(fatorial(n-m)));
}

int     entrada(int c, char **v, double *n, double *p, double *m_0, double *m_1, int *a) {
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

void    debug(double n, double p, double m_0, double m_1, int algoritmo) {
  printf("%lf %lf %lf %lf %d \n", n, p, m_0, m_1, algoritmo);
}

double  binomial(double n, double p, double r) {
  return selecao(n, r) * pow(p, r) * pow((1 - p), (n - r));
}

double  binomial_esperanca(double n, double p) {
  return (n * p);
}

double  binomial_variancia(double n, double p) {
  return (n * p)*(1 - p);
}

double  aplica_binomial_intervalo(double n, double p, double m_0, double m_1) {
  int i;
  double acum = 0;
  for(i = m_0; i <= m_1; i += 1)
    acum += binomial(n, p, i);
  return acum;
}

void    aplica_binomial(double n, double p, double m_0, double m_1) {
  printf(" ## Distribuicao Binomial ## \n");
  printf("Valores: \t\t%lf\n", n);
  printf("Probabilidade: \t\t%lf\n", p);
  printf("Intervalo: \t\t[%lf, %lf]\n", m_0, m_1);
  printf("###### Valor calculado: %lf\n", aplica_binomial_intervalo(n, p, m_0, m_1));
}

double    normal(double n, double p, double m_0, double m_1) {
  double z_0 = ((p - binomial_esperanca(n, p))/(sqrt(binomial_variancia(n, p))));
  return ltqnorm(z_0);
}

void    aplica_normal(double n, double p, double m_0, double m_1) {
  printf(" ## Distribuicao Normal ## \n");
  printf("Valores: \t\t%lf\n", n);
  printf("Probabilidade: \t\t%lf\n", p);
  printf("Intervalo: \t\t[%lf, %lf]\n", m_0, m_1);
  printf("###### Valor calculado: %lf\n", normal(n, p, m_0, m_1));
}

int     main(int argc, char **argv) {
  double n, p, m_0, m_1;
  int algoritmo;
  
  if(!entrada(argc, argv, &n, &p, &m_0, &m_1, &algoritmo))
    return EXIT_SUCCESS;

  if(algoritmo == 1)
    aplica_binomial(n, p, m_0, m_1);
  else if(algoritmo == 2)
    aplica_normal(n, p, m_0, m_1);

  return EXIT_SUCCESS;
}
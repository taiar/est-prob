#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

static const double valores[] = {
  0.0000, 0.0040, 0.0080, 0.0120, 0.0160, 0.0199, 0.0239, 0.0279, 0.0319, 0.0359, 0.0398, 0.0438,
  0.0478, 0.0517, 0.0557, 0.0596, 0.0636, 0.0675, 0.0714, 0.0753, 0.0793, 0.0832, 0.0871, 0.0910,
  0.0948, 0.0987, 0.1026, 0.1064, 0.1103, 0.1141, 0.1179, 0.1217, 0.1255, 0.1293, 0.1331, 0.1368,
  0.1406, 0.1443, 0.1480, 0.1517, 0.1554, 0.1591, 0.1628, 0.1664, 0.1700, 0.1736, 0.1772, 0.1808,
  0.1844, 0.1879, 0.1915, 0.1950, 0.1985, 0.2019, 0.2054, 0.2088, 0.2123, 0.2157, 0.2190, 0.2224,
  0.2257, 0.2291, 0.2324, 0.2357, 0.2389, 0.2422, 0.2454, 0.2486, 0.2517, 0.2549, 0.2580, 0.2611,
  0.2642, 0.2673, 0.2704, 0.2734, 0.2764, 0.2794, 0.2823, 0.2852, 0.2881, 0.2910, 0.2939, 0.2967,
  0.2995, 0.3023, 0.3051, 0.3078, 0.3106, 0.3133, 0.3159, 0.3186, 0.3212, 0.3238, 0.3264, 0.3289,
  0.3315, 0.3340, 0.3365, 0.3389, 0.3413, 0.3438, 0.3461, 0.3485, 0.3508, 0.3531, 0.3554, 0.3577,
  0.3599, 0.3621, 0.3643, 0.3665, 0.3686, 0.3708, 0.3729, 0.3749, 0.3770, 0.3790, 0.3810, 0.3830,
  0.3849, 0.3869, 0.3888, 0.3907, 0.3925, 0.3944, 0.3962, 0.3980, 0.3997, 0.4015, 0.4032, 0.4049,
  0.4066, 0.4082, 0.4099, 0.4115, 0.4131, 0.4147, 0.4162, 0.4177, 0.4192, 0.4207, 0.4222, 0.4236,
  0.4251, 0.4265, 0.4279, 0.4292, 0.4306, 0.4319, 0.4332, 0.4345, 0.4357, 0.4370, 0.4382, 0.4394,
  0.4406, 0.4418, 0.4429, 0.4441, 0.4452, 0.4463, 0.4474, 0.4484, 0.4495, 0.4505, 0.4515, 0.4525,
  0.4535, 0.4545, 0.4554, 0.4564, 0.4573, 0.4582, 0.4591, 0.4599, 0.4608, 0.4616, 0.4625, 0.4633,
  0.4641, 0.4649, 0.4656, 0.4664, 0.4671, 0.4678, 0.4686, 0.4693, 0.4699, 0.4706, 0.4713, 0.4719,
  0.4726, 0.4732, 0.4738, 0.4744, 0.4750, 0.4756, 0.4761, 0.4767, 0.4772, 0.4778, 0.4783, 0.4788,
  0.4793, 0.4798, 0.4803, 0.4808, 0.4812, 0.4817, 0.4821, 0.4826, 0.4830, 0.4834, 0.4838, 0.4842,
  0.4846, 0.4850, 0.4854, 0.4857, 0.4861, 0.4864, 0.4868, 0.4871, 0.4875, 0.4878, 0.4881, 0.4884,
  0.4887, 0.4890, 0.4893, 0.4896, 0.4898, 0.4901, 0.4904, 0.4906, 0.4909, 0.4911, 0.4913, 0.4916,
  0.4918, 0.4920, 0.4922, 0.4925, 0.4927, 0.4929, 0.4931, 0.4932, 0.4934, 0.4936, 0.4938, 0.4940,
  0.4941, 0.4943, 0.4945, 0.4946, 0.4948, 0.4949, 0.4951, 0.4952, 0.4953, 0.4955, 0.4956, 0.4957,
  0.4959, 0.4960, 0.4961, 0.4962, 0.4963, 0.4964, 0.4965, 0.4966, 0.4967, 0.4968, 0.4969, 0.4970,
  0.4971, 0.4972, 0.4973, 0.4974, 0.4974, 0.4975, 0.4976, 0.4977, 0.4977, 0.4978, 0.4979, 0.4979,
  0.4980, 0.4981, 0.4981, 0.4982, 0.4982, 0.4983, 0.4984, 0.4984, 0.4985, 0.4985, 0.4986, 0.4986,
  0.4987, 0.4987, 0.4987, 0.4988, 0.4988, 0.4989, 0.4989, 0.4989, 0.4990, 0.4990
};

static const char* indices[] = {
  "0.000000", "0.010000", "0.020000", "0.030000", "0.040000", "0.050000", "0.060000", "0.070000",
  "0.080000", "0.090000", "0.100000", "0.110000", "0.120000", "0.130000", "0.140000", "0.150000",
  "0.160000", "0.170000", "0.180000", "0.190000", "0.200000", "0.210000", "0.220000", "0.230000",
  "0.240000", "0.250000", "0.260000", "0.270000", "0.280000", "0.290000", "0.300000", "0.310000",
  "0.320000", "0.330000", "0.340000", "0.350000", "0.360000", "0.370000", "0.380000", "0.390000",
  "0.400000", "0.410000", "0.420000", "0.430000", "0.440000", "0.450000", "0.460000", "0.470000",
  "0.480000", "0.490000", "0.500000", "0.510000", "0.520000", "0.530000", "0.540000", "0.550000",
  "0.560000", "0.570000", "0.580000", "0.590000", "0.600000", "0.610000", "0.620000", "0.630000",
  "0.640000", "0.650000", "0.660000", "0.670000", "0.680000", "0.690000", "0.700000", "0.710000",
  "0.720000", "0.730000", "0.740000", "0.750000", "0.760000", "0.770000", "0.780000", "0.790000",
  "0.800000", "0.810000", "0.820000", "0.830000", "0.840000", "0.850000", "0.860000", "0.870000",
  "0.880000", "0.890000", "0.900000", "0.910000", "0.920000", "0.930000", "0.940000", "0.950000",
  "0.960000", "0.970000", "0.980000", "0.990000", "1.000000", "1.010000", "1.020000", "1.030000",
  "1.040000", "1.050000", "1.060000", "1.070000", "1.080000", "1.090000", "1.100000", "1.110000",
  "1.120000", "1.130000", "1.140000", "1.150000", "1.160000", "1.170000", "1.180000", "1.190000",
  "1.200000", "1.210000", "1.220000", "1.230000", "1.240000", "1.250000", "1.260000", "1.270000",
  "1.280000", "1.290000", "1.300000", "1.310000", "1.320000", "1.330000", "1.340000", "1.350000",
  "1.360000", "1.370000", "1.380000", "1.390000", "1.400000", "1.410000", "1.420000", "1.430000",
  "1.440000", "1.450000", "1.460000", "1.470000", "1.480000", "1.490000", "1.500000", "1.510000",
  "1.520000", "1.530000", "1.540000", "1.550000", "1.560000", "1.570000", "1.580000", "1.590000",
  "1.600000", "1.610000", "1.620000", "1.630000", "1.640000", "1.650000", "1.660000", "1.670000",
  "1.680000", "1.690000", "1.700000", "1.710000", "1.720000", "1.730000", "1.740000", "1.750000",
  "1.760000", "1.770000", "1.780000", "1.790000", "1.800000", "1.810000", "1.820000", "1.830000",
  "1.840000", "1.850000", "1.860000", "1.870000", "1.880000", "1.890000", "1.900000", "1.910000",
  "1.920000", "1.930000", "1.940000", "1.950000", "1.960000", "1.970000", "1.980000", "1.990000",
  "2.000000", "2.010000", "2.020000", "2.030000", "2.040000", "2.050000", "2.060000", "2.070000",
  "2.080000", "2.090000", "2.100000", "2.110000", "2.120000", "2.130000", "2.140000", "2.150000",
  "2.160000", "2.170000", "2.180000", "2.190000", "2.200000", "2.210000", "2.220000", "2.230000",
  "2.240000", "2.250000", "2.260000", "2.270000", "2.280000", "2.290000", "2.300000", "2.310000",
  "2.320000", "2.330000", "2.340000", "2.350000", "2.360000", "2.370000", "2.380000", "2.390000",
  "2.400000", "2.410000", "2.420000", "2.430000", "2.440000", "2.450000", "2.460000", "2.470000",
  "2.480000", "2.490000", "2.500000", "2.510000", "2.520000", "2.530000", "2.540000", "2.550000",
  "2.560000", "2.570000", "2.580000", "2.590000", "2.600000", "2.610000", "2.620000", "2.630000",
  "2.640000", "2.650000", "2.660000", "2.670000", "2.680000", "2.690000", "2.700000", "2.710000",
  "2.720000", "2.730000", "2.740000", "2.750000", "2.760000", "2.770000", "2.780000", "2.790000",
  "2.800000", "2.810000", "2.820000", "2.830000", "2.840000", "2.850000", "2.860000", "2.870000",
  "2.880000", "2.890000", "2.900000", "2.910000", "2.920000", "2.930000", "2.940000", "2.950000",
  "2.960000", "2.970000", "2.980000", "2.990000", "3.000000", "3.010000", "3.020000", "3.030000",
  "3.040000", "3.050000", "3.060000", "3.070000", "3.080000", "3.090000"
};

static int max = 310;

double phi(double n) {
  char valor[30];
  int i, indice = 0;

  if(n < 0)
    return 1 - phi((-1) * n);

  sprintf(valor, "%lf", n);
  for (i = 0; i < max; ++i)
    if(strcmp(valor, indices[i]) == 0) {
      indice = i;
      break;
    }
  return valores[indice];
}

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

double binomial_esperanca(double n, double p) {
  return (n * p);
}

double binomial_variancia(double n, double p) {
  return (n * p)*(1 - p);
}

double aplica_binomial_intervalo(double n, double p, double m_0, double m_1) {
  int i;
  double acum = 0;
  for(i = m_0; i <= m_1; i += 1)
    acum += binomial(n, p, i);
  return acum;
}

void aplica_binomial(double n, double p, double m_0, double m_1) {
  printf(" ## Distribuicao Binomial ## \n");
  printf("Distribuição: \tX ~ B(%lf, %lf) \n", n, p);
  printf("Intervalo: \t[%lf, %lf]\n", m_0, m_1);
  printf("Probabilidade: \tP( %lf <= X <= %lf) = %lf\n", m_0, m_1, aplica_binomial_intervalo(n, p, m_0, m_1));
}

double normal_padrao_intervalo(double m_0, double m_1) {
  double p_0 = phi(m_0);
  double p_1 = phi(m_1);
  return (p_1 > p_0) ? (p_1 - p_0) : (p_0 - p_1);
}

void aplica_normal(double n, double p, double m_0, double m_1) {
  double b_esp = binomial_esperanca(n, p);
  double b_var = binomial_variancia(n, p);
  double b_des = sqrt(b_var);
  double n_0   = (m_0 - b_esp)/b_des;
  double n_1   = (m_1 - b_esp)/b_des;

  printf(" ## Distribuicao Normal ## \n");
  printf("Binomial: \tX ~ B(%lf, %lf)\n", n, p);
  printf("Normal: \tZ ~ N(%lf, %lf)\n", b_esp, b_var);
  printf("Probabilidade: \tP( %lf <= X <= %lf)  ~ P(%lf <= Z <= %lf) = %lf\n", m_0, m_1,
    n_0, n_1, normal_padrao_intervalo(n_0, n_1));
}

int main(int argc, char **argv) {
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

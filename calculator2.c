#include "putchar.h"

double number(char *);
double fuctor_number(char *);
double mul_div(char *);
double ft_res(char *);

static int index = 0;

int main(int argc, char **argv)
{
  double res;
  if(argc == 2)
  {
    res = ft_res(argv[1]);
    printf("%f\n", res);
  }
  else
    printf("Введите боьше данных\n");
  return 0;
}

double number(char *str)
{
  double res = 0.0, div = 10.0;
  int sign = 1;
  //if(str[index] == '-')
  if(str[index] == '-' && (str[index+1] <= '9' && str[index+1] >= '0'))
  {
    sign = -1;
    ++index;
  }
  while(str[index] <= '9' && str[index] >= '0')
  {
    res = res * 10 + (str[index] - '0');
    ++index;
  }
  if(str[index] == '.')
  {
    ++index;
    while(str[index] <= '9' && str[index] >= '0')
    {
      res = res + (str[index] - '0') / div;
      div *= 10.0;
      ++index;
    }
  }
  return res * sign;
}

double factor_number(char *str)
{
  double res;
  int sign = 1;
  if(str[index] == '-' && (str[index+1] <= '9' && str[index+1] >= '0'))
  {
    sign = -1;
    ++index;
  }
  if(str[index] == '(')
  {
    ++index;
    res = ft_res(str);
    if(str[index] != ')')
      printf("Скобки закрой\n");
    ++index;
  }
  else 
    res = number(str);
  return res * sign;
}

double mul_div(char *str) // mul(multiplication)  div(division)
{
  double res = factor_number(str);
  double x;
  if(str[index] == '*')
  {
    ++index;
    res *= factor_number(str);
  }
  if(str[index] == '/')
  {
    ++index;
    x = factor_number(str);
    if(x != 0.0)
      res /= x;
  }
  return res;
}

double ft_res(char *str)
{
  double res = mul_div(str);
  if(str[index] == '-')
  {
    ++index;
    res -= mul_div(str);
  }
  if(str[index] == '+')
  {
    ++index;
    res += mul_div(str);
  }
  return res;
}

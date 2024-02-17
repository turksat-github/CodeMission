#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv, char **envp) {
  long double a = -0.0000000000000001;// 16 digits
  printf ("%.16Lf\n", a);
  long long int b = -123456789012345678;// 18 digits
  printf ("%lld\n", b);
  return EXIT_SUCCESS;
}
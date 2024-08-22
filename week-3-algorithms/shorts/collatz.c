#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int collatz(int n);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./collatz number\n");
    return 1;
  }

  char *arg = argv[1];

  for (int i = 0, len = strlen(arg); i < len; i++)
  {
    if (!isdigit(arg[i]))
    {
      fprintf(stderr, "Usage: ./collatz number\n");
      return 1;
    }
  }

  int number = atoi(arg);
  if (number <= 0)
  {
    {
      fprintf(stderr, "Number must be positive\n");
      return 1;
    }
  }

  printf("%i steps\n", collatz(number));

  return 0;
}

int collatz(int n)
{
  // base case
  if (n == 1)
  {
    return 0;
  }

  // recursive case
  return (n % 2 == 0) ? 1 + collatz(n / 2) : 1 + collatz(3 * n + 1);
}

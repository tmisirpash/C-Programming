#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char ** argv)
{
  int i;
  for (i = 1; i < argc; i++)
    {
      printf("%c", argv[i][strlen(argv[i])-1]);
      if (i == argc - 1)
	{
	  printf("\n");
	}
    }
  return 0;
}

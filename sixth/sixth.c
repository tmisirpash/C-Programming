#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char ** argv)
{
  int i;
  for (i = 1; i < argc; i++)
    {
      // printf("%s: %zu\t%c\n", argv[i], strlen(argv[i]), argv[i][strlen(argv[i])-1]);
      if (argv[i][0] == 'a' || argv[i][0] == 'e' || argv[i][0] == 'i' || argv[i][0] == 'o' || argv[i][0] == 'u'|| argv[i][0] == 'A' || argv[i][0] == 'E' || argv[i][0] == 'I' || argv[i][0] == 'O' || argv[i][0] == 'U')
	{
	  printf("%syay", argv[i]);
	}
      else
	{
	  int x;
	  int y;
	  char * temp = malloc(sizeof(char) * strlen(argv[i]));
	  temp[0] = argv[i][0];
	  for (x = 1; x < strlen(argv[i]); x++)
	    {
	      if (argv[i][x] == 'a' || argv[i][x] == 'e' || argv[i][x] == 'i' || argv[i][x] == 'o' || argv[i][x] == 'u'|| argv[i][0] == 'A' || argv[i][0] == 'E' || argv[i][0] == 'I' || argv[i][0] == 'O' || argv[i][0] == 'U')
		{
		  for (y = x; y < strlen(argv[i]); y++)
		    {
		      printf("%c", argv[i][y]);
		    }
		  break;
		}
	      else
		{
		  temp[x] = argv[i][x];
		}
	    }
	  for (y = 0; y < x; y++)
	    {
	      printf("%c", temp[y]);
	    }
	  free(temp);
	  printf("ay");
	}
      if (i == argc - 1)
	{
	  printf("\n");
	}
      else
	{
	  printf(" ");
	}
    }
  return 0;
}


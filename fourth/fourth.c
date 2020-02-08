#include<stdlib.h>
#include<stdio.h>

int main(int argc, char ** argv)
{
  FILE *f = fopen(argv[1], "r");
  int row1;
  int col1;
  int row2;
  int col2;
  fscanf(f, "%d\t%d\n", &row1, &col1);
  int ** m1 = malloc(sizeof(int *) * row1);
  int ** m2 = malloc(sizeof(int *) * row2);
  int x;
  for (x = 0; x < row1; x++)
    {
      m1[x] = malloc(sizeof(int) * col1);
    }
  int i;
  int j;
  for (i = 0; i < row1; i++)
    {
      for (j = 0; j < col1; j++)
	{
	  if (j == col1 - 1)
	    {
	      fscanf(f, "%d\n", &m1[i][j]);
  	    }
	  else
	    {
	      fscanf(f, "%d\t", &m1[i][j]);
	    }
	}
    }
  fscanf(f, "%d\t%d\n", &row2, &col2);
  if (col1 != row2)
    {
      printf("bad-matrices\n");
      return 0;
    }
  for (x=0;x < row2; x++)
    {
      m2[x] = malloc(sizeof(int)*col2);
    }
  for (i = 0; i < row2; i++)
    {
      for (j = 0; j < col2; j++)
	{
	  if (j == col2 - 1)
	    {
	      fscanf(f, "%d\n", &m2[i][j]);
	    }
	  else
	    {
	      fscanf(f, "%d\t", &m2[i][j]);
	    }
	}
    }
  int ** m3 = malloc(sizeof(int *) * row1);
  for (x = 0; x < row1; x++)
    {
      m3[x] = malloc(sizeof(int)*col2);
    }
  for (i = 0; i < row1; i++)
    {
      for (j = 0; j < col2; j++)
	{
	  m3[i][j] = 0;
	  for(x = 0; x < col1; x++)
	    {
	      m3[i][j] += m1[i][x] * m2[x][j];
	    }
	  if (j == col2 - 1)
	    {
	      printf("%d\n", m3[i][j]);
	    }
	  else
	    {
	      printf("%d\t", m3[i][j]);
	    }
	}
    }
  for (i = 0; i < row1; i++)
    {
      free(m1[i]);
      free(m3[i]);
    }
  free(m1);
  free(m3);
  for (i = 0; i < row2; i++)
    {
      free(m2[i]);
    }
  free(m2);
  return 0;
}

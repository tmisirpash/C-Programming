#include<stdlib.h>
#include<stdio.h>

int main(int argc, char ** argv)
{
  FILE *f = fopen(argv[1], "r");
  int dimension;
  fscanf(f, "%d\n", &dimension);
  int **square = malloc(dimension * sizeof(int *));
  int i;
  int j;
  for (i = 0; i < dimension; i++)
    {
      square[i] = malloc(dimension * sizeof(int));
    }
  int * numberCheck = malloc(dimension * dimension * sizeof(int));
  for (i = 0; i < dimension * dimension; i++)
    {
      numberCheck[i] = 0;
    }
  for (i = 0; i < dimension; i++)
    {
      for (j = 0; j < dimension; j++)
	{
	  if (j == dimension - 1)
	    {
	      fscanf(f, "%d\n", &square[i][j]);
	    }
	  else
	    {
	      fscanf(f, "%d\t", &square[i][j]);
	    }
	  if (square[i][j] > dimension * dimension || square[i][j] <= 0)
	    {
	      printf("not-magic\n");
	      return 0;
	    }
	  numberCheck[square[i][j]-1] = square[i][j];
	}
    }
  for (i = 0; i < dimension * dimension; i++)
    {
      if (numberCheck[i] != i + 1)
	{
	  printf("not-magic\n");
	  return 0;
	}
    }
  int mConstant = dimension * (dimension * dimension + 1)/2;
  // Rows
  int tempSum = 0;
  for (i = 0; i < dimension; i++)
    {
      for (j = 0; j < dimension; j++)
	{
	  tempSum += square[i][j];
	}
      if (tempSum != mConstant)
	{
	  printf("not-magic\n");
	  return 0;
	}
      tempSum = 0;
    }
  //Columns
  for (i = 0; i < dimension; i++)
    {
      for (j = 0; j < dimension; j++)
	{
	  tempSum += square[j][i];
	}
      if (tempSum != mConstant)
	{
	  printf("not-magic\n");
	  return 0;
	}
      tempSum = 0;
    }
  //Left Diagonal
  for (i = 0; i < dimension; i++)
    {
      tempSum += square[i][i];
    }
  if (tempSum != mConstant)
    {
      printf("not-magic\n");
      return 0;
    }
  tempSum = 0;
  //Right Diagonal
  for (i = 0; i < dimension; i++)
    {
      tempSum += square[i][dimension - i - 1];
    }
  if (tempSum != mConstant)
    {
      printf("not-magic\n");
      return 0;
    }
  //Made it!
  printf("magic\n");
  for (i = 0; i < dimension; i++)
    {
      free(square[i]);
    }
  free(square);
  free(numberCheck);
  return 0;
}

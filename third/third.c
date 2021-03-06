#include<stdlib.h>
#include<stdio.h>

struct node
{
  int data;
  struct node* next;
};

struct node* table[1000];
void insertNode(int data)
{
  struct node* n = malloc(sizeof(struct node));
  n->data = data;
  n->next = NULL;
  int hashCode = data % 1000;
  if (data < 0)
    {
      hashCode = hashCode * -1;
    }
  if (table[hashCode]==NULL)
    {
      table[hashCode] = n;
      printf("inserted\n");
    }
  else
    {
      struct node* pointer = table[hashCode];
      int checker = 0;
      while (pointer != NULL)
	{
	  if (pointer->data == data)
	    {
	      printf("duplicate\n");
	      checker = 1;
	      break;
	    }
	  pointer = pointer->next;
	}
      if (checker == 0)
	{
	  n->next = table[hashCode];
	  table[hashCode] = n;
	  printf("inserted\n");
	}
    }
}
void searchNode(int data)
{
  int hashCode = data % 1000;
  if (data < 0)
    {
      hashCode = hashCode * -1;
    }
  struct node* pointer = table[hashCode];
  int checker = 0;
  while (pointer != NULL)
    {
      if (pointer->data == data)
	{
	  checker = 1;
	  printf("present\n");
	  break;
	}
      pointer = pointer->next;
    }
  if (checker == 0)
    {
      printf("absent\n");
    }
}
int main(int argc, char ** argv)
{
  FILE *f = fopen(argv[1], "r");
  char operation;
  int number;
  int r = fscanf(f, "%c\t%d\n", &operation, &number);
  while (r==2)
    {
      if(operation == 'i')
	{
	  insertNode(number);
	}
      else
	{
	  searchNode(number);
	}
      r = fscanf(f, "%c\t%d\n", &operation, &number);
    }
  int i;
  for (i = 0; i < 1000; i++)
    {
      struct node * current = table[i];
      struct node * ptr = table[i];
      while (ptr != NULL)
	{
	  ptr = ptr->next;
	  free(current);
	  current = ptr;
	}
    }
  return 0;
}

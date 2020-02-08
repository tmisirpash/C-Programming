#include<stdlib.h>
#include<stdio.h>

struct node 
{
  int data;
  struct node* next;
};
struct node* front = NULL;
int size = 0;
void insertNode(int data)
{
  struct node* n;
  n = malloc(sizeof(struct node));
  n -> data = data;
  n -> next = NULL;
  if (front == NULL)
    {
      front = n;
      size++;
    }
  else
    {
      struct node* pointer = front;
      struct node* previous = NULL;
      while (pointer != NULL)
	{
	  if (pointer->data == data)
	    {
	      break;
	    }
	  if (pointer->data > data)
	    {
	      if(pointer == front)
		{
		  n->next = front;
		  front = n;
		  size++;
		  break;
		}
	      else
		{
		  previous->next = n;
		  n->next=pointer;
		  size++;
		  break;
		}
	    }
	  else
	    {
	      if (pointer->next == NULL)
		{
		  pointer->next = n;
		  size++;
		  break;
		}
	    }
	  previous = pointer;
	  pointer = pointer->next;
	}
    }
}
void deleteNode(int data)
{
  struct node* pointer = front;
  struct node* previous = NULL;
  while (pointer != NULL)
    {
      if (pointer->data == data)
	{
	  if (pointer == front)
	    {
	      front = pointer->next;
	    }
	  else
	    {
	      previous->next = pointer->next;
	    }
	  size--;
	}
      previous = pointer;
      pointer = pointer->next;
    }
}
int main(int argc, char** argv)
{
  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
    {
      printf("error\n");
      return 0;
    }
  char operation;
  int number;
  int r = fscanf(f, "%c\t%d\n", &operation, &number);
  if (r!=2)
    {
      printf("%d\n", 0);
      return 0;
    }
  while(r==2)
    {
      if(operation == 'i')
	{
	  insertNode(number);
	}
      else
	{
	  deleteNode(number);
	}
      r=fscanf(f, "%c\t%d\n", &operation, &number);
    }
  printf("%d\n", size);
  if (size != 0)
    {
      struct node * pointer = front;
      while (pointer != NULL)
	{
	  if (pointer->next == NULL)
	    {
	      printf("%d", pointer->data);
	    }
	  else
	    {
	      printf("%d\t", pointer->data);
	    }
	  pointer=pointer->next;
	}
      printf("\n");
    }
  struct node* pointer;
  while (front != NULL)
    {
      pointer = front;
      front = front->next;
      free(pointer);
    }
  return 0;
}

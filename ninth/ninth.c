#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  int height;
  struct node* left;
  struct node* right;
};
int size = 0;
struct node * makeNode(int);
void changeHeights(struct node*);

void changeHeights(struct node * r)
{
  if (r == NULL)
    {
      return;
    }
  changeHeights(r->left);
  changeHeights(r->right);
  r->height = r->height-1;
}

struct node * delete(int data, struct node * r)
{
  if (r == NULL)
    {
      printf("fail\n");
      return r;
    }
  else if (data < r->data)
    {
     r->left = delete(data, r->left);
     return r;
    }
  else if (data > r->data)
    {
     r->right = delete(data, r->right);
     return r;
    }
  else
    {
      // 0 children
      if (r->left == NULL && r->right == NULL)
	{
	  free(r);
	  size--;
	  return NULL;
	}
      // 1 child on the left
      else if(r->left != NULL && r->right == NULL)
	{
	  struct node * n = r->left;
	  free(r);
	  changeHeights(n);
	  size--;
	  return n;
	}
      // 1 child on the right
      else if (r->right != NULL && r->left == NULL)
	{
	  struct node *n = r->right;
	  free(r);
	  changeHeights(n);
	  size--;
	  return n;
	}
      //2 children
      else
	{
	  struct node * ptr = r->right;
	  while (ptr->left != NULL)
	    {
	      ptr = ptr->left;
	    }
	  r->data = ptr->data;
	  //  r->height = ptr->height;
	  r->right = delete(ptr->data, r->right);
	  return r;
	}
    }
}

void freeTree(struct node * r)
{
  if (r == NULL)
    {
      return;
    }
  freeTree(r->left);
  freeTree(r->right);
  free(r);
}


void searchNode(int data, struct node * r)
{
  if (r == NULL)
    {
      printf("absent\n");
    }
  else if (r->data == data)
    {
      printf("present %d\n", r->height);
    }
  else if (data < r->data)
    {
      searchNode(data, r->left);
    }
  else
    {
      searchNode(data, r->right);
    }
}
struct node * insertNode(int data, struct node * r, int h)
{
  if (r == NULL)
    {
      struct node * temp = makeNode(data);
      temp->height = h;
      printf("inserted %d\n", temp->height);
      size++;
      return  temp;
    }
  else if (data == r->data)
    {
      printf("duplicate\n");
      return r;
    }
  else if (data < r->data)
    {
      r->left = insertNode(data, r->left, h+1);
     return r;
    }
  else
    {
      r->right = insertNode(data, r->right, h+1);
     return r;
    }
}
struct node * makeNode(int data)
{
  struct node * n = malloc(sizeof(struct node));
  n->height = 0;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}
int main(int argc, char ** argv)
{
  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
    {
      printf("error\n");
      return 0;
    }
  char operation;
  int number;
  struct node * root = NULL;
  int r = fscanf(f, "%c\t%d\n", &operation, &number);
  while (r == 2)
    {
      if (operation == 'i')
	{
	  if (root == NULL)
	    {
	      root = insertNode(number, root, 1);
	    }
	  else 
	    {
	      insertNode(number, root, 1);
	    }
       	}
      else if (operation == 's')
	{
	   searchNode(number, root);
	}
      else
	{
	  int checker = size;
	  root = delete(number, root);
	  if (size != checker)
	    {
	      printf("success\n");
	    }
	}
      r = fscanf(f, "%c\t%d\n", &operation, &number);
    }
  freeTree(root);
  return 0;
}

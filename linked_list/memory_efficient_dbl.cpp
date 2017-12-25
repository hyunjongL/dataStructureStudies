/*
  Memory Efficient Doubly Linked Lists
  XOR of pointers to next and before node is stored
  This effectively stores pointers by reducing its total size into half.
  The sideeffect?
    less intuitive than normal linked List
    needs more computation to iterate
    needs 2 nodes backand forth to iterate
  Still, may be used in some times where the total size matters and computation
  is sufficient. + with programmer's effort to understand the underlying
  implemtation.
  */
#include "memory_efficient_dbl.hpp"

using namespace std;

void printint(void* p){
  printf("%d\n", *(int*)p);
  return;
}

int main(){
  printf("Hello world!\n");
  xorList* xlist = new xorList;
  printf("head: %p, tail: %p, NULLs %p, %p\n", xlist->getHead(), xlist->getTail(), xlist->getHead()->getXOR(), xlist->getTail()->getXOR());
  for(int i=0; i<10; i++){
    int* p = (int*) malloc(sizeof(int));
    *p = i;
    xlist->insertVal((void*) p);
  }
  xlist->traverse(printint);
  for(int i=0; i<5; i++){
    printf("%d", *(int*)xlist->popback());
  }
  for(int i=0;i<5;i++){
    printf("%d", *(int*)xlist->popfront());
  }
  return 0;
}

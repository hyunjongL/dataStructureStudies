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

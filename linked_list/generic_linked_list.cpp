//generic_linked_list.cpp
#include <iostream>
#include "generic_linked_list.hpp"

using namespace std;

node* node::getParent(){
  return this->parent;
}
bool node::setParent(node* p){
  try{
    this->parent = p;
    return true;
  }catch (const exception& e) {
    return false;
  }
}
void* node::getValue(){
  return this->value;
}
bool node::setValue(void* v){
  try{
    this->value = v;
    return true;
  }catch(const exception& e){
    return false;
  }
}
bool node::isRoot(){
  return (this->getParent() == NULL);
}

void printint(void* p)
{
  printf("%d\n", *(int*)p);
}

void node::traverse(void func(void*)){
  node* n0de = this;
  while(!n0de->isRoot()){
    func(n0de->getValue());
    n0de = n0de->getParent();
  }
  return;
}

int main(){
  printf("Hello world!\n");
  node* master = new node();
  printf("%p\n", master->getParent());
  int* val = (int*)malloc(sizeof(int));
  *val = 100;
  master->setValue((void*)val);
  node* n = NULL;

  for(int i=0; i<10; i++){
    if(n == NULL){
      node* new_node = new node();
      new_node->setParent(master);
      int* val = (int*)malloc(sizeof(int));
      *val = i;
      new_node->setValue((void*)val);
      n = new_node;
    }
    else{
      node* new_node = new node();
      new_node->setParent(n);
      int* val = (int*)malloc(sizeof(int));
      *val = i;
      new_node->setValue((void*)val);
      n = new_node;
    }
  }
  n->traverse(printint);
  return 1;
}

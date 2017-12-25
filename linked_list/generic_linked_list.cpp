//generic_linked_list.cpp
/*
  Generic Linked Lists
  We want to make a list that can store any kind of values.
  So, what I have thought is to make a list that stores void pointers pointing
  whatever values I put in. The important part is how are we going to interpret
  the values. I suggest a way to read/traverse nodes with a function as a parameter.
  For example 'printInt' below describes a function that prints int stored in
  a void pointer. Which means, if I store integers in the list, I can skim through
  the list and print what is stored inside. We usually store only one kind of type
  in a datastructure, so this approach seems legit.*/

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

// memory_efficient_dbl.hpp
#include <stdint.h>
#include <iostream>

using namespace std;

class node{
private:
  void* xor_addr;
  void* value;
public:
  node() : xor_addr(NULL), value(NULL) {};
  void* getNext(void*);
  void* getXOR();
  bool setXOR(void* p);
  void* getValue();
  bool setValue(void* p);
  void traverse(void function(void*));
  bool isRoot();
};
void* node::getNext(void* before){
  return (void*)((uintptr_t)this->getXOR() ^ (uintptr_t)before);
}
void* node::getXOR(){
  return this->xor_addr;
}
bool node::setXOR(void* p){
  try{
    this->xor_addr = p;
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

class xorList{
private:
  node* head;
  node* tail;
  int size;
public:
  xorList();
  node* getFirst();
  node* getTail();
  node* getHead();
  void insert(node*);
  void insertVal(void*);
  void* popback();
  void* popfront();
  void traverse(void function(void*));
};
xorList::xorList(){
  head = new node;
  tail = new node;
  head->setXOR(tail);
  tail->setXOR(head);
  size = 0;
}
node* xorList::getTail(){
  return this->tail;
}
node* xorList::getHead(){
  return this->head;
}

void xorList::insert(node* p){
  node* last_node = (node*)this->getTail()->getXOR();
  node* second_last = (node*)((uintptr_t)last_node->getXOR() ^ (uintptr_t)this->getTail());
  last_node->setXOR((void*) ((uintptr_t)second_last ^ (uintptr_t)p));
  this->getTail()->setXOR((void*) p);
  p->setXOR((void*) ((uintptr_t) last_node ^ (uintptr_t)this->getTail()));
  return;
}
void xorList::insertVal(void* v){
  node* n = new node;
  n->setValue(v);
  this->insert(n);
  return;
}

void xorList::traverse(void function(void*)){
  node* one = this->getHead();
  node* two = (node*)one->getXOR();
  while(two != this->getTail()){
    function(two->getValue());
    node* temp = two;
    two = (node*)((uintptr_t)two->getXOR() ^ (uintptr_t)one);
    one = temp;
  }
  return;
}

void* xorList::popback(){
  node* last_node = (node*) this->getTail()->getXOR();
  if(last_node == this->getHead()){
    return NULL;
  }
  node* second_last = (node*)((uintptr_t)last_node->getXOR() ^ (uintptr_t)this->getTail());
  second_last->setXOR((void*) ((uintptr_t)this->getTail() ^ ((uintptr_t)second_last->getXOR() ^ (uintptr_t)last_node)));
  this->getTail()->setXOR(second_last);
  void* val = last_node->getValue();
  delete(last_node);
  return val;
}

void* xorList::popfront(){
  node* first_node = (node*) this->getHead()->getXOR();
  if(first_node == this->getTail()){
    return NULL;
  }
  node* second_first = (node*)((uintptr_t)first_node->getXOR() ^ (uintptr_t)this->getHead());
  second_first->setXOR((void*) ((uintptr_t)this->getHead() ^ ((uintptr_t)second_first->getXOR() ^ (uintptr_t)first_node)));
  this->getHead()->setXOR(second_first);
  void* val = first_node->getValue();
  delete(first_node);
  return val;
}

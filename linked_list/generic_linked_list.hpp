//generic_linked_list.hpp

class node{
private:
  node* parent;
  void* value;
public:
  node() : parent(NULL), value(NULL) {};
  node* getParent();
  bool setParent(node* p);
  void* getValue();
  bool setValue(void* p);
  void traverse(void function(void*));
  bool isRoot();
};

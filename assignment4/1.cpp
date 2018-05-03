int a;
int b;
int total;

void DynIntStack::div(){
  pop(a);
  pop(b);

  total = b/a;

  push(total);

}

#include <iostream>

#include "cod.hpp"
#include "angajat.hpp"
#include "produs.hpp"

using namespace std;

int main(){
  /*cnp tmp1("6250201017558");
  id<angajat> tmp2(1);
  asistent ionel(string("ionel2"), string("ionescu2"), tmp1, tmp2);

  cout<<ionel.get_salariu();*/

  vector<produs*> bd_produse;
  int type;
  cin>>type;
  switch(type){
    case 1:
      bd_produse.push_back(new articol_vestimentar());
      (*(--bd_produse.end()))->operator>>(cin);
    break;
  }

  return 0;
}

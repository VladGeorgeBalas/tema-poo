#include <iostream>
#include <fstream>

#include "cod.hpp"
#include "angajat.hpp"
#include "produs.hpp"

using namespace std;

int main(){
  /*cnp tmp1("6250201017558");
  id<angajat> tmp2(1);
  asistent ionel(string("ionel2"), string("ionescu2"), tmp1, tmp2);

  cout<<ionel.get_salariu();*/
  
  //variabile
  vector<pair<produs*, unsigned int>> catalog_produse;

  /*
   *  citirea catalogului de produse sub forma <produs, stoc>
   */
  ifstream fin("produse");

  int type;
  while(fin>>type){
    switch(type){
      case 1:
        catalog_produse.push_back(pair<produs*, unsigned int>(new articol_vestimentar(), 0));
        (--catalog_produse.end())->first->operator>>(fin);
        fin>>(--catalog_produse.end())->second;
        break;
      case 2:
        catalog_produse.push_back(pair<produs*, unsigned int>(new disc(), 0));
        (--catalog_produse.end())->first->operator>>(fin);
        fin>>(--catalog_produse.end())->second;
        break;
      case 3:
        catalog_produse.push_back(pair<produs*, unsigned int>(new vintage(), 0));
        (--catalog_produse.end())->first->operator>>(fin);
        fin>>(--catalog_produse.end())->second;
        break;
    }
  }

  fin.close();

  /*
   *  de aici pana aici merge codul :D
   */

  ofstream fout("produse");

  for(vector<pair<produs*, unsigned int>>::iterator i = catalog_produse.begin(); i != catalog_produse.end(); i++)
  {
    i->first->operator<<(fout);
    fout<<i->second;
    fout<<'\n'; 
  }

  fout.close();

  return 0;
}

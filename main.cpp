#include <iostream>
#include <fstream>

#include "cod.hpp"
#include "angajat.hpp"
#include "produs.hpp"
#include "comanda.hpp"

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

  vector<angajat*> catalog_angajati;
  ifstream f_ang("angajati"); 
  while(f_ang>>type){
    switch(type){
      case 1:
        catalog_angajati.push_back(new manager());
        (*--catalog_angajati.end())->operator>>(f_ang);
        break;
      case 2:
        catalog_angajati.push_back(new asistent());
        (*--catalog_angajati.end())->operator>>(f_ang);
        break;
      case 3:
        catalog_angajati.push_back(new operator_comenzi());
        (*--catalog_angajati.end())->operator>>(f_ang);
        break;
    }
  }
  f_ang.close();

  /*
   *  de aici pana aici merge codul :D
   */
  //operator_comenzi op_test{};
  //op_test.operator>>(cin);
  //op_test.operator<<(cout);
  
  //verificare numar angajati
  int nr_manager = 0;
  int nr_asistent = 0;
  int nr_operator = 0;
  for(vector<angajat*>::iterator i = catalog_angajati.begin(); i != catalog_angajati.end(); i++){

  }

  //verificare numar produse 
  
  //citire comanda
  string comanda;
  cin>>comanda;

  if(comanda == "add_angajat"){
    
  }else if(comanda == "add_produs"){

  }else if(comanda == "add_comanda"){

  }else if(comanda == "remove_angajat"){

  }else if(comanda == "top_3"){

  }else if(comanda == "top_1"){}

  ofstream fout("produse");
  for(vector<pair<produs*, unsigned int>>::iterator i = catalog_produse.begin(); i != catalog_produse.end(); i++)
  {
    i->first->operator<<(fout);
    fout<<i->second;
    fout<<'\n'; 
  }
  fout.close();

  ofstream f_ang_out("angajati");
  for(vector<angajat*>::iterator i = catalog_angajati.begin(); i != catalog_angajati.end(); i++){
    (*i)->operator<<(f_ang_out);
    f_ang_out<<"\n";
  }
  f_ang_out.close();


  return 0;
}

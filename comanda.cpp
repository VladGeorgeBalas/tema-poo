#include "comanda.hpp"
#include "produs.hpp"
#include <istream>
#include <string.h>
#include <vector>

comanda::comanda(
    const vector<produs*>& produse_comanda,
    const time_t& primire,
    const time_t& finalizare
    ):
  produse_comanda(produse_comanda),
  primire(primire),
  finalizare(finalizare){

  }

unsigned int comanda::get_pret(){
  unsigned int result = 0;

  for(produs* i : produse_comanda){
    result += i->get_pret();
  }

  return result;
}

bool comanda::check_validity(){
  unsigned int nr_discuri = 0;
  unsigned int nr_articole_vestimentare= 0;
  unsigned int pret = this->get_pret();

  for(produs* i : produse_comanda)
  {
    if(typeid(*i) == typeid(*(new disc)))
      nr_discuri++;
    if(typeid(*i) == typeid(*(new articol_vestimentar)))
      nr_articole_vestimentare++;
  }

  //cout<<nr_discuri<<" "<<nr_articole_vestimentare<<"\n";

  return (pret > 100) && (nr_discuri < 5) && (nr_articole_vestimentare < 3);
}

ostream& comanda::operator<<(ostream& out){
  out<<produse_comanda.size()<<' ';
  out<<primire<<' ';
  out<<finalizare<<'\n';

  for(vector<produs*>::iterator i = produse_comanda.begin(); i != produse_comanda.end(); i++){
    (*i)->operator<<(out);
    out<<'\n';
  }

  return out;
}

istream& comanda::operator>>(istream& in){
  int type;
  int size;

  in>>size;

  in>>primire;
  in>>finalizare;

  in>>type;

  for(int i = 0; i < size; i++){
    switch(type){
      case 1:
        produse_comanda.push_back(new articol_vestimentar());
        (*--produse_comanda.end())->operator>>(in);
        break;
      case 2:
        produse_comanda.push_back(new disc());
        (*--produse_comanda.end())->operator>>(in);
        break;
      case 3:
        produse_comanda.push_back(new vintage());
        (*--produse_comanda.end())->operator>>(in);
        break;
    }
  }

  return in;
}

#include "produs.hpp"

using namespace std;

produs::produs(
    const string& denumire,
    const unsigned int& pret,
    const id<produs>& id_produs
    ):id_produs(0){
  if(clasa_id_produs.check_availability(id_produs))
    this->id_produs = id_produs;

  this->denumire = denumire;
  this->pret = pret;
}

ostream& produs::operator<<(ostream& out){
  out<<denumire<<'\n';
  out<<pret<<'\n';
  out<<id_produs<<'\n';

  return out;
}

istream& produs::operator>>(istream& in){
  in>>denumire;
  in>>pret;
  in>>id_produs;

  return in;
}

articol_vestimentar::articol_vestimentar(
    const string& denumire,
    const unsigned int& pret,
    const id<produs>& id_produs,
    const string& culoare,
    const string& marca
    ):
  produs(denumire, pret, id_produs),
  culoare(culoare),
  marca(marca){

  }

unsigned int articol_vestimentar::get_pret(){
  return pret + 20;
}

ostream& articol_vestimentar::operator<<(ostream& out){
  this->produs::operator<<(out);

  out<<culoare<<'\n';
  out<<marca<<'\n';

  return out;
}

istream& articol_vestimentar::operator>>(istream& in){
  this->produs::operator>>(in);

  in>>culoare;
  in>>marca;

  return in;
}

disc::disc(
    const string& denumire,
    const unsigned int& pret,
    const id<produs>& id_produs,
    const string& tip_disc,
    const string& casa_de_discuri,
    const time_t& data,
    const string& trupa,
    const string& nume_album
    ):
  produs(denumire, pret, id_produs),
  tip_disc(tip_disc),
  casa_de_discuri(casa_de_discuri),
  data(data),
  trupa(trupa),
  nume_album(nume_album){
  }

unsigned int disc::get_pret(){
  return pret+5;
}

ostream& operator<<(ostream& out, disc& src){
  //operator<<(out, (produs&) src);
  out<<src.tip_disc<<'\n';
  out<<src.casa_de_discuri<<'\n';
  out<<src.data<<'\n';
  out<<src.trupa<<'\n';
  out<<src.nume_album<<'\n';

  return out;
}

istream& operator>>(istream& in, disc& dst){
  //operator>>(in, (produs&) dst);
  in>>dst.tip_disc;
  in>>dst.casa_de_discuri;
  in>>dst.data;
  in>>dst.trupa;
  in>>dst.nume_album;

  return in;
}

vintage::vintage(
    const string& denumire,
    const unsigned int& pret,
    const id<produs>& id_produs,
    const bool& mint,
    const unsigned char& coeficient_raritate
    ):
  produs(denumire, pret, id_produs),
  mint(mint),
  coeficient_raritate(coeficient_raritate){

  }

unsigned int vintage::get_pret(){
  return pret + 5 + 15*coeficient_raritate;
}

ostream& operator<<(ostream& out, vintage& src){
  //operator<<(out, (produs&)src);

  out<<src.mint;
  out<<src.coeficient_raritate;

  return out;
}

istream& operator>>(istream& in, vintage& dst){
  //operator>>(in, (produs&)dst);

  in>>dst.mint;
  in>>dst.coeficient_raritate;

  return in;
}

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
  out<<denumire<<' ';
  out<<pret<<' ';
  out<<id_produs<<' ';

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
  out<<"1 ";

  this->produs::operator<<(out);

  out<<culoare<<' ';
  out<<marca<<' ';

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

ostream& disc::operator<<(ostream& out){
  out<<"2 ";
  this->produs::operator<<(out);
  out<<tip_disc<<' ';
  out<<casa_de_discuri<<' ';
  out<<data<<' ';
  out<<trupa<<' ';
  out<<nume_album<<' ';

  return out;
}

istream& disc::operator>>(istream& in){
  this->produs::operator>>(in);
  in>>tip_disc;
  in>>casa_de_discuri;
  in>>data;
  in>>trupa;
  in>>nume_album;

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

ostream& vintage::operator<<(ostream& out){
  out<<"3 ";

  this->produs::operator<<(out);

  out<<mint<<' ';
  out<<coeficient_raritate<<' ';

  return out;
}

istream& vintage::operator>>(istream& in){
  this->produs::operator>>(in);

  in>>mint;
  in>>coeficient_raritate;

  return in;
}

#include "angajat.hpp"
#include <ostream>
#include <vector>

angajat::angajat(
    const string& nume,
    const string& prenume,
    const cnp& cnp_angajat,
    const id<angajat>& id_angajat
    ):id_angajat(0), cnp_angajat("0000000000000"), salariu(1){
  //check nume
  if(3 < nume.length() && nume.length() < 30)
    this->nume = nume;
  //else
    //throw error

  //check prenume
  if(3 < prenume.length() && prenume.length() < 30)
    this->prenume = prenume;
  //else
    //throw error
  
  if(cnp_angajat.check_validity() && clasa_cnp.check_availability(cnp_angajat))
    this->cnp_angajat = cnp_angajat;

  if(clasa_id_angajat.check_availability(id_angajat))
    this->id_angajat = id_angajat;
}

ostream& angajat::operator<<(ostream& out){
  out<<nume<<'\n';
  out<<prenume<<'\n';
  out<<data_angajare<<'\n';
  out<<cnp_angajat<<'\n';
  out<<id_angajat<<'\n';

  return out;
}

istream& angajat::operator>>(istream& in){
  //aici ar trebui facute si niste verificari daca
  //utilizatorul manipuleaza manual salvarea, dar 
  //daca e manipulata doar de program, verificarea 
  //la initializare e suficienta

  in>>nume;
  in>>prenume;
  in>>data_angajare;
  in>>cnp_angajat;
  in>>id_angajat;

  return in;
}

float angajat::get_salariu(){
  return this->salariu_baza * this->coeficient;
}

manager::manager(
    const string& nume,
    const string& prenume,
    const cnp& cnp_angajat,
    const id<angajat>& id_angajat
    ):angajat(nume, prenume, cnp_angajat, id_angajat), salariu(1.25){}

ostream& manager::operator<<(ostream& out){
  out<<"1 ";

  this->angajat::operator<<(out);

  return out;
}

istream& manager::operator>>(istream& in){
  this->angajat::operator>>(in);

  return in;
}

asistent::asistent(
    const string& nume,
    const string& prenume,
    const cnp& cnp_angajat,
    const id<angajat>& id_angajat
    ):angajat(nume, prenume, cnp_angajat, id_angajat), salariu(0.75){}

ostream& asistent::operator<<(ostream& out){
  out<<"2 ";

  this->angajat::operator<<(out);

  return out;
}

istream& asistent::operator>>(istream& in){
  this->angajat::operator>>(in);

  return in;
}

operator_comenzi::operator_comenzi(
    const string& nume,
    const string& prenume,
    const cnp& cnp_angajat,
    const id<angajat>& id_angajat,
    const vector<comanda>& comenzi_manipulate
    ):
  angajat(nume, prenume, cnp_angajat, id_angajat),
  comenzi_manipulate(comenzi_manipulate),
  salariu(1){

  }

ostream& operator_comenzi::operator<<(ostream& out){
  out<<"3 ";
  this->angajat::operator<<(out);

  out<<comenzi_manipulate.size()<<" ";
  for(comanda i : comenzi_manipulate){
    i.operator<<(out);
  }

  return out;
}

istream& operator_comenzi::operator>>(istream& in){
  this->angajat::operator>>(in);

  int size; in>>size;

  for(int i = 0; i < size; i++){
    comenzi_manipulate.push_back(comanda());
    (--comenzi_manipulate.end())->operator>>(in);
  }

  return in;
}

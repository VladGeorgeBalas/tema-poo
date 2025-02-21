#include "angajat.hpp"

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

ostream& operator<<(ostream& out, angajat& src){
  out<<src.nume<<'\n';
  out<<src.prenume<<'\n';
  out<<src.data_angajare<<'\n';
  out<<src.cnp_angajat<<'\n';
  out<<src.id_angajat<<'\n';

  return out;
}

istream& operator>>(istream& in, angajat& dst){
  //aici ar trebui facute si niste verificari daca
  //utilizatorul manipuleaza manual salvarea, dar 
  //daca e manipulata doar de program, verificarea 
  //la initializare e suficienta

  in>>dst.nume;
  in>>dst.prenume;
  in>>dst.data_angajare;
  in>>dst.cnp_angajat;
  in>>dst.id_angajat;

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

asistent::asistent(
    const string& nume,
    const string& prenume,
    const cnp& cnp_angajat,
    const id<angajat>& id_angajat
    ):angajat(nume, prenume, cnp_angajat, id_angajat), salariu(0.75){}

#pragma once

#include <string.h>
#include <time.h>
#include <iostream>
#include "cod.hpp"

using namespace std;

class angajat;

static code<id<angajat>> clasa_id_angajat;
static code<cnp> clasa_cnp;

class salariu{
protected:
  static const unsigned int salariu_baza = 3500;
  float coeficient;

public:
  virtual float get_salariu() = 0;

  salariu(float coeficient):coeficient(coeficient){};
  ~salariu(){};
};

class angajat: virtual public salariu{
protected:
  //coduri
  id<angajat> id_angajat;
  cnp cnp_angajat;

  //detalii angajat
  time_t data_angajare = 0;

  //detalii personale
  string nume;
  string prenume;
public:
  angajat(
      const string&,
      const string&,
      const cnp&,
      const id<angajat>&
      );
  angajat(const angajat&);
  ~angajat() = default;

public:
  friend ostream& operator<<(ostream&, angajat&);
  friend istream& operator>>(istream&, angajat&);

public:
  float get_salariu() override;
};

class manager: public angajat, virtual public salariu{
public:
  manager(
      const string&,
      const string&,
      const cnp&,
      const id<angajat>&
      );
};

class asistent: public angajat, virtual public salariu{
public:
  asistent(
    const string&,
    const string&,
    const cnp&,
    const id<angajat>&
    );
};

class operator_comenzi: public angajat, virtual public salariu{
private:
  //vector<comanda>
};

#pragma once

#include <string.h>
#include <time.h>
#include <iostream>
#include "cod.hpp"
#include "comanda.hpp"

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

  salariu(float coeficient = 1):coeficient(coeficient){};
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
  angajat() = default;

  angajat(
      const string&,
      const string&,
      const cnp&,
      const id<angajat>&
      );
  angajat(const angajat&);
  ~angajat() = default;

public:
  virtual ostream& operator<<(ostream&);
  virtual istream& operator>>(istream&);

public:
  float get_salariu() override;
};

class manager: public angajat, virtual public salariu{
public:
  manager() = default;

  manager(
      const string&,
      const string&,
      const cnp&,
      const id<angajat>&
      );

  ostream& operator<<(ostream& out) override;
  istream& operator>>(istream& in) override;
};

class asistent: public angajat, virtual public salariu{
public:
  asistent() = default;

  asistent(
    const string&,
    const string&,
    const cnp&,
    const id<angajat>&
    );

  ostream& operator<<(ostream& out) override;
  istream& operator>>(istream& in) override;
};

class operator_comenzi: public angajat, virtual public salariu{
private:
  vector<comanda> comenzi_manipulate;

public:
  operator_comenzi() = default;

  operator_comenzi(
      const string&,
      const string&,
      const cnp&,
      const id<angajat>&,
      const vector<comanda>&
      );

  ostream& operator<<(ostream& out) override;
  istream& operator>>(istream& in) override;
};

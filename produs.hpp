#include <string.h>
#include "cod.hpp"

#pragma once

using namespace std;

class produs;

static code<id<produs>> clasa_id_produs;

//pentru numarul de produse, folosim o baza de date mare cu tuple-uri <produs, stoc>

class produs{
protected:
  string denumire;
  unsigned int pret;
  id<produs> id_produs;

public:
  produs() = default;
  produs(
      const string&,
      const unsigned int&,
      const id<produs>&
      );

  ~produs() = default;

public:
  virtual unsigned int get_pret() = 0;

public:
  virtual ostream& operator<<(ostream&);
  virtual istream& operator>>(istream&);
};

class articol_vestimentar: public produs{
private:
  string culoare;
  string marca;

public:
  articol_vestimentar() = default;
  articol_vestimentar(
      const string&,
      const unsigned int&,
      const id<produs>&,
      const string&,
      const string&
      );

public:
  unsigned int get_pret() override;

public:
  ostream& operator<<(ostream&) override;
  istream& operator>>(istream&) override;
};

class disc: public produs{
private:
  string tip_disc;  //aici mergea cu enum
  string casa_de_discuri;
  time_t data;
  string trupa;
  string nume_album;

public:
  disc() = default;
  disc(
      const string&,
      const unsigned int&,
      const id<produs>&,
      const string&,
      const string&,
      const time_t&,
      const string&,
      const string&
      );

public:
  unsigned int get_pret() override;

public:
  ostream& operator<<(ostream&) override;
  istream& operator>>(istream&) override;
};

class vintage: public produs{
private:
  bool mint;
  unsigned char coeficient_raritate; //aici mergea mai frumos cu enum
                                     
public:
  vintage() = default;
  vintage(
      const string&,
      const unsigned int&,
      const id<produs>&,
      const bool&,
      const unsigned char&
      );

public:
  unsigned int get_pret() override;

public:
  ostream& operator<<(ostream&) override;
  istream& operator>>(istream&) override;
};

#include "produs.hpp"

#pragma once

class comanda{
private:
  vector<produs*> produse_comanda;
  time_t primire;
  time_t finalizare;

public:
  comanda() = default;
  comanda(
      const vector<produs*>&,
      const time_t&,
      const time_t&
      );

public:
  bool check_validity();
  unsigned int get_price();
};

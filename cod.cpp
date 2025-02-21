#include "cod.hpp"
#include <iterator>

/* 
 *  Metode CNP
 * */

bool cnp::check_validity() const{
  if(value.length()!=13) return 0;

  string cnp_verificare = "279146358279";
  unsigned int suma_verificare = 0;

  for(unsigned int i = 0; i < 12; i++)
  {
    suma_verificare += (value[i] - '0') * (cnp_verificare[i] - '0');
  }
  suma_verificare = suma_verificare % 11; 

  if(suma_verificare < 10) return (value[12] - '0') == suma_verificare;
  else return 1 == suma_verificare;
}

bool operator==(const cnp& trg, const cnp& cmp){
  return trg.value == cmp.value;
}

bool operator>(const cnp& trg, const cnp& cmp){
 return trg.value > cmp.value;
}

istream& operator>>(istream& in, cnp& src){
  in>>src.value;

  if(!src.check_validity()) src.value = "0000000000000";

  return in;
}

ostream& operator<<(ostream& out, const cnp& src){
  out<<src.value;

  return out;
}

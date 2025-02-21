#pragma once

#include <iostream>
#include <vector>
#include <string.h>
#include <iterator>
#include <exception>

using namespace std;

template<typename CLASS>
class code{
private:
  //stocare coduri
  inline static vector<CLASS> taken_codes;
public:
  //constructori si destructori
  code() = default;
  code(const code&) = delete;
  ~code() = default;
public:
  //accesare
  bool check_availability(const CLASS& src){
    for(CLASS i: this->taken_codes){
      if( i == src)
        return 0;
  }

    return 1;
  };

public:
  //modificare
  const CLASS& append(const CLASS& src){
    if(!this->check_availability(src)){
      //throw exception("multiple entry");
      cout<<"multipla intrare";
    }
    else {
      this->taken_codes.push_back(src);
    }

    return src;
  };

  const CLASS remove(const CLASS& src){
    if(this->check_availability(src))
      //eroare:
      cout<<"nu exista intrarea";
    else {
      for(typename vector<CLASS>::iterator i = this->taken_codes.begin(); i != this->taken_codes.end(); i++)
        if(*i == src){
          this->taken_codes.erase(i);
          break;
        }
    }

    return src;
  };
};

class code_class{
public:
  friend bool operator==(const code_class&, const code_class&);
  friend bool operator>(const code_class&, const code_class&);
  //citire si scriere
  friend istream& operator>>(istream&, code_class&);
  friend ostream& operator<<(ostream&, code_class&);
  //destructor virtual
  virtual ~code_class(){};
};

template<typename name>
class id:public code_class{
private:
  unsigned int value;
public:
  id() = default;
  id(const unsigned int& src):value(src){};

  friend bool operator==(const id& trg, const id& cmp){
    return trg.value == cmp.value;
  }

  friend bool operator>(const id& trg, const id& cmp){
    return trg.value > cmp.value;
  }

  friend istream& operator>>(istream& in, id& src){
    in>>src.value;

    return in;
  }
  
  friend ostream& operator<<(ostream& out, id& src){
    out<<src.value;

    return out;
  }

  ~id() = default;
};

class cnp:public code_class{
private:
  string value;

public:
  bool check_validity() const;

  cnp() = default;
  cnp(const string& src){
    value = src;
    if(!this->check_validity())
      value = "0000000000000";
  };

  friend bool operator==(const cnp&, const cnp&);
  friend bool operator>(const cnp&, const cnp&);
  friend istream& operator>>(istream&, cnp&);
  friend ostream& operator<<(ostream&, const cnp&);

  ~cnp() = default;
};

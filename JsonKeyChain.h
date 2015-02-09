#ifndef JsonKeyChain_h
#define JsonKeyChain_h

#include "JsonKey.h"

//This number should not exceed 16
#define MAX_JSON_KEY_DEPTH 8

class JsonKeyChain {

public:
  JsonKeyChain();
  JsonKeyChain(const JsonKeyChain& old);
  JsonKeyChain & operator[](int );
  
  JsonKeyChain & operator[](const char *key);
  bool operator==(const JsonKeyChain& other);
  bool operator!=(const JsonKeyChain& other);
  void query();

  ~JsonKeyChain();

private:
  int counter;
  bool isDisposed;
  JsonKey * keysArray[MAX_JSON_KEY_DEPTH];
};

#endif
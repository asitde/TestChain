//
// Created by Dave Nash on 20/10/2017.
//

#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include<iostream>
#include<sstream>
#include<ctime>

class Block {

public:

  // Constructor
  Block(unsigned int nIndex, const std::string& rstrData);

  // Destructor
  ~Block();

public:

  void SetPreviousBlockHash(const std::string rstrPreviousBlockHash);

  std::string GetBlockHash();

  void MineBlock(unsigned int nDifficulty);

private:

  std::string CalculateHash() const;

private:

    unsigned int  _nIndex;
    std::string   _strHash;
    std::string   _strPreviousHash;
    unsigned int  _nNonce;
    std::string   _sData;
    time_t        _tTime;
};

#endif //TESTCHAIN_BLOCK_H

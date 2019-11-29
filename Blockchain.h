//
// Created by Dave Nash on 20/10/2017.
//

#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {

public:

  // Constructor
  Blockchain();

  void AddBlock(Block& rNewBlock);

private:
  Block GetLastBlock() const;

private:
  std::vector<Block>  _vChain;

private:

  static const int DIFFICULTY_LEVEL = 6;

};

#endif //TESTCHAIN_BLOCKCHAIN_H

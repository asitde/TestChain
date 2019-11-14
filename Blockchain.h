//
// Created by Dave Nash on 20/10/2017.
//

#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block bNew);

private:
    unsigned int _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};

#endif //TESTCHAIN_BLOCKCHAIN_H

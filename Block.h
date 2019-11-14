//
// Created by Dave Nash on 20/10/2017.
//

#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

//#include <cstdint>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

class Block {
public:
    string sHash;
    string sPrevHash;

    Block(unsigned int nIndexIn, const string &sDataIn);

    void MineBlock(unsigned int nDifficulty);

private:
    unsigned int _nIndex;
    unsigned int _nNonce;
    string _sData;
    time_t _tTime;

    string _CalculateHash() const;
};

#endif //TESTCHAIN_BLOCK_H

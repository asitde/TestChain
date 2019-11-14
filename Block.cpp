//
// Created by Dave Nash on 20/10/2017.
//

#include "Block.h"
#include "sha256.h"

Block::Block(unsigned int nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    _tTime = time(NULL);

    sHash = _CalculateHash();
}

void Block::MineBlock(unsigned int nDifficulty)
{
    char* cstr = new char[nDifficulty + 1];
    for (unsigned int i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);
    delete [] cstr;

    do
    {
        _nNonce++;
        sHash = _CalculateHash();
    }
    while (sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << sHash << endl;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;

    return sha256(ss.str());
}

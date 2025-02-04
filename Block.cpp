//
// Created by Dave Nash on 20/10/2017.
//

#include "Block.h"
#include "sha256.h"

Block::Block(unsigned int nIndex, const std::string& strData)
:_nIndex(nIndex),
_strHash(""),
_strPreviousHash(""),
_nNonce(0),
_sData(strData),
_tTime(time(NULL))
{}

Block::~Block()
{}

void Block::SetPreviousBlockHash(const std::string rstrPreviousBlockHash)
{
  _strPreviousHash = rstrPreviousBlockHash;
}

std::string Block::GetBlockHash()
{
  return _strHash;
}

void Block::MineBlock(unsigned int nDifficulty)
{
  std::string str(nDifficulty,48);

  // Reset the nonce
  _nNonce = 0;

  time_t tTimeStart = time(NULL);
  do
  {
    _nNonce++;
    _strHash = CalculateHash();
    //std::cout <<_strHash << std::endl;
  }
  while(_strHash.substr(0, nDifficulty) != str);
  time_t tTimeEnd = time(NULL);

  std::cout << "Block mined: " << _strHash << "Time taken: " << (tTimeEnd-tTimeStart) << "seconds" << std::endl;

}

std::string Block::CalculateHash() const
{
  std::stringstream ss;
  ss << _nIndex << _strPreviousHash << _tTime << _sData << _nNonce;

  return sha256(ss.str());
}

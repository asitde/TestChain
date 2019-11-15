//
// Created by Dave Nash on 20/10/2017.
//

#include "Blockchain.h"

Blockchain::Blockchain()
:_nDifficulty(DIFFICULTY_LEVEL)
{
  _vChain.push_back(Block(0, "Genesis Block"));
}

void Blockchain::AddBlock(Block& rNewBlock)
{
  rNewBlock.SetPreviousBlockHash(GetLastBlock().GetBlockHash());
  rNewBlock.MineBlock(_nDifficulty);
  _vChain.push_back(rNewBlock);
}

Block Blockchain::GetLastBlock() const
{
  return _vChain.back();
}

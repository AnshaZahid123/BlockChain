#include"Block.h"
#include<iostream>
#include<sstream>
#include <bits/stdc++.h>
class BlockChain{
private:
    Block *genesisBlock;

    Block *current;

public:
    void addBlock(std::string value);
    std::string getTimeStamp();
    std::string calculateHash(std::string data,std::string timestamp,std::string previousHash);
    void printChain();

};

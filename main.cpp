#include <iostream>
#include"BlockChain.cpp"

int main()
{
    BlockChain b;
    std::string strdata="This is block 1";
   // std::string str=b.getTimeStamp();
   // std::cout<<b.calculateHash(strdata, str,"");
    b.addBlock(strdata);
    b.addBlock("This is block 2");
    b.addBlock("This is block 3");
    //b.printChain();
    return 0;
}

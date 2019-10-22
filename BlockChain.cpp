#include"Blockchain.h"
#include "sha256.cpp"
#include <string>
#include<sstream>
std::string BlockChain::calculateHash(std::string data,std::string timestamp,std::string previousHash)
{
    int d = std::atoi (data.c_str());  //converting string values into integer for addition
    int t = std::atoi (timestamp.c_str());
    int p = std::atoi (previousHash.c_str());
    int h =(d+t+p);
    std::stringstream ss; //converting integer into string for calculating hash
    ss<<h;
    std::string s;
    ss>>s;
    std::cout<<s;
    /*std::string str;
    str.append(data);
    str.append(timestamp);
    str.append(previousHash);*/
    return sha256(s);
}
std::string BlockChain:: getTimeStamp(){
    time_t now = time(0);
   // convert now to string form
   char* dt = ctime(&now);
   return dt;
}
void BlockChain::addBlock(std::string data)
{


    if(genesisBlock->data=="\0")
    {
        std::cout<<"jhj";
		genesisBlock->data=data;
        genesisBlock->timestamp = getTimeStamp();
        genesisBlock->previousHash="";
        genesisBlock->Hash=calculateHash(data,genesisBlock->timestamp,genesisBlock->previousHash);
        genesisBlock->next=NULL;
		
    }
    else{
        Block *temp = new Block;
        current=genesisBlock;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        temp->data=data;
        temp->timestamp = getTimeStamp();
        temp->previousHash=current->Hash;
        temp->Hash=calculateHash(data,temp->timestamp,temp->previousHash);
        temp->next=NULL;
        current->next=temp;

    }
}
void BlockChain::printChain()
{
        int i=0;
        Block *temp = new Block;
        temp=genesisBlock;

        while(temp!=NULL)
        {
            std::cout<<"Block"<<++i<<"\nData:"<<temp->data<<"\n";
            //std::cout<<"Hash:"<<temp->Hash<<"\n";
            //std::cout<<"Previous Hash:"<<temp->previousHash<<"\n";
            temp=temp->next;
        }


}

#include<iostream>
#include <ctime>
struct Block{

        std::string data;
        std::string Hash;
        std::string previousHash;
        std::string timestamp;
        Block *next;
};

#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    // TODO
    previousHash = _previousHash;
}

string Block::calculateHash() {
    // TODO
    stringstream hashstream;

    // nonce is added to stream, then previous hash, then timestamp, then values of transactions
    
    hashstream << nonce << previousHash << timestamp;

    int vectorSize = transactions.size();

    for (int i = 0; i < vectorSize; i++) {

        hashstream << transactions[i].toString();

    }

    return sha256(hashstream.str()); 

}

void Block::mineBlock(unsigned int difficulty) {
    // TODO

    bool flag = false;

    while (flag == false) {

        nonce++;

        string importantString = calculateHash();

        string importantSubString = importantString.substr(0,difficulty);

        bool flag2 = false;

        for (unsigned int i = 0; i < difficulty; i++) {

            if (importantSubString[i] != '0') {

                flag2 = true;

            }

        }

        if (flag2 == false) {

            hash = importantString;

            flag = true;

        }

    }

}

string Block::toString() {
    // TODO
    stringstream streamData; 
    streamData << "Nonce: " << nonce << " PreviousHash: " << previousHash << " TimeStamp: " << timestamp << " Hash: " << hash << " Transaction Data: ";
    for (int i = 0; i < transactions.size(); i++) {
        streamData << transactions[i].toString();
    }
    return streamData.str();
}

vector<Transaction> Block::returnTransactionVector() {
    return transactions;
}

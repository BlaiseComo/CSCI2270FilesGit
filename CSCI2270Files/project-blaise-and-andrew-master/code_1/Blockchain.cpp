#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    //Transaction freeMoney("BFC","make money by mining",0);
    //pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // TODO

    int importantBalance = getBalanceOfAddress(src);

    if (importantBalance >= coins) {

        Transaction newTransaction(src, dst, coins);

        pending.push_back(newTransaction);

    }

    else cout << "Could Not Add Transaction" << endl;

}

bool Blockchain::isChainValid() { 
    // TODO
    
    for (int i = 1; i < chain.size(); i++) {

        if (chain[i-1].returnHash() != chain[i].returnPreviousHash()) {

            return false;

        }

        for (int x = 0; x < difficulty; x++) {

            if (chain[i].returnHash()[x] != '0') {

                return false;

            }

        }

    }

    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO

    Block newBlock(pending, time(nullptr), getLatestBlock().returnHash());

    newBlock.mineBlock(difficulty);

    pending.clear();

    chain.push_back(newBlock);

    Transaction rewardTransaction("BFC", minerAddress, miningReward);

    pending.push_back(rewardTransaction);

    return true;

}

int Blockchain::getBalanceOfAddress(string address) {
    // TODO

    int balance = 0;

    for (int i = 0; i < chain.size(); i++) {

        vector<Transaction> lolvector = chain[i].returnTransactionVector();

        for (int x = 0; x < lolvector.size(); x++) {

            if (lolvector[x].getReceiver() == address) {

                balance += lolvector[x].getAmount();

            }
            
            if (lolvector[x].getSender() == address) {

                balance -= lolvector[x].getAmount();

            }

            if (balance < 0) {

                cout << "ERROR IN FINDING BALANCE" << endl;

            }

        }

    }
    return balance;
}

void Blockchain::prettyPrint() {
    // TODO
    for (int i = 0; i < chain.size(); i++) {
        cout << chain[i].toString() << endl;
    }
    cout << endl;
}
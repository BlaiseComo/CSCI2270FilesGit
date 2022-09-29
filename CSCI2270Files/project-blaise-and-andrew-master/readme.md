# CSCI 2270 – Data Structures - Final Project 

Start by carefully reading the write-up contained in `CSCI2270_Spring22_Project.pdf`.

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. Also, include the names of the team-members/authors.

Team Members: 
Andrew Truong
Blaise Como

User-Interface: 
The user_interface.cpp file is an interactive way to use the blockchain system, it allows the user to make transactions, verify the blockchain is valid, mine blocks, visualize the blockchain, and get the balance of a certain user, if someone is not a user there balance will be zero. To use the interface, simply input the number corresponding to the procedure.

Making a transaction:
The user is asked who wants to send the money, who wants to receive the money, and the amount of money to be sent. This will then go into the pending transcations until a new block is mined.

Verifying the blockchain:
This checks if the blocks in the chain are valid and connected by comparing the previous hash of a block to the actual hash of the previous block.

Mine blocks:
The user is asked who wants to mine a block. After a block is mined, the person mining the block receives 10 bitcoins, and all pending transactions are finalized. The block is then added to the block chain.

Visualizing the blockchain:
This prints out the nonce, the previous hash, the time stamp, and all the transactions for each block of the chain.

Get balance of user:
This prints the balance of a person.







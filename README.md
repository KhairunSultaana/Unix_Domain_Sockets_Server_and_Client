# Unix_Domain_Sockets_Server_and_Client
Server Client Program

Unix Domain Sockets Server and Client
This repository contains the C++ code for a server and client using Unix domain sockets. The server accepts requests on port 5005 and adds two integers sent from the client. The client sends two integers to the server and receives the sum back from the server.

How to Run
Save the code as server.cpp and client.cpp.
Compile the code with the following commands:
g++ -o server server.cpp
g++ -o client client.cpp


3. Run the server with the following command:

./server


4. Run the client with the following command:

./client

The client will print the sum of the two integers.

Makefile
A makefile is also included to compile the code. To use the makefile, save it as Makefile and then run the following command:

make
This will compile the server and client executables. You can then run the server and client with the following commands:

./server
./client

Author 

Khairun Sultaana Shaik

License
This code is licensed under the MIT License.

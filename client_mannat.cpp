// Client side C/C++ program to demonstrate Socket programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <iostream>
// #include <bits/stdc++.h>
#include <unistd.h>
#define PORT 8080


using namespace std;

int main(int argc, char const* argv[])
{
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    cout << "\n=> Socket client has been created..." << endl;


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((client_fd= connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr)))< 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    try{
    while (true){
    string inp;
    cout<<"Person1: ";
    getline(cin,inp);

    send(sock, inp.c_str(), strlen(inp.c_str()), 0);
    printf("                                                    delivered \n");
    char buffer[1024] = { 0 };
    cout << "Person2: ";
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
    }
    }
    catch(const std::exception& e)
    {
        // closing the connected socket
            close(client_fd);
            return 0;
}
    }
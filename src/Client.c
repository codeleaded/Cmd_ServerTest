#include "/home/codeleaded/System/Static/Library/Networking.h"


#define SIGNAL_MSG  (SIGNAL_START + 0)

void Client_Proc_Connect(Vector* signalhandlers,Client* c,void* data,int size){
    printf("Client_Connect: %d\n",c->sockfd);
}
void Client_Proc_Disconnect(Vector* signalhandlers,Client* c,void* data,int size){
    printf("Client_Disconnect: %d\n",c->sockfd);
}
void Client_Proc_Msg(Vector* signalhandlers,Client* c,void* data,int size){
    printf("Client_Msg: %d\n",c->sockfd);
}

int main(){
    Client s = Client_Make(5000,"192.168.2.99",(SignalHandler[]){
        SignalHandler_New(SIGNAL_CONNECT,(void (*)(void*,void*,void*,int))Client_Proc_Connect),
        SignalHandler_New(SIGNAL_DISCONNECT,(void (*)(void*,void*,void*,int))Client_Proc_Disconnect),
        SignalHandler_New(SIGNAL_MSG,(void (*)(void*,void*,void*,int))Client_Proc_Msg),
        SignalHandler_Null()
    });

    while(1){
        //char buffer[1024];
        //int size = scanf("%1023s",buffer);
        //Client_Signal_Send(&s,SIGNAL_MSG,buffer,size);

        Client_Update(&s);
        Client_DoAll(&s);

        printf("Waiting...\n");
        Thread_Sleep_M(1000);
    }
    
    Client_Free(&s);
    return 0;
}
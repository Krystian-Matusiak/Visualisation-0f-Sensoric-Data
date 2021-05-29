// Biblioteki

#include <QPainter>
#include <QMainWindow>
#include <QPushButton>
#include <QBrush>
#include <QStatusBar>

#include "mainwindow.h"

using namespace std;

// ////////////////////////////////////////////////////////////////////////////





Receiver *receive = new Receiver;
Transmitter *transmit = new Transmitter;

void *Petla_odbiornika(void *){
  receive->UruchomServer(PORT_REC);
  return NULL;
}

void *Petla_nadajnika(void*){
  transmit->SocketConfig(PORT_TRAN);
  return NULL;
}


int main(int argc, char *argv[]){

    pthread_t            Watek_odbiornika;
    pthread_t            Watek_nadajnika;
    pthread_create(&Watek_odbiornika,NULL,Petla_odbiornika,0L);
    pthread_create(&Watek_nadajnika,NULL,Petla_nadajnika,0L);



    QApplication App (argc, argv);
    MainWindow *Wind = new MainWindow(receive->DSens,receive->DSilniki, transmit);

    Wind->show();
    Wind->setBackground();


    int end = App.exec();

    pthread_cancel(Watek_odbiornika);
    pthread_cancel(Watek_nadajnika);
    pthread_join      (Watek_odbiornika,NULL);
    pthread_join      (Watek_nadajnika,NULL);


    return end;
}

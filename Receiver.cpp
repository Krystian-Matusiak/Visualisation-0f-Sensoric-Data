


#include "Receiver.h"



int Receiver::Odbierz(int GnOdbioru){
  ssize_t  IZ;

   while ( IZ = read(GnOdbioru,DANA, ROZM*sizeof(char) ) > 0 ){

       for(int i=0 ; i<3 ; i++){
        paczka_danych[0][i]=DANA[i];
        paczka_danych[1][i]=DANA[i+3];
        paczka_danych[2][i]=DANA[i+6];
        paczka_danych[3][i]=DANA[i+9];
        paczka_danych[4][i]=DANA[i+12];
        paczka_danych[5][i]=DANA[i+15];
      }

       // Przyjmowanie danych PWM1 i PWM2
      for( int i=0 ; i<3 ; i++ ){
          paczka_danych[6][i]=DANA[i+18];
          paczka_danych[8][i]=DANA[i+22];
      }

      // Przyjmowanie danych DIR1 i DIR2
      paczka_danych[7][0]=DANA[21];
      paczka_danych[9][0]=DANA[25];

      // Przyjmowanie danej BATT
      for(int i=0 ; i<4 ; i++)
        paczka_danych[10][i]=DANA[i+26];

      DSilniki.setPWM1(paczka_danych[6]);
      DSilniki.setPWM2(paczka_danych[8]);

      DSilniki.dir_motor1 = paczka_danych[7][0]-48;
      DSilniki.dir_motor2 = paczka_danych[9][0]-48;

      DSens.setSensors(paczka_danych);
      DSens.setBatt(paczka_danych[10]);

   }

  return 0;
}


int Receiver::UruchomServer(int Port){
  int  GnNasluchu;
  int  GnPolaczenia;
  struct sockaddr_in    cli_addr, serv_addr;
  socklen_t  ClAddrLen;

  if ((GnNasluchu = socket(AF_INET,SOCK_STREAM,0)) < 0) return -1;

  bzero((char *)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(Port);
  if (bind(GnNasluchu,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
    return -2;
  }

  ClAddrLen = sizeof(cli_addr);

   if (listen(GnNasluchu,5) < 0)  return -3;

   while (1) {
    GnPolaczenia = accept(GnNasluchu,(struct sockaddr *)&cli_addr,&ClAddrLen);
    if (GnPolaczenia < 0) return -4;
    if (this->Odbierz(GnPolaczenia)) break;

    close(GnPolaczenia);
   }
  close(GnNasluchu);
}

















#include "Transmitter.h"



int Transmitter::Nadaj(int Sk2Client, char DANA[100]){  //const  char Napis[8][301])
  ssize_t  IlWyslanych;
  ssize_t IlDoWyslania = ROZM_TRAN*sizeof(char);

    IlWyslanych = write(Sk2Client , DANA, ROZM_TRAN*sizeof(char) );

    if (IlWyslanych < 0){
    cerr<<"***ERROR*****"<<endl;
  }

}


int Transmitter::SocketConfig(int Port){

    int                 GnNadawania;
    struct sockaddr_in  DaneAdSerw;

    bzero((char *)&DaneAdSerw,sizeof(DaneAdSerw));
    DaneAdSerw.sin_family = AF_INET;
    DaneAdSerw.sin_addr.s_addr = inet_addr("192.168.8.104");
    //DaneAdSerw.sin_addr.s_addr = inet_addr("10.11.14.136");
    DaneAdSerw.sin_port = htons(Port);

    GnNadawania = socket(AF_INET,SOCK_STREAM,0);
    if (GnNadawania < 0) {
       cerr << "*** Blad otwarcia gniazda." << endl;
       return 1;
    }
    if (connect(GnNadawania,(struct sockaddr*)&DaneAdSerw,sizeof(DaneAdSerw)) < 0){
       cerr << "*** Brak mozliwosci polaczenia do portu: " << Port << endl;
       return 1;
     }

    // Dane po kolei: PWM1 DIR1 PWM2 DIR2 BATT MODE
    char DANA[ROZM_TRAN] = "        ";



    string pwm1;
    string pwm2;
    string dir1;
    string dir2;
    string batt;
    string mode;


    do {

        pwm1 = to_string( tab_danych[0] );
        pwm2 = to_string( tab_danych[2] );

        dir1 = to_string( tab_danych[1] );
        dir2 = to_string( tab_danych[3] );

        mode = to_string( tab_danych[5] );



      strcpy(DANA+0,  pwm1.c_str());
      strcpy(DANA+3,  dir1.c_str());
      strcpy(DANA+4,  pwm2.c_str());
      strcpy(DANA+7,  dir2.c_str());
      strcpy(DANA+8,  mode.c_str());

      //cout << DANA[0] << DANA[1] << DANA[2] << DANA[3] << DANA[4] << DANA[5] << endl;
      //cout << "cala dana=" << DANA << endl;
      Nadaj(GnNadawania,DANA);
      usleep(50000);
    } while (1);

    close(GnNadawania);

}



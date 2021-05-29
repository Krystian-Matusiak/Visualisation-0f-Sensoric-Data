#include <iostream>
#include <iomanip>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <typeinfo>
#include <cstdlib>
#include <string>
#include <unistd.h>

#define PORT_TRAN          6001
//# define ROZM_NAPISU    30

using namespace std;

#include "DaneSensoryczne.h"
#include "DaneSilnikowe.h"


/*! \brief Klasa odpowiadająca za nadawanie danych do innego urządzenia. */

class Transmitter{

public:

    /*! Funkcja odpowiadająca za nadawanie danych poprzez socket.
        \param[in] GnOdbioru - deskryptor gniazda.
     */
    int Nadaj(int Sk2Client, char DANA[100]);

    /*! Funkcja aktywująca stan "nasłuchiwania". Gdy dane się pojawią, aktywowana jest funkcja Odbierz, aby przyjąć dane.
        \param[in] Port - zmienna, która odnosi się do otworzonego portu komunikacyjnego.
     */
    int SocketConfig(int Port);



    /*! Zmienna, przechowująca kolejno: PWM pierszego silnika, kierunek pierwszego silnika, PWM drugiego silnika, kierunek drugiego silnika oraz tryb ruchu (1-tryb ręczny, 0-tryb automatyczny) */
    int tab_danych[6];


};













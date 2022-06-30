#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <unistd.h>


#define ZN_KROTKI             4
#define ZN_DLUGI              8
#define MARGINES             10
#define ODSTEP_ZNAKU         16
#define PRZESUNIECIE_X        3

#define WSKSEK_D              8
#define PORT            6000
#define PORT_REC   6000

#include "DaneSensoryczne.h"
#include "DaneSilnikowe.h"

/*! \brief Klasa odpowiadająca za otrzymywanie danych z innego urządzenia. */

class Receiver{

public:

    /*! Funkcja odpowiadająca za odbieranie danych i przypisanie ich do konkretnych klas.
        \param[in] GnOdbioru - deskryptor gniazda.
     */
    int Odbierz(int GnOdbioru);

    /*! Funkcja aktywująca stan "nasłuchiwania". Gdy dane się pojawią, aktywowana jest funkcja Odbierz, aby przyjąć dane.
        \param[in] Port - zmienna, która odnosi się do otworzonego portu komunikacyjnego.
     */
    int UruchomServer(int Port);


    /*! Zmienna, do której przekazywany będzie ciąg znaków, przesyłany przez socket'y. */
    char DANA[ROZM];

    /*! Zmienna, które przechowują 6 danych czujnikowych, wypełnienie sygnału PWM dla każdego z dwóch silników, kierunek obrotu tych silników oraz stopień naładowania akumulatora. */
    char paczka_danych[11][ROZM];

    /*! Klasa, do której zapisywane będą dane sensoryczne, otrzymane z komunikacji */
    DaneSensoryczne DSens;

    /*! Klasa, do której zapisywane będą dane silnikowe, otrzymane z komunikacji */
    DaneSilnikowe DSilniki;

};









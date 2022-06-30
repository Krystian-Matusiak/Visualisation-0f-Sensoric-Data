#ifndef DANESENSORYCZNE_H
#define DANESENSORYCZNE_H



#include <string>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPalette>

#define ROZM 30
#define ROZM_TRAN 10




/*! \brief Klasa przechowująca dane dotyczące wykonanych pomiarów (czujniki i bateria). */

class DaneSensoryczne{

    public:

        /*! Uzupełnia dane pobrane z czujników odbiciowych.
            \param[in] parse_sensors - zestaw danych, przechowujących informacje o odczytach z czujników.
         */
        void setSensors(char parse_sensors[11][ROZM]);

        /*! Wypełnia daną, związaną z poziomem naładowania akumulatora
            \param[in] parse_batt - tablica, przechowująca dane o aktualnym napięciu akumulatora.
         */
        void setBatt(char parse_batt[4]);



        /*! Wartości wszystkich czujników odbiciowych */
        double CzujnikiOdb[6];

        /*! Zmienna, przechowująca dane o poziomie naładowania baterii */
        double batt ;
};

#endif // DANESENSORYCZNE_H



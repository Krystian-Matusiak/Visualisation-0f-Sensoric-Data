#ifndef DANESILNIKOWE_H
#define DANESILNIKOWE_H



#include <string>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPalette>

#define ROZM 30
#define ROZM_TRAN 10

#define sample 40


/*! \brief Klasa przechowująca dane dotyczące silników. */

class DaneSilnikowe{

    public:

        /*! Funkcja odpowiadająca za pobranie danej, dotyczącej wartości wypełnienia PWM dla silnika 1 (lewego).
            \param[in] parse_pwm1 - tablica zmiennych typu charakter; jest to dana przetrzymujące informacje o wypełnieniu sygnału PWM dla lewego silnika.
         */
        void setPWM1(char parse_pwm1[3]);

        /*! Funkcja odpowiadająca za pobranie danej, dotyczącej wartości wypełnienia PWM dla silnika 2 (prawego).
            \param[in] parse_pwm2 - tablica zmiennych typu charakter; jest to dana przetrzymujące informacje o wypełnieniu sygnału PWM dla prawego silnika.
         */
        void setPWM2(char parse_pwm2[3]);

        /*! Funkcja przetrzymująca i aktualizująca tablicę danych z wypełnieniem sygnału PWM silnika lewego. Następnie tablica wykorzystywana jest do wygenerowania wykresu, poprzez
         *  dopisywanie nowej wartości na koniec tablicy i usuwanie pierwszej wartości.
            \param[in] new_val - wartość, która będzie wpisywana na koniec tablicy.
         */
        void newPlotY(double *new_val);

        /*! Funkcja przetrzymująca i aktualizująca tablicę danych z wypełnieniem sygnału PWM silnika prawego. Następnie tablica wykorzystywana jest do wygenerowania wykresu, poprzez
         *  dopisywanie nowej wartości na koniec tablicy i usuwanie pierwszej wartości.
            \param[in] new_val - wartość, która będzie wpisywana na koniec tablicy.
         */
        void newPlotZ(double *new_val);


        //char info1[11][ROZM];

        /*! Wielkość, określają stan wypełnienia sygnału PWM (pulse width modulation) w procentach [%] */
        double *pwm1=new double;

        /*! Wielkość, określają stan wypełnienia sygnału PWM (pulse width modulation) w procentach [%] */
        double *pwm2=new double;

        /*! Zmienne, dotyczące kierunku jazdy (false - jazda w tył, true - jazda w przód) */
        bool dir_motor1=false;

        /*! Zmienne, dotyczące kierunku jazdy (false - jazda w tył, true - jazda w przód) */
        bool dir_motor2=false;

        /*! Zbiór wartości dla wykresów PWM pierwszego silnika */
        double plotY[sample];

        /*! Zbiór wartości dla wykresów PWM pierwszego silnika */
        double plotZ[sample];
};


#endif // DANESILNIKOWE_H






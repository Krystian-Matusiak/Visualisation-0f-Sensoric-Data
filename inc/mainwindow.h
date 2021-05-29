#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include "Receiver.h"
#include "Transmitter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//#define sample 7
//#define ROZM 36





// //////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Klasa określa główne okienko aplikacje. W nim są wszystkie funkcje dotyczące wyświetlania. */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( DaneSensoryczne *DSENSORYCZNE , DaneSilnikowe *DSILNIKOWE , Transmitter * transmit , QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    /*! Funkcja wyświetlająca dane czujnikowe w tabelii.
        \param[in] c1 - wartość odczytana z czujnika 1.
        \param[in] c2 - wartość odczytana z czujnika 2.
        \param[in] c3 - wartość odczytana z czujnika 3.
        \param[in] c4 - wartość odczytana z czujnika 4.
        \param[in] c5 - wartość odczytana z czujnika 5.
        \param[in] c6 - wartość odczytana z czujnika 6.
     */
    void setSensor_data_label(int c1, int c2, int c3, int c4, int c5, int c6);

    /*! Funkcja wyświetlająca dane dot. silników w tabelii.
        \param[in] dir1 - kierunek obrotu pierwszego silnika.
        \param[in] pwm1 - wypełnienie PWM dla pierwszego silnika.
        \param[in] dir2 - kierunek obrotu drugiego silnika.
        \param[in] pwm2 - wypełnienie PWM dla drugiego silnika.
     */
    void setMotor_data_label(int dir1, int pwm1, int dir2, int pwm2);

   // void GdyNapis(const QString &Napis);

    /*! Funkcja "nasłuchująca" dane oraz wykonująca się w nieskończoność, w celu ciągłej aktualizacji danych dot. czujników. */
    void GdySekunda();

    /*! Funkcja konfigurująca wygląd tła aplikacji. */
    void setBackground();

    /*! Funkcja przedstawiająca wizualnie kierunek i prędkość kół za pomocą strzałek, zmieniających swój rozmiar.
        \param[in] pwm_left - zmienna przechowująca informacje o wypełnieniu PWM lewego silnika.
        \param[in] pwm_right - zmienna przechowująca informacje o wypełnieniu PWM prawego silnika.
        \param[in] dir_left - zmienna przechowująca informacje o kierunku lewego silnika.
        \param[in] dir_right - zmienna przechowująca informacje o kierunku prawego silnika.
     */
    void setArrows(double pwm_left , double pwm_right , bool dir_left , bool dir_right);

    /*! Funkcja wyświetlająca dane dot. silników w tabelii. */
    void setButtons();

    /*! Funkcja konfigurująca wygląd tabel itp (np. ustawienie poziomu przezroczystości). */
    void setLabels();

    /*! Funkcja przedstawiająca wizualnie stan naładowania akumulatora.
        \param[in,out] battery_state - przetrzymuje informacje o aktualnym stanie baterii.
     */
    void setBattery(double *battery_state);


    /*! Funkcja, wykonująca się podczas naciśnięcia przycisku. Powoduje wysłanie do robota sygnału, powodującego skręt w prawo. */
    void RightB_Clicked();

    /*! Funkcja, wykonująca się podczas naciśnięcia przycisku. Powoduje wysłanie do robota sygnału do robota, powodującego skręt w lewo. */
    void LeftB_Clicked();

    /*! Funkcja, wykonująca się podczas naciśnięcia przycisku. Powoduje wysłanie do robota sygnału, powodującego jazdę do przodu. */
    void UpB_Clicked();

    /*! Funkcja, wykonująca się podczas naciśnięcia przycisku. Powoduje wysłanie do robota sygnału, powodującego jazdę do tyłu. */
    void DownB_Clicked();

    /*! Funkcja, powodująca przełączanie trybów poruszania się. Dostępne są sterowanie automatyczne oraz ręczne. */
    void ChangeModeB_Clicked();

    /*! Funkcja, wykonująca się podczas puszczenia przycisku. Powoduje zakończenie ruchu (zatrzymuje robota). */
    void RightB_Released();

    /*! Funkcja, wykonująca się podczas puszczenia przycisku. Powoduje zakończenie ruchu (zatrzymuje robota). */
    void LeftB_Released();

    /*! Funkcja, wykonująca się podczas puszczenia przycisku. Powoduje zakończenie ruchu (zatrzymuje robota). */
    void UpB_Released();

    /*! Funkcja, wykonująca się podczas puszczenia przycisku. Powoduje zakończenie ruchu (zatrzymuje robota). */
    void DownB_Released();

private slots:

    /*! Funkcja ustawiająca najistotniejsze konfiguracje wykresu.*/
    void setPlot();


    /*! Funkcja generująca wykres.*/
    void makePlot();

    /*! Funkcja generująca graf słupkowy, informujący o danych czujnikowych z transoptoprów.
        \param c1 - wartość odczytana z czujnika 1.
        \param[in] c2 - wartość odczytana z czujnika 2.
        \param[in] c3 - wartość odczytana z czujnika 3.
        \param[in] c4 - wartość odczytana z czujnika 4.
        \param[in] c5 - wartość odczytana z czujnika 5.
        \param[in] c6 - wartość odczytana z czujnika 6.
     */
    void makeGraph(double c1, double c2, double c3, double c4, double c5, double c6);

private:
    Ui::MainWindow *ui;

    QTimer       _Sekundnik;

    DaneSensoryczne *DaneSen;
    DaneSilnikowe *DaneSil;
    Transmitter * transmitter;

};
#endif // MAINWINDOW_H









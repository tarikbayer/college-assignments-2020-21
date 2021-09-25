/* Dateiname: EVKD.h:
Enthält das Hauptprogramm laut Aufgabenstellung

AD-Praktikum SoSe 2021
Gruppe: 20
Schmidt, Nicole, Mat.-Nr.: 11148335
Bayer, Tarik, Mat.-Nr.: 11149643
Abgabe am: 21.6.21
Praktikumsblatt: 2.1
Compiler Flags: -
Linker libraries/options: -
*/
#ifndef EVKD_H
#define EVKD_H


class EVKD
{
    public:
        EVKD();
        EVKD(char * LPSZDaten, EVKD * N);

        char * getDaten() const;
        EVKD * getNext();
        void setNext(EVKD * N);

        bool operator > (EVKD &e);
        bool operator == (EVKD &e);

        virtual ~EVKD();

    protected:

    private:
        char * Daten;
        //wird noch nicht benutzt
        int Anz;
        EVKD * Next;

    friend class QUEUE;
};

#endif // EVKD_H

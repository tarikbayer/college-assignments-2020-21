/* Dateiname: QUEUE.h:
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
#ifndef QUEUE_H
#define QUEUE_H
#include "EVKD.h"

class QUEUE
{
    public:
        QUEUE();

        void queueIn(char * InText);
        char * queueOut();
        void einfuegeSortiert (EVKD * In, int Max);
        EVKD * loesche(int Pos);
        void iSort();
        void zeigDich();
        virtual ~QUEUE();

    protected:

    private:
        EVKD * Enter;
        EVKD * sorted;
        int Anz;
};

#endif // QUEUE_H

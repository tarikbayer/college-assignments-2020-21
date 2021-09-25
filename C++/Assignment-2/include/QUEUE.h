
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


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
        //is not used yet
        int Anz;
        EVKD * Next;

    friend class QUEUE;
};

#endif // EVKD_H

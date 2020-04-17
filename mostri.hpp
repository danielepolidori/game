#ifndef MOSTRI_HPP
#define MOSTRI_HPP
#include "bot.hpp"


class mostri : public bot
{
    protected:
        int res, tm, cd1, cd2, cd3;
    public:
        mostri(int t, int s, int l, int m);
        ~mostri();
        void tip_m(); ///dà nome, lvl e exp al personaggio in base al tipo
        int azione();       ///decide quale mossa usare
        int turno_m(int dmg, bool st, bool dt );    ///effettua il turno del mostro

        ///stampe
        void stp_cd();  ///stampa cd mosse
        void stp_comb();///stampa usata nel combattimento

        ///controlli
        void contr_cd();    ///diminuisce il cd ad ogni turno
        void resuscita();   ///fa ritornare al massimo la vita e resetta i cd alla fenice
        void cura_ossa();   ///ricura lo scheletro gigante ad ogni turno
        void barr_streg();  ///ogni 4 turni la barriera dello stregone si riforma



};

#endif // MOSTRI_HPP

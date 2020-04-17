#ifndef BOT_HPP
#define BOT_HPP
#include <string>
class bot {
	protected:
		int x, y, hp, hpm, atk, lvl, def, exp, dstun, ddtempo, daum_dif, daum_atk, barr, dcura;
		std::string n;
			     //variabili stat giocatore
	public:
        bot ();     ///costruttore
        ~bot();     ///distruttore
        int getx(); ///ritorna il valore di x
        int gety(); ///ritorna il valore di y
        std::string getn(); ///ritorna nome
        int expp();             ///ritorna l'esperienza
        void tk_damage(int dan);///diminuisce la vita del valore in input - la difesa

        ///stampe
        void statb();   ///stampa lo stato del bot

        ///controlli
        bool morte();               ///restituisce un booleano(0=vivo,1=morto)
        bool contr_stun();           ///diminuisce lo stun di un turno
        void get_dtempo(bool s);    ///diminuisce la vita se n è ferito
        bool dtempo_att();          ///controlla se n ha ferito l'altro personaggio
        void contr_dif();           ///dimezza la difesa quando daum_dif torna a 0
        void contr_atk();           ///dimezza l'attacco quando daum_atk torna a 0
        void contr_cur();           ///aumenta hp

        ///mosse
        int att_base();         ///restituisce atk
        int dtempo(int *cd);    ///restituisce atk e mette ddtempo a 2
        int stun(int *cd);      ///restituisce atk e mette dstun a 2
        int att_pot(int *cd);   ///restituisce atk+atk*50%
        int aum_dif(int *cd);   ///raddoppia attacco e mette daum_dif a 2
        int aum_atk(int *cd);   ///raddoppia attacco e mette daum_atk a 2
        int barriera(int *cd);  ///attiva la barriera
        int cura(int *cd);      ///mette cur a 3

};
#endif // BOT_HPP

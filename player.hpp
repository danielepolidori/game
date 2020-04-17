#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include "bot.hpp"


class player:public bot {
	protected:
		int ps, expm, cd1, cd2, cd3, cd4, cd5, cd6, cd7;
        bool a1, a2, a3, a4, a5, a6, a7, chatk;

	public:
		player(std::string name);	///costruttore
        ~player();          ///distruttore
        void gexp(int n);   ///aumenta exp di un valore in input
	int glvl();		///ritorna livello attuale giocatore
        int azione();       ///decisione mossa da usare
        int turno_p(int dmg, bool st, bool dt); ///effettua turno giocatore
        void lvl_up();      ///aumenta di livello se exp>expm
        void cheat_hp();    ///ripristina la vita del giocatore fino a hpm
        void cheat_atk();   ///quintuplica l'attacco del giocatore

        ///stampe
        void stat();    ///stampa le statistiche complete
        void skills();  ///stampa descrizione e valore mosse
        void stp_comb();///stampa valori in combattimento

        ///controlli
        void contr_cd();    ///diminuisce i cd ad ogni turno
        void reset_cd();    ///rimette a 0 i cd

        ///mosse
        int use_a0();   ///restituisce atk
        int use_a1();   ///restituisce atk + altro danno
        int use_a2();   ///restituisce atk + var stun=2
        int use_a3();   ///restituisce atk + var sang=2

	//movimenti
	void movimento(char tmp);   ///cambia valori x,y in base a (w,a,s,d)
	void azz_coo();	///le coordinate del player diventano (0,0)
	void mod_coo(int x_new, int y_new);	///le coordinate del player vengono sostituite da quelle passate in input
};


#endif // PLAYER_HPP

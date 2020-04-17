#include <iostream>
#include <cstdio>

#include "funzioniD.hpp"
#include "mappa.hpp"
#include "bot.hpp"
#include "player.hpp"
#include "mostri.hpp"

using namespace std;

bool chiediInizio(){

    char risp ; // risposta iniziale del giocatore

    cout << "Sei ancora convinto di voler proseguire?\n\nPremi il tasto corrispondente alla tua scelta e poi il tasto 'invio':\ny --> Si\nn --> No\n\nRisposta: " ;

    cin >> risp ;

    if (risp == 'n' || risp == 'N'){
        cout << "\nVergogna.\n" ;
        return(false);
    }
    else if (risp == 'y' || risp == 'Y')
        return(true);
    else{
        cout << "L'input non e' corretto. Per favore scegli un opzione tra quelle proposte nell'elenco.\n\n" ;
        return(chiediInizio()); // Ricorsivamente
    }
}

bool chiediScale(){

    char risposta ; // Risposta dell'utente se vuole salire le scale o meno

    cout << "In questa stanza ci sono delle scale. Vuoi salire al piano successivo?\nPremi il tasto corrispondente alla tua scelta e poi il tasto 'invio':\ny --> Si\nn --> No\n\nRisposta: " ;

    cin >> risposta ;

    if((risposta == 'y') || (risposta == 'Y')){
        return(true);
    }
    else if((risposta == 'n') || (risposta == 'N')){
        return(false);
    }
    else{
        cout << "L'input non e' corretto. Per favore scegli un opzione tra quelle proposte nell'elenco.\n\n" ;
        return(chiediScale());  // Ricorsivamente
    }

}

bool tornaIndietro(){

    char r ; // Risposta dell'utente se vuole salire le scale o meno

    cout << "In questa stanza ci sono le scale da cui sei salito. Vuoi tornare al piano precedente?\nPremi il tasto corrispondente alla tua scelta e poi il tasto 'invio':\ny --> Si\nn --> No\n\nRisposta: " ;

    cin >> r ;

    if((r == 'y') || (r == 'Y')){
        return(true);
    }
    else if((r == 'n') || (r == 'N')){
        return(false);
    }
    else{
        cout << "\nL'input non e' corretto. Per favore scegli un opzione tra quelle proposte nell'elenco.\n\n" ;
        return(tornaIndietro());    // Ricorsivamente
    }

}

void stampaAusiliarie(){

    cout << "i --> Se vuoi conoscere le info sulla partita e sulle statistiche attuali del tuo personaggio" ;
    cout << "\nr --> Se vuoi rileggere le regole del gioco\n" ;
}

void mostraInfo(player *g_info, int num_p2){

	cout << endl ;

	g_info->stat();

	cout << "\nTi trovi nel piano " << num_p2 << "\n\n" ;
}

void mostraRegole(){

    cout << "\n- Queste sono le regole del gioco:\nPer vincere devi accumulare tanta esperienza tale da arrivare al livello 20.\nL'esperienza si ottiene uccidendo i mostri che incontrerai nella mappa.\nSegui le istruzioni a video e... buona fortuna!\n\n" ;
}

void stampaDirezioni(bool w_1, bool a_1, bool s_1, bool d_1){

    cout << "\n- In che direzione ti vuoi muovere?\nPremi il tasto corrispondente alla tua scelta e poi il tasto 'invio':\n" ;

    // Controlla quali sono le direzioni lecite e stampa come possibilita' per il giocatore solamente quelle
    if(w_1) cout << "w --> verso l'alto\n" ;

    if(a_1) cout << "a --> verso sinistra\n" ;

    if(s_1) cout << "s --> verso il basso\n" ;

    if(d_1) cout << "d --> verso destra\n" ;
}

void chiediMovimento(ptr_mappa map_mov, player *g_mov, bool w_2, bool a_2, bool s_2, bool d_2, int num_p1){

    char dir ;  // Valore in input della direzione di movimento scelta dal giocatore

    cout << "\nRisposta: " ;

    cin >> dir ;

    // Muovo il giocatore
    if ((dir == 'w' || dir == 'W') && w_2){

        g_mov->movimento('w') ; // Cambio le coordinate del giocatore

        map_mov->visita(g_mov->getx(), g_mov->gety()) ;    // Aggiorno il booleano visitato della nuova stanza
    }
    else if ((dir == 'a' || dir == 'A') && a_2){

        g_mov->movimento('a') ; // Cambio le coordinate del giocatore

        map_mov->visita(g_mov->getx(), g_mov->gety()) ;    // Aggiorno il booleano visitato della nuova stanza
    }
    else if ((dir == 's' || dir == 'S') && s_2){

        g_mov->movimento('s') ; // Cambio le coordinate del giocatore

        map_mov->visita(g_mov->getx(), g_mov->gety()) ;    // Aggiorno il booleano visitato della nuova stanza
    }
    else if ((dir == 'd' || dir == 'D') && d_2){

        g_mov->movimento('d') ; // Cambio le coordinate del giocatore

        map_mov->visita(g_mov->getx(), g_mov->gety()) ;    // Aggiorno il booleano visitato della nuova stanza
    }
    else if (dir == 'w' || dir == 'W' || dir == 'a' || dir == 'A' || dir == 's' || dir == 'S' || dir == 'd' || dir == 'D'){ // Il problema allora e' dovuto ad uno dei booleani w,a,s,d che si trova a false

        cout << "\nNon puoi muoverti nella direzione scelta, seleziona una di quelle possibili nell'elenco.\n" ;

        stampaDirezioni(w_2, a_2, s_2, d_2);
        stampaAusiliarie();

        chiediMovimento(map_mov, g_mov, w_2, a_2, s_2, d_2, num_p1);
    }
    else if (dir == 'i' || dir == 'I'){ // Info

        mostraInfo(g_mov, num_p1);

        stampaDirezioni(w_2, a_2, s_2, d_2);
        stampaAusiliarie();

        chiediMovimento(map_mov, g_mov, w_2, a_2, s_2, d_2, num_p1);
    }
    else if (dir == 'r' || dir == 'R'){ // Regole

        mostraRegole();

        stampaDirezioni(w_2, a_2, s_2, d_2);
        stampaAusiliarie();

        chiediMovimento(map_mov, g_mov, w_2, a_2, s_2, d_2, num_p1);
    }
    else{

        cout << "L'input non e' corretto. Per favore scegli un opzione tra quelle proposte nell'elenco." ;

        stampaDirezioni(w_2, a_2, s_2, d_2);
        stampaAusiliarie();

        chiediMovimento(map_mov, g_mov, w_2, a_2, s_2, d_2, num_p1);
    }
}

ptr_lista_mostri inserisciMostri(ptr_lista_mostri head, ptrmostri e, int p_corrente){

    ptr_lista_mostri tmp = NULL ;

    while(e != NULL){   // Serie di mostri nell'elenco passato dalla mappa

        if(head != NULL){  // Se la lista non e' vuota

            // Crea il mostro in elenco aggiungendolo alla lista dei mostri
            tmp = new lista_mostri ;
            tmp->piano_riferimento = p_corrente ;
            tmp->mostro_corrente = new mostri(e->x, e->y, p_corrente + 1, e->tipomostro) ;  // I mostri avranno livello=piano_corrente+1
            tmp->next = head ;
            head = tmp ;
        }
        else{   // Se la lista e' vuota crea il primo elemento

            head = new lista_mostri ;
            head->piano_riferimento = p_corrente ;
            head->mostro_corrente = new mostri(e->x, e->y, p_corrente + 1, e->tipomostro) ;   // I mostri avranno livello=piano_corrente+1
            head->next = NULL ;
        }

        e = e->next ;
    }

    return(head);
}

ptr_lista_mostri rimuoviMostro(ptr_lista_mostri head, int p_rel, int x_rel, int y_rel){

    bool trovato = false ;
    ptr_lista_mostri tmp = head, tmp_succ = NULL ;

    if(head != NULL){

        if((head->piano_riferimento == p_rel) &&            // Se il mostro e' il primo elemento della lista
           ((head->mostro_corrente)->getx() == x_rel) &&
           ((head->mostro_corrente)->gety() == y_rel)){

                if(head->next != NULL){     // C'e' almeno un altro elemento oltre la testa

                    head = head->next ;
                    delete tmp ;
                    tmp = NULL ;
                }
                else{                       // La testa e' l'unico elemento

                    delete head ;
                    head = NULL ;

                    return(NULL) ;
                }
        }
        else{   // Se il mostro non e' il primo elemento della lista

            while((tmp->next != NULL) && !trovato){

                if(((tmp->next)->piano_riferimento == p_rel) &&
                   (((tmp->next)->mostro_corrente)->getx() == x_rel) &&
                   (((tmp->next)->mostro_corrente)->gety() == y_rel)){

                        trovato = true ;

                        tmp_succ = tmp->next ;

                        if((tmp->next)->next != NULL){  // Se non e' l'ultimo elemento della lista

                            tmp->next = (tmp->next)->next ;
                            delete tmp_succ ;
                            tmp_succ = NULL ;
                        }
                        else{   // Se e' l'ultimo elemento della lista

                            tmp->next = NULL ;
                            delete tmp_succ ;
                            tmp_succ = NULL ;
                        }
                }

                if(!trovato) tmp = tmp->next ;  // In questo modo non passa al 'next' appena trova l'elemento (risparmi una iterazione)
            }
        }
    }

    return(head);
}

ptr_lista_mostri combattimento(bool& risultato, player *g_comb, mostri *m_comb, ptr_lista_mostri h_comb, int p_comb, ptr_mappa mappa){

    // Considera l'eventualita' del piano con un Boss
    if(mappa->is_piano_boss(p_comb) &&
       ((mappa->get_ultimastanza())->x == g_comb->getx()) && ((mappa->get_ultimastanza())->y == g_comb->gety()))
        cout << "\nNella stanza in cui ti trovi c'e' un mostro.\nGuardando la creatura piu' attentamente sembra essere " << m_comb->getn() << " e possiamo star certi, vista la sua stazza, che sia un Boss!\n\n" ;
    else cout << "\nNella stanza in cui ti trovi c'e' un mostro.\nGuardando la creatura piu' attentamente sembra essere " << m_comb->getn() << "!\n\n" ;

	g_comb->stp_comb();
	cout << "\n\t\t\tSi scontrera' con" << endl;
    bool mm=0, mp=0;    // mp=true quando e' morto il player, mm=true quando e' morto il mostro
    int danni=0;
    while(mm==0 && mp==0){
        danni=m_comb->turno_m(danni, g_comb->contr_stun(), g_comb->dtempo_att());
        if (danni==-1){
            mm=1;
            g_comb->reset_cd();
            g_comb->gexp(m_comb->expp());
        } else {
            danni=g_comb->turno_p(danni, m_comb->contr_stun(), m_comb->dtempo_att());
            if (danni==-1){
                mp=1;
            }
        }
    }

    if(mp){ // Se il giocatore e' morto

        cout << endl << g_comb->getn() << " e' stato ucciso da " << m_comb->getn() << ".\n" ;

        risultato = true ;  // Perche' la partita e' finita
    }
    else if(mm){    // Se e' morto il mostro

        cout << endl << g_comb->getn() << " ha ucciso " << m_comb->getn() << ".\n" ;

        // Cancello il mostro morto dalla mia lista dei mostri
        h_comb = rimuoviMostro(h_comb, p_comb, g_comb->getx(), g_comb->gety()) ;

        // Cancello il mostro morto dalla stampa (aggiornando il contenuto della stanza)
        mappa->set_contenuto(0, g_comb->getx(), g_comb->gety()) ;

        risultato = false ;
    }

    return(h_comb);
}

ptr_lista_mostri piano(int num_p, ptr_mappa mapp, player *g, ptr_lista_mostri h, bool& f, bool& v, bool& diet){

    // scala=true quando il giocatore decide di accedere alla scala verso il piano successivo; w,a,s,d per sapere se e' possibile muoversi in quella direzione (true->SI, false->NO); m=true quando nella stanza c'e' un mostro; direzioni[] prende in input dalla mappa le direzioni lecite rispetto alla posizione attuale del giocatore.
    bool scala = false, w = false, a = false, s = false, d = false, m = false, direzioni[4] ;
    ptr_lista_mostri m_stanza = NULL, aux = h ; // m_stanza puntera' al mostro della stanza (se presente); aux scansiona la lista dei mostri.

    // Serie di stanze - Turni di gioco
    while (!scala && !f && !diet){ // finche' il personaggio non trova la scala o finche' la partita non e' finita o finché non torna al piano precedente

        // Aggiornamento variabili
        scala = false ;
        m = false ;
        m_stanza = NULL ;
        aux = h ;

        // Controlla se il giocatore puo' spostarsi in w/a/s/d e aggiorna le rispettive variabili
        mapp->direzioni_lecite(g->getx(), g->gety(), direzioni) ;
        w = direzioni[0] ;
        d = direzioni[1] ;
        s = direzioni[2] ;
        a = direzioni[3] ;

        // MOVIMENTO

        // Se ci troviamo nella prima stanza del piano chiediamo al giocatore se vuole tornare al piano precedente o meno, se si allora diet=true
        if((g->getx() == 0) && (g->gety() == 0) && (num_p > 0))
            diet = tornaIndietro() ;
        // Se ci troviamo nell'ultima stanza del piano chiediamo al giocatore di scegliere se salire al piano successivo o meno, se si allora scala=true
        else if(((mapp->get_ultimastanza())->x == g->getx()) && ((mapp->get_ultimastanza())->y == g->gety()))
            scala = chiediScale() ;

        if(!scala && !diet){

            stampaDirezioni(w, a, s, d);
            stampaAusiliarie();

            chiediMovimento(mapp, g, w, a, s, d, num_p);

            // Mostra lo spostamento effettuato
            mapp->stampa_mappa(g->getx(), g->gety()) ;

            // COMBATTIMENTO (se e' eventualmente presente un mostro nella stanza)

            // Cerca nella lista il mostro che, se presente, si trova nella stanza
            //(accede alla mia lista perche' e' la' che si vede se un mostro e' ancora vivo o e' morto, non nell'elenco passato dalla mappa perche' quest'ultimo non viene aggiornato
            while(aux != NULL && !m){

                if((aux->piano_riferimento == num_p) &&
                    ((aux->mostro_corrente)->getx() == g->getx()) &&
                    ((aux->mostro_corrente)->gety() == g->gety())){

                        m = true ;  // Controlla se nella stanza c'e' un mostro e aggiorna 'm'
                        m_stanza = aux ;
                }

                aux = aux->next ;
            }

            if(m){

            	h = combattimento(f, g, m_stanza->mostro_corrente, h, num_p, mapp) ;    // Se il giocatore muore allora f=true e la partita quindi finisce

            	// Stampa per far vedere la stanza senza M per indicare che il mostro e' morto
            	cout << endl ;
                mapp->stampa_mappa(g->getx(), g->gety()) ;
            }
        }
        else if(scala) g->azz_coo() ;   // Se il giocatore sta salendo al piano successivo allora modifica le coordinate del giocatore ponendole uguali a zero, in questo modo si trovera' nella prima stanza del nuovo piano

        // Se il giocatore ha vinto (ha raggiunto il livello 20 di esperienza)
        if(g->glvl() >= 20) v = true ;

        // Se il giocatore ha vinto allora la partita e' finita
        if(v) f = true ;
    }

    return(h);
}

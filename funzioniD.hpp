#ifndef FUNZIONID_HPP_INCLUDED
#define FUNZIONID_HPP_INCLUDED

#include "mappa.hpp"
#include "bot.hpp"
#include "player.hpp"
#include "mostri.hpp"

typedef mappa* ptr_mappa;

struct lista_piani{
    int numero_piano;
    ptr_mappa piano_corrente;
    lista_piani *next;
};
typedef lista_piani* ptr_lista_piani;

typedef mostri* ptr_mostro;

struct lista_mostri{
    int piano_riferimento ;
    ptr_mostro mostro_corrente;
    lista_mostri *next;
};
typedef lista_mostri* ptr_lista_mostri;

bool chiediInizio();
// Preconditions:
// Postconditions: E' una funzione ricorsiva. Chiede se si vuole iniziare la partita. Ritorna true se accetta, false altrimenti.

bool chiediScale();
// Preconditions:
// Postconditions: E' una funzione ricorsiva. Chiede se si vuole salire le scale per accedere al piano successivo. Ritorna true se accetta, false altrimenti.

bool tornaIndietro();
// Preconditions:
// Postconditions: E' una funzione ricorsiva. Chiede se si vuole scendere le scale per tornare al piano precedente. Ritorna true se accetta, false altrimenti.

void stampaAusiliarie();
// Preconditions:
// Postconditions: Mostra la possibilita' di visualizzare le statistiche o le regole di gioco.

void mostraInfo(player *g_info, int num_p2);
// Preconditions: g_info e' un puntatore alla classe player (il giocatore); num_p2 e' il numero del piano corrente.
// Postconditions: Mostra le statistiche di gioco e del personaggio.

void mostraRegole();
// Preconditions:
// Postconditions: Mostra le regole di gioco.

void stampaDirezioni(bool w_1, bool a_1, bool s_1, bool d_1);
// Preconditions: bool=true -> e' possibile muoversi in quella direzione, false altrimenti.
// Postconditions: Stampa a video la richiesta di inserire la direzione in cui muoversi, dando soltanto le opzioni possibili al momento.

void chiediMovimento(mappa *map_mov, player *g_mov, bool w_2, bool a_2, bool s_2, bool d_2, int num_p1);
// Preconditions: map_mov e' un puntatore alla classe mappa del piano corrente; g_mov e' un puntatore alla classe player (il giocatore);
//                w_2,a_2,s_2,d_2 indicano le direzioni di movimento lecite ; num_p1 e' il numero del piano corrente.
// Postconditions: E' una funzione ricorsiva. Chiede di scegliere un movimento per il giocatore e lo effettua.

ptr_lista_mostri inserisciMostri(ptr_lista_mostri head, ptrmostri e, int p_corrente);
// Preconditions: head e' un puntatore alla testa della lista dei mostri; e e' un puntatore alla testa dell'elenco dei mostri passato in input dalla mappa;
//                p_corrente e' il numero del piano corrente.
// Postconditions: Inserisce, creandoli, i mostri dell'elenco (preso in input dalla mappa) nella lista dei mostri. Restituisce la testa della lista stessa.
//                 L'aggiunta viene fatta in testa cosi' da accedere piu' rapidamente agli ultimi elementi aggiunti alla lista.

ptr_lista_mostri rimuoviMostro(ptr_lista_mostri head, int p_rel, int x_rel, int y_rel);
// Preconditions: head e' un puntatore alla testa della lista dei mostri;
//                p_rel,x_rel,y_rel sono il numero del piano e le coordinate in cui si trova il mostro da rimuovere.
// Postconditions: Rimuove il mostro indicato in input dalla lista passata in input e ritorna la testa alla lista stessa.
//                 Considera i tre casi (rimozione in testa, rimozione nel centro e rimozione alla fine della lista).

ptr_lista_mostri combattimento(bool& risultato, player *g_comb, mostri *m_comb, ptr_lista_mostri h_comb, int p_comb, ptr_mappa mappa);
// Preconditions: risultato indica se il giocatore e' vivo (=false) o morto (=true); g_comb e' un puntatore alla classe player (il giocatore);
//                m_comb e' un puntatore alla classe mostri (il mostro combattente); h_comb e' un puntatore alla testa della lista dei mostri;
//                p_comb e' il numero del piano corrente; mappa e' un puntatore alla classe mappa del piano corrente.
// Postconditions: Informa sul risultato dello scontro, true se il giocatore e' morto, false se e' vivo (ed e' morto il mostro).
//                 Ritorna un puntatore alla testa della lista dei mostri.

ptr_lista_mostri piano(int num_p, ptr_mappa mapp, player *g, ptr_lista_mostri h, bool& f, bool& v, bool& diet);
// Preconditions: num_p indica il numero del piano; mapp e' un puntatore alla classe mappa del piano corrente; g e' un puntatore alla classe player (il giocatore);
//                h e' un puntatore alla testa della lista dei mostri; f indica se il gioco e' finito; v indica se il gioatore ha vinto; diet indica se il
//                giocatore ha deciso di tornare al piano precedente (=true).
// Postconditions: Gestisce la sequenza dei turni di gioco finche' il giocatore non trova la scala superiore, passando cosi' al piano successivo
//                 (che sara' gestitio da una nuova chiamata alla funzione da parte del main), oppure quella inferiore oppure muore.
//                 Ritorna un puntatore alla testa della lista dei mostri.

#endif // FUNZIONID_HPP_INCLUDED

#ifndef MAPPA_H
#define MAPPA_H

struct stanza
{
  stanza* scale;
  int x,y, contenuto;
  bool visitata;
  stanza* precedente;
  stanza* w;
  stanza* d;
  stanza* s;
  stanza* a;
};

struct elenco_mostri
{
  int tipomostro, x, y;
  elenco_mostri *next;
};

typedef stanza* ptrstanza;

struct elenco_stanze{
  ptrstanza stanza;
  elenco_stanze *next;
  };

typedef elenco_mostri* ptrmostri;
typedef elenco_stanze* ptrelenco;


class mappa
{
protected:
    int dimensione_piano, stanzexpiano, mostrixpiano, piano;
    ptrstanza **mappa_piano; // è lecito?
    ptrstanza ultima_stanza;
    ptrelenco head_stanze;
    ptrmostri head_mostri;

public:
    mappa(int piano, ptrstanza precedente);
    //Preconditions: prende in input il piano e il puntatore alla stanza precedente da inserire nelle scale
    //Postconditions: costurisce la mappa
    int numerostanze();
    //Postconditions: imposta il numero di stanze per piano
    int dimensione();
    //Postconditions: Calcola la dimensione della matrice della mappa per un determinato piano
    ptrstanza crea_stanza(ptrstanza precedente, int direzione);
    //Preconditions: prende in input il puntatore alla stanza precedente, e la direzione in cui generare la nuova stanza
    //Postconditions: crea la stanza collegandola alla precedente
    ptrstanza crea_prima_stanza(ptrstanza precedente);
    //Preconditions: Prende in input il puntatore all'ultima stanza del piano precedente per settarlo nelle scale
    //Postconditions: Crea la prima stanza di un piano, facendo puntare le scale a 'precedente'
    ptrstanza crea_prima_stanza();
    //Preconditions: Da utilizzare solo al livello 0
    //Postconditions: Costruisce la prima stanza del livello 0, lasciando a NULL le scale
///   ptrstanza crea_ultima_stanza(ptrstanza precedente, int direzione, int ascissa, int ordinata); non usata
    void inserisci_stanza_in_elenco(ptrstanza stanzadainserire);
    //Preconditions: prende in input la stanza appena creata
    //Postoconditions: inserisce la stanza in una lista di stanze
    void inserisci_mostro_in_elenco(ptrstanza stanzaincuisitrovailmostro);
    //Preconditions: prende in input la stanza in cui si trova il mostro appena inserito
    //Postconditions: inserisce coordinate e tipo di mostro in una lista di mostri
    void set_contenuto(int oggetto, int x, int y);
    //Preconditions: prende in input cosa inserire in una stanza e le coordinate di esso
    //Postconditions: modifica il contenuto della stanza che si trova alle coordinate date, col contenuto dato
    bool is_piano_boss(int piano);
    //Postconditions: verifica che il piano è quello in cui inserire un boss vedendo se il piano è del tipo 4*n, n naturale
    bool is_border(int ascissa, int ordinata);
    //Preconditions: prende le coordinate della posizione in cui vorrei costruire
    //Postconditions: restituisce true se non posso costruire perché sono oltre le dimensioni della mappa, false altrimenti
    bool gia_costruito(int ascissa, int ordinata);
    //Preconditions: prende in input le coordinate della stanza in cui voglio costruire
    //Postconditions: restituisce true se esiste già una stanza in quelle coordinate, false altrimenti
    bool stessa_direzione(int ultima_direzione, int random, int direzione); //direzione dev’essere da 0 a 3
    //Preconditions: direzione indica dove voglio costruire (0123 per WDSA), random dove ho costruito l'ultima volta e ultima_direzione quella prima
    //Postconditions: restituisce true nel caso in cui sono tutti e tre uguali, false in caso contrario
/// void prec_succ(int precedente, int successivo, int variazioni_xy[]); non usato
    //Postconditions:controlla se l’ultima direzione e quella in cui ho costruito sono allineate o meno: se sono uguali, non fa niente, se sono diverse azzera variazioni_xy[]
    void visita(int x, int y);
    //Preconditions: prende in input le coordinate della stanza in cui si trova il giocatore
    //Postconditions: cambia in true il booleano "visitata" della stnaza
    void inizializza_matrice(int dimensione);
    //Preconditions: prende in input la dimensione della matrice calcolata dal metodo della mappa
    //Postconditions: inizializza una matrice quadrata dimensione x dimensione di ptrstanza a NULL
    ptrstanza get_ultimastanza();
    //Postconditions: restituisce il puntatore all'ultima stanza del piano
    void riempi_stanze();
    //Postconditions: inserisce i mostri nelle stanze disponibili
/// void stampino(); non usata
/// void stampastanze();non usata
    ptrstanza** get_matrice();
    //Postconditions: restuisce il puntatore alla matrice
    int get_piano();
    //Postconditions: restituisce il piano della mappa
    ptrmostri get_mostri();
    //Postconditions: restituisce la lista con le coordinate delle stanze in cui sono stati inseriti i mostri e il tipo di mostro inserito
    void set_scale_finali(ptrstanza pianosuccessivo);
    //Preconditions: prende in input il puntatore alla prima stanza del piano che viene creato
    //Postconditions: imposta le scale dell'ultima stanza di un piano inserendo in puntatore alla prima del piano successivo
    ptrstanza get_scale_iniziali();
    //Postconditions: inserisci il puntatore all'ultima stanza del piano precedente nelle scale della prima stanza
    ptrstanza get_primastanza();
    //Postconditions: restituisce il puntatore alla prima stanza del piano
    void direzioni_lecite(int x, int y, bool direzionilecite[]);
    //Preconditions: prende le coordinate di una stanza, e un array di quattro booleani
    //Postconditions: modifica l'array impostando a true le posizioni corrispondenti alle porte utili

    //Per la stampa

    char pers(int x, int y, int x_p1, int y_p1);
    //Preconditions: prende in input le coordinate del giocatore e quelle della stanza che si sta stampando
    //Postconditions: stampa P nella stanza se è presente il personaggio
    char mostro(int x, int y);
    //Preconditions: prende in input le coordinate del giocatore e quelle della stanza che si sta stampando
    //Postconditions: stampa P nella stanza se è presente il personaggio
/// char death(int x, int y);
    char scala(int x, int y);
    //Preconditions: prende in input le coordinate della stanza che si sta stampando
    //Postconditions: stampa # nella stanza se son presenti le scale
    void check_linkd(int x, int y);
    //Preconditions: prende in input le coordinate della stanza in cui si sta stampando
    //Postconditions: riempie di 1 un array laddove esistono connessioni orizzontali tra le stanze
    void check_links(int a[], int x, int y);
    //Preconditions: prende in input le coordinate della stanza in cui si sta stampando
    //Postconditions: riempie di 1 un array laddove esistono connessioni verticali tra le stanze
    bool mid_line(int a[]);
    //Preconditions: prende in input l'array in cui sono indicate le connessioni verticali
    //Postconditions: restituisce true se bisogna continuare a stampare in verticale e stampa le connessioni verticali
    void stampa_mappa(int x_p, int y_p);
    //Preconditions: prende le coordinate del personaggio
    //Postconditions: stampa la mappa del piano corrente

    };

#endif // MAPPA_H

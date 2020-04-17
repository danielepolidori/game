#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

#include "funzioniD.hpp"
#include "mappa.hpp"
#include "bot.hpp"
#include "player.hpp"
#include "mostri.hpp"

using namespace std;

int main(){

    int p = 0, piano_max = 0 ; // 'p' e' il numero del piano (il primo piano e' lo 0); 'piano_max' e' il numero del piano piu' alto raggiunto
    // fine=true quando il gioco e' finito (il giocatore puo' sia aver vinto che perso); vitt=true se il giocatore ha vinto; dietro=true se sto tornando al piano precedente; flag viene utilizzato per scandire la lista di piani.
    bool fine = false, vitt = false, dietro = false, flag = false ;
    string nome_giocatore ;
    ptr_lista_piani head_p = NULL, l_p = NULL ;
    ptr_lista_mostri head_m = NULL ;

    cout << "\n\nBenvenuto, giocatore.\n\n" ;

    mostraRegole();

    if (chiediInizio()){

        // Chiede in input il nome da dare al giocatore
        cout << "\nInserire il nome del giocatore da tastiera: " ;

        cin >> nome_giocatore ;

        // Creazione del giocatore
        player giocatore = player(nome_giocatore) ;

        // Serie di piani
        while (!fine){

            // Aggiornamento variabili
            flag = false ;

            // Se sto tornando al piano precendente cerco la relativa mappa nella mia lista di piani
            if(((p <= piano_max)&&(p != 0)) || ((p == 0) && (piano_max > 0))){

                l_p = head_p ;
                while(l_p != NULL && !flag){

                    if(l_p->numero_piano == p) flag = true ;

                    if(!flag) l_p = l_p->next ;
                }
            }
            // Creazione della mappa del p-esimo piano e aggiunta alla lista dei piani
            else if(p == 0){  // Quindi c'e' un unico caso in cui p=0

                head_p = new lista_piani ;
                head_p->numero_piano = p ;
                head_p->piano_corrente = new mappa(p, NULL) ;
                head_p->next = NULL ;
                l_p = head_p ;
            }
            else if(p > 0){   // Se p>=1

                l_p = head_p ;
                while((l_p->next) != NULL) l_p = l_p->next ;
                l_p->next = new lista_piani ;
                (l_p->next)->numero_piano = p ;
                (l_p->next)->piano_corrente = new mappa(p, (l_p->piano_corrente)->get_ultimastanza()) ;    // (l_p->piano_corrente)->get_ultimastanza() da' in input l'ultima stanza del piano precedente al costruttore
                (l_p->piano_corrente)->set_scale_finali(((l_p->next)->piano_corrente)->get_primastanza());    // Imposta come scale finali del piano precedente la prima stanza del piano corrente
                (l_p->next)->next = NULL ;
                l_p = l_p->next ;
            }
            // A questo punto l_p punta all'elemento della lista contenente il piano attuale

            // Creazione della lista dei mostri nel p-esimo piano (se ci troviamo per la prima volta in questo piano oppure se e' il primo piano di gioco)
            if((p > piano_max) || ((p == 0)&& (piano_max==0))) head_m = inserisciMostri(head_m, (l_p->piano_corrente)->get_mostri(), p) ;

            // Modifico le coordinate del giocatore se sta tornando al piano precedente
            if(dietro) giocatore.mod_coo(((l_p->piano_corrente)->get_ultimastanza())->x, ((l_p->piano_corrente)->get_ultimastanza())->y) ;

            cout << endl ;
            (l_p->piano_corrente)->stampa_mappa(giocatore.getx(), giocatore.gety()) ;

            // Aggiorno le variabili
            dietro = false ;
            if(p>piano_max) piano_max = p ; // Aggiorno solamente se e' la prima volta che il giocatore accede a quel piano

            // Cio' che succede per ogni piano
            head_m = piano(p, l_p->piano_corrente, &giocatore, head_m, fine, vitt, dietro);

            if(dietro) p = p - 1 ;
            else p = p + 1 ;
        }

        if (vitt) cout << "\nComplimenti, hai vinto!\n" ;
        else cout << "\nRitenta, sarai piu' fortunato.\n" ;
     }
	return 0;
}

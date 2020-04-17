#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "mappa.hpp"
using namespace std;

//tipo mostri 1-5: 1=tigre selvaggia, 2= coccodrillo della palude, 3= toro furioso, 4=fenice infuocata, 6-10: 5= soldato scheletro, 6=arciere delle catacombe, 7= abominio, 8=scheletro gigante, 11-15: 9=monaco del tempio, 10=mago divino, 11=angelo della morte, 12= drago fedele della luce, 16-20: 13= Imperatore oscuro, 14=scagnozzo infernale, 15=paladino degli inferi, 16=stregone supremo

//il game manager da il numero de livello e avvia il costruttore della mappa. Questa nuova mappa ha il puntatore al livello precedente, tranne nel caso del primo livello.

  mappa::mappa(int numeropiano, ptrstanza precedente)
  {
  piano=numeropiano;
  int contatore_stanze;
  ptrstanza stanza_corrente;
  bool array_NESO[4];
  int i,n,x1,y1; // n mi conta i cicli e serve per aumentare ogni volta di uno il random, x1,y1 sono le coordinate della stanza corrente quando costruisco
  i=1; //numero a caso
  int random, ultima_direzione; //indica qual e` stato il risultato del random ammissibile precedente
  stanzexpiano=numerostanze();
  mostrixpiano=stanzexpiano/2;
  dimensione_piano=dimensione();
  inizializza_matrice(dimensione_piano);
  head_stanze=new elenco_stanze;
  if(precedente==NULL) mappa_piano[0][0]=crea_prima_stanza();
  else mappa_piano[0][0]=crea_prima_stanza(precedente);
  head_stanze->stanza=NULL;
  head_stanze->next=NULL; //inizializzo la lista delle stanze del piano
  stanza_corrente=mappa_piano[0][0];
  array_NESO[0]=false;
  array_NESO[1]=true;
  array_NESO[2]=true;
  array_NESO[3]=false;
  srand(time(0)+i);
  ultima_direzione=rand()%4;
  while(array_NESO[ultima_direzione]==false) ultima_direzione=(ultima_direzione+1)%4;
    if (ultima_direzione==1)
    {
     stanza_corrente->d=crea_stanza(stanza_corrente,ultima_direzione);
     stanza_corrente=stanza_corrente->d;
     inserisci_stanza_in_elenco(stanza_corrente);
    }
    else if (ultima_direzione==2)
    {
      stanza_corrente->s=crea_stanza(stanza_corrente,ultima_direzione);
      stanza_corrente=stanza_corrente->s;
      inserisci_stanza_in_elenco(stanza_corrente);
    }


x1=stanza_corrente->x;
y1=stanza_corrente->y;
mappa_piano[y1][x1]=stanza_corrente;

      array_NESO[0]=!((is_border(x1,y1-1))||(gia_costruito(x1,y1-1)));
      array_NESO[1]=!((is_border(x1+1,y1))||(gia_costruito(x1+1,y1)));
      array_NESO[2]=!((is_border(x1,y1+1))||(gia_costruito(x1,y1+1)));
      array_NESO[3]=!((is_border(x1-1,y1))||(gia_costruito(x1-1,y1)));


  contatore_stanze=stanzexpiano-2;
  while(contatore_stanze>0)
  {
    srand(time(0)+i);
    random=rand()%4;
    while(array_NESO[random]==0) random=(random+1)%4;
    if(random==0)
    {
     stanza_corrente->w=crea_stanza(stanza_corrente,random); //inizializza quello a nord
     stanza_corrente=stanza_corrente->w; //aggiorna la stanza_corrente a quella costruita a Nord
    inserisci_stanza_in_elenco(stanza_corrente);
    }
    else if (random==1)
    {
     stanza_corrente->d=crea_stanza(stanza_corrente,random);
     stanza_corrente=stanza_corrente->d;
     inserisci_stanza_in_elenco(stanza_corrente);
    }
    else if (random==2)
    {
      stanza_corrente->s=crea_stanza(stanza_corrente,random);
      stanza_corrente=stanza_corrente->s;
      inserisci_stanza_in_elenco(stanza_corrente);
    }
    else if (random==3)
    {
      stanza_corrente->a=crea_stanza(stanza_corrente,random);
      stanza_corrente=stanza_corrente->a;
      inserisci_stanza_in_elenco(stanza_corrente);
    }

      x1=stanza_corrente->x;
      y1=stanza_corrente->y;

      array_NESO[0]=!((is_border(x1,y1-1))||(gia_costruito(x1,y1-1))||(stessa_direzione(ultima_direzione,random,0)));
      array_NESO[1]=!((is_border(x1+1,y1))||(gia_costruito(x1+1,y1))||(stessa_direzione(ultima_direzione,random,1)));
      array_NESO[2]=!((is_border(x1,y1+1))||(gia_costruito(x1,y1+1))||(stessa_direzione(ultima_direzione,random,2)));
      array_NESO[3]=!((is_border(x1-1,y1))||(gia_costruito(x1-1,y1))||(stessa_direzione(ultima_direzione,random,3)));

      if(array_NESO[0]|| array_NESO[1]|| array_NESO[2]|| array_NESO[3])
       {
       mappa_piano[y1][x1]=stanza_corrente;
       ultima_direzione=random;
       contatore_stanze-=1;
       i=i+1;
       }

     else
      {
       while((array_NESO[0]|| array_NESO[1]|| array_NESO[2]|| array_NESO[3])==false)
       {
         stanza_corrente=stanza_corrente->precedente;
         x1=stanza_corrente->x;
         y1=stanza_corrente->y;
      array_NESO[0]=!((is_border(x1,y1-1))||(gia_costruito(x1,y1-1)));
      array_NESO[1]=!((is_border(x1+1,y1))||(gia_costruito(x1+1,y1)));
      array_NESO[2]=!((is_border(x1,y1+1))||(gia_costruito(x1,y1+1)));
      array_NESO[3]=!((is_border(x1-1,y1))||(gia_costruito(x1-1,y1)));
       }
         mappa_piano[y1][x1]=stanza_corrente;
         ultima_direzione=random;
         contatore_stanze-=1;
         i=i+1;
      }


      }

   ultima_stanza=stanza_corrente;
   head_mostri=new elenco_mostri;
   head_mostri->next=NULL;
   head_mostri->x=-1;
   head_mostri->y=-1;
   head_mostri->tipomostro=-1;

   riempi_stanze();
  }

int mappa::numerostanze()//calcola il numero di stanze per un determinato piano
  {
   return(piano+6);
  }


int mappa::dimensione() //calcola la dimensione della matrice della mappa per un determinato piano
  { int x,n;
    x=(2-(numerostanze()%3))+piano;
    n=(x+1)/3;
    return(6+2*(n-1));
  }


ptrstanza mappa::crea_stanza(ptrstanza precedente, int direzione)/*direzione e` il risultato del random fatto prima ovvero in che direzione sto costruendo. Useremo i numeri 0,1,2,3 per w,d,s,a come convenzione*/
  { ptrstanza room;
    int ascissa, ordinata;
    ascissa=precedente->x;
    ordinata=precedente->y;
  	 room=new stanza;
  	 room->precedente=precedente;
  	 room->visitata=false;
  	 room->contenuto=0;
  	 room->scale=NULL;

  	 if (direzione==0)
  	  {
  	   room->s=precedente; //caso nord
  	   ordinata-=1;
  	   }
  	 else room->s=NULL;
  	 if (direzione==1)
  	 {
  	  room->a=precedente;
  	  ascissa+=1;
  	 }
  	 else room->a=NULL;
  	 if (direzione==2)
  	 {
  	  room->w=precedente;
  	  ordinata+=1;
  	 }
  	 else room->w=NULL;
  	 if (direzione==3)
  	 {
  	  room->d=precedente;
  	  ascissa-=1;
  	 }
  	 else room->d=NULL;
  	 room->x=ascissa;
  	 room->y=ordinata;
  	 return (room);

  }

ptrstanza mappa::crea_prima_stanza(ptrstanza precedente)
 {
   ptrstanza primastanza;
   primastanza=new stanza;
   primastanza->x=0;
   primastanza->y=0;
   primastanza->precedente=NULL;
   primastanza->visitata=true;
   primastanza->contenuto=0;
   primastanza->scale=precedente;
   primastanza->w=NULL;
   primastanza->d=NULL;
   primastanza->s=NULL;
   primastanza->a=NULL;
   return(primastanza);
  }

ptrstanza mappa::crea_prima_stanza()
  {
   ptrstanza primastanza;
   primastanza=new stanza;
   primastanza->x=0;
   primastanza->y=0;
   primastanza->precedente=NULL;
   primastanza->visitata=true;
   primastanza->contenuto=0;
   primastanza->scale=NULL;
   primastanza->w=NULL;
   primastanza->d=NULL;
   primastanza->s=NULL;
   primastanza->a=NULL;
   return(primastanza);
  }

void mappa::inserisci_stanza_in_elenco(ptrstanza stanzadainserire)
   {
    ptrelenco tmp;
    tmp=head_stanze;
    if((head_stanze->stanza==NULL)&&(head_stanze->next==NULL))
    head_stanze->stanza=stanzadainserire;
    else {
        while(tmp->next!=NULL) tmp=tmp->next;
        tmp->next=new elenco_stanze;
        (tmp->next)->stanza=stanzadainserire;
        (tmp->next)->next=NULL;
        }
}

void mappa::inserisci_mostro_in_elenco(ptrstanza stanzaincuisitrovailmostro)
 	{ptrmostri tmp;
 	 tmp=head_mostri;
 	 if(head_mostri->x<0)
 	 {
 	 head_mostri->x=stanzaincuisitrovailmostro->x;
 	 head_mostri->y=stanzaincuisitrovailmostro->y;
 	 head_mostri->tipomostro=stanzaincuisitrovailmostro->contenuto;
 	 head_mostri->next=NULL;
 	 }
 	 else {
         while(tmp->next!=NULL) tmp=tmp->next;
         tmp->next=new elenco_mostri;
         (tmp->next)->x=stanzaincuisitrovailmostro->x;
         (tmp->next)->y=stanzaincuisitrovailmostro->y;
         (tmp->next)->tipomostro=stanzaincuisitrovailmostro->contenuto;
         (tmp->next)->next=NULL;
         }
    }


void mappa::set_contenuto(int oggetto, int x, int y) //non usata
 	{
 	if((0<=oggetto)&&(oggetto<=15)) //controllo se e` un contenuto lecito
 	mappa_piano[y][x]->contenuto=oggetto;
 	else cout << "hai inserito un oggetto non permesso\n";
 	}
bool mappa::is_piano_boss(int piano)
  {
    if((piano==4)||((piano-4)%5==0)) return true;
    else return false;
   }

bool mappa::is_border(int ascissa, int ordinata) //prende le coordinate della posizione in cui vorrei costruire
   {
     if ((ascissa<0)||(ascissa>dimensione_piano-1)||(ordinata<0)||(ordinata>dimensione_piano-1)) return(true);
     else return(false);
    }

bool mappa::gia_costruito(int ascissa, int ordinata)
   { if (mappa_piano[ordinata][ascissa]==NULL) return(false);
     else return(true);
   }

bool mappa::stessa_direzione(int ultima_direzione, int random, int direzione) //direzione dev’essere da 0 a 3
    {
    if (direzione>3) cout << "La direzione dev’essere 0, 1, 2 o 3\n";
    else
     {
     if((random+ultima_direzione)%2==1) return(false);
     else if (((random+ultima_direzione)%2==0)&&(random==direzione))  {
        return(true);
        }
     else
     {
     return(false);
     }
     }
    }

void mappa::visita(int x, int y)
    {
      mappa_piano[y][x]->visitata=true;
    }

void mappa::inizializza_matrice(int dimensione)
    { int n,m;
      mappa_piano=new ptrstanza*[dimensione];
      for(n=0;n<dimensione;n++)
      {
       mappa_piano[n]=new ptrstanza[dimensione];
       for(m=0;m<dimensione;m++){
            mappa_piano[n][m]=NULL;
       }
      }
     }

ptrstanza mappa::get_ultimastanza()
     {
       return(ultima_stanza);
     }

void mappa::riempi_stanze()
     {
     bool flag=true;
     int gruppo;
     int stanza_scelta, mostro_scelto;
     int l,k,j,numero,n;
     numero=-1;
     int stanzescelte[mostrixpiano];
     if(((piano%20)>=0)&&((piano%20)<=4)) gruppo=0;
     else if(((piano%20)>=5)&&((piano%20)<=9)) gruppo=1;
     else if(((piano%20)>=10)&&((piano%20)<=14)) gruppo=2;
     else if(((piano%20)>=15)&&((piano%20)<=19)) gruppo=3;
     for(j=0;j<mostrixpiano;j++) {stanzescelte[j]=numero; numero-=1;};
     ptrelenco tmp;
     for(l=0;l<mostrixpiano;l++)
          {
          	flag=true;
            tmp=head_stanze;
            while(flag){
            srand(time(0)+l);
            stanza_scelta=rand()%(stanzexpiano-2);
            stanzescelte[l]=stanza_scelta;
            n=0;
             while((n<l)&&(stanza_scelta!=stanzescelte[n]))
             {
                n=n+1;
             }
             if(n==l) flag=false;
             else flag=true;
             }
            if(stanza_scelta==0)
            {
                if(!((tmp->stanza->x==0)&&(tmp->stanza->y==0)))
                srand(time(0)+k); //scelgo il mostro
                mostro_scelto=((rand()%3)+1)+(gruppo*4); //il +1 serve a non farmi venire 0, perche` 0 vuol dire che non ci sono mostri
                (tmp->stanza)->contenuto=mostro_scelto;
                inserisci_mostro_in_elenco(tmp->stanza);
            }
            else {
             for(k=0;k<stanza_scelta;k++){

                tmp=tmp->next;
              }

            srand(time(0)+k); //scelgo il mostro
            mostro_scelto=((rand()%3)+1)+(gruppo*4); //il +1 serve a non farmi venire 0, perche` 0 vuol dire che non ci sono mostri
            (tmp->stanza)->contenuto=mostro_scelto;
            if(!((tmp->stanza->x==0)&&(tmp->stanza->y==0)&&(tmp->stanza==get_ultimastanza())))
            inserisci_mostro_in_elenco(tmp->stanza);
            }
          }
          mappa_piano[0][0]->contenuto=0;
          if((piano-4)%5==0) {ultima_stanza->contenuto=4+gruppo*4;
          inserisci_mostro_in_elenco(ultima_stanza);} //se e` un livello del boss metto dentro il boss
}


ptrmostri mappa::get_mostri(){

 return (head_mostri);
}

ptrstanza mappa::get_primastanza(){
 return (mappa_piano[0][0]);
 }

ptrstanza mappa::get_scale_iniziali(){

    return (mappa_piano[0][0]->scale);
}

void mappa::set_scale_finali(ptrstanza pianosuccessivo){

    ultima_stanza->scale=pianosuccessivo;
}



ptrstanza** mappa::get_matrice(){

    return(mappa_piano);
}

int mappa::get_piano(){

    return(piano);
}

void mappa::direzioni_lecite(int x, int y, bool direzionilecite[]){
direzionilecite[0]=(mappa_piano[y][x]->w!=NULL);
direzionilecite[1]=(mappa_piano[y][x]->d!=NULL);
direzionilecite[2]=(mappa_piano[y][x]->s!=NULL);
direzionilecite[3]=(mappa_piano[y][x]->a!=NULL);

}

char mappa::pers(int x, int y, int x_p1, int y_p1){
    //if (((mappa_piano[y][x]-> x)== x_p1) &&((mappa_piano[y][x]-> y)== y_p1)) return'P';
    if ((x == x_p1) && (y == y_p1)) return'P';
    else return' ';
}

char mappa::mostro(int x, int y){
    if (((mappa_piano[y][x]->contenuto)>=1) && ((mappa_piano[y][x]->contenuto) <= 16))
        {if((is_piano_boss(piano))&&(get_ultimastanza()->x==x)&&(get_ultimastanza()->y==y)) return 'B';
         else return'M';
        }
    else return' ';
}

char mappa::scala(int x, int y){
    if ((x == get_ultimastanza()->x) && (y == get_ultimastanza() ->y))return'#';
    else return' ';
}

void mappa::check_linkd(int x, int y){
    if((mappa_piano[y][x]->d)!= NULL) cout << "\t-\t";
    else cout << "\t\t ";
}

void mappa::check_links(int a[], int x, int y){
    if ((mappa_piano[y][x]->s)!= NULL) a[x]= 1;
    else a[x]=0;
}

bool mappa::mid_line(int a[]){
    cout<< endl ;
    int i=0;
    bool continua = false ;
    while (i< dimensione_piano){
        if(a[i]==1){

        continua = true ;

		cout<< "\t|\t\t\t";
	}
        else cout<< "\t\t\t\t";
        i = i + 1;
    }
    cout << endl;

	return(!continua);
}

void mappa::stampa_mappa(int x_p, int y_p)
{ int x=0, y=0;
    int a[dimensione_piano];
    bool fermati = false ;

     for (int k=0; k<dimensione_piano ; k++){a[k]=0;} //inizializza array a 0
    cout << "\t|"<<endl;
    while(y < dimensione_piano && !fermati) {
        if ((mappa_piano[y][x]!=NULL) && ((mappa_piano [y][x] -> visitata)== true)){

                cout << "["<<pers(x,y, x_p, y_p)<<"\t"<<mostro(x,y)<<scala(x,y)<<"\t]" ;
                check_linkd(x,y);
                check_links(a, x, y);
            }
        else {cout << "\t\t\t\t"; // crea buchi sotto la 0,0  se le 1,0 2,0 ... non esistono o non sono visitate
        }

        x = x +1;
        while(x < dimensione_piano){
            if ((mappa_piano[y][x]!=NULL) && ((mappa_piano [y][x] -> visitata)== true)) {
                      


		    cout << "["<<pers(x,y,x_p,y_p)<<"\t"<<mostro(x,y)<<scala(x,y)<<"\t]";
                    check_linkd(x, y);
                    check_links(a, x, y);
            }
            else cout << "\t\t\t\t";

            x = x + 1;
        }


        fermati = mid_line(a);//va a capo ad inizio funzione e a fine funzione.

        for (int k=0; k<dimensione_piano ; k++){a[k]=0;} ///ho aggiunto solo questo

        x = 0;
        y = y + 1;
    }
    cout << endl;

}


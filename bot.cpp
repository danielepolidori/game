#include <iostream>
#include "bot.hpp"
#include <string>
using namespace std;

bot::bot(){}

bot::~bot(){}

int bot::getx(){
    return x;
}

int bot::gety(){
    return y;
}

std::string bot::getn(){
    return n;
}

int bot::expp(){
    return exp;
}

void bot::tk_damage(int dan){
    dan=(dan*(100-def))/100;
    if (barr>0) {
        barr=barr-dan;
        cout << "\nLa barriera di " << n << " assorbe " << dan << " danni" << endl;
        if (barr<=0) {
            cout << "\nLa barriera di " << n << " e' stata spezzata" << endl;
            hp=hp+barr;
            cout << "\n" << n << " riceve " << -1*barr << " danni" << endl;
        }
    } else {
        hp=hp-dan;
        cout << "\n" << n << " riceve " << dan << " danni" << endl;
    }
}

void bot::statb(){			// visualizza le statistiche
    cout << "\n---------------------------------------------------------------------";
    cout << "\n" << n
    << "\nhp=  " << hp << "/" << hpm
    << "\natk= " << atk
    << "\ndef= " << def << endl;
    cout << "\n---------------------------------------------------------------------";
}

bool bot::morte(){
    bool d=0;
    if (hp<=0) {
        d=1;
    }
    return d;
}

bool bot::contr_stun(){
    bool ds=0;
    if (dstun>0) {
        dstun=dstun-1;
        ds=1;
    }
    return ds;
}

void bot::get_dtempo(bool s){
    if (s) {
        int tmp=hpm/40;
        hp=hp-tmp;
        cout << "\n" << n << " soffre per la ferita da sanguinamento perdendo " << tmp << " punti vita" << endl;
    }
}

bool bot::dtempo_att(){
    bool dt=0;
    if (ddtempo>0) {
        dt=1;
    }
    return dt;
}

void bot::contr_dif(){
    if (daum_dif>0){
        daum_dif=daum_dif-1;
        if (daum_dif==0) {
            def=def/2;
            cout << "\nLa difesa di " << n << " torna ad essere normale" << endl;
        }
    }
}

void bot::contr_atk(){
    if (daum_atk>0){
        daum_atk=daum_atk-1;
        if (daum_atk==0) {
            atk=atk/2;
            cout << "\nL'attacco di " << n << " torna ad essere normale" << endl;
        }
    }
}

void bot::contr_cur(){
    if (dcura>0) {
        int tmp=hpm/10;
        if (tmp>(hpm-hp)){
            tmp=hpm-hp;
        }
        hp=hp+tmp;
        cout << "\nA " << n << " vengono ripristinati " << tmp << " punti vita" << endl;
        dcura=dcura-1;
    }
}

int bot::att_base(){
    cout << "\n" << n << " attacca l'avversario" << endl;
    return atk;
}

int bot::dtempo(int *cd){
    *cd=3;
    ddtempo=2;
    cout << "\n" << n << " ferisce l'avversario facendolo sanguinare per 2 turni" << endl;
    return atk;
}

int bot::stun(int *cd){
    *cd=4;
    dstun=2;
    cout << "\n" << n << " attacca l'avversario stordendolo per 2 turni" << endl;
    return atk;
}

int bot::att_pot(int *cd){
    *cd=3;
    cout << "\n" << n << " attacca l'avversario con una grande potenza" << endl;
    return (atk+((atk*50)/100));
}

int bot::aum_dif(int *cd) {
    cout << "\n" << n << " raddoppia la difesa per due turni" << endl;
    daum_dif=4;
    def=def*2;
    *cd=4;
    return (0);
}

int bot::aum_atk(int *cd) {
    cout << "\n" << n << " raddoppia l'attacco per due turni" << endl;
    daum_atk=4;
    atk=atk*2;
    *cd=4;
    return (0);
}

int bot::barriera(int *cd) {
    cout << "\n" << n << " crea una barriera che lo protegge" << endl;
    barr=hpm/4;
    *cd=4;
    return (0);
}

int bot::cura(int *cd){
    cout << "\n" << n << " attiva una magia che permette di recuperare un po' di vita per 3 turni" << endl;
    dcura=4;
    *cd=4;
    return (0);
}




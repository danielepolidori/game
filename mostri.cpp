#include "mostri.hpp"
#include <iostream>
using namespace std;

mostri::mostri(int t, int s, int l, int m)
{
            tm=m;
            lvl=l;
			def=25;
			x=t;
			y=s;
			ddtempo=0;
			dstun=0;
			daum_dif=0;
			daum_atk=0;
            barr=0;
            dcura=0;
            res=1;
            cd1=0;
			cd2=0;
			cd3=0;
            tip_m();
}

mostri::~mostri()
{
    //dtor
}

void mostri::tip_m(){
    switch(tm) {
    case (1):
        n="Tigre selvaggia";
        exp=lvl*100;
        hp =lvl*50;
        hpm=lvl*50;
        atk =lvl*5;
        break;

    case (2):
        n="Coccodrillo delle paludi";
        exp=lvl*100;
        hp =lvl*50;
        hpm=lvl*50;
        atk =lvl*5;
        break;

    case (3):
        n="Toro infuriato";
        exp=lvl*100;
        hp =lvl*50;
        hpm=lvl*50;
        atk =lvl*5;
        break;

    case (4):
        n="Fenice infuocata";
        exp=lvl*300;
        hp =lvl*50;
        hpm=lvl*50;
        atk =lvl*10;
        break;

    case (5):
        n="Soldato scheletro";
        exp=lvl*100;
        hp =lvl*75;
        hpm=lvl*75;
        atk =lvl*5;
        break;

    case (6):
        n="Arciere delle catacombe";
        exp=lvl*100;
        hp =lvl*75;
        hpm=lvl*75;
        atk =lvl*5;
        break;

    case (7):
        n="Abominio";
        exp=lvl*100;
        hp =lvl*50;
        hpm=lvl*50;
        atk =lvl*5;
        break;

    case (8):
        n="Scheletro gigante";
        exp=lvl*300;
        hp =lvl*75;
        hpm=lvl*75;
        atk =lvl*10;
        break;

    case (9):
        n="Monaco del tempio";
        exp=lvl*100;
        hp =lvl*100;
        hpm=lvl*100;
        atk =lvl*10;
        break;

    case (10):
        n="Mago divino";
        exp=lvl*100;
        hp =lvl*100;
        hpm=lvl*100;
        atk =lvl*10;
        break;

    case (11):
        n="Angelo della morte";
        exp=lvl*100;
        hp =lvl*100;
        hpm=lvl*100;
        atk =lvl*10;
        break;

    case (12):
        n="Drago fedele della luce";
        exp=lvl*300;
        hp =lvl*100;
        hpm=lvl*100;
        atk =lvl*10;
        break;

    case (13):
        n="Imperatore oscuro";
        exp=lvl*100;
        hp =lvl*100;
        hpm=lvl*100;
        atk =lvl*10;
        break;

    case (14):
        n="Scagnozzo infernale";
        exp=lvl*100;
        hp =lvl*100;
        hpm=lvl*100;
        atk =lvl*10;
        break;

    case (15):
        n="Paladino degli inferi";
        exp=lvl*100;
        hp =lvl*100;
        hpm=lvl*100;
        atk =lvl*10;
        break;

    case (16):
        n="Stregone supremo";
        exp=lvl*500;
        hp =lvl*100;
        hpm=lvl*100;
        atk =lvl*10;
        break;
    }
}

int mostri::azione() {
    switch(tm) {
    case (1):   ///azione tigre
        if (ddtempo==0 && cd1==0){
            return dtempo(&cd1);
        } else if (cd2==0) {
            return att_pot(&cd2);
        } else {
            return att_base();
        }

        break;

    case (2):   ///azione coccodrillo
        if (dstun==0 && cd1==0){
            return stun(&cd1);
        } else if (cd2==0) {
            return att_pot(&cd2);
        } else {
            return att_base();
        }
        break;

    case (3):   ///azione toro
        if (ddtempo==0 && cd1==0){
            return dtempo(&cd1);
        } else if (dstun==0 && cd2==0) {
            return stun(&cd2);
        } else {
            return att_base();
        }
        break;

    case (4):   ///azione fenice
        if (ddtempo==0 && cd1==0){
            return dtempo(&cd1);
        } else if (daum_dif==0 && cd2==0) {
            return aum_dif(&cd2);
        } else {
            return att_base();
        }
        break;

    case (5):   ///azione soldato
        if (daum_dif==0 && cd1==0){
            return aum_dif(&cd1);
        } else if (dcura==0 && cd2==0 && hpm!=hp) {
            return cura(&cd2);
        } else {
            return att_base();
        }
        break;

    case (6):   ///azione arciere
        if (daum_atk==0 && cd1==0){
            return aum_atk(&cd1);
        } else if (cd2==0) {
            return att_pot(&cd2);
        } else {
            return att_base();
        }
        break;

    case (7):   ///azione abom
        if (daum_atk==0 && cd1==0){
            return aum_atk(&cd1);
        } else if (barr==0 && cd2==0) {
            return barriera(&cd2);
        } else {
            return att_base();
        }
        break;

    case (8):   ///azione gigante
        if (dstun==0 && cd1==0){
            return stun(&cd1);
        } else if (daum_dif==0 && cd2==0 && dstun==0) {
            return aum_dif(&cd2);
        } else {
            return att_base();
        }
        break;

    case (9):   ///azione monaco
        if (barr==0 && cd1==0){
            return barriera(&cd1);
        } else if (dcura==0 && cd2==0 && hpm!=hp) {
            return cura(&cd2);
        } else {
            return att_base();
        }
        break;

    case (10):   ///azione mago
        if (dstun==0 && cd1==0){
            return stun(&cd1);
        } else if (dcura==0 && cd2==0 && hpm!=hp) {
            return cura(&cd2);
        } else {
            return att_base();
        }
        break;

    case (11):  ///azione angelo
        if (ddtempo==0 && cd1==0){
            return dtempo(&cd1);
        } else if (dcura==0 && cd2==0 && hpm!=hp) {
            return cura(&cd2);
        } else {
            return att_base();
        }
        break;

    case (12):  ///azione drago
        if (daum_atk==0 && cd1==0){
            return aum_atk(&cd1);
        } else if (dcura==0 && cd2==0 && hpm!=hp) {
            return cura(&cd2);
        } else {
            return att_base();
        }
        break;

    case (13):  ///azione imperatore
        if (daum_atk==0 && cd1==0){
            return aum_atk(&cd1);
        } else if (ddtempo==0 && cd2==0) {
            return dtempo(&cd2);
        } else {
            return att_base();
        }
        break;

    case (14):  ///azione scagnozzo
        if (ddtempo==0 && cd1==0){
            return dtempo(&cd1);
        } else if (barr==0 && cd2==0) {
            return barriera(&cd2);
        } else {
            return att_base();
        }
        break;

    case (15):  ///azione paladino
        if (daum_dif==0 && cd1==0){
            return aum_dif(&cd1);
        } else if (daum_atk==0 && cd2==0) {
            return aum_atk(&cd2);
        } else {
            return att_base();
        }
        break;

    case (16):  ///azione stregone
        if (daum_atk==0 && cd1==0){
            return aum_atk(&cd1);
        } else if (dstun==0 && cd2==0) {
            return stun(&cd2);
        } else {
            return att_base();
        }
        break;
    }
    cout << "errore fatale" << endl;
    return 0;
}

int mostri::turno_m(int dmg, bool st, bool dt){
    int dan=0;
    if (dmg>0) tk_damage(dmg);
    contr_cur();
    if (tm==8) {
        cura_ossa();
    }
    get_dtempo(dt);
    stp_comb();
    if (morte()) {
        if (tm==4 && res==1)  {
            resuscita();
        } else {
            return -1;
        }
    }
    contr_cd();
    contr_dif();
    contr_atk();
    if (st==0 || tm==12){
        dan=dan+azione();
    } else {
        cout << "\n" << n << " non può agire perche' e' ancora stordito" << endl;
    }
    return dan;
}

void mostri::stp_cd(){
    cout << cd1 << cd2 << cd3 << endl;
}

void mostri::stp_comb(){			// visualizza le statistiche
    cout << "\n---------------------------------------------------------------------";
    cout << "\n\t\t\t\t\t" << n
    << "\n\t\t\t\t\thp=  " << hp << "/" << hpm
    << "\n\t\t\t\t\tatk= " << atk
    << "\n\t\t\t\t\tdef= " << def;
    if (barr>0) cout << "\n\t\t\t\t\tbarriera=  " << barr << "/" << hpm/4;
    cout << "\n---------------------------------------------------------------------";
}

void mostri::contr_cd(){
    if (cd1>0) cd1=cd1-1;
    if (cd2>0) cd2=cd2-1;
    if (ddtempo>0) ddtempo=ddtempo-1;
}

void mostri::resuscita() {  ///per fenice
    hp=hpm;
    res=0;
    cout << "\n" << n << " dopo essere diventata cenere torna in vita di nuovo" << endl;
}

void mostri::cura_ossa() {  ///per gigante
        int tmp=hpm/15;
        if (tmp>(hpm-hp)){
            tmp=hpm-hp;
        }
        hp=hp+tmp;
        cout << "\na " << n << " vengono ripristinati " << tmp << " punti vita" << endl;
}

void mostri::barr_streg() {     ///per stregone
    cout << "\n" << n << " crea una barriera che lo protegge" << endl;
    barr=hpm/4;
}



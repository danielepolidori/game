#include "player.hpp"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

player::player(std::string name)
{
    n=name;
    lvl=1;
    //hp = 150;
    //hpm=150;
    //atk = 35;
    hp = 250;
    hpm=250;
    atk = 50;
    def=25;
    x=0;
    y=0;
    a1=0;
    a2=0;
    a3=1;
    a4=0;
    a5=0;
    a6=0;
    a7=0;
    cd1=0;
    cd2=0;
    cd3=0;
    cd4=0;
    cd5=0;
    cd6=0;
    cd7=0;
    ps=0;
    exp=0;
    expm=100;
    ddtempo=0;
    dstun=0;
    daum_dif=0;
    daum_atk=0;
    barr=0;
    dcura=0;
    chatk=0;
}

player::~player(){

}

void player::movimento(char tmp) {

    if (tmp == 'w') {
        y=y-1;
    } else if (tmp == 's') {
        y=y+1;
    } else if (tmp == 'a') {
        x=x-1;
    } else if (tmp == 'd') {
        x=x+1;
    }
}

void player::azz_coo(){

	x = 0 ;
	y = 0 ;
}

void player::mod_coo(int x_new, int y_new){

	x = x_new ;
	y = y_new ;
}

void player::stat(){			// visualizza le statistiche
    cout << "\nIl giocatore " << n << " ha le seguenti stat:\n"
    <<"lvl=" << lvl
    <<"\nexp=" << exp << "/" << expm
    <<"\nhp=" << hp << "/" << hpm
    << "\natk=" << atk
    << "\ndef=" << def << endl;
}

void player::skills(){			// visualizza le skill
    cout << "il giocatore " << n << " ha le seguenti skills:\n"
    << "colpo letale: infligge una gran quantita' di danni sul colpo;\ne' attualmente al livello " << a1
    << "\ncarica brutale: oltre a infliggere danno stordisce il nemico\ne' attualmente al livello " << a2
    << "\nsanguinamento: oltre a infliggere danno applica un debuff al nemico che perdera' un ammontare di vita costante per ogni turno\ne' attualmente al livello " << a3 << endl;
}

void player::stp_comb(){			// visualizza le statistiche
    cout << "\n---------------------------------------------------------------------";
    cout << "\n\t\t" << n
    << "\n\t\thp=  " << hp << "/" << hpm
    << "\n\t\tatk= " << atk
    << "\n\t\tdef= " << def << endl;
    if (barr>0) cout << "\n\t\tbarriera=  " << barr << "/" << hpm/4;
    cout << "\n---------------------------------------------------------------------";
}

void player::contr_cd(){
    if (cd1>0) cd1=cd1-1;
    if (cd2>0) cd2=cd2-1;
    if (cd3>0) cd3=cd3-1;
    if (cd4>0) cd4=cd4-1;
    if (cd5>0) cd5=cd5-1;
    if (cd6>0) cd6=cd6-1;
    if (cd7>0) cd7=cd7-1;
    if (ddtempo>0) ddtempo=ddtempo-1;
}

void player::reset_cd(){
    cd1=0;
    cd2=0;
    cd3=0;
    cd4=0;
    cd5=0;
    cd6=0;
    cd7=0;
}

void player::gexp(int n){   //aumenta l'esperienza di un'ammontare in input
    exp=exp+n;
	lvl_up();
}

int player::glvl(){
	return lvl;
}

int player::azione() {
    int dmg=-1;
    string q;
    while (dmg<0) {
        cout << "\n" << n << ": inserire 0 per attacco base";
        if (a1 && cd1==0) cout << ", 1 per sanguinamento";
        if (a2 && cd2==0) cout << ", 2 per carica brutale";
        if (a3 && cd3==0) cout << ", 3 per colpo letale";
        if (a4 && cd4==0) cout << ", 4 per rinforzo";
        if (a5 && cd5==0) cout << ", 5 per rabbia";
        if (a6 && cd6==0) cout << ", 6 per barriera";
        if (a7 && cd7==0) cout << ", 7 per cura";
	cout << endl;




        //getline(cin,q);
        cin >> q ;

        if (q=="0") {
            dmg=att_base();
        } else if (q=="1") {
            if (a1==0) {
                cout << "\nLa mossa non e' stata sbloccata" << endl;
            } else if (cd1>0){
                cout << "\nPer usare sanguinamento devi aspettare " << cd1 << " turni" << endl;
            } else {
                dmg=dtempo(&cd1);
            }
        } else if (q=="2") {
            if (a2==0) {
                cout << "\nLa mossa non e' stata sbloccata" << endl;
            } else if (cd2>0){
                cout << "\nPer usare carica brutale devi aspettare " << cd2 << " turni" << endl;
            } else {
                dmg=stun(&cd2);
            }
        } else if (q=="3") {
            if (a3==0) {
                cout << "\nLa mossa non e' stata sbloccata" << endl;
            } else if (cd3>0){
                cout << "\nper usare colpo letale devi aspettare " << cd3 << " turni" << endl;
            } else {
                dmg=att_pot(&cd3);
            }
        } else if (q=="4") {
            if (a4==0) {
                cout << "\nLa mossa non e' stata sbloccata" << endl;
            } else if (cd4>0){
                cout << "\nper usare rinforzo devi aspettare " << cd4 << " turni" << endl;
            } else {
                dmg=aum_dif(&cd4);
            }
        } else if (q=="5") {
            if (a5==0) {
                cout << "\nLa mossa non e' stata sbloccata" << endl;
            } else if (cd5>0){
                cout << "\nPer usare rabbia devi aspettare " << cd5 << " turni" << endl;
            } else {
                dmg=aum_atk(&cd5);
            }
        } else if (q=="6") {
            if (a6==0) {
                cout << "\nLa mossa non e' stata sbloccata" << endl;
            } else if (cd6>0){
                cout << "\nPer usare barriera devi aspettare " << cd6 << " turni" << endl;
            } else {
                dmg=barriera(&cd6);
            }
        } else if (q=="7") {
            if (a7==0) {
                cout << "\nLa mossa non e' stata sbloccata" << endl;
            } else if (cd7>0){
                cout << "\nPer usare cura devi aspettare " << cd7 << " turni" << endl;
            } else {
                dmg=cura(&cd7);
            }
        } else if (q=="123456789") {
            cheat_hp();
            cout << "\nInserito trucco vita" << endl;
        } else if (q=="987654321") {
            cheat_atk();
        }else {
            cout << "\nE' stato inserito un carattere non valido" << endl;
        }
    }
    return dmg;
}

int player::turno_p(int dmg, bool st, bool dt){
        int dan=0;
        if (dmg>0) tk_damage(dmg);
        contr_cur();
        get_dtempo(dt);
        stp_comb();
        if (morte()) {
            return -1;
        }
        contr_cd();
        contr_dif();
        contr_atk();
        if (st==0){
            dan=azione();
        } else {
            cout << "\n" << n << " non puo' agire perche' e' ancora stordito" << endl;
        }
        return dan;
}

void player::lvl_up(){                  //aumento delle statistiche per ogni aumento di livello
    while (exp>=expm){
        string tmp;
        tmp="0";
        exp=exp-expm;
        expm=expm*3;
        lvl=lvl+1;
        hpm = (hpm*150)/100;
        hp=hpm;
        atk = (atk*150)/100;
	cout << "\n" << n << " e' salito al livello " << lvl << "!" << endl;
        if (lvl%3==0 && lvl<=18){
            while (tmp=="0"){
                cout << "\n" << n << " scegli la skill da migliorare:" << endl;
                if (!a1) cout << "1 per sanguinamento" << endl;
                if (!a2) cout << "2 per carica brutale" << endl;
                if (!a3) cout << "3 per colpo letale" << endl;
                if (!a4) cout << "4 per rinforzo" << endl;
                if (!a5) cout << "5 per rabbia" << endl;
                if (!a6) cout << "6 per barriera" << endl;
                if (!a7) cout << "7 per cura" << endl;

                cin >> tmp;
                if (tmp == "1") {
                    if (a1) {
                        cout << "\nSanguinamento e' gia' stato sbloccato, selezionare una mossa da sbloccare"  << endl;
                        tmp="0";
                    } else {
                        a1=1;
			cout << "\nHai sbloccato sanguinamento, per usare sanguinamento premi il tasto 1 quando sei in combattimento"  << endl;
                    }
                } else if (tmp == "2") {
                    if (a2) {
                        cout << "\nCarica brutale e' gia' stata sbloccata, selezionare una mossa da sbloccare"  << endl;
                        tmp="0";
                    } else {
                        a2=1;
			cout << "\nHai sbloccato carica brutale, per usare carica brutale premi il tasto 2 quando sei in combattimento"  << endl;
                    }
                } else if (tmp == "3") {
                    if (a3) {
                        cout << "\nColpo letale e' gia' stato sbloccato, selezionare una mossa da sbloccare"  << endl;
                        tmp="0";
                    } else {
                        a3=1;
			cout << "\nHai sbloccato colpo letale, per usare colpo letale premi il tasto 3 quando sei in combattimento"  << endl;
                    }
                } else if (tmp == "4") {
                    if (a4) {
                        cout << "\nRinforzo e' gia' stato sbloccato, selezionare una mossa da sbloccare"  << endl;
                        tmp="0";
                    } else {
                        a4=1;
			cout << "\nHai sbloccato rinforzo, per usare rinforzo premi il tasto 4 quando sei in combattimento"  << endl;
                    }
                } else if (tmp == "5") {
                    if (a5) {
                        cout << "\nRabbia e' gia' stata sbloccata, selezionare una mossa da sbloccare"  << endl;
                        tmp="0";
                    } else {
                        a5=1;
			cout << "\nHai sbloccato rabbia, per usare rabbia premi il tasto 5 quando sei in combattimento"  << endl;
                    }
                } else if (tmp == "6") {
                    if (a6) {
                        cout << "\nBarriera e' gia' stata sbloccata, selezionare una mossa da sbloccare"  << endl;
                        tmp="0";
                    } else {
                        a6=1;
			cout << "\nHai sbloccato barriera, per usare barriera premi il tasto 6 quando sei in combattimento"  << endl;
                    }
                } else if (tmp == "7") {
                    if (a7) {
                        cout << "\nCura e' gia' stata sbloccata, selezionare una mossa da sbloccare"  << endl;
                        tmp="0";
                    } else {
                        a7=1;
			cout << "\nHai sbloccato cura, per usare cura premi il tasto 7 quando sei in combattimento"  << endl;
                    }
                } else {
                    cout << "\nInserire un carattere valido"  << endl;
                    tmp="0";
                }
            }
        }
    }
}

void player::cheat_hp(){
    hp=hpm;
}

void player::cheat_atk(){
    if (chatk==0){
        atk=atk*5;
        cout << "\nAttivato trucco attacco" << endl;
    } else {
        atk=atk/5;
        cout << "\nDisattivato trucco attacco" << endl;
    }
}

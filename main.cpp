#include <iostream>

using namespace std;

struct knoten {
 int info;
 knoten *next;
};


class Ablage
{

public:
    int cnt = 0;

    knoten* oben = NULL;
    Ablage();
    Ablage(int cnt, knoten* oben);

    void drauflegen(int x);
    void runternehmen();
    void top();
};




int main()
{
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    knoten* oben1 = NULL, oben2, oben3;

    Ablage Ablage1(cnt1, oben1), Ablage2(cnt2, &oben2), Ablage3(cnt3, &oben3);

    Ablage1.drauflegen(23);                     //Wert 23 wird gespeichert
    cout << "Wert 1 der Ursprungsablage: ";
    Ablage1.top();                              //oberster Wert (23) wird ausgegeben
    Ablage1.drauflegen(56);
    cout << "Wert 2 der Ursprungsablage: ";
    Ablage1.top();
    Ablage1.drauflegen(78);
    cout << "Wert 3 der Ursprungsablage: ";
    Ablage1.top();                              //oberster Wert (78) wird ausgegeben




    Ablage2.drauflegen(Ablage1.oben->info);     //oberster Wert der Ablage1 wird auf die Ablage2 gelegt
    Ablage1.top();
    Ablage1.runternehmen();
    Ablage2.drauflegen(Ablage1.oben->info);     //nächster Wert auf die Ablage2 ist der Wert der Ablage1 nach einem "runternehmen()"
    Ablage1.top();                              //oberster Wert der Ablage1 nach einem "runternehmen()"
    Ablage1.runternehmen();
    Ablage2.drauflegen(Ablage1.oben->info);
    Ablage1.top();
    Ablage1.runternehmen();                     //letzer Wert wird gelöscht, um memory-leaks zu vermeiden


    Ablage3.drauflegen(Ablage2.oben->info);     //Siehe Block oben, nur zwischen Ablage3 und Ablage2
    Ablage2.top();
    Ablage2.runternehmen();
    cout << "Wert 1 der End-Ablage: ";
    Ablage3.top();
    Ablage3.drauflegen(Ablage2.oben->info);
    Ablage2.top();
    Ablage2.runternehmen();
    cout << "Wert 2 der End-Ablage: ";
    Ablage3.top();
    Ablage3.drauflegen(Ablage2.oben->info);
    Ablage2.top();
    Ablage2.runternehmen();
    cout << "Wert 3 der End-Ablage: ";
    Ablage3.top();

    // Anti-Memoryleak:
    Ablage3.runternehmen();
    Ablage3.runternehmen();
    Ablage3.runternehmen();

}

Ablage::Ablage(){};

Ablage::Ablage(int T_cnt, knoten* T_oben) : cnt(T_cnt), oben(T_oben){};


void::Ablage::top(){
    if (cnt > 0)        // Avoid NULL reference
    cout << oben->info << endl;     // Wert auf welches Zeiger "oben" zeigt
}

void::Ablage::drauflegen(int x){
    knoten *p = new knoten; // erzeuge neuen Knoten

    p->info = x; // Infowert wird x
    p->next = oben; // next-Wert wird initialisiert mit Positionszeiger
    // es wird also VOR dem aktuellen Element eingefügt
    oben = p; // Positionszeiger zeigt nun auf das neue Element

    cnt++; // Zähler erhöhen
}

void::Ablage::runternehmen() {
 knoten * help; // Merken des Nachfolgers des Positionszeigers

 if (cnt == 0) // Nur sinnvoll, wenn es mindestens ein Element gibt
 help = NULL;
 else {
 help = oben-> next;
 cnt--; // Zähler verringern
 }

 delete oben; // Speicher aufräumen

 oben = help; // Positionszeiger wird ehemaliger Nachfolger
}


//Definitionen alle gleich wie in der "Ablage"

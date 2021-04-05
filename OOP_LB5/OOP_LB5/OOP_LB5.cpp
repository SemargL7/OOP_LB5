/*Створити базовий клас УПАКУВАННЯ ДЛЯ ЛІКІВ(задаються назва, розмір упакування (ширина, довжина, висота).

Створити похідні класи УПАКУВАННЯ ДЛЯ ЛІКІВ У ТАБЛЕТКАХ (задається вага таблеток з упакуванням) та УПАКУВАННЯ ДЛЯ ЛІКІВ У ПОРОШКАХ (задається вага порошку).
Для введених даних про різні ліки, наявні в аптеці,                                                                                         
обчислити їх сумарну вагу та сумарний об’єм і визначити чи можна розмістити ці ліки у певній тарі із заданими максимально можливим об’ємом і максимально можливою вагою

Для перевірки використати масив вказівників на об’єкти базового класу,
яким присвоїти адреси об’єктів похідних класів.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int n; int m;

class PFM {
private:
    char name[30];
    int l;
    int w;
    int h;
public:
    PFM() {}
    PFM(char n[], int l, int w, int h) { strcpy(name, n); this->l = l; this->w = w; this->h = h;
    }
    ~PFM() {}

    void SetName(char a[30]) { strcpy(name, a); }
    void SetL(int a) { l = a; }
    void SetW(int a) { w = a; }
    void SetH(int a) { h = a; }

    string GetName() { return name; }
    int GetL() { return l; }
    int GetW() { return w; }
    int GetH() { return h; }
};

class PFM_T : public PFM {
private:
    int weight;
public:
    PFM_T() :PFM() {}
    PFM_T(char n[], int l, int w, int h, int wT) :PFM(n, l, w, h), weight(wT) {}
    ~PFM_T() {}

    void SetWeight(int a) { weight = a; }

    int GetWeight() { return weight; }
};

class PFM_P : public PFM {
private:
    int weight;
public:
    PFM_P() :PFM() {}
    PFM_P(char n[], int l, int w, int h, int wT) :PFM(n, l, w, h), weight(wT) {}
    ~PFM_P() {}

    void SetWeight(int a) { weight = a; }

    int GetWeight() { return weight; }
};

int sum_weight(PFM_T a[]) {
    int sum_w = 0;
    for (int i = 0; i < n; i++) {
        sum_w += a[i].GetWeight();
    }
    return sum_w;
}
int sum_weight(PFM_P a[]) {
    int sum_w = 0;
    for (int i = 0; i < m; i++) {
        sum_w += a[i].GetWeight();
    }
    return sum_w;
}
int sum_volume(PFM a[], int q) {
    int sum_v = 0;
    for (int i = 0; i < q; i++) {
        sum_v += a[i].GetL() * a[i].GetW() * a[i].GetH();
    }
    return sum_v;
}
void Input(PFM_T* ex) {
    cout << "Name: ";
    char a[30];
    scanf("%s", &a);
    getchar; getchar;



    cout << "Size(mm)\n";
    int l = 0, w = 0, h = 0;
    cout << "L: ";
    cin >> l; 
    cout << "W: ";
    cin >> w;
    cout << "H: ";
    cin >> h;


    int c;
    cout << "Weight(in grams): ";
    cin >> c;

    ex->SetName(a);

    ex->SetL(l);
    ex->SetW(w);
    ex->SetH(h);

    ex->SetWeight(c);
    cout << "\n";
}
void Input(PFM_P* ex) {
    cout << "Name: ";
    char a[30];
    scanf("%s", &a);
    getchar; getchar;



    cout << "Size(mm)\n";
    int l = 0, w = 0, h = 0;
    cout << "L: ";
    cin >> l;
    cout << "W: ";
    cin >> w;
    cout << "H: ";
    cin >> h;


    int c;
    cout << "Weight(in grams): ";
    cin >> c;

    ex->SetName(a);

    ex->SetL(l);
    ex->SetW(w);
    ex->SetH(h);

    ex->SetWeight(c);
    cout << "\n";
}

int main() {
    //Вводимо інформацію в класи
    cout << "How many drugs(pills) is in batch?" << endl;
    cin >> n;
    cout << "How many drugs(powder) is in batch?" << endl;
    cin >> m;
    PFM_T* batch_of_drugs_T = new PFM_T[n];
    PFM_P* batch_of_drugs_P = new PFM_P[m];
    for (int i = 0; i < n; i++) {
        Input(&batch_of_drugs_T[i]);
    }
    for (int i = 0; i < m; i++) {
        Input(&batch_of_drugs_P[i]);
    }

    //Задаєм максимальні значення тарі(об'єм, вагу)
    int tara_w, tara_v;
    cout << "Tara max find out the weight(grams): ";
    cin >> tara_w;
    cout << "Tara max find out the volume(mm^3): ";
    cin >> tara_v;
    //Якщо тара може зважити, то виведе інформацію
    (sum_weight(batch_of_drugs_T) + sum_weight(batch_of_drugs_P) <= tara_w) && sum_volume(batch_of_drugs_T, n) + sum_volume(batch_of_drugs_P, m) <= tara_v
        ? cout << "Weight of batch of drugs " << sum_weight(batch_of_drugs_T) + sum_weight(batch_of_drugs_P) << " grams" << endl
        << "Volume of batch of drugs " << sum_volume(batch_of_drugs_T, n) + sum_volume(batch_of_drugs_P, m) << " mm^3" << endl
        : cout << "weight/volume is too big" << endl;
    //Створюємо масив із базовим класом і задаємо параметри уже створених похідних
    PFM* ptr_batch_of_drugs = new PFM[n+m];
    for (int i = 0; i < n; i++) {
        ptr_batch_of_drugs[i] = batch_of_drugs_T[i];
    }
    
    for (int i = 0; i < m; i++) {
        ptr_batch_of_drugs[i+n] = batch_of_drugs_P[i];
    }
    
    //Виводимо
    for (int i = 0; i < n+m; i++) {
        cout <<"Name: " << ptr_batch_of_drugs[i].GetName() << endl;
        cout <<"Volume: " <<ptr_batch_of_drugs[i].GetL() * ptr_batch_of_drugs[i].GetW() * ptr_batch_of_drugs[i].GetH()
            << "(" << ptr_batch_of_drugs[i].GetL()<<"x"<<ptr_batch_of_drugs[i].GetW()<<"x"<<ptr_batch_of_drugs[i].GetH()<< ")" << endl << endl;
    }
}
//POP 2017-12-14 projekt 1 Rogaczewski Patryk; kompilator: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609; środowisko programistyczne: Visual Studio Code
 
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
//Funckje w programie:
void start(string plansza[10][10]);
void show(string plansza[10][10]);
void zapis_historia_gracz1(string x, string y, string p, string r);
void zapis_historia_gracz2(string x, string y, string p, string r);
void odczythistoria();
void pomoc();
void damka(string plansza[10][10], int m, int n, int a, int b);
void white_move(string plansza[10][10], int m, int n, int a, int b, string x, string y, string p, string r);
void black_move(string plansza[10][10], int m, int n, int a, int b, string x, string y, string p, string r);
void check_gracz1(string plansza[10][10]);
void check_gracz2(string plansza[10][10]);
void aktualny_wynik(string plansza[10][10], int &suma_1, int &suma_2);
bool gracz1(string plansza[10][10], int m, int n, int a, int b);
bool gracz2(string plansza[10][10], int m, int n, int a, int b);
bool menu_1(string plansza[10][10], int suma_1, int suma_2);
void menu_2(string plansza[10][10],int suma_1, int suma_2);
void whitedamka_change(string plansza[10][10]);
void blackdamka_change(string plansza[10][10]);
void wynik_gracz1(string plansza[10][10], int &suma_1);
void wynik_gracz2(string plansza[10][10], int &suma_2);
/////////////////////////////////////////////////////////////////////////////////////
//Funkcja przypisująca wartości odpowiednim polom na planszy
void start(string plansza[10][10])
{
    plansza[0][0] = "A";
    plansza[0][1] = "x";
    plansza[0][2] = ".";
    plansza[0][3] = "x";
    plansza[0][4] = ".";
    plansza[0][5] = "x";
    plansza[0][6] = ".";
    plansza[0][7] = "x";
    plansza[0][8] = ".";
    ////////////////////
    plansza[1][0] = "B";
    plansza[1][1] = ".";
    plansza[1][2] = "x";
    plansza[1][3] = ".";
    plansza[1][4] = "x";
    plansza[1][5] = ".";
    plansza[1][6] = "x";
    plansza[1][7] = ".";
    plansza[1][8] = "x"; 
    ////////////////////
    plansza[2][0] = "C";
    plansza[2][1] = ".";
    plansza[2][2] = ".";
    plansza[2][3] = ".";
    plansza[2][4] = ".";
    plansza[2][5] = ".";
    plansza[2][6] = ".";
    plansza[2][7] = ".";
    plansza[2][8] = ".";
    ////////////////////
    plansza[3][0] = "D";
    plansza[3][1] = ".";
    plansza[3][2] = ".";
    plansza[3][3] = ".";
    plansza[3][4] = ".";
    plansza[3][5] = ".";
    plansza[3][6] = ".";
    plansza[3][7] = ".";
    plansza[3][8] = ".";
    ////////////////////
    plansza[4][0] = "E";
    plansza[4][1] = ".";
    plansza[4][2] = ".";
    plansza[4][3] = ".";
    plansza[4][4] = ".";
    plansza[4][5] = ".";
    plansza[4][6] = ".";
    plansza[4][7] = ".";
    plansza[4][8] = ".";
    ////////////////////
    plansza[5][0] = "F";
    plansza[5][1] = ".";
    plansza[5][2] = ".";
    plansza[5][3] = ".";
    plansza[5][4] = ".";
    plansza[5][5] = ".";
    plansza[5][6] = ".";
    plansza[5][7] = ".";
    plansza[5][8] = ".";
    ////////////////////
    plansza[6][0] = "G";
    plansza[6][1] = "o";
    plansza[6][2] = ".";
    plansza[6][3] = "o";
    plansza[6][4] = ".";
    plansza[6][5] = "o";
    plansza[6][6] = ".";
    plansza[6][7] = "o";
    plansza[6][8] = ".";
    ////////////////////
    plansza[7][0] = "H";
    plansza[7][1] = ".";
    plansza[7][2] = "o";
    plansza[7][3] = ".";
    plansza[7][4] = "o";
    plansza[7][5] = ".";
    plansza[7][6] = "o";
    plansza[7][7] = ".";
    plansza[7][8] = "o";
    ////////////////////
    plansza[8][0] = "/";
    plansza[8][1] = "1";
    plansza[8][2] = "2";
    plansza[8][3] = "3";
    plansza[8][4] = "4";
    plansza[8][5] = "5";
    plansza[8][6] = "6";
    plansza[8][7] = "7";
    plansza[8][8] = "8";
}
//Funckja rysująca planszę na ekranie
void show(string plansza[10][10])
{
    ////////////////////
    cout << "-------------------" << endl;
    cout << "|  Gra w warcaby  |"  << endl;
    cout << "-------------------" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[0][0] << "|" << plansza[0][1] << "|" << plansza[0][2] << "|" << plansza[0][3] << "|" << plansza[0][4];
    cout << "|" << plansza[0][5] << "|" << plansza[0][6] << "|" << plansza[0][7] << "|" << plansza[0][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[1][0] << "|" << plansza[1][1] << "|" << plansza[1][2] << "|" << plansza[1][3] << "|" << plansza[1][4];
    cout << "|" << plansza[1][5] << "|" << plansza[1][6] << "|" << plansza[1][7] << "|" << plansza[1][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[2][0] << "|" << plansza[2][1] << "|" << plansza[2][2] << "|" << plansza[2][3] << "|" << plansza[2][4];
    cout << "|" << plansza[2][5] << "|" << plansza[2][6] << "|" << plansza[2][7] << "|" << plansza[2][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[3][0] << "|" << plansza[3][1] << "|" << plansza[3][2] << "|" << plansza[3][3] << "|" << plansza[3][4];
    cout << "|" << plansza[3][5] << "|" << plansza[3][6] << "|" << plansza[3][7] << "|" << plansza[3][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[4][0] << "|" << plansza[4][1] << "|" << plansza[4][2] << "|" << plansza[4][3] << "|" << plansza[4][4];
    cout << "|" << plansza[4][5] << "|" << plansza[4][6] << "|" << plansza[4][7] << "|" << plansza[4][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[5][0] << "|" << plansza[5][1] << "|" << plansza[5][2] << "|" << plansza[5][3] << "|" << plansza[5][4];
    cout << "|" << plansza[5][5] << "|" << plansza[5][6] << "|" << plansza[5][7] << "|" << plansza[5][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[6][0] << "|" << plansza[6][1] << "|" << plansza[6][2] << "|" << plansza[6][3] << "|" << plansza[6][4];
    cout << "|" << plansza[6][5] << "|" << plansza[6][6] << "|" << plansza[6][7] << "|" << plansza[6][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[7][0] << "|" << plansza[7][1] << "|" << plansza[7][2] << "|" << plansza[7][3] << "|" << plansza[7][4];
    cout << "|" << plansza[7][5] << "|" << plansza[7][6] << "|" << plansza[7][7] << "|" << plansza[7][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "|" << plansza[8][0] << "|" << plansza[8][1] << "|" << plansza[8][2] << "|" << plansza[8][3] << "|" << plansza[8][4];
    cout << "|" << plansza[8][5] << "|" << plansza[8][6] << "|" << plansza[8][7] << "|" << plansza[8][8] << "|" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "------------------- " << endl;
}
//Funkcja odpowiedzialna za ruch białych pionków
void white_move(string plansza[10][10], int m, int n, int a, int b, string x, string y, string p, string r)
{
    int w,w2,k1,k2,k3,k4;
    string bufor;
    w = m - 1;
    w2 = m - 2;
    k1 = n - 1;
    k2 = n + 1;
    k3 = n - 2;
    k4 = n + 2;
    if(w>=0 && w<=7 && k1>=1 && k1<=8 && k2>=1 && k2<=8)
    {
        if(w2>=0 && w<=7 && k3>=1 && k3<=8 && k4>=1 && k4<=8)
        {
            if(plansza[w][k1]=="x" && plansza[w][k2]=="x" || plansza[w][k1]=="X" && plansza[w][k2]=="X" || plansza[w][k1]=="x" && plansza[w][k2]=="X" || plansza[w][k1]=="X" && plansza[w][k2]=="x")
            {
                if(plansza[w2][k3]=="." && plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k3)
                    {
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else if(a==w2 && b==k4)
                    {   
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }
                else if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                }
                else if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {   
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }

            }
            else if(plansza[w][k1]=="." && plansza[w][k2]=="x" || plansza[w][k1]=="." && plansza[w][k2]=="X")
            {
                if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {   
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k1)
                    {
                        bufor = plansza[w][k1];
                        plansza[w][k1] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }

            }
            else if(plansza[w][k1]=="x" && plansza[w][k2]=="." || plansza[w][k1]=="X" && plansza[w][k2]==".")
            {
                if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {   
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k2)
                    {
                        bufor = plansza[w][k2];
                        plansza[w][k2] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="o" && plansza[w][k2]=="o" || plansza[w][k1]=="O" && plansza[w][k2]=="O" || plansza[w][k1]=="o" && plansza[w][k2]=="O" || plansza[w][k1]=="O" && plansza[w][k2]=="o")
            {
                if(a==w && b==k1)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
                else if(a==w && b==k2)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
                else if(a==w2 && b==k3)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
                else if(a==w2 && b==k4)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            else if(plansza[w][k1]=="o" && plansza[w][k2]=="x" || plansza[w][k1]=="O" && plansza[w][k2]=="x" || plansza[w][k1]=="o" && plansza[w][k2]=="X" || plansza[w][k1]=="O" && plansza[w][k2]=="X")
            {
                if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {   
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k1)
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="x" && plansza[w][k2]=="o" || plansza[w][k1]=="x" && plansza[w][k2]=="O" || plansza[w][k1]=="X" && plansza[w][k2]=="o" || plansza[w][k1]=="X" && plansza[w][k2]=="O")
            {
                if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {   
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k2)
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }
            }///dodano modyfikacje
            else if(plansza[w][k1]=="o" && plansza[w][k2]=="." || plansza[w][k1]=="O" && plansza[w][k2]==".")
            {
                if(plansza[w2][k3]=="o" || plansza[w2][k3]=="O" || plansza[w2][k3]=="x" || plansza[w2][k3]=="X" || plansza[w2][k3]==".")
                {
                    if(a==w && b==k2)
                    {
                        bufor = plansza[w][k2];
                        plansza[w][k2] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]=="o" || plansza[w][k1]=="." && plansza[w][k2]=="O")
            {
                if(plansza[w2][k4]=="o" || plansza[w2][k4]=="O" || plansza[w2][k4]=="x" || plansza[w2][k4]=="X" || plansza[w2][k4]==".")
                {
                    if(a==w && b==k1)
                    {
                        bufor = plansza[w][k1];
                        plansza[w][k1] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }
            }
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else if(plansza[w][k1]=="." && plansza[w][k2]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                } 
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }

            }

        }
        else if(w2>=0 && w<=7 && k3>=1 && k3<=8)
        {
            if(plansza[w][k1]=="x" && plansza[w][k2]=="." || plansza[w][k1]=="X" && plansza[w][k2]==".")
            {
                if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k2)
                    {
                        bufor = plansza[w][k2];
                        plansza[w][k2] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="o" && plansza[w][k2]=="." || plansza[w][k1]=="O" && plansza[w][k2]==".")
            {
                if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else if(plansza[w][k1]=="." && plansza[w][k2]=="x" || plansza[w][k1]=="." && plansza[w][k2]=="X" || plansza[w][k1]=="." && plansza[w][k2]=="o" || plansza[w][k1]=="." && plansza[w][k2]=="O")
            {
            if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                } 
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                } 
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }

        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if(w2>=0 && w<=7 && k4>=1 && k4<=8)
        {
            if(plansza[w][k1]=="." && plansza[w][k2]=="x" || plansza[w][k1]=="." && plansza[w][k2]=="X")
            {
                if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k1)
                    {
                        bufor = plansza[w][k1];
                        plansza[w][k1] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz1(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]=="o" || plansza[w][k1]=="." && plansza[w][k2]=="O")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else if(plansza[w][k1]=="x" && plansza[w][k2]=="." || plansza[w][k1]=="X" && plansza[w][k2]=="." || plansza[w][k1]=="o" && plansza[w][k2]=="." || plansza[w][k1]=="." && plansza[w][k2]=="O")
            {
                if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                } 
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                } 
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else
        {
            if(plansza[w][k1]=="." && plansza[w][k2]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            else if(plansza[w][k1]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            else if(plansza[w][k2]==".")
            {
                if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz1(plansza);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(w>=0 && w<=7 && k1>=1 && k1<=8)
    {
        if(w2>=0 && w2<=7 && k3>=1 && k3<=8)
        {
            if(plansza[w][k1]=="x" || plansza[w][k1]=="X")
            {
                if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;

                    }
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            else if(plansza[w][k1]=="o" || plansza[w][k1]=="O")
            {
                if(a==w && b==k1)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            else if(plansza[w][k1]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                }
            }
        }
        else if(plansza[w][k1]=="x" || plansza[w][k1]=="X" || plansza[w][k1]=="o" || plansza[w][k1]=="O")
        {
            if(a==w && b==k1)
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz1(plansza);
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz1(plansza);
            }
        }
        else if(plansza[w][k1]==".")
        {
            if(a==w && b==k1)
            {
                bufor = plansza[w][k1];
                plansza[w][k1] = plansza[m][n];
                plansza[m][n] = bufor;
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz1(plansza);
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(w>=0 && w<=7 && k2>=1 && k2<=8)
    {
        if(w2>=0 && w2<=7 && k4>=1 && k4<=8)
        {
            if(plansza[w][k2]=="x" || plansza[w][k2]=="X")
            {
                if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz1(x,y,p,r);

                    }
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            else if(plansza[w][k2]=="o" || plansza[w][k2]=="O")
            {
                if(a==w && b==k2)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz1(plansza);
                }
            }
            else if(plansza[w][k2]==".")
            {
                if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz1(x,y,p,r);
                }
            }
        }
        else if(plansza[w][k2]=="x" || plansza[w][k2]=="X" || plansza[w][k2]=="o" || plansza[w][k2]=="O")
        {
            if(a==w && b==k2)
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz1(plansza);
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz1(plansza);
            }
        }
        else if(plansza[w][k2]==".")
        {
            if(a==w && b==k2)
            {
                bufor = plansza[w][k2];
                plansza[w][k2] = plansza[m][n];
                plansza[m][n] = bufor;
                zapis_historia_gracz1(x,y,p,r);
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz1(plansza);
            }
        }
    }
    else
    {
        cout << "Nie można wykonać ruchu!";
        check_gracz1(plansza);
    }
}
//Funkcja odpowiedzialna za ruch czarnych pionków
void black_move(string plansza[10][10], int m, int n, int a, int b, string x, string y, string p, string r)
{
    int w,w2,k1,k2,k3,k4;
    string bufor;
    w = m + 1;
    w2 = m + 2;
    k1 = n - 1;
    k2 = n + 1;
    k3 = n - 2;
    k4 = n + 2;
    if(w>=0 && w<=7 && k1>=1 && k1<=8 && k2>=1 && k2<=8)
    {
        if(w2>=0 && w<=7 && k3>=1 && k3<=8 && k4>=1 && k4<=8)
        {
            if(plansza[w][k1]=="o" && plansza[w][k2]=="o" || plansza[w][k1]=="O" && plansza[w][k2]=="O" || plansza[w][k1]=="o" && plansza[w][k2]=="O" || plansza[w][k1]=="O" && plansza[w][k2]=="o")
            {
                if(plansza[w2][k3]=="." && plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k3)
                    {
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else if(a==w2 && b==k4)
                    {   
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }
                else if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                }
                else if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {   
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }

            }
            else if(plansza[w][k1]=="." && plansza[w][k2]=="o" || plansza[w][k1]=="." && plansza[w][k2]=="O")
            {
                if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {   
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k1)
                    {
                        bufor = plansza[w][k1];
                        plansza[w][k1] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }

            }
            else if(plansza[w][k1]=="o" && plansza[w][k2]=="." || plansza[w][k1]=="O" && plansza[w][k2]==".")
            {
                if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {   
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k2)
                    {
                        bufor = plansza[w][k2];
                        plansza[w][k2] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="x" && plansza[w][k2]=="x" || plansza[w][k1]=="X" && plansza[w][k2]=="X" || plansza[w][k1]=="x" && plansza[w][k2]=="X" || plansza[w][k1]=="X" && plansza[w][k2]=="x")
            {
                if(a==w && b==k1)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
                else if(a==w && b==k2)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
                else if(a==w2 && b==k3)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
                else if(a==w2 && b==k4)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            else if(plansza[w][k1]=="x" && plansza[w][k2]=="o" || plansza[w][k1]=="X" && plansza[w][k2]=="o" || plansza[w][k1]=="x" && plansza[w][k2]=="O" || plansza[w][k1]=="X" && plansza[w][k2]=="O")
            {
                if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {   
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k1)
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="o" && plansza[w][k2]=="x" || plansza[w][k1]=="o" && plansza[w][k2]=="X" || plansza[w][k1]=="O" && plansza[w][k2]=="x" || plansza[w][k1]=="O" && plansza[w][k2]=="X")
            {
                if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {   
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k2)
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }
            }
            ///
            else if(plansza[w][k1]=="x" && plansza[w][k2]=="." || plansza[w][k1]=="X" && plansza[w][k2]==".")
            {
                if(plansza[w2][k3]=="x" || plansza[w2][k3]=="X" || plansza[w2][k3]=="o" || plansza[w2][k3]=="O" || plansza[w2][k3]==".")
                {
                    if(a==w && b==k2)
                    {
                        bufor = plansza[w][k2];
                        plansza[w][k2] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]=="x" || plansza[w][k1]=="." && plansza[w][k2]=="X")
            {
                if(plansza[w2][k4]=="x" || plansza[w2][k4]=="X" || plansza[w2][k4]=="o" || plansza[w2][k4]=="O" || plansza[w2][k4]==".")
                {
                    if(a==w && b==k1)
                    {
                        bufor = plansza[w][k1];
                        plansza[w][k1] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                } 
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }

            }

        }
        else if(w2>=0 && w<=7 && k3>=1 && k3<=8)
        {
            if(plansza[w][k1]=="o" && plansza[w][k2]=="." || plansza[w][k1]=="O" && plansza[w][k2]==".")
            {
                if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k2)
                    {
                        bufor = plansza[w][k2];
                        plansza[w][k2] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="x" && plansza[w][k2]=="." || plansza[w][k1]=="X" && plansza[w][k2]==".")
            {
                if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else if(plansza[w][k1]=="." && plansza[w][k2]=="o" || plansza[w][k1]=="." && plansza[w][k2]=="O" || plansza[w][k1]=="." && plansza[w][k2]=="x" || plansza[w][k1]=="." && plansza[w][k2]=="X")
            {
               if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                } 
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                } 
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }

        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if(w2>=0 && w<=7 && k4>=1 && k4<=8)
        {
            if(plansza[w][k1]=="." && plansza[w][k2]=="o" || plansza[w][k1]=="." && plansza[w][k2]=="O")
            {
                if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                }
                else
                {
                    if(a==w && b==k1)
                    {
                        bufor = plansza[w][k1];
                        plansza[w][k1] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Nie można wykonać ruchu!";
                        check_gracz2(plansza);
                    }
                }
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]=="x" || plansza[w][k1]=="." && plansza[w][k2]=="X")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else if(plansza[w][k1]=="o" && plansza[w][k2]=="." || plansza[w][k1]=="O" && plansza[w][k2]=="." || plansza[w][k1]=="x" && plansza[w][k2]=="." || plansza[w][k1]=="." && plansza[w][k2]=="X")
            {
                if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                } 
            }
            else if(plansza[w][k1]=="." && plansza[w][k2]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                } 
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else
        {
            if(plansza[w][k1]=="." && plansza[w][k2]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            else if(plansza[w][k1]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            else if(plansza[w][k2]==".")
            {
                if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz2(plansza);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(w>=0 && w<=7 && k1>=1 && k1<=8)
    {
        if(w2>=0 && w2<=7 && k3>=1 && k3<=8)
        {
            if(plansza[w][k1]=="o" || plansza[w][k1]=="O")
            {
                if(plansza[w2][k3]==".")
                {
                    if(a==w2 && b==k3)
                    {
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k1] = ".";
                        bufor = plansza[w2][k3];
                        plansza[w2][k3] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);

                    }
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            else if(plansza[w][k1]=="x" || plansza[w][k1]=="X")
            {
                if(a==w && b==k1)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            else if(plansza[w][k1]==".")
            {
                if(a==w && b==k1)
                {
                    bufor = plansza[w][k1];
                    plansza[w][k1] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
            }
        }
        else if(plansza[w][k1]=="o" || plansza[w][k1]=="O" || plansza[w][k1]=="x" || plansza[w][k1]=="X")
        {
            if(a==w && b==k1)
            {
            cout << "Nie można wykonać ruchu!";
            check_gracz2(plansza);
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz2(plansza);
            }
        }
        else if(plansza[w][k1]==".")
        {
            if(a==w && b==k1)
            {
                bufor = plansza[w][k1];
                plansza[w][k1] = plansza[m][n];
                plansza[m][n] = bufor;
                zapis_historia_gracz2(x,y,p,r);
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz2(plansza);
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(w>=0 && w<=7 && k2>=1 && k2<=8)
    {
        if(w2>=0 && w2<=7 && k4>=1 && k4<=8)
        {
            if(plansza[w][k2]=="o" || plansza[w][k2]=="O")
            {
                if(plansza[w2][k4]==".")
                {
                    if(a==w2 && b==k4)
                    {
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);
                    }
                    else
                    {
                        cout << "Możliwy jest atak na przeciwnika!";
                        plansza[w][k2] = ".";
                        bufor = plansza[w2][k4];
                        plansza[w2][k4] = plansza[m][n];
                        plansza[m][n] = bufor;
                        zapis_historia_gracz2(x,y,p,r);

                    }
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            else if(plansza[w][k2]=="x" || plansza[w][k2]=="X")
            {
                if(a==w && b==k2)
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
                else
                {
                    cout << "Nie można wykonać ruchu!";
                    check_gracz2(plansza);
                }
            }
            else if(plansza[w][k2]==".")
            {
                if(a==w && b==k2)
                {
                    bufor = plansza[w][k2];
                    plansza[w][k2] = plansza[m][n];
                    plansza[m][n] = bufor;
                    zapis_historia_gracz2(x,y,p,r);
                }
            }
        }
        else if(plansza[w][k2]=="o" || plansza[w][k2]=="O" || plansza[w][k2]=="x" || plansza[w][k2]=="X")
        {
            if(a==w && b==k2)
            {
            cout << "Nie można wykonać ruchu!";
            check_gracz2(plansza);
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz2(plansza);
            }
        }
        else if(plansza[w][k2]==".")
        {
            if(a==w && b==k2)
            {
                bufor = plansza[w][k2];
                plansza[w][k2] = plansza[m][n];
                plansza[m][n] = bufor;
                zapis_historia_gracz2(x,y,p,r);
            }
            else
            {
                cout << "Nie można wykonać ruchu!";
                check_gracz2(plansza);
            }
        }
    }
    else
    {
        cout << "Nie można wykonać ruchu!";
        check_gracz2(plansza);
    }
}    
//Funckcja sprawdzająca wprowadzane dane przez gracza 1
void check_gracz1(string plansza[10][10])
{
    string x,p,y,r;
    int a, b, m, n;
    do
    {
    cout << "Podaj współrzędne aktualnej pozycji: " << endl;
    cout << "Współrzędna x: ";
    cin >>  x;
    x[0] = toupper(x[0]);
    }
    while(x!="A" && x!="B" && x!="C" && x!="D" && x!="E" && x!="F" && x!="G" && x!="H" && x.length()!=1);
    do
    {
    cout << "Podaj współrzędne aktualnej pozycji: " << endl;
    cout << "Współrzędna y: ";
    cin >> y;
    }
    while(y!="1" && y!="2" && y!="3" && y!="4" && y!="5" && y!="6" && y!="7" && y!="8");
    if(x=="A") m = 0;
    else if(x=="B") m = 1;
    else if(x=="C") m = 2;
    else if(x=="D") m = 3;
    else if(x=="E") m = 4;
    else if(x=="F") m = 5;
    else if(x=="G") m = 6;
    else if(x=="H") m = 7;
    if(y=="1") n = 1;
    else if(y=="2") n = 2;
    else if(y=="3") n = 3;
    else if(y=="4") n = 4;
    else if(y=="5") n = 5;
    else if(y=="6") n = 6;
    else if(y=="7") n = 7;
    else if(y=="8") n = 8;
    do
    {
    cout << "Podaj współrzędne docelowej pozycji: " << endl;
    cout << "Współrzędna x: ";
    cin >>  p;
    }
    while(p!="A" && p!="B" && p!="C" && p!="D" && p!="E" && p!="F" && p!="G" && p!="H");
    do
    {
    cout << "Podaj współrzędne docelowej pozycji: " << endl;
    cout << "Współrzędna y: ";
    cin >> r;
    }
    while(r!="1" && r!="2" && r!="3" && r!="4" && r!="5" && r!="6" && r!="7" && r!="8");
    if(p=="A") a = 0;
    else if(p=="B") a = 1;
    else if(p=="C") a = 2;
    else if(p=="D") a = 3;
    else if(p=="E") a = 4;
    else if(p=="F") a = 5;
    else if(p=="G") a = 6;
    else if(p=="H") a = 7;
    if(r=="1") b = 1;
    else if(r=="2") b = 2;
    else if(r=="3") b = 3;
    else if(r=="4") b = 4;
    else if(r=="5") b = 5;
    else if(r=="6") b = 6;
    else if(r=="7") b = 7;
    else if(r=="8") b = 8;
    cout << endl;
    if(plansza[m][n]=="o") white_move(plansza,m,n,a,b,x,y,p,r);
    else if(plansza[m][n]=="O") cout <<"Ruch damki";//damka(plansza,m,n,a,b);
    else
    {
        cout << "m: " << m;
        cout << "n: " << n;
        cout << "Na polu nie ma pionka lub wybrałeś pole dla gracza 2";
        check_gracz1(plansza);
    }
}
//Funckja sprawdzająca wprowadzane dane przez gracza 2
void check_gracz2(string plansza[10][10])
{
    string x,p,y,r;
    int a, b, m, n;
    do
    {
    cout << "Podaj współrzędne aktualnej pozycji: " << endl;
    cout << "Współrzędna x: ";
    cin >>  x;
    x[0] = toupper(x[0]);
    }
    while(x!="A" && x!="B" && x!="C" && x!="D" && x!="E" && x!="F" && x!="G" && x!="H" && x.length()!=1);
    do
    {
    cout << "Podaj współrzędne aktualnej pozycji: " << endl;
    cout << "Współrzędna y: ";
    cin >> y;
    }
    while(y!="1" && y!="2" && y!="3" && y!="4" && y!="5" && y!="6" && y!="7" && y!="8");
    if(x=="A") m = 0;
    else if(x=="B") m = 1;
    else if(x=="C") m = 2;
    else if(x=="D") m = 3;
    else if(x=="E") m = 4;
    else if(x=="F") m = 5;
    else if(x=="G") m = 6;
    else if(x=="H") m = 7;
    if(y=="1") n = 1;
    else if(y=="2") n = 2;
    else if(y=="3") n = 3;
    else if(y=="4") n = 4;
    else if(y=="5") n = 5;
    else if(y=="6") n = 6;
    else if(y=="7") n = 7;
    else if(y=="8") n = 8;
    do
    {
    cout << "Podaj współrzędne docelowej pozycji: " << endl;
    cout << "Współrzędna x: ";
    cin >>  p;
    }
    while(p!="A" && p!="B" && p!="C" && p!="D" && p!="E" && p!="F" && p!="G" && p!="H");
    do
    {
    cout << "Podaj współrzędne docelowej pozycji: " << endl;
    cout << "Współrzędna y: ";
    cin >> r;
    }
    while(r!="1" && r!="2" && r!="3" && r!="4" && r!="5" && r!="6" && r!="7" && r!="8");
    if(p=="A") a = 0;
    else if(p=="B") a = 1;
    else if(p=="C") a = 2;
    else if(p=="D") a = 3;
    else if(p=="E") a = 4;
    else if(p=="F") a = 5;
    else if(p=="G") a = 6;
    else if(p=="H") a = 7;
    if(r=="1") b = 1;
    else if(r=="2") b = 2;
    else if(r=="3") b = 3;
    else if(r=="4") b = 4;
    else if(r=="5") b = 5;
    else if(r=="6") b = 6;
    else if(r=="7") b = 7;
    else if(r=="8") b = 8;
    cout << endl;
    if(plansza[m][n]=="x") black_move(plansza,m,n,a,b,x,y,p,r);
    else if(plansza[m][n]=="X") cout <<"Ruch damki";//damka(plansza,m,n,a,b);
    else
    {
        cout << "Na polu nie ma pionka lub wybrałeś pole dla gracza 1";
        check_gracz2(plansza);
    }
}
//Funckja wyświetlająca dany wynik
void aktualny_wynik(string plansza[10][10], int &suma_1, int &suma_2)
{
    wynik_gracz1(plansza,suma_1);
    wynik_gracz2(plansza,suma_2);
    cout << "-------------------" << endl;
    cout << "| Aktualny wynik: |"  << endl;
    cout << "-------------------" << endl;
    cout << "Gracz 1(białe): " << suma_1 << endl;
    cout << "Gracz 2(czarne): " << suma_2 << endl;
}
//Funkcja obliczająca wynik dla gracza 1
void wynik_gracz1(string plansza[10][10], int &suma_1)
{
    suma_1 = 0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(plansza[i][j]=="o" || plansza[i][j]=="O")
            {
                suma_1 = suma_1 + 1;
            }
        }
    }
}
//Funkcja obliczająca wynik dla gracza 2
void wynik_gracz2(string plansza[10][10], int &suma_2)
{
    suma_2 = 0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(plansza[i][j]=="x" || plansza[i][j]=="X")
            {
                suma_2 = suma_2 + 1;
            }
        }
    }
}
//Funkcja obsługująca menu 1
bool menu_1(string plansza[10][10], int suma_1, int suma_2)
{
    cout << "|-----------------------------------|" << endl;
    cout << "|          Gra w warcaby!           |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| Menu:                             |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| 1. Pojedynek Gracz 1 vs Gracz 2   |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| 2. Pomoc                          |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| 3. Wyjście                        |" << endl;
    cout << "|-----------------------------------|" << endl;
    int choice;
    cin >> choice;
    switch(choice)
    {
        case 1:
        {
            do
            {
                cout << "Gracz 1" << endl;
                show(plansza);
                check_gracz1(plansza);
                aktualny_wynik(plansza,suma_1,suma_2);
                whitedamka_change(plansza);
                if (suma_2 == 0)
                {   
                    cout << "Wygrał gracz 1";
                    return false;
                }                
                show(plansza);
                check_gracz2(plansza);
                aktualny_wynik(plansza,suma_1,suma_2);
                blackdamka_change(plansza);;
                if (suma_1 == 0)
                {
                    cout << "Wygrał gracz 2";
                    return false;
                }
            }
            while(true);
            break;
        }
        case 2:
        {
            pomoc();
        break;
        } 
        case 3:
        {

        break;
        }
    }

}
//Funkcja zamieniająca białego pionka na damkę
void whitedamka_change(string plansza[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(plansza[0][j]=="o")
            {
                plansza[0][j] = "O";
            }
        }
    }
}
//Funkcja zammieniająca czarnego pionka na damkę
void blackdamka_change(string plansza[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(plansza[7][j]=="x")
            {
                plansza[7][j] = "X";
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void zapis_historia_gracz1(string x, string y, string p, string r)
{
    
    fstream plik;
    plik.open("historia.txt", ios::app);
    if(plik.good()==true)
    {
        plik << "Gracz 1: " << "z pola (" << x << "," << y << ") na pole (" << p << "," << r << ")" << endl;

        plik.close();
    }
    else
    {
        cout << "Zabroniony dostęp do pliku!";
    }
}
void zapis_historia_gracz2( string x, string y, string p, string r)
{
    fstream plik;
    plik.open("historia.txt", ios::app);
    if(plik.good()==true)
    {
        plik << "Gracz 2: " << "z pola (" << x << "," << y << ") na pole (" << p << "," << r << ")" << endl;

        plik.close();
    }
    else
    {
        cout << "Zabroniony dostęp do pliku!";
    }
}
void odczythistoria()
{
    fstream plik;
    string dane;
    plik.open("historia.txt", ios::in);
    if(plik.good()==true)
    {
        while(!plik.eof())
        {
            getline(plik, dane);
            cout << dane << endl;
        }
        plik.close();
    }
    else
    {
        cout << "Zabroniony dostęp do pliku!";
    }
}
void pomoc()
//Funckja wyswietlajaca pomoc
{
    cout << "Gracze poruszają się na zmianę, pierwszy figurami x, drugi figurami o." << endl; 
    cout << endl;
    cout << "Figury mogą przekształcić się w damki oznaczone przez X oraz O." << endl;
    cout << endl;
    cout << "W jednej turze gracz może poruszyć się jedną figurą." << endl;
    cout << endl;
    cout << "Możliwe ruchy:" << endl;
    cout << endl;
    cout << "Figury o i x mogą się poruszyć po przekątnej o jedno pole do przodu" << endl;
    cout << endl;
    cout << "Figury o i x mogą bić w przód, czyli przeskakiwać figurę przeciwnika na pole znajdujące się tuż za nim; pole to musi być wolne." << endl;
    cout << endl;
    cout << "Figury O i X mogą wykonywać te same ruchy co o i x w dowolnym kierunku" << endl;
    cout << endl;
    cout << "Jeżeli figura o i x skonczy swój ruch na ostatnim polu, wtedy zmienia się w figurę O i X. Po zbiciu figura jest zdejmowana z planszy. Bicie jest wymagane." << endl;
    cout << endl;
    cout << "Możliwe jest wielokrotne bicie" << endl;
    cout << endl;
    cout << "Gracz przegrywa jeśli nie może poruszyć się żadną z figur lub wszystkie straci" << endl;
}
//Funckja obsługująca menu 2
void menu_2(string plansza[10][10], int suma_1, int suma_2)
{
    cout << "|-----------------------------------|" << endl;
    cout << "|          Gra w warcaby!           |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| 1. Zobacz historię ruchów         |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| 2. Pomoc                          |" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "| 3. Powrót do menu gry             |" << endl;
    cout << "|-----------------------------------|" << endl;
    int x;
    cin >> x;
    switch(x)
    {
        case 1:
        {
            odczythistoria();
        break;
        }
        case 2:
        {
            pomoc();
        break;
        }
        case 3:
        {
            menu_1(plansza,suma_1,suma_2);
        break;
        }
        default:
        {
            break;
        }
    }
}
void damka(string plansza[10][10], int m, int n, int a, int b)
{

    string bufor;
    if(plansza[a][b]==".")
    {
        bufor = plansza[a][b];
        plansza[a][b] = plansza[m][n];
        plansza[m][n] = bufor;
    }
    else
    {
        if(plansza[m][n]=="O")
        {
            check_gracz1(plansza);
        }
        else if(plansza[m][n]=="X")
        {
            check_gracz2(plansza);
        }
    }
}
int main()
{   
    int suma_1 = 0;
    int suma_2 = 0;
    string plansza[10][10];
    start(plansza);
    menu_1(plansza,suma_1,suma_2);
    cout << endl;
    menu_2(plansza,suma_1,suma_2);
    
    return 0;
}




 

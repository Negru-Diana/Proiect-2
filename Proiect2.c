#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct Clienti
{
    char user[50], password[50];
} client;

struct conturiFinanciare
{
    char cont[20], denumire[50],tip[15];
} contFinanciar;

struct dateFisier
{
    char text[1000];
} text[1000];

struct Tranzactii
{
    char numar[4], tip[30], beneficiar[50], suma[10], cont[20], operatie[2];
    char data[20];    /// zi/luna/an
} tranzactie;

struct solduri
{
    char cont[20];
    double sold;
}sold[1000];


/// Facute: UI  (cerinta 1)
/// Facute: ADAUGA CONT FINANCIAR, EDITEAZA CONT FINANCIAR, STERGE CONT FINANCIAR, VIZUALIZARE CONTURI FINANCIARE (cerinta 2)
/// Facute: VIZUALIZARE TRANZACTII, INREGISTRARE TRANZACTII (cerinta 3)
/// Facute: CALCUL SOLD                                     (cerinta 4)
/// Facute: CREARE CONT, AUTENTIFICARE   (cerinta 6)
/// Facute: VALIDAREA DATELOR DE INTRAREA   (cerinta 9)
/// Facute: ISTORIC LOGARI (salvare in fisier)



void mesaj_optiune1(); /// mesaj pentru optiunile autentificare/creare cont nou
int operatie_aleasa_din_meniu();  /// citirea operatiei pe care doreste sa o faca utilizatorul
void autentificare();  /// intrare in cont
void creare_cont(); ///crearea unui cont nou
void citire_user(); /// citirea user-ului de la tastatura
void citire_parola(); /// citirea parolei de la tastatura
void operatii_user();  /// coordoneaza citirea si validarea user-ului
void operatii_parola();  /// coordoneaza citirea si validarea parolei
bool valideaza_user(char user[]);  /// valideaza user-ul (se verifica daca este unic)
bool valideaza_parola(char parola[]); /// valideaza parola (lungime minima de 8 caractere)
void mesaj_eroare_verificare_user();  /// mesaj eroare deschidere fisier
void mesaj_eroare_salvare_cont(); /// mesaj eroare deschidere fisier
void mesaj_cont_creat(); /// mesaj salvare cont cu succes
void mesaj_user_invalid(); /// mesaj user invalid
void mesaj_parola_invalida(); /// mesaj parola invalida
void salveaza_cont(); /// se salveaza datele de logare in fisierul "conturi.txt"
void mesaj_optiune_invalida(); /// mesaj optiunea aleasa nu exista

void autentificare(); /// autentificare in contul deja existent
bool gaseste_cont(); /// cautarea contului in fisierul "conturi.txt"
void mesaj_eroare_logare(); /// mesaj eroare deschidere fisier
void mesaj_autentificare_nereusita(); /// mesaj date logare incorecte
void mesaj_probleme_logare(); /// mesaj probleme logare (eroare)

void contabilitate(); /// gestionarea ampla a proiectului
void mesaj_optiuni(); /// afisarea optiunilor
void mesaj_iesire_program(); /// mesaj de iesire din program
void adauga_logare(); /// adauga logarea in fisierul "istoricLogari.txt"
void gestionare_meniu1(); /// gestionarea meniului 1 (cerinta 2)
void meniu1(); /// cerinta 2
void gestionare_meniu2(); /// gestionarea meniului 2 (cerinta 3)
void meniu2(); /// cerinta 3
void gestionare_meniu4(); /// gestionarea meniului 4 (cerinta 5)
void meniu4(); /// cerinta 5

void creare_cont_financiar(); /// crearea unui cont financiar
void citeste_cont(); /// numarul contului creat
void citeste_denumire_cont(); /// denumirea contului creat
void citeste_tip_cont(); /// tipul contului creat
void operatii_cont(); /// citire si validare cont (se repeta pana este valid)
void operatii_denumire_cont(); /// citire si validare denumire cont (se repeta pana este valid)
void operatii_tip_cont(); /// citire si validare tip cont (se repeta pana cand este valid)
bool valideaza_cont(); /// validare cont
bool valideaza_denumire_cont(); /// validare denumire cont
bool valideaza_tip_cont(); /// valideaza tip cont
void mesaj_cont_invalid(); /// mesaj cont invalid (invalid sau existent)
void mesaj_denumire_cont_invalida(); /// mesaj denumire cont invalida (vida)
void mesaj_tip_cont_invalid(); /// mesaj tip cont invalid
void adauga_cont_financiar(); /// se adauga contul financiar in fisierul "conturiFinanciare.txt"
void mesaj_adaugare_cont_financiar_nereusita(); /// mesaj adaugare nereusita a contului financiar in fisier
void mesaj_adaugare_cont_financiar(); /// mesaj cont financiar adaugat/creat cu succes

void editare_cont_financiar(); /// editarea unui cont financiar
bool gaseste_cont_financiar(); /// gaseste cont financiar dupa cont
void mesaj_editare_nereusita(); /// mesaj editare nereusita
void mesaj_cont_financiar_negasit(); /// mesaj cont financiar negasit (inexistent)
void coordonare_editare_cont_financiar(); /// coordoneaza editarea si salvarea modificarilor in fisierul "conturiFinanciare.txt"
void mesaj_editare_cont_financiar_reusita(); /// mesaj editare salvata cu succes

void sterge_cont_financiar(); /// stergere cont financiar
void coordonare_stergere_cont_financiar(); /// coordoneaza stergerea unui cont financiar
void mesaj_cont_financiar_sters(); /// mesaj cont financiar sters
void mesaj_cont_financiar_nesters(); ///mesaj stergere nereusita
void mesaj_conturi_financiare_inexistente(); /// mesaj cand nu exista conturi financiare de afisat

void vizualizeaza_conturi_financiare(); /// afisarea tuturor conturilor financiare din fisierul "conturiFinanciare.txt"
void mesaj_eroare_incarcare_conturi();  /// mesaj de eroare daca fisierul cu conturi nu a putut fi accesat

void inregistrare_tranzactii(); /// inregistrarea tranzactiilor
void operatii_numar_tranzactie(); /// citire si validare numar tranzactie (se repeta pana este valid)
void operatii_tip_tranzactie(); /// citire si validare tip tranzactie (se repeta pana este valid)
void operatii_beneficiar_tranzactie(); /// citire si validare beneficiar tranzactie (se repeta pana este valid)
void operatii_suma_tranzactie(); /// citire si validare suma tranzactie (se repeta pana este valid)
void operatii_data_tranzactie(); /// citire si validare data tranzactie (se repeta pana este valid)
void citeste_numar_tranzactie(); /// numar tranzactie
void citeste_tip_tranzactie(); /// tip tranzactie
void citeste_beneficiar_tranzactie(); /// beneficiar tranzactie
void citeste_suma_tranzactie(); /// suma tranzactie
void citeste_data_tranzactie(); /// data tranzactie
bool valideaza_numar_tranzactie(); /// validare numar tranzactie
bool valideaza_tip_tranzactie(); /// validare tip tranzactie
bool valideaza_beneficiar_tranzactie(); /// validare beneficiar tranzactie
bool valideaza_suma_tranzactie(); /// validare suma tranzactie
bool valideaza_data_tranzactie(); /// validare data tranzactie
void mesaj_eroare_incarcare_tranzactie(); /// mesaj eroare pentru incarcare tranzactie
void mesaj_numar_tranzactie_invalid(); /// mesaj numar tranzactie invalid
void mesaj_tip_tranzactie_invalid(); /// mesaj tip tranzactie invalid
void mesaj_beneficiar_tranzactie_invalid(); /// mesaj beneficiar tranzactie invalid
void mesaj_suma_tranzactie_invalida(); /// mesaj suma tranzactie invalida
void mesaj_data_tranzactie_invalida(); /// mesaj data tranzactie invalida
void mesaj_salvare_tranzactie_nereusita(); /// mesaj salvare tranzactie nereusita
void mesaj_salvare_tranzactie_reusita(); /// mesaj salvare tranzactie reusita
bool verifica_daca_este_numar(char suma[10]);  /// functia verifica daca un string este numar sau nu
void salveaza_tranzactie_in_fisier(); /// se salveaza datele despre tranzactie in fisierul "tranzactii.txt"
void citeste_operatie_tranzactie(); /// citeste operatie tranzactiei (+/-)
void citeste_cont_tranzactie(); /// citeste contul tranzactiei
void operatii_operatie_tranzactie(); /// citire si validare operatie tranzactie (se repeta pana este valid)
void operatii_cont_tranzactie(); /// citire si validare cont tranzactie (se repeta pana este valid)
bool valideaza_operatie_tranzactie(); /// validare operatie tranzactie
bool valideaza_cont_tranzactie(); /// validare cont tranzactie
void mesaj_operatie_tranzactie_invalida(); /// mesaj operatie tranzactie invalida
void mesaj_tranzactie_nesalvata(); /// mesaj tranzactie nesalvata
void mesaj_cont_tranzactie_invalid(); /// mesaj cont tranzactie invalid/inexistent


void afiseaza_tranzactii(); /// afisarea tuturor tranzactiilor inregistrare
void mesaj_tranzactii_inexistente(); /// mesaj cand nu exista tranzactii de afisat

void solduri(); /// soldurile conturilor bancare
void calculeaza_sold(int index); /// calcularea soldului bancar
void afiseaza_sold(int index); /// afisarea soldului bancar
void mesaj_solduri_inexistente(); /// mesaj nu exista solduri de afisat
void mesaj_eroare_solduri(); /// soldurile nu pot fi afisate

void calculeaza_sold_cont(); /// calcularea soldului unui cont (cerinta 4)
void citeste_cont_sold(); /// citeste contul pentru care sa se calculeze soldul
bool valideaza_cont_sold(); /// valideaza contul citit
void operatii_cont_sold(); /// citire si validare cont tranzactie (se repeta pana este valid)
void mesaj_eroare_sold_cont(); /// mesaj eroare sold cont

void extras_de_cont(); /// extras de cont (cerinta 5)
void

int main()
{
    mesaj_optiune1();
    int optiune=operatie_aleasa_din_meniu();
    if(optiune==1) /// autentificare
    {
        autentificare();
    }
    else
    {
        if(optiune==2) /// crearea cont nou
        {
            creare_cont();
        }
        else  /// mesaj eroare - optiune invalida
        {
            mesaj_optiune_invalida();
            main();
            return;
        }
    }
}

void mesaj_optiune_invalida() /// mesaj optiunea aleasa nu exista
{
    printf("\nOptiunea aleasa este invalida!\n");
}

void mesaj_optiune1() /// mesaj pentru optiunile autentificare/creare cont nou
{
    printf("\nIntroduceti numarul optiunii alese: \n");
    printf("1. Autentificare \n");
    printf("2. Creare cont nou \n");
}

int operatie_aleasa_din_meniu()    /// citirea operatiei pe care doreste sa o faca utilizatorul
{
    int optiune;
    printf("\nNumar: ");
    scanf("%d",&optiune);

    return optiune;
}

/// CREARE CONT

void mesaj_user_invalid() ///mesaj user invalid
{
    printf("\nUser-ul introdus este invalid!");
}

void operatii_user()  /// coordoneaza citirea s validarea user-ului (returneaza user-ul daca acesta este valid, altfel reface operatiile)
{
    char user[40];
    ///citire user
    citire_user();

    strcpy(user,client.user);

    ///validare user
    bool valid=valideaza_user(user);
    if(valid==true)
    {
        //printf("valid");
        strcpy(client.user,user);
    }
    else
    {
        mesaj_user_invalid();
        operatii_user();
    }
}

void citire_user() /// citirea user-ului de la tastatura
{
    char user[40];
    printf("\nUser: ");
    scanf("%s",user);

    strcpy(client.user,user);
}

bool valideaza_user(char user[])  /// valideaza user-ul (se verifica daca este unic)
{
    FILE *fptr;
    fptr = fopen("conturi.txt","r");  /// deschidere fisier pentru citire

    if(fptr==NULL)  /// fisierul cu conturi nu a fost gasit
    {
        mesaj_eroare_verificare_user(); /// mesaj eroare
    }
    else
    {
        if(strlen(user)<3) /// daca user-ul este vid sau are lungimea mai mica de 3 litere, atunci este invalid
        {
            return false;
        }

        while(!feof(fptr)) /// se citesc toate datele din fisier
        {
            char s[100];
            fscanf(fptr,"%s",s);
            char *token=strtok(s,";");
            if(strcmp(user,token)==0)  /// daca user-ul citit de la tastatura este acelasi cu cel din fisier, user-ul este invalid
            {
                fclose(fptr);
                return false;
            }
        }
        fclose(fptr);
        return true;  /// user valid, unic
    }
}

void mesaj_eroare_verificare_user()  /// mesaj eroare deschidere fisier
{
    printf("/nA intervenit o problema, nu putem verifica user-ul momentan!");
}


void operatii_parola()  /// coordoneaza citirea si validarea parolei
{
    char parola[40];
    ///citire parola
    citire_parola();

    strcpy(parola,client.password);

    ///validare parola
    bool valid=valideaza_parola(parola);
    if(valid==true)
    {
        //printf("valid");
        strcpy(client.password,parola);
    }
    else
    {
        mesaj_parola_invalida();
        operatii_parola();
    }
}

void citire_parola() /// citirea parolei de la tastatura
{
    char parola[40];
    printf("\nPassword: ");
    scanf("%s",parola);

    strcpy(client.password,parola);
}

bool valideaza_parola(char parola[]) /// valideaza parola (lungime minima de 8 caractere)
{
    if(strlen(parola)<8)
    {
        return false;
    }
    return true;
}

void mesaj_parola_invalida() ///mesaj parola invalida
{
    printf("\nParola introdusa este invalida! (verificati sa aiba minim 8 caractere)");
}

void mesaj_eroare_salvare_cont() /// mesaj eroare deschidere fisier
{
    printf("\nContul nu a putut fi creat!");
}

void mesaj_cont_creat() /// mesaj salvare cont cu succes
{
    printf("\nCont creat cu succes!\n");
}

void salveaza_cont() /// se salveaza datele de logare in fisierul "conturi.txt"     (FORMAT: user;password)
{
    FILE *fptr;
    fptr = fopen("conturi.txt","a");  ///deschidem fisierul pentru a adauga date la finalul acestuia
    if(fptr==NULL) ///eroare de deschidere a fisierului
    {
        mesaj_eroare_salvare_cont();
        main();
        return;
    }

    fprintf(fptr, client.user);
    fprintf(fptr, ";");
    fprintf(fptr, client.password);
    fprintf(fptr,"\n");

    fclose(fptr);

    mesaj_cont_creat();

    ///golire parametrii client
    strcpy(client.user,"");
    strcpy(client.password, "");
}

void creare_cont() ///crearea unui cont nou
{
    char user[40];
    operatii_user(); /// user-ul este pastrat in client.user
    operatii_parola(); /// parola este pastrata in client.password
    salveaza_cont();
    main();
}



/// AUTENTIFICARE


bool gaseste_cont() /// cautarea contului in fisierul "conturi.txt"
{
    FILE *fptr;
    fptr=fopen("conturi.txt","r");

    if(fptr==NULL) ///eroare de deschidere a fisierului
    {
        mesaj_eroare_logare();
        main();
        return;
    }

    while(!feof(fptr)) /// se citesc toate datele din fisier
    {
        char s[100];
        fscanf(fptr,"%s",s);
        char *token=strtok(s,";");
        if(strcmp(client.user,token)==0)  /// daca user-ul citit de la tastatura este acelasi cu cel din fisier
        {
            token=strtok(NULL,";");
            if(strcmp(client.password,token)==0) /// daca parola citita de la tastatura este aceeasi cu cea din fisier
            {
                return true;
            }
            return false;
        }
    }
    return false;
    fclose(fptr);

}

void mesaj_eroare_logare() /// mesaj eroare deschidere fisier
{
    printf("\nDin cauza unor probleme nu se poate realiza logarea!");
}

void mesaj_autentificare_nereusita() /// mesaj date logare incorecte
{
    printf("\nUser si/sau parola incorecte.");
}

void mesaj_probleme_logare() /// mesaj probleme logare (eroare)
{
    printf("\nA intervenit o problema la autentificare.");
}

void autentificare() /// autentificare in contul deja existent
{
    /// ne asiguram ca structura client este golita
    strcpy(client.user,"");
    strcpy(client.password,"");

    citire_user();
    citire_parola();

    if(gaseste_cont()==false)
    {
        mesaj_autentificare_nereusita();
        autentificare();
    }
    else
    {
        if(strcmp(client.user,"")!=0 && strcmp(client.password,"")!=0)
        {
            contabilitate();
        }
        else
        {
            mesaj_probleme_logare();
            main();
        }
    }
}

/// PROIECT 2 - cerinte

void mesaj_optiuni() /// afisarea optiunilor
{
    printf("\nIntroduceti numarul optiunii alese: \n");
    printf("1. Conturi financiare\n");                       /// cerinta 2
    printf("2. Tranzactii\n");                               /// cerinta 3
    printf("3. Calcul sold\n");                              /// cerinta 4
    printf("4. Rapoarte financiare\n");                      /// cerinta 5
    printf("5. Managementul datelor clientilor\n");          /// cerinta 7
    printf("6. Import/Export date financiare\n");            /// cerinta 8
    printf("7. Audit si Logging\n");                         /// cerinta 11
    printf("0. Iesire program\n");
}

void mesaj_iesire_program() /// mesaj de iesire din program
{
    printf("\nLa revedere!");
}

void meniu1() /// cerinta 2
{
    printf("\nIntroduceti numarul optiunii alese: \n");
    printf("1. Creare cont financiar\n");
    printf("2. Editare cont financiar\n");
    printf("3. Sterge cont financiar\n");
    printf("4. Vizualizeaza conturi financiare\n");
    printf("0. Inapoi\n");
}

void gestionare_meniu1() /// gestionarea meniului 1 (cerinta 2)
{
    meniu1();
    int optiune=operatie_aleasa_din_meniu();
    if(optiune==0)  /// inapoi la meniul principal
    {
        contabilitate();
    }
    else
    {
        if(optiune==1) /// creare cont financiar
        {
            creare_cont_financiar();
        }
        else
        {
            if(optiune==2) /// editare cont financiar
            {
                editare_cont_financiar();
            }
            else
            {
                if(optiune==3) /// stergere cont financiar
                {
                    sterge_cont_financiar();
                }
                else  /// optiune invalida
                {
                    if(optiune==4) /// vizualizeaza conturi financiare
                    {
                        vizualizeaza_conturi_financiare();
                    }
                    else
                    {
                        mesaj_optiune_invalida();
                    }
                }
            }
        }
    }
}

void gestionare_meniu2() /// gestionarea meniului 2 (cerinta 3)
{
    meniu2();
    int optiune=operatie_aleasa_din_meniu();
    if(optiune==0)  /// inapoi la meniul principal
    {
        contabilitate();
    }
    else
    {
        if(optiune==1) /// inregistrare tranzactii
        {
            inregistrare_tranzactii();
        }
        else
        {
            if(optiune==2) /// vizualizare tranzactii
            {
                afiseaza_tranzactii();
            }
            else
            {
                mesaj_optiune_invalida();
            }
        }
    }
}

void meniu2() /// cerinta 3
{
    printf("\nIntroduceti numarul optiunii alese: \n");
    printf("1. Inregistrare tranzactii\n");
    printf("2. Vizualizare tranzactii\n");
    printf("0. Inapoi\n");
}


void gestionare_meniu4() /// gestionarea meniului 4 (cerinta 5)
{
    meniu4();
    int optiune=operatie_aleasa_din_meniu();
    if(optiune==0)
    {
        contabilitate();
    }
    else
    {
        if(optiune==1) /// extras de cont
        {

        }
        else
        {
            if(optiune==2) /// solduri
            {
                solduri();
            }
            else
            {
                if(optiune==3) /// registre de tranzactii
                {

                }
                else
                {
                    if(optiune==4) /// rapoarte de cheltuieli
                    {

                    }
                    else
                    {
                        mesaj_optiune_invalida();
                    }
                }
            }
        }
    }
}

void meniu4() /// cerinta 5
{
    printf("\nIntroduceti numarul optiunii alese: \n");
    printf("\n1. Extras de cont");
    printf("\n2. Solduri");
    printf("\n3. Registre de tranzactii");
    printf("\n4. Rapoarte de cheltuieli");
    printf("\n0. Inapoi");
}

void adauga_logare() /// adauga logarea in fisierul "istoricLogari.txt"   (FORMAT: user;ziSaptamana luna ziLuna ora:minut:secunda an)
{
    FILE *fptr;
    fptr=fopen("istoricLogari.txt","a");

    if(fptr==NULL) ///eroare de deschidere a fisierului
    {
        mesaj_eroare_logare();
        main();
        return;
    }

    struct tm* local;
    time_t t = time(NULL);

    // Get the localtime
    local = localtime(&t);

    fprintf(fptr, client.user);
    fprintf(fptr, ";");
    fprintf(fptr, asctime(local));

    fclose(fptr);
}

void contabilitate() /// gestionarea ampla a proiectului
{
    adauga_logare();

    bool continua=true;
    while(continua==true)
    {
        mesaj_optiuni();
        int optiune=operatie_aleasa_din_meniu();
        if(optiune==1)   /// cerinta 2
        {
            gestionare_meniu1();
        }
        else
        {
            if(optiune==2) ///cerinta 3
            {
                gestionare_meniu2();
            }
            else
            {
                if(optiune==3)
                {
                    calculeaza_sold_cont();
                }
                else
                {
                    if(optiune==4) ///cerinta 5
                    {
                        gestionare_meniu4();
                    }
                    else
                    {
                        if(optiune==5)
                        {
                            ///cerinta 7
                        }
                        else
                        {
                            if(optiune==6)
                            {
                                ///cerinta 8
                            }
                            else
                            {
                                if(optiune==7)
                                {
                                    ///cerinta 11
                                }
                                else
                                {
                                    if(optiune==0) ///iesire program
                                    {
                                        mesaj_iesire_program();
                                        continua=false;
                                    }
                                    else
                                    {
                                        mesaj_optiune_invalida();
                                        contabilitate();
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



/// CONTURI FINANCIARE (cerinta 2)

// CREARE CONT FINANCIAR (1.1)

void citeste_cont() /// numarul contului creat
{
    char cont[20];
    printf("\nCont: ");
    scanf("%s",&cont);

    strcpy(contFinanciar.cont,cont);
}

void citeste_denumire_cont() /// denumirea contului creat
{
    char denumire[50];
    printf("\nDenumire: ");
    scanf("%s", &denumire);

    strcpy(contFinanciar.denumire,denumire);
}

void citeste_tip_cont() /// tipul contului creat
{
    char tip[15];
    printf("\nTip (A - activ, P - pasiv, B - bifunctional): ");
    scanf("%s", &tip);

    strcpy(contFinanciar.tip,tip);
}

bool valideaza_cont() /// validare cont
{
    if(strlen(contFinanciar.cont)<1)
    {
        return false;
    }

    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","r");

    while(!feof(fptr))
    {
        char s[1000];
        fscanf(fptr,"%s",s);

        char *token=strtok(s,";");
        if(strcmp(token,contFinanciar.cont)==0)
        {
            fclose(fptr);
            return false;
        }
    }

    fclose(fptr);
    return true;
}

bool valideaza_denumire_cont() /// validare denumire cont
{
    if(strlen(contFinanciar.denumire)<1)
    {
        return false;
    }
    return true;
}

bool valideaza_tip_cont() /// valideaza tip cont
{

    if(strlen(contFinanciar.tip)<1)
    {
        return false;
    }

    if(strcmp(contFinanciar.tip,"b")==0 || strcmp(contFinanciar.tip,"B")==0)
    {
        strcpy(contFinanciar.tip,"");
        strcpy(contFinanciar.tip,"B");
        return true;
    }

    if(strcmp(contFinanciar.tip,"p")==0 || strcmp(contFinanciar.tip,"P")==0)
    {
        strcpy(contFinanciar.tip,"");
        strcpy(contFinanciar.tip,"P");
        return true;
    }

    if(strcmp(contFinanciar.tip,"a")==0 || strcmp(contFinanciar.tip,"A")==0)
    {
        strcpy(contFinanciar.tip,"");
        strcpy(contFinanciar.tip,"A");
        return true;
    }

    return false;
}

void mesaj_cont_invalid() /// mesaj cont invalid (invalid sau existent)
{
    printf("\nContul introdus este invalid sau existent!\n");
}

void operatii_cont() /// citire si validare cont (se repeta pana este valid)
{
    citeste_cont();
    bool valid=valideaza_cont();
    if(valid==false)
    {
        mesaj_cont_invalid();
        operatii_cont();
    }
}

void mesaj_denumire_cont_invalida() /// mesaj denumire cont invalida (vida)
{
    printf("\nDenumirea contului este invalida!\n");
}

void operatii_denumire_cont() /// citire si validare denumire cont (se repeta pana este valid)
{
    citeste_denumire_cont();
    bool valid=valideaza_denumire_cont();
    if(valid==false)
    {
        mesaj_denumire_cont_invalida();
        operatii_denumire_cont();
    }
}

void mesaj_tip_cont_invalid() /// mesaj tip cont invalid
{
    printf("\nTipul contului este invalid! Acesta trebuie sa fie de forma: A - activ, P - pasiv, B - bifunctional\n");
}

void operatii_tip_cont() /// citire si validare tip cont (se repeta pana cand este valid)
{
    citeste_tip_cont();
    bool valid=valideaza_tip_cont();
    if(valid==false)
    {
        mesaj_tip_cont_invalid();
        operatii_tip_cont();
    }
}

void adauga_cont_financiar() /// se adauga contul financiar in fisierul "conturiFinanciare.txt"      (FORMAT: cont;denumireCont;tipCont)
{
    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","a");

    if(fptr==NULL)
    {
        mesaj_adaugare_cont_financiar_nereusita();
        contabilitate();
        return;
    }

    fprintf(fptr,contFinanciar.cont);
    fprintf(fptr,";");
    fprintf(fptr,contFinanciar.denumire);
    fprintf(fptr,";");
    fprintf(fptr,contFinanciar.tip);
    fprintf(fptr,"\n");

    fclose(fptr);

    mesaj_adaugare_cont_financiar();
}

void mesaj_adaugare_cont_financiar_nereusita() /// mesaj adaugare nereusita a contului financiar in fisier
{
    printf("\nContul financiar nu a putut fi creat!\n");
}

void mesaj_adaugare_cont_financiar() /// mesaj cont financiar adaugat/creat cu succes
{
    printf("\nContul financiar a fost creat cu succes!\n");
}

void creare_cont_financiar() /// crearea unui cont financiar
{
    /// golesc campurile contFinanciar
    strcpy(contFinanciar.cont,"");
    strcpy(contFinanciar.denumire,"");
    strcpy(contFinanciar.tip,"");

    operatii_cont();
    operatii_denumire_cont();
    operatii_tip_cont();

    adauga_cont_financiar();
}


// EDITARE CONT FINANCIAR (1.2)

void mesaj_editare_nereusita() /// mesaj editare nereusita
{
    printf("\nContul nu poate fi modificat.\n");
}

bool gaseste_cont_financiar() /// gaseste cont financiar dupa cont
{
    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","r");

    if(fptr==NULL)
    {
        mesaj_editare_nereusita();
        contabilitate();
        return;
    }

    while(!feof(fptr))
    {
        char s[1000];
        fscanf(fptr,"%s",s);

        char *token=strtok(s,";");
        if(strcmp(token,contFinanciar.cont)==0)
        {
            fclose(fptr);
            return true;
        }
    }

    fclose(fptr);
    return false;
}

void mesaj_cont_financiar_negasit() /// mesaj cont financiar negasit (inexistent)
{
    printf("\nContul nu a fost gasit!\n");
}

void mesaj_editare_cont_financiar_reusita() /// mesaj editare salvata cu succes
{
    printf("\nContul a fost editat cu succes!\n");
}

void coordonare_editare_cont_financiar() /// coordoneaza editarea si salvarea modificarilor in fisierul "conturiFinanciare.txt"
{
    char cont_curent[50];
    strcpy(cont_curent,contFinanciar.cont);

    /// golesc campurile contFinanciar
    strcpy(contFinanciar.cont,"");
    strcpy(contFinanciar.denumire,"");
    strcpy(contFinanciar.tip,"");

    operatii_cont();
    operatii_denumire_cont();
    operatii_tip_cont();


    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","r");

    if(fptr==NULL)
    {
        mesaj_editare_nereusita();
        contabilitate();
        return;
    }
    int index=0; /// numarul de elemente citite din fisier
    while(!feof(fptr))
    {
        char s[1000];
        char aux[1000];

        fscanf(fptr,"%s",s);
        strcpy(aux,s);

        char *token=strtok(s,";");
        if(strcmp(token,cont_curent)!=0 && strlen(aux)>4)
        {
            strcpy(text[index].text,aux);
            index++;
        }
    }
    fclose(fptr);

    fptr=fopen("conturiFinanciare.txt","w");

    if(fptr==NULL)
    {
        mesaj_editare_nereusita();
        contabilitate();
        return;
    }

    for(int i=0; i<index; i++)
    {
        fprintf(fptr,text[i].text);
        fprintf(fptr,"\n");
    }

    fprintf(fptr,contFinanciar.cont);
    fprintf(fptr,";");
    fprintf(fptr,contFinanciar.denumire);
    fprintf(fptr,";");
    fprintf(fptr,contFinanciar.tip);
    fprintf(fptr,"\n");

    fclose(fptr);

    mesaj_editare_cont_financiar_reusita();
}


void editare_cont_financiar() /// editarea unui cont financiar
{
    /// golesc campurile contFinanciar
    strcpy(contFinanciar.cont,"");
    strcpy(contFinanciar.denumire,"");
    strcpy(contFinanciar.tip,"");

    citeste_cont();
    bool gasit=gaseste_cont_financiar();
    if(gasit==false)
    {
        mesaj_cont_financiar_negasit();
        editare_cont_financiar();
        return;
    }
    else
    {
        coordonare_editare_cont_financiar();
    }
}


// STERGERE CONT FINANCIAR (1.3)

void mesaj_cont_financiar_nesters() ///mesaj stergere nereusita
{
    printf("\nContul financiar nu a putut fi sters!\n");
}

void mesaj_cont_financiar_sters() /// mesaj cont financiar sters
{
    printf("\nContul a fost sters cu succes!\n");
}

void coordonare_stergere_cont_financiar() /// coordoneaza stergerea unui cont financiar
{
    char cont_curent[50];
    strcpy(cont_curent,contFinanciar.cont);

    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","r");

    if(fptr==NULL)
    {
        mesaj_cont_financiar_nesters();
        contabilitate();
        return;
    }
    int index=0; /// numarul de elemente citite din fisier
    while(!feof(fptr))
    {
        char s[1000];
        char aux[1000];

        fscanf(fptr,"%s",s);
        strcpy(aux,s);

        char *token=strtok(s,";");
        if(strcmp(token,cont_curent)!=0 && strlen(aux)>4)
        {
            strcpy(text[index].text,aux);
            index++;
        }
    }
    fclose(fptr);

    fptr=fopen("conturiFinanciare.txt","w");

    if(fptr==NULL)
    {
        mesaj_cont_financiar_nesters();
        contabilitate();
        return;
    }

    for(int i=0; i<index; i++)
    {
        fprintf(fptr,text[i].text);
        fprintf(fptr,"\n");
    }

    fclose(fptr);

    mesaj_cont_financiar_sters();
}


void sterge_cont_financiar() /// stergere cont financiar
{
    /// golesc campurile contFinanciar
    strcpy(contFinanciar.cont,"");
    strcpy(contFinanciar.denumire,"");
    strcpy(contFinanciar.tip,"");

    citeste_cont();
    bool gasit=gaseste_cont_financiar();
    if(gasit==false)
    {
        mesaj_cont_financiar_negasit();
        sterge_cont_financiar();
        return;
    }
    else
    {
        coordonare_stergere_cont_financiar();
    }
}



// VIZUALIZARE CONTURI FINANCIARE (1.4)

void mesaj_eroare_incarcare_conturi()  /// mesaj de eroare daca fisierul cu conturi nu a putut fi accesat
{
    printf("\nNu se pot afisa conturile financiare momentan.\n");
}

void mesaj_conturi_financiare_inexistente() /// mesaj cand nu exista conturi financiare de afisat
{
    printf("\nNu exista conturi financiare de afisat!\n");
}

void vizualizeaza_conturi_financiare() /// afisarea tuturor conturilor financiare din fisierul "conturiFinanciare.txt"
{
    int cate=0;

    printf("\nToate conturile financiare:\n");

    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","r");

    if(fptr==NULL)
    {
        mesaj_eroare_incarcare_conturi();
        contabilitate();
        return;
    }

    while(!feof(fptr))
    {
        char s[1000];
        fscanf(fptr,"%s",s);

        if(strlen(s)<6)
        {
            continue;
        }

        char *token=strtok(s,";");
        printf("\nCont: %s", token);

        token=strtok(NULL,";");
        printf("\nDenumire: %s",token);

        token=strtok(NULL,";");
        printf("\nTip: %s", token);
        printf("\n");

        cate++;
    }

    fclose(fptr);

    if(cate==0)
    {
        mesaj_conturi_financiare_inexistente();
    }
}



/// TRANZACTII

// INREGISTRARE TRANZACTII

void mesaj_operatie_tranzactie_invalida() /// mesaj operatie tranzactie invalida
{
    printf("\nOperatia este invalida! Operatia poate sa fie doar + sau - .");
}

void citeste_operatie_tranzactie() /// citeste operatie tranzactiei (+/-)
{
    char operatie[3];
    printf("operatie (+/-): ");
    scanf("%s", &operatie);

    strcpy(tranzactie.operatie,operatie);
}

void operatii_operatie_tranzactie() /// citire si validare operatie tranzactie (se repeta pana este valid)
{
    citeste_operatie_tranzactie();

    bool valid=valideaza_operatie_tranzactie();
    if(valid==false)
    {
        mesaj_operatie_tranzactie_invalida();
        operatii_operatie_tranzactie();
        return;
    }
}

bool valideaza_operatie_tranzactie() /// validare operatie tranzactie
{
    if(strcmp(tranzactie.operatie,"+")==0 || strcmp(tranzactie.operatie,"-")==0)
    {
        return true;
    }

    return false;
}


void citeste_cont_tranzactie() /// citeste contul tranzactiei
{
    char cont[20];
    printf("numar cont: ");
    scanf("%s", &cont);

    strcpy(tranzactie.cont,cont);
}

void mesaj_tranzactie_nesalvata() /// mesaj tranzactie nesalvata
{
    printf("\nTranzactia nu poate fi inregistrata!\n");
}

void mesaj_cont_tranzactie_invalid() /// mesaj cont tranzactie invalid/inexistent
{
    printf("\nContul introdus este invalid/inexistent!\n");
}

void operatii_cont_tranzactie() /// citire si validare cont tranzactie (se repeta pana este valid)
{
    citeste_cont_tranzactie();
    bool valid=valideaza_cont_tranzactie();
    if(valid==false)
    {
        mesaj_cont_tranzactie_invalid();
        operatii_cont_tranzactie();
        return;
    }
}

bool valideaza_cont_tranzactie() /// validare cont tranzactie
{
    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","r");

    if(fptr==NULL)
    {
        mesaj_eroare_incarcare_conturi();
        contabilitate();
        return;
    }

    while(!feof(fptr))
    {
        char s[1000];
        fscanf(fptr,"%s",s);

        if(strlen(s)<6)
        {
            continue;
        }

        char *token=strtok(s,";");

        if(strcmp(token,tranzactie.cont)==0)
        {
            return true;
        }
    }
    return false;
}



void mesaj_data_tranzactie_invalida() /// mesaj data tranzactie invalida
{
    printf("\nData introdusa este invalida!\n");
}

void operatii_data_tranzactie() /// citire si validare data tranzactie (se repeta pana este valid)
{
    citeste_data_tranzactie();
    bool valid=valideaza_data_tranzactie();

    if(valid==false)
    {
        mesaj_data_tranzactie_invalida();
        operatii_data_tranzactie();
    }
}

void citeste_data_tranzactie() /// data tranzactie
{
    char data[20];
    printf("data (zi/luna/an): ");
    scanf("%s", &data);

    strcpy(tranzactie.data,data);
}

bool valideaza_data_tranzactie() /// validare data tranzactie
{
    char data[20];
    strcpy(data, tranzactie.data);

    char *token=strtok(data,"/");  // zi
    if(strcmp(token,"0")>0 && strcmp(token,"32")<0)
    {
        token=strtok(NULL, "/"); // luna
        if(strcmp(token,"0")>0 && strcmp(token,"13")<0)
        {
            token=strtok(NULL,"/");  // an
            bool valid=verifica_daca_este_numar(token);
            if(valid==true && strcmp(token,"2000")>0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


void operatii_suma_tranzactie() /// citire si validare suma tranzactie (se repeta pana este valid)
{
    citeste_suma_tranzactie();
    bool valid=valideaza_suma_tranzactie();

    if(valid==false)
    {
        mesaj_suma_tranzactie_invalida();
        operatii_suma_tranzactie();
    }
}

void citeste_suma_tranzactie() /// suma tranzactie
{
    char suma[10];
    printf("suma: ");
    scanf("%s", &suma);

    strcpy(tranzactie.suma,suma);
}

void mesaj_suma_tranzactie_invalida() /// mesaj suma tranzactie invalida
{
    printf("\nSuma introdusa este invalida!\n");
}

bool verifica_daca_este_numar(char suma[10])  /// functia verifica daca un string este numar sau nu
{
    bool valid;
    for(int i=0; i<strlen(suma); i++)
    {
        if(suma[i]>='0' && suma[i]<='9')
        {
            valid=true;
        }
        else
        {
            valid=false;
            break;
        }
    }

    return valid;
}

bool valideaza_suma_tranzactie() /// validare suma tranzactie
{
    if(strchr(tranzactie.suma,'.')==NULL)
    {
        bool valid = verifica_daca_este_numar(tranzactie.suma);
        if(valid==false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        char suma[10];
        strcpy(suma,tranzactie.suma);

        char *token=strtok(suma,".");

        bool valid=verifica_daca_este_numar(token);

        if(valid==true)
        {
            token=strtok(NULL,".");

            valid=verifica_daca_este_numar(token);

            if(valid==true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}

void mesaj_beneficiar_tranzactie_invalid() /// mesaj beneficiar tranzactie invalid
{
    printf("\nNumele beneficiarului introdus este invalid!\n");
}

void operatii_beneficiar_tranzactie() /// citire si validare beneficiar tranzactie (se repeta pana este valid)
{
    citeste_beneficiar_tranzactie();
    bool valid=valideaza_beneficiar_tranzactie();

    if(valid==false)
    {
        mesaj_beneficiar_tranzactie_invalid();
        operatii_beneficiar_tranzactie();
    }
}

void citeste_beneficiar_tranzactie() /// beneficiar tranzactie
{
    char beneficiar[50];
    char nl[3];
    printf("beneficiar: ");

    scanf("%c",&nl);
    scanf("%[^\n]%*c",&beneficiar);

    strcpy(tranzactie.beneficiar,beneficiar);
}

bool valideaza_beneficiar_tranzactie() /// validare beneficiar tranzactie
{
    if(strlen(tranzactie.beneficiar)<1)
    {
        return false;
    }

    return true;
}

void mesaj_tip_tranzactie_invalid() /// mesaj tip tranzactie invalid
{
    printf("\nTipul tranzactiei este invalid!\n");
}

void operatii_tip_tranzactie() /// citire si validare tip tranzactie (se repeta pana este valid)
{
    citeste_tip_tranzactie();
    bool valid=valideaza_tip_tranzactie();

    if(valid==false)
    {
        mesaj_tip_tranzactie_invalid();
        operatii_tip_tranzactie();
    }
}

void citeste_tip_tranzactie() /// tip tranzactie
{
    char tip[30];
    printf("tip tranzactie: ");
    scanf("%s", &tip);

    strcpy(tranzactie.tip,tip);
}

bool valideaza_tip_tranzactie() /// validare tip tranzactie
{
    if(strlen(tranzactie.tip)<1)
    {
        return false;
    }
    return true;
}


void mesaj_eroare_incarcare_tranzactie() /// mesaj eroare pentru incarcare tranzactie
{
    printf("\Momentan nu pot fi incarcate tranzactii.\n");
}

void mesaj_numar_tranzactie_invalid() /// mesaj numar tranzactie invalid
{
    printf("\nNumarul tranzactiei este invalid/exitsent!\n");
}

void operatii_numar_tranzactie() /// citire si validare numar tranzactie (se repeta pana este valid)
{
    citeste_numar_tranzactie();
    bool valid=valideaza_numar_tranzactie();

    if(valid==false)
    {
        mesaj_numar_tranzactie_invalid();
        operatii_numar_tranzactie();
    }
}

void citeste_numar_tranzactie() /// numar tranzactie
{
    char numar[4];
    printf("numar tranzactie: ");
    scanf("%s", &numar);

    strcpy(tranzactie.numar,numar);
}


bool valideaza_numar_tranzactie() /// validare numar tranzactie
{
    if(strlen(tranzactie.numar)<1)
    {
        return false;
    }

    bool valid=verifica_daca_este_numar(tranzactie.numar);
    if(valid==false)
    {
        return false;
    }

    FILE *fptr;
    fptr=fopen("tranzactii.txt","r");

    if(fptr==NULL)
    {
        mesaj_eroare_incarcare_tranzactie();
        contabilitate();
        return;
    }

    while(!feof(fptr))
    {
        char s[1000];
        fscanf(fptr,"%s",s);

        char *token=strtok(s,";");

        if(strcmp(token,tranzactie.numar)==0)
        {
            fclose(fptr);
            return false;
        }
    }
    fclose(fptr);

    return true;
}

void mesaj_salvare_tranzactie_nereusita() /// mesaj salvare tranzactie nereusita
{
    printf("\nTranzactia nu a putut fi salvata!\n");
}

void mesaj_salvare_tranzactie_reusita() /// mesaj salvare tranzactie reusita
{
    printf("\nTranzactia a fost salvata cu succes!\n");
}

void salveaza_tranzactie_in_fisier() /// se salveaza datele despre tranzactie in fisierul "tranzactii.txt"     (FORMAT: numar, tip, cont, operatie, beneficiar, suma, data)
{
    FILE *fptr;
    fptr=fopen("tranzactii.txt","a");

    if(fptr==NULL)
    {
        mesaj_salvare_tranzactie_nereusita();
        contabilitate();
        return;
    }

    fprintf(fptr, tranzactie.numar);
    fprintf(fptr, ";");
    fprintf(fptr, tranzactie.tip);
    fprintf(fptr, ";");
    fprintf(fptr, tranzactie.cont);
    fprintf(fptr,";");
    fprintf(fptr, tranzactie.operatie);
    fprintf(fptr,";");
    fprintf(fptr, tranzactie.beneficiar);
    fprintf(fptr, ";");
    fprintf(fptr, tranzactie.suma);
    if(strchr(tranzactie.suma,'.')==NULL)
    {
        fprintf(fptr,".00");
    }
    fprintf(fptr, ";");
    fprintf(fptr, tranzactie.data);
    fprintf(fptr, "\n");

    fclose(fptr);

    mesaj_salvare_tranzactie_reusita();
}

void inregistrare_tranzactii() /// inregistrarea tranzactiilor
{
    operatii_numar_tranzactie();
    operatii_tip_tranzactie();
    operatii_cont_tranzactie();
    operatii_operatie_tranzactie();
    operatii_beneficiar_tranzactie();
    operatii_suma_tranzactie();
    operatii_data_tranzactie();

    salveaza_tranzactie_in_fisier();
}


// AFISARE TRANZACTII

void mesaj_tranzactii_inexistente() /// mesaj cand nu exista tranzactii de afisat
{
    printf("\nNu exista tranzactii de afisat!\n");
}

void afiseaza_tranzactii() /// afisarea tuturor tranzactiilor inregistrare
{
    int cate=0;
    printf("\nTranzactii: \n");

    FILE *fptr;
    fptr=fopen("tranzactii.txt","r");

    while(!feof(fptr))
    {
        char s[1000];
        //fscanf(fptr,"%s",s);
        fgets(s, 1000, fptr);

        if(strlen(s)<5)
        {
            continue;
        }

        char *token=strtok(s,";");    /// numar tranzactie
        printf("\nNumar tranzactie: %s", token);

        token=strtok(NULL, ";");     /// tip tranzactie
        printf("\nTip tranzactie: %s", token);

        token=strtok(NULL, ";");    /// beneficiar
        printf("\nBeneficiar: %s", token);

        token=strtok(NULL, ";");    /// suma
        printf("\nSuma: %s lei", token);

        token=strtok(NULL, ";");    /// data
        printf("\nData: %s", token);

        cate++;
    }

    fclose(fptr);

    if(cate==0)
    {
        mesaj_tranzactii_inexistente();
    }
}

/// SOLD

void calculeaza_sold_cont() /// calcularea soldului unui cont (cerinta 4)
{

    operatii_cont_sold();
    sold[0].sold=0.0;
    calculeaza_sold(0);
    afiseaza_sold(0);
}

void citeste_cont_sold() /// citeste contul pentru care sa se calculeze soldul
{
    char cont[20];
    printf("\ncont: ");
    scanf("%s", &cont);

    strcpy(sold[0].cont,cont);
}

bool valideaza_cont_sold() /// valideaza contul citit
{
    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","r");

    if(fptr==NULL)
    {
        mesaj_eroare_sold_cont();
        contabilitate();
        return;
    }

    while(!feof(fptr))
    {
        char s[1000];
        fscanf(fptr,"%s",s);

        if(strlen(s)<6)
        {
            break;
        }

        char *token=strtok(s,";");
        if(strcmp(sold[0].cont,token)==0)
        {
            fclose(fptr);
            return true;
        }
    }

    fclose(fptr);
    return false;
}

void operatii_cont_sold() /// citire si validare cont tranzactie (se repeta pana este valid)
{
    citeste_cont_sold();
    bool valid=valideaza_cont_sold();
    if(valid==false)
    {
        mesaj_cont_tranzactie_invalid();
        operatii_cont_sold();
        return;
    }
}

void mesaj_eroare_sold_cont() /// mesaj eroare sold cont
{
    printf("\nSoldul contului nu poate fi afisat!\n");
}


// SOLDURI (4.2)

void afiseaza_sold(int index) /// afisarea soldului bancar
{
    printf("Soldul contului %s este de %.2f lei\n",sold[index].cont,sold[index].sold);
}

void mesaj_solduri_inexistente() /// mesaj nu exista solduri de afisat
{
    printf("\nNu exista solduri de afisat!\n");
}

void calculeaza_sold(int index) /// calcularea soldului bancar
{
    char cont[20];
    strcpy(cont, sold[index].cont);

    FILE *fptr;
    fptr=fopen("tranzactii.txt","r");

    if(fptr==NULL)
    {
        mesaj_eroare_solduri();
        contabilitate();
        return;
    }

    while(!feof(fptr))
    {
        char s[1000];
        fgets(s,1000,fptr);

        if(strlen(s)<4)
        {
            break;
        }

        char *token=strtok(s,";");  // numar tranzactie
        token=strtok(NULL,";"); // tip tranzactie
        token=strtok(NULL,";"); // cont

        if(strcmp(cont, token)==0)
        {
            token=strtok(NULL,";");  // operatie
            if(strcmp(token,"+")==0)  /// adunare
            {
                token=strtok(NULL,";"); //beneficiar
                token=strtok(NULL,";"); //suma

                char *end;
                double suma=strtod(token,&end);

                sold[index].sold+=suma;

            }
            else  /// scadere
            {
                token=strtok(NULL,";"); //beneficiar
                token=strtok(NULL,";"); //suma

                //double suma=atof(token);

                char *end;
                double suma=strtod(token,&end);

                sold[index].sold-=suma;
            }
        }
    }
    fclose(fptr);
}

void mesaj_eroare_solduri() /// soldurile nu pot fi afisate
{
    printf("\nSoldurile conturilor nu pot fi afisate!\n");
}

void solduri() /// soldurile conturilor bancare
{
    FILE *fptr;
    fptr=fopen("conturiFinanciare.txt","r");

    if(fptr==NULL)
    {
        mesaj_eroare_solduri();
        contabilitate();
        return;
    }
    int index=0;

    while(!feof(fptr))
    {
        char s[1000];
        fscanf(fptr,"%s",s);

        if(strlen(s)<6)
        {
            break;
        }

        char *token=strtok(s,";");

        strcpy(sold[index].cont,token);

        index++;
    }

    fclose(fptr);


    if(index==0)
    {
        mesaj_solduri_inexistente();
        return;
    }

    for(int i=0;i<index;i++)
    {
        sold[i].sold=0.0;
        calculeaza_sold(i);
    }

    for(int i=0;i<index;i++)
    {
        afiseaza_sold(i);
    }
}



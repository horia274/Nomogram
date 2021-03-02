# Nomogram

## Enunt

Pe scurt, este vorba de a verifica daca un *grid* dat si niste constrangeri satisfac conditiile
impuse de jocul **Nomogram**. Pentru mai multe detalii cititi acest [link](https://acs.curs.pub.ro/2019/pluginfile.php/50548/mod_folder/content/0/Programare_2019___Tema_1.pdf?forcedownload=1), in cadrul sectiunii *Problema 4 - Nomogram*.

## Explicatii cod

Pentru fiecare grid, voi citi in variabilele *n*, *m* dimensiunile matricii *a*, cea completata
cu 1 si 0 de gigel. Matricea *l* contine pe pozitia *l\[i]\[0]* numarul grupurilor colorate iar
pe urmatoarele pozitii de pe linia *i*, dimensiunile grupurilor. In mod analog folosesc si
matricea *c* pentru coloane.
	
Functia **check** returneaza valoarea 1 daca gridul este corect, respectiv 0, daca este
gresit. Voi folosi si in interiorul functiei si in main variabilele *n*, *m* si matricile *a*, *l*,
*c* cu aceleasi semnificatii. Verific conditiile problemei, iar daca pe parcurs, gasesc
contradictii, returnez valoarea 0. In final de tot, daca functia trece de toate restrictiile,
inseamna ca gridul este corect si returnez valoarea 1.

Acum, in aceasta functie, pentru fiecare linie *i* din matricea *a*, verific daca informatiile
din matricea *l* corespund cu gridul stocat in matricea *a*. Pentru fiecare linie i a matricii,
calculez in variabila *nr*, cate grupuri colorate exista, iar la final compar rezultatul cu *l[i]\[0]*.
Pentru fiecare grup colorat, voi calcula dimensiunea in variabila *dim*. Variabila *k*, este
un indice pentru matricea *l*, pentru a putea compara valoarea lui dim cu *l\[i]\[k]*. 

Pe linia *i*, daca primul element este 1, atunci numarul grupurilor colorate este 1, iar
dimnesiunea acestuia este tot 1. Acum parcurg indicii *j*, de la 1 la m-1 si dinting urmatoarele
situatii:

1. Daca pe pozitia curenta *j* am valoarea 1 iar pe cea anterioara *j-1* tot 1, inseamna ca grupul
colorat nu s-a terminat, iar dimensiunea acestuia creste cu o unitate. De asemenea, trebuie tinut
cont daca se ajunge la marginea matricii *a* (j==m-1), caci trebuie verificata dimensiunea obtinuta
cu valoarea din matricea *l*.
	
2. Daca pe pozitia curenta am 1 iar pe cea anterioara 0, inseamna ca am gasit un nou grup colorat,
astfel numarul lor de pe linia *i* creste cu o unitate, iar dimensiunea devine 1. Trebuie verificat
din nou daca am ajuns la capatul matricii *a* (j==m-1).

3. Daca pe pozitia curenta am 0 si pe cea anterioara 1, inseamna ca grupul colorat s-a terminat si
trebuie din nou verificata dimensiunea lui. Apoi dimensiunea trebuie actualizata cu valoarea 1, iar
*k* incrementat, sa pot verifica in continuare daca *dim*==*l\[i]\[k]* sau nu.

Apoi, in cadrul for-ului care vizeaza linia *i*, verific daca numarul grupurilor colorate *nr* este
egal cu l[i]\[0].

Acelasi lucru il voi face si cu coloanele, cu aceleasi variabile, *nr* si *dim*, schimband doar indicii
si matricea *c*, in locul lui *l*.

In **main**, citesc datele problemei, variabila *t* reprezinta numarul de puzzle-uri iar pentru fiecare
citesc datele respective (dimensiunile *n* si *m*, matricile *l*, *c*, *a*). In vectorul *v*, pe pozitia *i*,
voi retine valoarea functiei **check**, a puzzle-ului, iar apoi daca *v\[i]*==1 voi afisa mesajul *corect*
iar altfel *eroare*.


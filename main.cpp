//*****************************************************************************************
//Universitatea TRANSILVANIA din Brasov: Facultatea de Inginerie Electrica si Stiinta Calculatoarelor
//Specializare: Inginerie electronica, telecomunicatii si tehnologii informationale
//CONTRIBUITORI:
//Catalin Daniel Bradac, ETTI, anul I, grupa I
//TEMA II PCLP, Fisiere in format Comma Separated Values (CSV).
//*****************************************************************************************


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // Introducerea datelor de la tastatura
  double M, N;
  cout << "Introdu coordonatele: ";
  cin >> M >> N;

  // Deschiderea fisierelor necesare programului
  ifstream fin("localitatiRO.csv");
  ofstream fout("vecini.csv");

  // Citirea numelor coloanelor din fisierul sursa si scrierea sa in fisierul target
  string line;
  getline(fin, line);
  fout << line << endl;

  // Citirea datelor linie cu linie, fiecare linie pe rand
  while (getline(fin, line)) {
    // Impartirea liniilor in campuri folosind o virgula ca delimitator
    vector<string> fields;
    size_t pos = 0, end;
    while ((end = line.find(',', pos)) != string::npos) {
      fields.push_back(line.substr(pos, end - pos));
      pos = end + 1;
    }
    fields.push_back(line.substr(pos));

    // Convertirea numarului populatiei intr-un numar intreg
    int population = stoi(fields[5]);

    // Convertirea coordonatelor
    double P = stod(fields[0]);
    double Q = stod(fields[1]);

    // Verificare daca locatia se afla la 0,5 grade de punct si are mai mult de 1000 de locuitori
    if (M - 0.5 <= P && P <= M + 0.5 && N - 0.5 <= Q && Q <= N + 0.5 && population > 1000) {
      // Scrierea datelor in fisierul target
      fout << line << endl;
    }
  }

  // Inchiderea fisierului sursa si target
  fin.close();
  fout.close();

  // Printeaza datele din fisierul target in consola
  {
  // Deschiderea fisierului target
  ifstream fin("vecini.csv");

  // Citirea datelor linie cu linie din fisierul target
  string line;
  while (getline(fin, line)) {
    // Printeaza rezultatul in consola
    cout << line << endl;
  }

  // Inchiderea fisierului target
  fin.close();

  return 0;
}

  return 0;
}

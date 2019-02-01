#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

/*
id1 = a^2 + b^2 + 2ab
id2 = a^2 + b^2 - 2ab
id3 = a^2 - b^2
*/

void id1();
void id2();
void id3();
int ficheroRespuestas();

int Coeficientes[2];
int Exponentes[2];
int preResultados[7];
/*
Posicion 0 = Primer monomio
Posicion 1 = Segundo monomio
... */
int op1;

//int Resultados[6];

int main()
{
  //int op1;
  cout <<" Que identidad desea usar?" <<endl;
  cout <<" 1. Suma al cuadrado" <<endl;
  cout <<" 2. Diferencia al cuadrado" <<endl;
  cout <<" 3. Suma por diferencia" <<endl;
  cout <<" ===> ";
  cin >> op1;
  //Siguiente paso
  cout <<" Ponga el coeficiente del primer monomio" <<endl;
  cout <<" ===> ";
  cin >> Coeficientes[0];
  cout <<" Ponga el exponente de la parte literal" <<endl;
  cout <<" ===> ";
  cin >> Exponentes[0];
  cout <<" Ponga el coeficiente del segundo monomio " <<endl;
  cout <<" ===> ";
  cin >> Coeficientes[1];
  cout <<" Ponga el exponente de la segunda parte literal" <<endl;
  cout <<" ====> ";
  cin >> Exponentes[1];
  //Tercer paso: reconocer la formula que hay que usar:
  /*
  Formula 1: a^2 + b^2 + 2ab
  Formula 2: a^2 + b^2 - 2ab
  Formula 3: a^2 - b^2
  */
  switch (op1) {
    case 1:{
      cout <<" Usted ha seleccionado 'Suma al cuadrado'... " <<endl;
      id1();
    }
    break;
    case 2:{
      cout <<" Usted ha seleccionado 'Diferencia al cuadrado'... " <<endl;
      id2();
    }
    break;
    case 3:{
      cout <<" Usted ha seleccionado 'Suma por diferencia'... " <<endl;
      id3();
    }
    break;
    default: cout <<" Opcion incorrecta " <<endl; exit(1);
  }
  string op2;
  cout <<" Quiere guardar el resultado en un fichero?(s/n)" <<endl;
  cout <<" ===> ";
  cin >> op2;
  if(op2 == "S"||op2 == "s")
  {
    if(ficheroRespuestas() == 1)
    {
      cout <<" El proceso ha fallado" <<endl;
    }
    else{
      cout <<" Se ha creado el fichero" <<endl;
    }
  }
  system("PAUSE");
  return 0;
}

void id1()
{
  //a^2 + b^2 + 2ab
  preResultados[0]=Coeficientes[0]*Coeficientes[0];
  preResultados[1]=Exponentes[0]*2;
  preResultados[2]=Coeficientes[1]*Coeficientes[1];
  preResultados[3]=Exponentes[1]*2;
  //2ab
  preResultados[4]=2*Coeficientes[0];
  preResultados[5]=preResultados[4]*Coeficientes[1];
  preResultados[6]=Exponentes[0]+Exponentes[1];
  cout <<" Es " <<preResultados[0] <<"x^" <<preResultados[1] <<" + " <<preResultados[2] <<"x^" <<preResultados[3] <<" + " <<preResultados[5] <<"x^" <<preResultados[6] <<endl;
}
void id2()
{
  //a^2 + b¨2 - 2ab
  preResultados[0]=Coeficientes[0]*Coeficientes[0];
  preResultados[1]=Exponentes[0]*2;
  preResultados[2]=Coeficientes[1]*Coeficientes[1];
  preResultados[3]=Exponentes[1]*2;
  //2ab
  preResultados[4]=2*Coeficientes[0];
  preResultados[5]=preResultados[4]*Coeficientes[1];
  preResultados[6]=Exponentes[0]+Exponentes[1];
  cout <<" Es " <<preResultados[0] <<"x^" <<preResultados[1] <<" + " <<preResultados[2] <<"x^" <<preResultados[3] <<" - " <<preResultados[5] <<"x^" <<preResultados[6] <<endl;
}
void id3()
{
  //a^2 - b^2
  preResultados[0]=Coeficientes[0]*Coeficientes[0];
  preResultados[1]=Exponentes[0]*2;
  preResultados[2]=Coeficientes[1]*Coeficientes[1];
  preResultados[3]=Exponentes[1]*2;
  //No hay 2ab
  cout <<" Es " <<preResultados[0] <<"x^" <<preResultados[1] <<" - " <<preResultados[2] <<"x^" <<preResultados[3] <<endl;
}

int ficheroRespuestas()
{
  cout <<" Que nombre de archivo quieres? (No hace falta poner la extension) " <<endl;
  cout <<" ===> ";
  cin.ignore();
  string nombreFichero;
  getline(cin, nombreFichero);
  nombreFichero = nombreFichero + ".txt";
  ofstream Respuestas;
  Respuestas.open(nombreFichero, ios::out);
  Respuestas << " Se ha seleccionado la Opcion " <<op1 <<": ";
  switch (op1) {
    case 1: Respuestas <<" Suma al cuadrado" <<endl;
    break;
    case 2: Respuestas <<" Diferencia al cuadrado" <<endl;
    break;
    case 3: Respuestas <<" Suma por diferencia" <<endl;
    break;
    default: exit(1);
  }
  Respuestas <<" El binomio es: ";
  switch(op1){
    case 1: Respuestas <<"(" <<Coeficientes[0] <<"x^" <<Exponentes[0] <<" + " <<Coeficientes[1] <<"x^" <<Exponentes[1] <<")^2" <<endl;
    break;
    case 2: Respuestas <<"(" <<Coeficientes[0] <<"x^" <<Exponentes[0] <<" - " <<Coeficientes[1] <<"x^" <<Exponentes[1] <<")^2" <<endl;
    break;
    case 3:{
      Respuestas <<"(" <<Coeficientes[0] <<"x^" <<Exponentes[0] <<" + " <<Coeficientes[1] <<"x^" <<Exponentes[1] <<")";
      Respuestas <<"(" <<Coeficientes[0] <<"x^" <<Exponentes[0] <<" - " <<Coeficientes[1] <<"x^" <<Exponentes[1] <<")" <<endl;
    }
    break;
    default: exit(1);
  }
  Respuestas <<" El resultado es: ";
  switch(op1)
  {
    case 1: Respuestas <<preResultados[0] <<"x^" <<preResultados[1] <<" + " <<preResultados[2] <<"x^" <<preResultados[3] <<" + " <<preResultados[5] <<"x^" <<preResultados[6] <<endl;
    break;
    case 2: Respuestas <<preResultados[0] <<"x^" <<preResultados[1] <<" + " <<preResultados[2] <<"x^" <<preResultados[3] <<" - " <<preResultados[5] <<"x^" <<preResultados[6] <<endl;
    break;
    case 3: Respuestas <<preResultados[0] <<"x^" <<preResultados[1] <<" - " <<preResultados[2] <<"x^" <<preResultados[3] <<endl;
    break;
    default: exit(1);
  }
  if(Respuestas.fail())
  {
    return 1;
  }
  else{
    Respuestas.close();
    return 0;
  }
}

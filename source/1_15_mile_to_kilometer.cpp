//Lina Klass
//Aufgabe 1.15 - Meilen in Kilometer umrechnen

#include <cmath>
#include <iostream> 

double mile_to_kilometer(double mile){ 
  double const faktor = 1.609;
  return faktor * mile;
}


int main(int argc, char* argv[])
{
  std::cout << "Geben Sie einen Wert in Meilen an, der in Km umgerechnet werden soll:\n"; 
  double mile = 0.0;
  std::cin >> mile;

  std::cout<< mile << " Meilen sind " << mile_to_kilometer(mile) << " Kilometer.\n";

}

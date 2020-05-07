//Lina Klass

#define CATCH_CONFIG_RUNNER 
#include "../external/catch-1.4.0/catch.hpp" 
#include <cmath>

//Aufgabe 1.8 - groesster gemeinsamer Teiler
int gcd(int a, int b){ 
  if (b == 0 && a == 0) {
        std::cout<< "Uebergebene Zahlen duerfen nicht beide negativ sein.";
        return -1;
    }

  if(b == 0){
    return abs(a);
  }
  else{
    return(gcd(b, a % b));
  }
}

//Aufgabe 1.9 - Quersumme
int checksum(int a){
    int result = 0;
    if(a<0){
      return -1;
      std::cout<<"Quersumme ist für negative Zahlen nicht definiert.";
    }
    while(a > 0){
        result = result + (a % 10);
        a = (a - (a % 10)) / 10;
    }
    return result;
}

//Aufgabe 1.10 - durch 3 und 5 teilbare Zahlen von 1 bis zu uebergebenem Parameter summieren
int sum_multiples(int until){
    int sum = 0;
    int i = 1; //zu testende Zahl
    if(until<1){
      return -1;
      std::cout<<"Die uebergebene Obergrenze muss groesser oder gleich 1 sein.";
    }
    while(i <= until){
        if((i % 3 == 0) || (i % 5 == 0)){
            sum = sum + i;
        }
            i = i + 1;
    }
    return sum;
}

//Aufgabe 1.11
double fract(double a){
  int vorkomma = int(a);
  return a-vorkomma;
} 

//Aufgabe 1.12 - Volumen Zylinder
double volumen_zylinder(double r, double h){
  if(r<0 || h<0){
    return -1;
    std::cout<<"Weder Radius noch Höhe des Zylinders dürfen negativ sein.";
  }
  else{
    return M_PI*pow(r,2.0)*h;
  }
}

//Aufgabe 1.12 - Oberflaeche Zylinder
double oberflaeche_zylinder(double r, double h){
  if(r<0 || h<0){
    return -1;
    std::cout<<"Weder Radius noch Höhe des Zylinders dürfen negativ sein.";
  }
  else{
    double surface = 2 * M_PI * r * (r + h);
    return surface;
  }
}

//Aufgabe 1.13 - Faktor einer natürlichen Zahl
int factorial(int a){
  int result = 1;
  if(a<0){
    return -1;
    std::cout<<"Die Eingabe darf nicht negativ sein.\n";
  }
  for(int i=1;i<=a;i++){
    result = result*i;
  }
  return result;
}

// Aufgabe 1.14 - Test ob Primzahl
bool is_prime(int a){ 
  if(a<=1){
    return false;
  }
  for(int i=2; i<a; i++){
    if(a%i == 0){
      return false;
    }
    else{
      return true;
    }
  }
  return true; //für Fall a == 2
}

// Aufgabe 1.8
TEST_CASE("größter_gemeinsamen_teiler_bestimmen", "[gcd]"){
  REQUIRE(gcd(2,4) == 2); 
  REQUIRE(gcd(9,6) == 3); 
  REQUIRE(gcd(3,7) == 1);
  REQUIRE(gcd(0,5) == 5);
  REQUIRE(gcd(4,0) == 4);
  REQUIRE(gcd(0,0) == -1); 
  REQUIRE(gcd(-1,0) == 1); 
  REQUIRE(gcd(0,-8) == 8); 
  REQUIRE(gcd(-9,-6) == 3); 
  REQUIRE(gcd(9,-6) == 3); 
}

//Aufgabe 1.9
TEST_CASE("Quersumme_berechnen", "[checksum]"){ 
  REQUIRE(checksum(121155) == 15); // Matrikelnummer
  REQUIRE(checksum(0) == 0); 
  REQUIRE(checksum(01) == 1); 
  REQUIRE(checksum(001) == 1);
  REQUIRE(checksum(1000) == 1); 
  REQUIRE(checksum(123) == 6); 
  REQUIRE(checksum(100) == 1); 
  REQUIRE(checksum(912) == 12);
  REQUIRE(checksum(-1) == -1);
  REQUIRE(checksum(-5) == -1);
}

//Aufgabe 1.10
TEST_CASE("berechne_sum_multiples", "[gcd]"){
  REQUIRE(sum_multiples(1000) == 234168);
  REQUIRE(sum_multiples(3) == 3);
  REQUIRE(sum_multiples(5) == 8);
  REQUIRE(sum_multiples(1) == 0);
  REQUIRE(sum_multiples(12) == 45);
  REQUIRE(sum_multiples(0) == -1);
  REQUIRE(sum_multiples(-4) == -1);
  REQUIRE(sum_multiples(1) == 0);
}


//Aufgabe 1.12 - Volumen
TEST_CASE("Volumen_Zylinder", "[volumen_zylinder]"){
  REQUIRE(volumen_zylinder(3,3) == Approx(84.82300165));
  REQUIRE(volumen_zylinder(1.1,0.1) == Approx(0.3801327111));
  REQUIRE(volumen_zylinder(-4,5) == -1);
  REQUIRE(volumen_zylinder(2,-7) == -1);
  REQUIRE(volumen_zylinder(0,4) == 0);
}

//Aufgabe 1.12 - Oberfläche
TEST_CASE("Oberflaeche_Zylinder", "[oberflaeche_zylinder]"){
  REQUIRE(oberflaeche_zylinder(3.1,7.8) == Approx(212.3088315));
  REQUIRE(oberflaeche_zylinder(0.5,2) == Approx(7.853981634));
  REQUIRE(oberflaeche_zylinder(0,3) == 0);
  REQUIRE(oberflaeche_zylinder(-3,3) == -1);
}

//Aufgabe 1.11
TEST_CASE("Nachkomma- Anteil einer Gleitkommazahl", "[fract]"){
  REQUIRE(fract(0.123) == Approx(0.123));
  REQUIRE(fract(5.176) == Approx(0.176)); 
  REQUIRE(fract(-9.444) == Approx(-0.444)); 
  REQUIRE(fract(-9.9941234567890) == Approx(-0.9941234567890)); 
  REQUIRE(fract(0) == 0); 
  REQUIRE(fract(5) == 0); 
  REQUIRE(fract(-3) == 0);
}

//Aufgabe 1.13
TEST_CASE("Faktor_einer_natürlichen_Zahl", "[factorial]"){
  REQUIRE(factorial(5) == 120);
  REQUIRE(factorial(11) == 39916800); 
  REQUIRE(factorial(0) == 1); 
  REQUIRE(factorial(1) == 1); 
  REQUIRE(factorial(-1) == -1); 
  REQUIRE(factorial(-4) == -1); 
}

//Aufgabe 1.14 (Eine Primzahl ist eine natürliche Zahl, die größer als 1 und ausschließlich durch sich selbst und durch 1 teilbar ist.)
TEST_CASE("check_if_prime", "[is_prime]"){
  REQUIRE(is_prime(0) == false); 
  REQUIRE(is_prime(-1) == false); 
  REQUIRE(is_prime(1) == false); 
  REQUIRE(is_prime(2) == true); 
  REQUIRE(is_prime(-9) == false); 
  REQUIRE(is_prime(3) == true);
  REQUIRE(is_prime(22) == false);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}

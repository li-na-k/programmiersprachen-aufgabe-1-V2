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

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}

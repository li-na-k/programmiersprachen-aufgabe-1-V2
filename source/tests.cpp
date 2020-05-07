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
  REQUIRE(checksum(121155) == 15);
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

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}

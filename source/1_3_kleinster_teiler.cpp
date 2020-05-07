//Lina Klass
//kleinste Zahl, die durch die Zahlen 1 bis 20 teilbar ist errechnen und ausgeben

#include <iostream>

int main(){
    bool found = false;
    int zahl = 1; // zu testende Zahl
    while(found == false){
        int i = 1; //aktuell zu prüfender Teiler
        while(i <= 20){
            if(zahl % i == 0){ 
                i++;
            }
            else{
                zahl = zahl + 1; //next
                i = 1; //reset
            }
        }
        found = true;
    }
    std::cout<<zahl << "\n";
    return 0;
}
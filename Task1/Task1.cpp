#include <iostream>


/* TYHJÄ ARRAY TULOSTUS:
- 858993460
- 858993460
- 858993460
- 858993460
- 858993460
- 858993460
- 858993460
- 858993460
- 858993460
- 858993460

Vastauksena tämä on kääntäjän omaa tyhjäädataa. Eli käytännössä osoittaa tyhjään muistiinm,
joka sillä hetkellä on varattu pinossa. Ja tämä todennäköisestim vaihtuisi kääntäjästä riippuen
*/
void print_empty_array() {

    int array[10];

    for (int i = 0; i < 10; i++) {
        std::cout << array[i] << std::endl;
    }
}

/* TAULUKON OHI TULOSTUS:
0
0
...
0
- 858993460

Taulukon ohi tulostettu kohta näyttää saman roskadatan
*/
void print_over_the_array() {

    int array[10];

    // Pelkkäää nollaa taulukkoon
    for (int i = 0; i < 10; i++) {

        array[i] = 0;
    }

    // Luetaan taulukon ohi
    for (int i = 0; i < 11; i++) {
        
        std::cout << array[i] << std::endl;
    }
}

/* TAULUKON OHI KIRJOITUS:
1
2
...
10
*Run-Time Check Failure #2 - Stack around the variable 'array' was corrupted.*

Taulukon ohi ei pystynyt kirjoittaa, koska siitä varten ei oltu varattu muistia, 
jonka takia olemattomaan kohtaan ei voinut kirjoittaa+
*/
void write_over_the_array() {

    int array[10];

    // Kirjoitetaan ja tulostetaan samalla
    for (int i = 0; i < 11; i++) {

        array[i] = i;
        std::cout << array[i] << std::endl;
    }
}

void dynamic_array() {
    // Dynaamisesti varattu taulukko
    unsigned n = 10;
    int* array = new int[n];

    // Taulukko täyteen nollia
    for (unsigned  i = 0; i < n; i++) {

        array[i] = 0;
    }

    // Sisällön muutos
    for (unsigned  i = 0; i < n; i++) {

        array[i] = 1;
    }

    // new[] taulukon kokoa ei voi muuttaa, koska se on kiinteä sen poistamiseen asti
    // Joten täytyy luoda uusi isompi taulukko, johon kopioidaan vanha data ja luodaan uusi
    unsigned new_n = 20;
    int* new_array = new int[new_n];

    for (unsigned  i = 0; i < new_n; i++) {

        if (i < n) {
            new_array[i] = array[i];
        }
        else {
            new_array[i] = 2;
        }
    }

    // Sen jälkeen voidaan poistaa alkuperäinen taulukko
    delete[] array;
    // Ja luoda uusi taulukko alkuperäisen nimellä ja kopioidaan sinne sivuun tallennettu data
    array = new_array;
    n = new_n;

    // Sisällön muutos
    for (unsigned i = 0; i < n; i++) {
        std::cout << array[i] << std::endl;
    }
    delete[] array;
    // Vähä kikkailuu, mut tolleen ainaskin toimii :)
}

int main()
{
    std::cout << "Hello World!\n";
    //print_empty_array();
    //print_over_the_array();
    //write_over_the_array();
    dynamic_array();
}

#include <iostream>
#include <string>
using namespace std;

     

class Vigenere

{

public:
string key;

     
//menyimpan nilai variabel Vignere sebagai String
 Vigenere(string key){

    for (int i = 0; i < key.size(); ++i){

        if (key[i] >= 'A' && key[i] <= 'Z')

            this->key += key[i];

        else if (key[i] >= 'a' && key[i] <= 'z')

            this->key += key[i] + 'A' - 'a';

        }

    }

     
//Proses encrypt terhadapstring yang akan di proses
string encrypt(string text){
string out;

    for (int i = 0, j = 0; i < text.length(); ++i){
    char c = text[i];

        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
        continue;
    out += (c + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
    }

    return out;
    }

//Proses decrypt terhadapstring yang akan di proses
string decrypt(string text){
string out;
    for (int i = 0, j = 0; i < text.length(); ++i){
    char c = text[i];
        if (c >= 'a' && c <= 'z')
        c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
        continue;

        out += (c - key[j] + 26) % 26 + 'A';
        j = (j + 1) % key.length();
    }
    return out;
            }
    };

int main(){
Vigenere cipher("VIGENERECIPHER");
    //String yang akan di proses 
    string original ="Elbama Giofandra Rizky Ramadhan";
    string encrypted = cipher.encrypt(original);
    string decrypted = cipher.decrypt(encrypted);

    //output enkripsi dan dekripsi terhadap string diatas
    cout << original << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    }
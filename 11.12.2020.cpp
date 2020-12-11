#include <iostream>
#include <fstream>
#define T_SIZE 200
using namespace std;


//int main(){
//	cout<<nwd(16, 12);
//}

class kolekcja{
	int t[T_SIZE];
	
	public:
		bool wczytaj_z_pliku();
		void show();
};

void kolekcja::show()
{
	for (int i=0; i<T_SIZE; i++)
	cout << t[i] << " ";
}

bool kolekcja::wczytaj_z_pliku()
{
	ifstream wejscie;
	wejscie.open("liczby.txt");
	
	if(!wejscie.good())
	{
		cerr << "Pliku nie mozna otworzyc!!";
		return false;
	}
	int licznik_wczytanych = 0;
	while (!wejscie.eof() && licznik_wczytanych < T_SIZE) 
		//dopoki nie koniec pliku i przczytanych liczb jest mnieij niz 200
	{
		wejscie >> t[licznik_wczytanych++]; //najpierw wczyta liczbe a potem licznik zwiekszy o 1
	}
	wejscie.close();
	return true;
}

int nwd(int x, int y)
{
    if (x < y)
        return nwd(y,x);
    if (y == 0)
        return x;
    return nwd(y, x%y);
}

int main(){
	kolekcja liczby; //tworzenie obiektu liczby klasy kolekcja
	if (liczby.wczytaj_z_pliku())
	{
	liczby.show();
	}
	return 0;
}

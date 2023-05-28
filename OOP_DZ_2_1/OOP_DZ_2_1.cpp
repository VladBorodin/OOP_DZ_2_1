#include <iostream>
#include <windows.h>
#define NAME 30
#define MAX 100
#define CIN_FLUSH if (std::cin.peek()) std::cin.ignore()

using namespace std;

class Human {
private:
	char* FIO;
public:
	Human() {
		FIO = nullptr;
	}
	char* getFIO() {
		return FIO;
	}
	void setFIO() {
		if (FIO != nullptr) {
			delete[] FIO;
		}
		FIO = new char[NAME];
		for (int i = 0; i < NAME; i++) {
			FIO[i] = 0;
		}
	}
	void handFIO() {
		if (FIO != nullptr) {
			delete[] FIO;
			FIO = nullptr;
		}
		char fio[NAME]{ 0 };
		cout << "Введите имя жильца: " << endl;
		gets_s(fio, NAME);
		system("cls");
		FIO = new char[strlen(fio) + 1]{ 0 };
		strcpy_s(FIO, strlen(fio) + 1, fio);
	}
	void randFIO() {
		int rndFIO = rand() % 10;
		/*
		for (int i = 0; i < 4; i++) {
			i % 2 != 0 ? FIO[i] = 46 : FIO[i] = rand() % 18 + 192;
		}
		*/
		if (rndFIO == 0) {
			rand() % 2 == 1 ? strcpy_s(FIO, strlen("Иванов") + 1, "Иванов") : strcpy_s(FIO, strlen("Иванова") + 1, "Иванова");
		} else if (rndFIO == 1) {
			rand() % 2 == 1 ? strcpy_s(FIO, strlen("Сергеев") + 1, "Сергеев") : strcpy_s(FIO, strlen("Сергеева") + 1, "Сергеева");
		} else if (rndFIO == 2) {
			rand() % 2 == 1 ? strcpy_s(FIO, strlen("Железный") + 1, "Железный") : strcpy_s(FIO, strlen("Железная") + 1, "Железная");
		} else if (rndFIO == 3) {
			strcpy_s(FIO, strlen("Новик") + 1, "Новик");
		} else if (rndFIO == 4) {
			rand() % 2 == 1 ? strcpy_s(FIO, strlen("Оршин") + 1, "Оршин") : strcpy_s(FIO, strlen("Оршина") + 1, "Оршина");
		} else if (rndFIO == 5) {
			strcpy_s(FIO, strlen("Ловчих") + 1, "Ловчих");
		} else if (rndFIO == 6) {
			strcpy_s(FIO, strlen("Полончук") + 1, "Полончук");
		} else if (rndFIO == 7) {
			rand() % 2 == 1 ? strcpy_s(FIO, strlen("Мечников") + 1, "Мечников") : strcpy_s(FIO, strlen("Мечникова") + 1, "Мечникова");
		} else if (rndFIO == 8) {
			rand() % 2 == 1 ? strcpy_s(FIO, strlen("Спиридонов") + 1, "Спиридонов") : strcpy_s(FIO, strlen("Спиридонова") + 1, "Спиридонова");
		} else if (rndFIO == 9) {
			rand() % 2 == 1 ? strcpy_s(FIO, strlen("Постов") + 1, "Постов") : strcpy_s(FIO, strlen("Постова") + 1, "Постова");
		}
	}
	void showFIO() {
		cout << "        --- ЖИЛЕЦ ---" << endl;
		int i = 0;
		while (FIO[i] != 0){
			cout << FIO[i];
			i++;
		}
		cout << endl;
	}
	Human(const Human& other) {
		for (int i = 0; i < NAME; i++) {
			this->FIO = other.FIO;						//проверить
		}
	}
	~Human() {
		/*
				if (FIO != nullptr){
					delete[] FIO;
					FIO = nullptr;
				}
		*/
	}
};
class Apartament {
private:
	Human* h;
	int randH{0};
	int aNomber[MAX]{ 0 };
public:
	Apartament() {
		h = nullptr;
	}
	void addHumans() {
		randH += rand() % 3 + 1;
		if (h == nullptr) {
			h = new Human[randH];
			for (int i = 0; i < randH; i++) {
				h[i].setFIO();
				h[i].randFIO();
			}
		} else {
			h[randH].setFIO();
			h[randH].randFIO();
			randH++;
		}
	}
	void addHumans(int amountH) {
		h = new Human[amountH];
		randH = amountH;
		for (int i = 0; i < amountH; i++) {
			h[i].setFIO();
			h[i].handFIO();
		}
	}
	void showApartament() {
		int i = 0;
		for (int i = 0; i<randH; i++) {
			h[i].showFIO();
		}
	}
	~Apartament() {
		delete[] h;
	}
};
class Home {
private:
	Apartament* apartaments;
	int aNomber[MAX]{0};
	int size{0};
public:
	int hAmount{0};
	int randA{0};
	Home() {
		apartaments = nullptr;
	}
	void addApartaments(int amountA) {
		randA = amountA;
		apartaments = new Apartament[amountA];
		for (int i = 0; i < amountA; i++) {
			aNomber[size] = size+1;
			cout << "Введите кол-во жильцов для кв № "<<aNomber[size++]<<": ";
			cin >> hAmount; 
			cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
			CIN_FLUSH;
			system("cls");
			apartaments[i].addHumans(hAmount);
		}
	}
	void addApartaments() { 
		randA = rand() % 16 + 4;
		apartaments = new Apartament[randA];
		for (int i = 0; i < randA; i++) {
			aNomber[size] = size++ + 1;
			apartaments[i].addHumans();
		}
	}
	void showHome() {
		int i = 0;
		for (int i = 0; i<randA; i++) {
			cout << "    --- --- Квартира № " << aNomber[i] << " --- ---" << endl;
			apartaments[i].showApartament();
		}
	}
	~Home() {
		delete[] apartaments;
	}
};
class Dvor {
private:
	Home* H;
	int hNomber[MAX]{0};
	int size{ 0 };
public:
	int HAmount{ 0 };
	int randH{ 0 };
	Dvor() {
		H = nullptr;
	}
	void addHome(int amountH) {
		randH = amountH;
		H = new Home[amountH];
		for (int i = 0; i < amountH; i++) {
			hNomber[size] = size + 1;
			cout << "Введите кол-во квартир для дома №" << hNomber[size++] << ": ";
			cin >> HAmount;
			cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
			CIN_FLUSH;
			system("cls");
			H[i].addApartaments(HAmount);
		}
	}
	void addHome() {
		randH = rand() % 3 + 1;
		H = new Home[randH];
		for (int i = 0; i < randH; i++) {
			hNomber[size] = size++ + 1;
			H[i].addApartaments();
		}
	}
	void showDvor() {
		int i = 0;
		for (int i = 0; i < randH; i++) {
			cout << "--- --- --- Дом № " << hNomber[i] << " --- --- ---" << endl;
			H[i].showHome();
		}
	}
	~Dvor() {
		delete[] H;
	}
};

int main() {
	system("chcp 1251 | cls");
	srand(time(0));
	Dvor d;
	int v{ 0 };
	bool yes{ 0 };
	cout << "Вы хотите сами настроить заполнить двор домами, а дома жильцами?\n1.Да\n2.Нет\n";
	while (v < 1 || v > 2) {
		cin >> v;
		cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
		CIN_FLUSH;
		switch (v)
		{
		case 1:
			yes = true;
			break;
		}
	}
	system("cls");
	if (yes) {
		cout << "Сколько домов у двора?" << endl;
		cin >> v;
		cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
		CIN_FLUSH;
		system("cls");
		d.addHome(v);
	} else {
		d.addHome();
	}
	d.showDvor();
}
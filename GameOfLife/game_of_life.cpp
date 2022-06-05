#include "game_of_life.h"

#include <ctime>

using namespace std;

bool game_of_life::slucajna_vrijednost()
{
	// 0 - min, 1 - max
	return rand() % (1 - 0 + 1) + 0;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {

			int brojSusjeda = 0;
			bool celija = celija_zauzeta(i, j);
			// Broj susjednih celija
			for (int y = -1; y <= 1; y++) {
				for (int x = -1; x <= 1; x++) {
					if (x == 0 && y == 0) continue;
					
					int xCelija = x + j;
					int yCelija = y + i;

					if (xCelija < 0 || xCelija >= STUPACA || yCelija < 0 || yCelija >= REDAKA) continue;

					bool c = celija_zauzeta(yCelija, xCelija);
					if (c) brojSusjeda++;
				}
			}

			if (celija)
			{
				if (brojSusjeda < 2 || brojSusjeda > 3) _sljedeca_generacija[i][j] = false;
			}
			else
			{
				if (brojSusjeda == 3) _sljedeca_generacija[i][j] = true;
			}
		}
	}

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	cout << endl;
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			bool celija = _generacija[i][j];

			if (celija) cout << '*';
			else cout << ' ';
		}
		cout << endl;
	}
}

#include <iostream>
#include <string>
#include <vector>
#include "asema.h"
using namespace std;


void Asema::anna_kaikki_raakasiirrot(int pelaaja, std::vector<Siirto>& siirrot) const
{
	for (int rivi = 0; rivi < 8; ++rivi)
		for (int linja = 0; linja < 8; ++linja)
		{
			int nappula = _lauta[rivi][linja];

			// Tyhj� ruutu?
			if (nappula == NA)
				continue;

			// Vastustajan nappula?
			if (nappulan_vari(pelaaja) != pelaaja)
				continue;

			// Haetaan nappulan raakasiirrot.
			switch (nappula)
			{
			case wR: case bR:
				anna_tornin_raakasiirrot(rivi, linja, pelaaja, siirrot);
				break;
			case wQ: case bQ:
				anna_daamin_raakasiirrot(rivi, linja, pelaaja, siirrot);
				break;
			case wN: case bN:
				anna_ratsun_raakasiirrot(rivi, linja, pelaaja, siirrot);
				break;
			case wB: case bB:
				anna_lahetin_raakasiirrot(rivi, linja, pelaaja, siirrot);
				break;
			case wK: case bK:
				anna_kuninkaan_raakasiirrot(rivi, linja, pelaaja, siirrot);
				break;
			case wP: case bP:
				anna_sotilaan_raakasiirrot(rivi, linja, pelaaja, siirrot);
				break;
			}
		}
}


void Asema::tyhjenna()
{
	for (int rivi = 0; rivi < 8; ++rivi)
		for (int linja = 0; linja < 8; ++linja)
			_lauta[rivi][linja] = NA;
}


void Asema::tee_siirto(const Siirto& s)
{
	// Otetaan alkuruudussa oleva nappula talteen.
	int nappula = _lauta[s._a_r][s._a_l];

	// Tyhjennet��n alkuruutu.
	_lauta[s._a_r][s._a_l] = NA;

	// Sijoitetaan loppuruutuun alkuper�inen nappula.
	_lauta[s._l_r][s._l_l] = nappula;

	// Vaihdetaan siirtovuoro.
	_siirtovuoro = vastustaja(_siirtovuoro);
}


void Asema::anna_tornin_raakasiirrot(int rivi, int linja, int pelaaja,
	vector<Siirto>& siirrot) const
{
	anna_raakasiirrot_suunnassa(rivi, linja,-1, 0, pelaaja, 7, true, false, siirrot);
	anna_raakasiirrot_suunnassa(rivi, linja, 1, 0, pelaaja, 7, true, false, siirrot);
	anna_raakasiirrot_suunnassa(rivi, linja, 0,-1, pelaaja, 7, true, false, siirrot);
	anna_raakasiirrot_suunnassa(rivi, linja, 0, 1, pelaaja, 7, true, false, siirrot);
}


void Asema::anna_raakasiirrot_suunnassa(int rivi, int linja, int rivi_muutos, int linja_muutos, 
	int pelaaja, int max_askeleet, bool voi_lyoda, bool pakko_lyoda, std::vector<Siirto>& siirrot) const
{
	int rivi_nyt = rivi;
	int linja_nyt = linja;
	int askeleet = 0;
	while (askeleet < max_askeleet)
	{
		rivi_nyt += rivi_muutos;
		linja_nyt += linja_muutos;

		// Ulkona laudalta?
		if (rivi_nyt < 0 || rivi_nyt > 7 || linja_nyt < 0 || linja_nyt > 7)
			break;

		// Tyhj� ruutu?
		if (_lauta[rivi_nyt][linja_nyt] == NA)
		{
			if (pakko_lyoda)
				break;
			siirrot.push_back(Siirto(rivi, linja, rivi_nyt, linja_nyt));
			askeleet++;
			continue;
		}

		// T�rm�t��n omaan nappulaan?
		if (nappulan_vari(_lauta[rivi_nyt][linja_nyt]) == pelaaja)
			break;

		// Ly�d��n vastustajan nappula.
		if (voi_lyoda)
			siirrot.push_back(Siirto(rivi, linja, rivi_nyt, linja_nyt));
		break;
	}



}



void Asema::tulosta() const
{
	const string nappulat[] = 
		{ "R", "N", "B", "Q", "K", "P", "r", "n", "b", "q", "k", "p", " " };

	for (int rivi = 0; rivi < 8; ++rivi)
	{
		string rivi_mj;
		for (int linja = 0; linja < 8; ++linja)
		{
			rivi_mj += (" | " + nappulat[_lauta[rivi][linja]]);
		}
		cout << "     +---+---+---+---+---+---+---+---+\n";
		cout << to_string(8 - rivi) + "   " + rivi_mj + " |\n";

	}

	//soosoosoososo
	cout << "     +---+---+---+---+---+---+---+---+\n";
	cout << "\n       A   B   C   D   E   F   G   H\n";
}

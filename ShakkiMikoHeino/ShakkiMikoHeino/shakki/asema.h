#pragma once
#include <vector>
#include "shakki.h"
#include "siirto.h"


class Asema
{
public:

	// Tyhjent�� laudan.
	void tyhjenna();

	// Tekee annetun siirron laudalla. Voidaan olettaa, ett�
	// siirto on laillinen.
	void tee_siirto(const Siirto& s);

	// Tulostaa lauta ascii-grafiikkana.
	void tulosta() const;

	// Antaa aseman kaikki raakasiirrot
	void anna_kaikki_raakasiirrot(int pelaaja, std::vector<Siirto>& siirrot) const;

	// Antaa tornin raakasiirrot (shakeista ei v�litet�).
	void anna_tornin_raakasiirrot(int rivi, int linja, int pelaaja,
		std::vector<Siirto>& siirrot) const;
	void anna_lahetin_raakasiirrot(int rivi, int linja, int pelaaja,
		std::vector<Siirto>& siirrot) const { /* TODO */ }
	void anna_daamin_raakasiirrot(int rivi, int linja, int pelaaja,
		std::vector<Siirto>& siirrot) const { /* TODO */ }
	void anna_ratsun_raakasiirrot(int rivi, int linja, int pelaaja,
		std::vector<Siirto>& siirrot) const { /* TODO */ }
	void anna_kuninkaan_raakasiirrot(int rivi, int linja, int pelaaja,
		std::vector<Siirto>& siirrot) const { /* TODO */ }
	void anna_sotilaan_raakasiirrot(int rivi, int linja, int pelaaja,
		std::vector<Siirto>& siirrot) const { /* TODO */ }


	/// Anna nappulan mahdolliset raakasiirrot tiettyyn suuntaan.
	///
	/// \param rivi			nappulan l�ht�rivi
	/// \param linja		nappulan l�ht�linja
	/// \param rivi_muutos	rivien koordinaattimuutos (esim. -1 on "yl�s")
	/// \param linja_muutos	linjojen koordinaattimuutos (esim. 1 on "oikea")
	/// \param pelaaja		nappulan v�ri (VALKEA, MUSTA)
	/// \param max_askeleet	maksimiaskeleet ko. suuntaan
	/// \param voi_lyoda	voiko nappula ly�d� ko. suuntaan?
	/// \param pakko_lyoda	onko nappulan pakko ly�d� liikkuessaan ko. suuntaan?
	/// \param siirrot		siirtovektori joka t�ytet��n mahdollisilla raakasiirroilla
	///
	void anna_raakasiirrot_suunnassa(int rivi, int linja, int rivi_muutos, int linja_muutos, 
		int pelaaja, int max_askeleet, bool voi_lyoda, bool pakko_lyoda, 
		std::vector<Siirto>& siirrot) const;

	// Laudan nappulat. Indeksointi [rivi][linja], esim.
	//
	// [0][0] : vasen yl�nurkka ("a8")
	// [7][0] : vasen alanurkka ("a1")
	// [7][7] : oikea alanurkka ("h1")
	//
	int _lauta[8][8] = {
		{ bR, bN, bB, bQ, bK, bB, bN, bR },
		{ bP, bP, bP, bP, bP, bP, bP, bP },
		{ NA, NA, NA, NA, NA, NA, NA, NA },
		{ NA, NA, NA, NA, NA, NA, NA, NA },
		{ NA, NA, NA, NA, NA, NA, NA, NA },
		{ NA, NA, NA, NA, NA, NA, NA, NA },
		{ wP, wP, wP, wP, wP, wP, wP, wP },
		{ wR, wN, wB, wQ, wK, wB, wN, wR }
	};

	int _siirtovuoro = VALKEA;
};


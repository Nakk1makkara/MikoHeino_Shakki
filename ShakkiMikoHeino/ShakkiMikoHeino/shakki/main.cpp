#include <iostream>
#include <string>
#include <vector>
#include "asema.h"
#include "siirto.h"
using namespace std;

int main()
{
	// Alkuasema.
	Asema asema;

	vector<Siirto> siirrot;
	asema.anna_kaikki_raakasiirrot(asema._siirtovuoro, siirrot);

	while (siirrot.size() > 0)
	{
		asema.tulosta();

		// TODO 1
		// tulosta mahdolliset siirrot muodossa
		// e2e4
		// e2e3
		// g1f3
		// jne.

		// TODO 2
		// tulosta laillisten siirtojen lukumäärä, esim.
		// 20

		// TODO 3
		// kysy pelaajan siirto tyyliin "e2e4" (huom! jos siirto on korotus, niin esim. "a7a8Q").
		// Luo vastaava Siirto-olio (siirto)
		// Älä hyväksy pelaajan siirtoa, ellei sitä löydy siirrot-vektorista!

		// Tehdään siirto laudalla
		// asema.tee_siirto(siirto);
	
		siirrot.clear();
		asema.anna_kaikki_raakasiirrot(asema._siirtovuoro, siirrot);
	}

	return 0;
}

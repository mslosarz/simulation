#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <root/TCanvas.h>
#include <root/TGraph2D.h>
#include <root/TRandom.h>

using namespace std;

int w1() {

	TCanvas *c = new TCanvas("c1", "", 0, 0, 700, 600);
	TGraph2D *dt = new TGraph2D();

	ifstream in("/opt/workspace-cpp/simulation/result_rand3.csv");

	string buff;

	getline(in, buff);

	int meanResidenceTime;
	int products;
	float lastProductPrice;
	float shopIncome;

	int n = 0;
	while (getline(in, buff)) {
			for (unsigned int i = 0; i < buff.size(); i++) {
				if (buff[i] == ';') {
					buff[i] = ' ';
				}
			}
			stringstream ss(buff);
			ss >> meanResidenceTime;
			ss >> products;
			ss >> lastProductPrice;
			ss >> shopIncome;
			dt->SetPoint(n, products, meanResidenceTime, shopIncome);
			n++;
	}
	gStyle->SetPalette(1);
	dt->SetTitle("Zaleznosc zysku od liczby produktow oraz czasu przebywania w sklepie");
	dt->GetXaxis()->SetTitle("Liczba produktow");
	dt->GetYaxis()->SetTitle("Sredni czas przebywania w sklepie");
	dt->GetZaxis()->SetTitle("Dochod");
	dt->Draw("surf1");
}

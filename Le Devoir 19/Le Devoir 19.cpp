#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
template<typename Z>
void ritiro(Z bloc[], const int eterno, Z inizio=0) {
	std::cout << "[ ";
	for (int i = inizio; i < eterno; i++) {		
		std::cout << bloc[i] << ", ";
	}
	std::cout << "\b\b]\n\n";
}
template<typename Z>
void rit(Z bloc[], const int eterno, Z inizio = 0) {
	std::sort(bloc + inizio + 1, bloc + eterno);
}
template<typename R>
void riemp(R bloc[], const int eterno,  R sinistro = -70,R destro = 70) {
	if (sinistro > destro)
		std::swap(sinistro, destro);
	srand(time(NULL));
	for (int i = 0; i < eterno; i++)
		bloc[i] = rand() % (destro - sinistro) + sinistro;
}
int NOD(int a, int b) {
	if (b == 0) 
		return a;
	return NOD(b, a % b);
}
int mirror_number(int num){
	int n = 0;
	while (num){
		n = 10 * n + num % 10;
		num /= 10;
	}
	return n;
}
template<typename T>
int cercare_indice(T bloc[], const int eterno, T valore) {
	for (int i = 0; i < eterno; i++)
		if (bloc[i] == valore)
			return i;
	return -1;
}
void prost(int bloc[], const int eterno, int sin, int des) {
	riemp(bloc, eterno, sin, des);
	ritiro(bloc, eterno);
}
int main() {
	setlocale(LC_ALL, "Russian");
	// ������ 1.
	int cis1, cis2;
	std::cout << "������ 1.\n������� ��� ����� : ";
	std::cin >> cis1 >> cis2;
	std::cout <<"���������� ����� �������� : "<< NOD(cis1, cis2)<<"\n\n";
	// ������ 2.
	int numero;
	std::cout << "������ 2.\n������� ����� : ";
	std::cin >> numero;
	std::cout << "\n��������� ����� " << mirror_number(numero) << "\n\n";
	// ������ 3.
	std::cout << "������ 3. \n��������� ������ : \n";
	int const ventuno = 21;
	int mas[ventuno];
	riemp(mas, ventuno);
	ritiro(mas, ventuno);
	int cif, indice;
	std::cout << "\n������� ����� �� ������� : ";
	std::cin >> cif;
	indice = cercare_indice(mas, ventuno,cif);
	if (indice != -1) {
		std::cout << "\n������: " << indice << "\n\n";
		std::cout << "�������� ������ : \n" ;
		rit(mas,ventuno,indice);
		ritiro(mas, ventuno, indice);
	}
	else
		std::cout << "\n����� ��� � �������.\n\n";
	// ������ 4. 
	std::cout << "\n������ 4.\n";
	const int dix=10;
	int ter[dix];
	int n1, n2;
	std::cout << "������� �������� : ";
	std::cin >> n1 >> n2;
	prost(ter, dix, n1, n2);

	return 0;
}
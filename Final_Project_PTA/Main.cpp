#include <stdio.h>
#include <string>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

typedef struct {
	char is;
	int cod;
	char brand[20];
	int memorie_cache;
	float pret;
	typedef struct {
		int an;
		int luna;
		int zi;
	}data_fabricatie;
	data_fabricatie d;
	int numar_nuclee;
	char cooler;
	int frecventa;
}cpu;

int nrart(FILE* f, int l) {
	int n, m, p;
	p = ftell(f);
	fseek(f, 0, 2);
	m = ftell(f);
	n = m / l;
	return n;
}

void creare() {
	FILE* f;
	int i, nr, n;
	cpu c;
	char nume[20];
	printf("Introduceti numele fisierului pe care doriti sa il creati: ");
	gets_s(nume);
	f = fopen(nume, "wb+");
	nr = sizeof(cpu);
	printf("\nIntroduceti codul procesorului: "); scanf_s("%d", &n);
	while (!feof(stdin)) {
		if (n > nrart(f, sizeof(cpu))) {
			fseek(f, 0, 2);
			c.is = 0;
			for (i = nrart(f, sizeof(cpu)); i < n; i++) {
				fwrite(&c, sizeof(cpu), 1, f);
			}
			fseek(f, (n - 1) * sizeof(cpu), 0);
			c.is = 1;
			c.cod = n;
			printf("\nCaracteristici generale procesor");
			printf("\nIntroduceti brandul procesorului: "); getc(stdin); gets_s(c.brand);
			printf("\nMemorie cache: "); scanf_s("%d", &c.memorie_cache);
			printf("\nPret: "); scanf_s("%f7.2", &c.pret);
			printf("\nAnul fabricatiei: "); scanf_s("%d", &c.d.an);
			printf("\nLuna fabricatiei: "); scanf_s("%d", &c.d.luna);
			printf("\nZiua fabricatiei: "); scanf_s("%d", &c.d.zi);
			printf("\nData fabricatiei: %d/%d/%d", c.d.zi, c.d.luna, c.d.an);
			printf("\nNumar nuclee: "); scanf_s("%d", &c.numar_nuclee);
			printf("\nCooler(Y/N): "); getc(stdin);  scanf_s("%c", &c.cooler);
			printf("\nFrecventa: "); scanf_s("%d", &c.frecventa);
			fwrite(&c, sizeof(c), 1, f);
		}
		else {
			fseek(f, (n - 1) * sizeof(cpu), 0);
			fread(&c, sizeof(cpu), 1, f);
			if (c.is == 0) {
				c.is = 1;
				c.cod = n;
				printf("\nCaracteristici generale procesor");
				printf("\nIntroduceti brandul procesorului: "); getc(stdin); gets_s(c.brand);
				printf("\nMemorie cache: "); scanf_s("%d", &c.memorie_cache);
				printf("\nPret: "); scanf_s("%f7.2", &c.pret);
				printf("\nAnul fabricatiei: "); scanf_s("%d", &c.d.an);
				printf("\nLuna fabricatiei: "); scanf_s("%d", &c.d.luna);
				printf("\nZiua fabricatiei: "); scanf_s("%d", &c.d.zi);
				printf("\nData fabricatiei: %d/%d/%d", c.d.zi, c.d.luna, c.d.an);
				printf("\nNumar nuclee: "); scanf_s("%d", &c.numar_nuclee);
				printf("\nCooler(Da/Nu): "); getc(stdin); scanf_s("%c", &c.cooler);
				printf("\nFrecventa: "); scanf_s("%d", &c.frecventa);
				fseek(f, (n - 1) * sizeof(cpu), 0);
				fwrite(&c, sizeof(c), 1, f);
			}
			else {
				printf("\nInregistrarea nu exista.");
			}
		}
		printf("\nIntroduceti codul procesorului: "); scanf_s("%d", &n);
	}
	fclose(f);
}

void adaugare() {
	FILE* f;
	int i, nr, n;
	cpu c;
	char nume[20];
	printf("Introduceti numele fisierului la care doriti sa adaugati articole: ");
	gets_s(nume);
	f = fopen(nume, "rb+");
	nr = sizeof(cpu);
	if (f == NULL) {
		f = fopen(nume, "wb+");
	}
	printf("\nIntroduceti codul procesorului: "); scanf_s("%d", &n);
	while (!feof(stdin)) {
		if (n > nrart(f, sizeof(cpu))) {
			fseek(f, 0, 2);
			c.is = 0;
			for (i = nrart(f, sizeof(cpu)); i < n; i++) {
				fwrite(&c, sizeof(cpu), 1, f);
			}
			fseek(f, (n - 1) * sizeof(cpu), 0);
			c.is = 1;
			c.cod = n;
			printf("\nCaracteristici generale procesor ");
			printf("\nIntroduceti brandul procesorului: "); getc(stdin); gets_s(c.brand);
			printf("\nMemorie cache: "); scanf_s("%d", &c.memorie_cache);
			printf("\nPret: "); scanf_s("%f7.2", &c.pret);
			printf("\nAnul fabricatiei: "); scanf_s("%d", &c.d.an);
			printf("\nLuna fabricatiei: "); scanf_s("%d", &c.d.luna);
			printf("\nZiua fabricatiei: "); scanf_s("%d", &c.d.zi);
			printf("\nData fabricatiei: %d/%d/%d", c.d.zi, c.d.luna, c.d.an);
			printf("\nNumar nuclee: "); scanf_s("%d", &c.numar_nuclee);
			printf("\nCooler(Y/N): "); getc(stdin);  scanf_s("%c", &c.cooler);
			printf("\nFrecventa: "); scanf_s("%d", &c.frecventa);
			fwrite(&c, sizeof(c), 1, f);
		}
		else {
			fseek(f, (n - 1) * sizeof(cpu), 0);
			fread(&c, sizeof(cpu), 1, f);
			if (c.is == 0) {
				c.is = 1;
				c.cod = n;
				printf("\nCaracteristici generale procesor");
				printf("\nIntroduceti brandul procesorului: "); getc(stdin); gets_s(c.brand);
				printf("\nMemorie cache: "); scanf_s("%d", &c.memorie_cache);
				printf("\nPret: "); scanf_s("%f7.2", &c.pret);
				printf("\nAnul fabricatiei: "); scanf_s("%d", &c.d.an);
				printf("\nLuna fabricatiei: "); scanf_s("%d", &c.d.luna);
				printf("\nZiua fabricatiei: "); scanf_s("%d", &c.d.zi);
				printf("\nData fabricatiei: %d/%d/%d", c.d.zi, c.d.luna, c.d.an);
				printf("\nNumar nuclee: "); scanf_s("%d", &c.numar_nuclee);
				printf("\nCooler(Y/N): "); getc(stdin);  scanf_s("%c", &c.cooler);
				printf("\nFrecventa: "); scanf_s("%d", &c.frecventa);
				fseek(f, (n - 1) * sizeof(cpu), 0);
				fwrite(&c, sizeof(c), 1, f);
			}
			else {
				printf("\nInregistrarea exista.");
			}
		}
		printf("\nIntroduceti codul procesorului: "); scanf_s("%d", &n);
	}
	fclose(f);
}

enum Specificatii { brand, memorie_cache, pret, data_fabricatie, numar_nuclee, cooler, frecventa };

Specificatii convert(const std::string& str) {
	if (str == "brand") return brand;
	else if (str == "memorie cache") return memorie_cache;
	else if (str == "pret") return pret;
	else if (str == "data fabricatie") return data_fabricatie;
	else if (str == "numar nuclee") return  numar_nuclee;
	else if (str == "cooler") return cooler;
	else if (str == "frecventa") return frecventa;
}

void modificare() {
	FILE* f;
	int i, n;
	cpu c;
	char nume[20];
	std::string spec;
	printf("Introduceti numele fisierului pe care doriti sa il modificati: ");
	gets_s(nume);
	if (!(f = fopen(nume, "rb+"))) {
		printf("\nFisierul nu exista");
	}
	else {
		printf("\nIntroduceti pozitia articolului pe care doriti sa il modificati: "); scanf_s("%d", &n);
		while (!feof(stdin)) {
			if (n > nrart(f, sizeof(c))) printf("Depaseste marimea fisierului.");
			else {
				fseek(f, (n - 1) * sizeof(c), 0);
				fread(&c, sizeof(c), 1, f);
				if (c.is == 1) {
					printf("\n%-20s || %5d || %5.2f || %5d/%5d/%5d || %5d || %c || %5d\n", c.brand, c.memorie_cache, c.pret, c.d.an, c.d.luna, c.d.zi, c.numar_nuclee, c.cooler, c.frecventa);
					printf("\nIntroduceti articolul pe care doriti sa il modificati(brand, memorie cache, pret, data fabricatie, numar nuclee, cooler, frecventa): ");
					std::cin >> spec;
					Specificatii s = convert(spec);
					switch (s) {
					case brand: {
						char brand2[20];
						printf("\nIntroduceti noul brand: "); std::cin >> brand2;
						strcpy(c.brand, brand2);
					}
							  break;
					case memorie_cache: {
						int memorie_cache2;
						printf("\nIntroduceti noua memorie cache: "); std::cin >> memorie_cache2;
						c.memorie_cache = memorie_cache2;
					}
									  break;
					case pret: {
						float pret2;
						printf("\nIntroduceti noul pret: "); std::cin >> pret2;
						c.pret = pret2;
					}
							 break;
					case data_fabricatie: {
						int an2, luna2, zi2;
						printf("\nIntroduceti noul an: "); std::cin >> an2;
						printf("\nIntroduceti noua luna: "); std::cin >> luna2;
						printf("\nIntroduceti noua zi: "); std::cin >> zi2;
						c.d.an = an2;
						c.d.luna = luna2;
						c.d.zi = zi2;
					}
										break;
					case numar_nuclee: {
						int numar_nuclee2;
						printf("\nIntroduceti noul numar de nuclee: "); std::cin >> numar_nuclee2;
						c.numar_nuclee = numar_nuclee2;
					}
									 break;
					case cooler: {
						char cooler2;
						printf("\nIntroduceti noul status la coolerului(Da/Nu): "); std::cin >> cooler2;
						c.cooler = cooler2;
					}
							   break;
					case frecventa: {
						int frecventa2;
						printf("\nIntroduceti noua frecventa: "); std::cin >> frecventa2;
						c.frecventa = frecventa2;
					}
								  break;
					default:
						printf("\nOptiune incorecta.");
					}
					fseek(f, (n - 1) * sizeof(c), 0);
					fwrite(&c, sizeof(c), 1, f);
				}
				else {
					printf("\nInregistrarea nu exista.");
				}
			}
			printf("\nIntroduceti pozitia articolului pe care doriti sa il modificati: "); scanf_s("%d", &n);
		}
		fclose(f);
	}
}

void stergere() {
	FILE* f;
	cpu c;
	int n;
	char nume[20];
	printf("Introduceti numele fisierului: ");
	gets_s(nume);
	if (!(f = fopen(nume, "rb+"))) {
		printf("\nFisierul nu exista");
	}
	else {
		printf("\nIntroduceti pozitia inregistrarii pe care doriti sa o stergeti:");
		scanf_s("%d", &n);
		while (!feof(stdin)) {
			if (n > nrart(f, sizeof(cpu))) {
				printf("\nDepaseste lungimea fisierului");
			}
			else {
				fseek(f, (n - 1) * sizeof(cpu), 0);
				fread(&c, sizeof(cpu), 1, f);
				if (c.is == 1) {
					printf("\n%-20s || %5d || %5.2f || %5d/%5d/%5d || %5d || %c || %5d\n", c.brand, c.memorie_cache, c.pret, c.d.an, c.d.luna, c.d.zi, c.numar_nuclee, c.cooler, c.frecventa);
					c.is = 0;
					fseek(f, (n - 1) * sizeof(cpu), 0);
					fwrite(&c, sizeof(cpu), 1, f);
				}
				else {
					printf("\nInregistrarea nu exista.");
				}
			}
			printf("\nIntroduceti pozitia inregistrarii pe care doriti sa o stergeti:");
			scanf_s("%d", &n);
		}
		fclose(f);
	}
}

void raport() {
	FILE* f, * g;
	cpu c;
	char nume[20];
	printf("Introduceti numele fisierului: ");
	gets_s(nume);
	if (!(f = fopen(nume, "rb+"))) {
		printf("\nFisierul nu exista");
	}
	else {
		g = fopen("lista_cpu.txt", "w");
		fprintf(g, "            Lista Procesoare            \n");
		fprintf(g, "==========================================\n");
		fprintf(g, " Cod || Brand || Memorie Cache || Pret || Data Fabricatie || Numar Nuclee || Cooler || Frecventa \n");
		fprintf(g, "==================================================================================\n");
		fread(&c, sizeof(cpu), 1, f);
		while (!feof(f)) {
			if (c.is == 1)
			{
				fprintf(g, "\n%5d || %-20s || %5d || %-7.2f || %2d/%2d/%4d || %5d || %c || %5d ", c.cod, c.brand, c.memorie_cache, c.pret, c.d.zi, c.d.luna, c.d.an, c.numar_nuclee, c.cooler, c.frecventa);
			}
			fread(&c, sizeof(cpu), 1, f);
		}
		fclose(f);
		fclose(g);
	}
}

void raport_partial_cooler() {
	FILE* f, * g;
	cpu c;
	char nume[20], cooler, nr;
	printf("Introduceti numele fisierului: ");
	gets_s(nume);
	if (!(f = fopen(nume, "rb+"))) {
		printf("\nFisierul nu exista");
	}
	else {
		g = fopen("lista_cooler.txt", "w");
		fprintf(g, "                                        Lista Procesoare                                         \n");
		fprintf(g, "=================================================================================================\n");
		fprintf(g, " Cod || Brand || Memorie Cache || Pret || Data Fabricatie || Numar Nuclee || Cooler || Frecventa \n");
		fprintf(g, "=================================================================================================\n");
		printf("\nCooler(Y/N): "); scanf_s("%c", &cooler);
		while (!feof(stdin)) {
			fprintf(g, "                             Afisarea procesoarelor care au cooler                               \n");
			rewind(f);
			nr = 0;
			fread(&c, sizeof(cpu), 1, f);
			while (!feof(f)) {
				if ((c.is == 1) && (c.cooler == cooler)) {
					fprintf(g, " Cod || Brand || Memorie Cache || Pret || Data Fabricatie || Numar Nuclee || Cooler || Frecventa \n");
					fprintf(g, "\n%5d || %-20s || %5d || %-7.2f || %2d/%2d/%4d || %5d || %c || %5d ", c.cod, c.brand, c.memorie_cache, c.pret, c.d.zi, c.d.luna, c.d.an, c.numar_nuclee, c.cooler, c.frecventa);
					nr = 1;
				}
				fread(&c, sizeof(cpu), 1, f);
			}
		}
		if (nr == 0) {
			printf("\nInregistrarea nu exista.");
			printf("\nCooler(Y/N): "); scanf("%c", cooler);
		}
		fclose(f);
		fclose(g);
	}
}

void raport_partial_nr_nuclee() {
	FILE* f, * g;
	cpu c;
	char nume[20];
	int nr_nuclee, nr;
	printf("Introduceti numele fisierului: ");
	gets_s(nume);
	if (!(f = fopen(nume, "rb+"))) {
		printf("Fisierul nu exista.");
	}
	else {
		g = fopen("lista_nr_nuclee.txt", "w");
		fprintf(g, "                                        Lista numar nuclee                                       \n");
		fprintf(g, "=================================================================================================\n");
		fprintf(g, " Cod || Brand || Memorie Cache || Pret || Data Fabricatie || Numar Nuclee || Cooler || Frecventa \n");
		fprintf(g, "=================================================================================================\n");
		printf("Introduceti numarul de nuclee: "); scanf_s("%d", &nr_nuclee);
		while (!feof(stdin)) {
			fprintf(g, "                             Afisarea procesoarelor care au %d nuclee                               \n", nr_nuclee);
			rewind(f);
			nr = 0;
			fread(&c, sizeof(cpu), 1, f);
			while (!feof(f)) {
				if ((c.is == 1) && (c.numar_nuclee == nr_nuclee)) {
					fprintf(g, " Cod || Brand || Memorie Cache || Pret || Data Fabricatie || Numar Nuclee || Cooler || Frecventa \n");
					fprintf(g, "\n%5d || %-20s || %5d || %-7.2f || %2d/%2d/%4d || %5d || %c || %5d ", c.cod, c.brand, c.memorie_cache, c.pret, c.d.zi, c.d.luna, c.d.an, c.numar_nuclee, c.cooler, c.frecventa);
					nr = 1;
				}
				fread(&c, sizeof(cpu), 1, f);
			}
			printf("Introduceti numarul de nuclee: "); scanf_s("%d", &nr_nuclee);
		}
		fclose(f);
		fclose(g);
	}
}



enum Optiuni { creare_fis, adaugare_fis, modificare_fis, stergere_fis, raport_fis, raport_partial_cooler_fis, raport_partial_nr_nuclee_fis };

Optiuni convert_op(const std::string& str) {
	if (str == "creare") return creare_fis;
	else if (str == "raport") return raport_fis;
	else if (str == "adaugare") return adaugare_fis;
	else if (str == "modificare") return modificare_fis;
	else if (str == "stergere") return stergere_fis;
	else if (str == "raport partial cooler") return raport_partial_cooler_fis;
	else if (str == "raport partial nr nuclee") return raport_partial_nr_nuclee_fis;
}

void main() {
	creare();
	std::string optiune;
	while (!feof(stdin)) {
		printf("Ce operatie doriti sa efectuati asupra fisierului?(adaugare, modificare, stergere, raport partial cooler, raport partial nr nuclee, raport)\n");
		getline(std::cin, optiune);
		Optiuni op = convert_op(optiune);
		switch (op) {
		case adaugare_fis:
			adaugare();
			break;
		case modificare_fis:
			modificare();
			break;
		case stergere_fis:
			stergere();
			break;
		case raport_fis:
			raport();
			break;
		case raport_partial_cooler_fis:
			raport_partial_cooler();
			break;
		case raport_partial_nr_nuclee_fis:
			raport_partial_nr_nuclee();
			break;
		default:
			printf("Operatie incorecta. Alegeti dintre adaugare, modificare, stergere, raport partial cooler, raport partial nr nuclee, raport.");
		}
		printf("Ce operatie doriti sa efectuati asupra fisierului?(adaugare, modificare, stergere, raport partial cooler, raport partial nr nuclee, raport)\n");
		getline(std::cin, optiune);
	}
}

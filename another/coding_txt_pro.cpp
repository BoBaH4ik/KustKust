#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstring>

#define INFO_S1 "����� ����������!\n������ ��������� ��������� ������������ ��� ������������ ���� �������������� ����.\n"
#define INFO_S2 "�������� '1' ���� �� ������ ������������ ����.\n�������� '0' ���� �� ������ ������������ ����.\n�������� ������ ������ ���� �� ������ �����.\n"
#define INFO_O "������� ���� ����������� �����.\n"
#define INFO_O_E "�� ������� ���� ���������� ������� ����.\n������� ���� ������ ��� �������� '0' ���� �� ������ �����.\n"
#define INFO_S_C "������� ���� ���������� ��������������� �����. (�������� '0' ����� ��������� �� ��������� '������� ����')\n"
#define INFO_S_D "������� ���� ���������� ��������������� �����. (�������� '0' ����� ��������� �� ��������� '������� ����')\n"
#define INFO_S_E "�� ������� ���� ���������� ��������� ����.\n������� ���� ������ ��� �������� '0' ���� �� ������ �����.\n"
#define INFO_R "�������������� ���������� �����:\n"
#define DESKTOP_C "C:\\Users\\Lenovo\\Desktop\\overcodefile.txt"
#define DESKTOP_D "C:\\Users\\Lenovo\\Desktop\\decodefile.txt"

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int fsize;
	unsigned char time;
	char* buffer, path_from[512], path_to[512], command;
	FILE* file_from, * file_to;

	cout << INFO_S1 << endl;

	while (true) {

		cout << INFO_S2 << endl;
		cin >> command;

		if (command == '1') {

			time = clock() % 64;

			cout << INFO_O << endl;
			
			while (true) {

				cin >> path_from;
				if (path_from[0] == '0') return 0;
				if (!fopen_s(&file_from, path_from, "r")) break;
				cout << INFO_O_E << endl;
			}

			fseek(file_from, 0, SEEK_END);
			fsize = ftell(file_from);
			rewind(file_from);

			buffer = new char[fsize + 1];

			fread(buffer, fsize, 1, file_from);
			for (int i = 0; i < fsize; i++) buffer[i] = buffer[i] + time;
			buffer[fsize] = '\0';

			fclose(file_from);

			//___________________________________________________________________________

			cout << INFO_S_C << endl;

			while (true) {

				cin >> path_to;
				if (path_to[0] == '0') { if (!fopen_s(&file_to, DESKTOP_C, "w")) break; }
				else if (!fopen_s(&file_to, path_to, "w")) break;
				cout << INFO_S_E << endl;
			}

			fwrite(&time, 1, 1, file_to);
			fwrite(buffer, fsize, 1, file_to);

			fclose(file_to);
			delete[] buffer;

			system("cls");
		}

		//_______________________________________________________________________________

		if (command == '0') {

			cout << INFO_O << endl;

			while (true) {

				cin >> path_from;
				if (path_from[0] == '0') return 0;
				if (!fopen_s(&file_from, path_from, "r")) break;
				cout << INFO_O_E << endl;
			}

			fseek(file_from, 0, SEEK_END);
			fsize = ftell(file_from) - 1;
			rewind(file_from);

			buffer = new char[fsize + 1];

			fread(&time, 1, 1, file_from);
			fread(buffer, fsize, 1, file_from);
			for (int i = 0; i < fsize; i++) buffer[i] = buffer[i] - time;
			buffer[fsize] = '\0';

			fclose(file_from);

			cout << INFO_R << endl << buffer << endl;

			//___________________________________________________________________________

			cout << INFO_S_C << endl;

			while (true) {

				cin >> path_to;
				if (path_to[0] == '0') { if (!fopen_s(&file_to, DESKTOP_D, "w")) break; }
				else if (!fopen_s(&file_to, path_to, "w")) break;
				cout << INFO_S_E << endl;
			}

			fwrite(buffer, fsize, 1, file_to);

			fclose(file_to);
			delete[] buffer;

			system("cls");
		}

		if ((command != '0') && (command != '1')) break;
	}

	return 0;
}
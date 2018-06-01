#include <iostream>
#include <fstream>

#include "file.h"
#include "geometry.h"
#include "search.h"

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	if (argc < 3)
	{
		cout << "Запуск: oioll.exe in.txt out.txt" << endl;
		return -1;
	}
	const char* inFileName = argv[1];
	const char* outFileName = argv[2];

	int num = count(argv[1]);

	if (num < 0) {
		cout << "Входной файл не существует" << endl;
		return -2;
	}

	else if (num<4) {
		cout << "Входной файл слишком мал" << endl;
		return -3;
	}
	point* arr = new point[num];
	if (!rp("in.txt", arr, num)) {
		cout << "Неизвестная ошибка при вводе точек " << endl;
		return -3;

	}

	const int maxnum = 3;
	treug arr1[maxnum];
	searchtr(arr, num, arr1, maxnum);
	if (!writetreug(argv[2], arr1, maxnum)) {
		cout << "Не удалось записать результат" << endl;
		return -4;
	}
	cout << "Программа успешно завершена" << endl;
	delete[] arr;
	return 0;
}

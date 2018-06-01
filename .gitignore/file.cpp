#include <fstream>

#include "file.h"
#include "geometry.h"

using namespace std;

int count(const char* filename) {
	ifstream in(filename);
	if (!in.is_open())
		return -1;
	double x, y;
	int i;
	for (i = 0; ; i++) {
		in >> x >> y;
		if (in.fail())
			break;
	}
	return i;
}

istream& operator >>(istream& in, point& p) {
	in >> p.x >> p.y;
	return in;
}

bool rp(const char* filename, point *arr, int maxpointnum) {
	ifstream in(filename);
	if (!in.is_open())
		return 0;
	for (int i = 0; i<maxpointnum; i++) {
		in >> arr[i];
		if (in.fail())
			return false;
	}
	return true;
}

ostream& operator <<(ostream& out, const point& p) {
	out << "(" << p.x << " " << p.y << ")";
	return out;
}

ostream& operator <<(ostream& out, const treug& tr) {
	out << "A=" << tr.vert[0] << " B=" << tr.vert[1] << " C=" << tr.vert[2] << " perim= " << tr.perim;
	return out;
}

bool writetreug(const char* fileName, const treug* arr1, int trNum) {
	ofstream out(fileName);
	if (!out.is_open())
		return false;
	for (int i = 0; i<trNum; i++)
		out << "#" << i + 1 << ": " << arr1[i] << endl;
	return true;
}

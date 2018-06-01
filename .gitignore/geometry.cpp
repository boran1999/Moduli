#include "geometry.h"
#include <cmath>

double dist(const point a, const point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double geron(double c1, double c2, double c3) {
	double pp = (c1 + c2 + c3) / 2;
	if (pp <= 0.0 || pp <= c1 || pp <= c2 || pp <= c3)
		return 0.0;
	return sqrt(pp*(pp - c1)*(pp - c2)*(pp - c3));
}
double calcAreaByPoints(const point a, const point b, const point c) {
	double ab = dist(a, b);
	double bc = dist(b, c);
	double ca = dist(c, a);
	return geron(ab, bc, ca);
}

//double areaf(treug& tr) {
//	double c1 = dist(tr.vert[0], tr.vert[1]);
//	double c2 = dist(tr.vert[1], tr.vert[2]);
//	double c3 = dist(tr.vert[2], tr.vert[0]);
//	tr.area = geron(c1, c2, c3);
//	return tr.area;
//}
double per(treug& tr) {
	double c1 = dist(tr.vert[0], tr.vert[1]);
	double c2 = dist(tr.vert[1], tr.vert[2]);
	double c3 = dist(tr.vert[2], tr.vert[0]);
	tr.perim = c1 + c2 + c3;
	return tr.perim;
}

#ifndef _geometry_h
#define _geometry_h

struct point {//
	double x, y;
};

struct treug {//
	point vert[3];
	//double area;
	double perim;
};

double dist(const point a, const point b);

//double areaf(treug& tr);

double per(treug& tr);

#endif

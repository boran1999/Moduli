#include <iostream>
#include <fstream>
#include "geometry.h"
#include "search.h"
using namespace std;
void findins(treug* arr1, int length, const treug& tr) {
	int pos;
	for (pos = length - 1; pos >= 0; pos--) {
		if (tr.perim <= arr1[pos].perim) {
			break;
		}
	}
	pos++;
	if (pos == length)
		return;
	for (int m = length - 2; m >= pos; m--) {
		arr1[m + 1] = arr1[m];
		arr1[pos] = tr;
	}
}
void clearp(point& p) {
	p.x = p.y = 0;
}
void cleart(treug& tr) {
	for (int i = 0; i < 3; i++) {
		clearp(tr.vert[i]);
	}
	tr.perim = 0;
}
void searchtr(const point* arr, int pointnum, treug* arr1, int maxtrnum) {
	if (maxtrnum <= 0) {
		return;
	}
	for (int i = 0; i < maxtrnum; i++) {
		cleart(arr1[i]);
	}
	treug tr;
	for (int i = 0; i < pointnum; i++) {
		tr.vert[0] = arr[i];
		for (int j = i + 1; j < pointnum; j++) {
			tr.vert[1] = arr[j];
			for (int k = j + 1; k < pointnum; k++) {
				tr.vert[2] = arr[k];
				per(tr);
				findins(arr1, maxtrnum, tr);
			}
		}

	}

}

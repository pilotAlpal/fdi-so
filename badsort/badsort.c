#include <stdio.h>

typedef struct Item {
   char  data[50];
   int  key;
} item;

item array[] = {
	{"p0k21", 21},
	{"p1k22", 22},
	{"p2k20", 20},
	{"p3k3", 3},
	{"p4k2", 2}
};

void sort(item *a, int n) {
	int i = 0, j = 0;
	int s = 1;
	
	for(; i < n & s != 0; i++) {
		s = 0;
		for(j = 0; j < n; j++) {
			if(a[j].key > a[j+1].key) {
				item t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				s++;
			}
		}
		n--;
	}
}


int main() {
	int i;
	sort(array,5);
	for(i = 0; i < 5; i++)
		printf("array[%d] = {%s, %d}\n",
			i, array[i].data, array[i].key);
	return 0;
}


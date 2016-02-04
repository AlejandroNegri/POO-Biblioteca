#include "Utils.h"

void pasar_a_minusculas(string &s) {
	int i,c=s.size();
	for (i=0;i<c;i++)
		s[i]=tolower(s[i]);
}



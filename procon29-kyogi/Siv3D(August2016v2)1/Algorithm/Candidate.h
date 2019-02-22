#pragma once
#include "../gneral.h"

class Candidate {
public:
	Candidate(int, int, int, Candidate*);
	Candidate();
	string getHash(void) {
		string hash = "";
		hash += to_string(int(this));
		return hash;
	}
	Candidate *before;
	pair<int, int> pos;
	int step;
	int eval;
};

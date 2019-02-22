#include "Candidate.h"

Candidate::Candidate(int x, int y, int s, Candidate* from){
	pos = make_pair(x, y);
	step = s;
	before = from;
}

Candidate::Candidate() {
	before = nullptr;
}

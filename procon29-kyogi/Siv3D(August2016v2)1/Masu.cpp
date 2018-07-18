#include "MapClass/Masu.h"
Masu* Masu::InsMasu = nullptr;

Masu* Masu::getMasu() {
	if (InsMasu == nullptr) {
		InsMasu = new Masu;
	}
	return InsMasu;
}
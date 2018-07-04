#include "Singleton.h"

Singleton::Singleton() {
	Instance = nullptr;
}

void Singleton::create()
{
	if (!Instance) {
		Instance = new Singleton;
	}
}

void Singleton::destroy()
{
	delete Instance;
	Instance = nullptr;
}

#pragma

class Singleton final{
public:
	static Singleton *getInstance() {
		return Instance;
	}

	static void create();
	static void destroy();
private:
	static Singleton *Instance;
	Singleton();
};
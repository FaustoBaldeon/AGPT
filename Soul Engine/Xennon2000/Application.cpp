#include "spch.h"

using namespace Soul;


int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize("Xenon2000", 640, 480);
	engine.Run();
	engine.Clean();

	return 0;
}

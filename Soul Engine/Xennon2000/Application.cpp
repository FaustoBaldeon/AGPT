#include "spch.h"
#include "Level.h"

using namespace Soul;


int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize("Xenon2000", 640, 640);
	Level currentLevel = engine.getLevel();

	engine.Run();
	engine.Clean();

	return 0;
}

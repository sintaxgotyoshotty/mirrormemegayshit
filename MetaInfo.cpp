#include "MetaInfo.h"
#include "Utilities.h"

void PrintMetaHeader()
{
	printf("                                  Ze");
	Utilities::SetConsoleColor(FOREGROUND_CYAN);
	printf("r0\n");
	Utilities::SetConsoleColor(FOREGROUND_WHITE);
	Utilities::Log("Build Date: %s", __DATE__);
}
#include "LoggerTests.h"
#include "../CommonLogger.h"

void test::log::Console() {
	ILogger* logger = new CommonLogger();

	logger->Critical("Critical Message %s, %i", "String values", 23);
	logger->Error("Error Message %s %f", "Another string, with comma", 45.956f);
	logger->Info("Howdy %s", "Partner");
	logger->Warn("Something %f", 42.0f);

	delete logger;
}
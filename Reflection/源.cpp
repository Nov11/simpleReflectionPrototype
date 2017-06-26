#include "POD.h"

int main() {
	POD* ptr = reinterpret_cast<POD*>(Reflection::Factory::getFactory().createInstance("POD"));
}
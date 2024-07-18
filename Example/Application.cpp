#include "Vortex.h"
#include "Vortex/Logging.h"

int main() {
    Vortex::Logger::Init();

    VT_TRACE("Welcome to Vortex");

    return 0;
}

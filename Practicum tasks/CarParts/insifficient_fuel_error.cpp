#include <stdio.h>
#include "insufficinet_fuel_error.h"


insufficient_fuel_error::insufficient_fuel_error() : std::logic_error("Insufficient fuel in the tank!"){}

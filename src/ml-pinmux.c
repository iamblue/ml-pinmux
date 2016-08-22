#include <string.h>
#include "jerry-api.h"
#include "pinmux.h"
#include "microlattice.h"

DELCARE_HANDLER(__pinmux) {
  uint8_t pin = (int) jerry_get_number_value(args_p[0]);

  uint8_t func = (int) jerry_get_number_value(args_p[1]);

  hal_pinmux_set_function(pin, func);

  return jerry_create_boolean (true);
}

void ml_pinmux_init(void) {
  REGISTER_HANDLER(__pinmux);
}
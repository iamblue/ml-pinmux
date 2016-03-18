#include <string.h>
#include "jerry.h"
#include "pinmux.h"
#include "microlattice.h"

DELCARE_HANDLER(pinmux) {
  uint8_t pin = (int)args_p[0].v_float32;
  uint8_t func = (int)args_p[1].v_float32;

  hal_pinmux_set_function(pin, func);

  ret_val_p->type = JERRY_API_DATA_TYPE_BOOLEAN;
  ret_val_p->v_bool = true;
  return true;
}

void ml_pinmux_init(void) {
  REGISTER_HANDLER(pinmux);
}
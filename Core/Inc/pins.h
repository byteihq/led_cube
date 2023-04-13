#ifndef INC_PINS_H_
#define INC_PINS_H_

#include <stdint.h>

typedef uint16_t _pin;

_pin DecToPin(uint16_t dec);

void ResetPin(_pin pin);
void ResetPins(const _pin *const pins, uint32_t len);

void SetPin(_pin pin);
void SetPins(const _pin *const pins, uint32_t len);

#endif /* INC_PINS_H_ */

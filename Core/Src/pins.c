#include "pins.h"

#include "stm32f4xx_hal.h"

_pin DecToPin(uint16_t dec) {
	switch (dec) {
	case 1:
		return GPIO_PIN_1;
	case 2:
		return GPIO_PIN_2;
	case 4:
		return GPIO_PIN_4;
	case 0:
	default:
		return GPIO_PIN_0;
	}
}

void ResetPin(_pin pin) {
	HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_RESET);
}

void ResetPins(const _pin *const pins, uint32_t len) {
	for (uint32_t i = 0; i < len; ++i)
		ResetPin(pins[i]);
}

void SetPin(_pin pin) {
	HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_SET);
}

void SetPins(const _pin *const pins, uint32_t len) {
	for (uint32_t i = 0; i < len; ++i)
		SetPin(pins[i]);
}

#ifndef INC_PIN_H_
#define INC_PIN_H_

#include <stdint.h>
#include <vector>

extern "C"
{
	#include "stm32f4xx_hal.h"
}

class Pin final
{
public:
	typedef uint16_t value_type;

	Pin() = delete;
	constexpr Pin(value_type pin): _pin(pin) {};

	void Set();
	void Reset();
	void Update(bool set);

	constexpr static value_type DecToPin(uint16_t number)
	{
		switch (number)
		{
			case 1:
				return GPIO_PIN_1;
			case 2:
				return GPIO_PIN_2;
			case 0:
			default:
				return GPIO_PIN_0;
		}
	}
	static void ResetPins(std::vector<Pin> &pins);
	static void SetPins(std::vector<Pin> &pins);

	~Pin() = default;

private:
	value_type _pin;
};

constexpr Pin operator "" _p(unsigned long long pin)
{
	return Pin(Pin::DecToPin(pin));
}

#endif /* INC_PIN_H_ */

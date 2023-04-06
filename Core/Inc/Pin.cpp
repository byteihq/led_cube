#include <Pin.h>

void Pin::Set()
{
	HAL_GPIO_WritePin(GPIOA, _pin, GPIO_PIN_SET);
}

void Pin::Reset()
{
	HAL_GPIO_WritePin(GPIOA, _pin, GPIO_PIN_RESET);
}

void Pin::Update(bool set)
{
	set ? Set() : Reset();
}

void Pin::ResetPins(std::vector<Pin> &pins)
{
	for (auto & p : pins)
		p.Reset();
}

void SetPins(std::vector<Pin> &pins)
{
	for (auto & p : pins)
		p.Set();
}

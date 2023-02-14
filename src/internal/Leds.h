#ifndef __DCSBIOS_LEDS_H
#define __DCSBIOS_LEDS_H

#include "ExportStreamListener.h"

namespace DcsBios {

	class LED : public Int16Buffer {
		private:
			unsigned int mask;
			GPIO_TypeDef* gpioPort_;
			uint16_t gpioPin_;
			bool reverse;
		public:
			LED(unsigned int address, unsigned int mask, GPIO_TypeDef* gpioPort, uint16_t gpioPin, bool reverse = false) : Int16Buffer(address), mask(mask), reverse(reverse) {
				
			}
			virtual void loop() {
				if (hasUpdatedData()) {
					bool state = getData() & mask;
					if (reverse) state = !state;
					HAL_GPIO_WritePin(gpioPort_, gpioPin_, (GPIO_PinState)state);
				}
			}
	};

}

#endif
/*! \file usartSingle.h
 \brief This is the core file for device with a single USART.

 Part of the following code is derived from setbaud.h found in avr-libc
 project ditributed under WinAVR20081205.

 The following copyright are included to respect the license of AVR-Libc.

 Copyright (c) 2007  Cliff Lawson
 Copyright (c) 2007  Carlos Lamas
 All rights reserved.

 \author Fr�d�ric Nadeau

 \warning Copyright (c) 2008 Fr�d�ric Nadeau
 All rights reserved.


 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:\n
 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.\n
 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.\n
 3. The name of the author nor the names of its contributors may not
 be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */
#include "avr-drv-errno.h"
#include "usartDef.h"
#include "xtal/xtal.h"

#include <assert.h>

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>

#define USART_RX_ERR_MASK	0x1C //0b0001 1100 //TODO Check these value
#define USART_RX_CHAR_IN	0x80 //0b1000 0000

int usartSingleSetBaudRate(uint32_t baudRate) {
	uint16_t uwBaud = (((OSCCLK) + 8UL * (baudRate)) / (16UL * (baudRate))
			- 1UL);
	_Bool useX2 = false;

	if (100 * (OSCCLK) > (16 * ((uwBaud) + 1)) * (100 * (baudRate) + (baudRate)
			* (2))) {
		uwBaud = (((OSCCLK) + 4UL * (baudRate)) / (8UL * (baudRate)) - 1UL);
		useX2 = true;
	} else if (100 * (OSCCLK) < (16 * ((uwBaud) + 1)) * (100 * (baudRate)
			- (baudRate) * (2))) {
		uwBaud = (((OSCCLK) + 4UL * (baudRate)) / (8UL * (baudRate)) - 1UL);
		useX2 = true;
	}

	if (100 * (OSCCLK) > (16 * ((uwBaud) + 1)) * (100 * (baudRate) + (baudRate)
			* (2))) {
		errno = EBAUDRATE;
		return -1;
	} else if (100 * (OSCCLK) < (16 * ((uwBaud) + 1)) * (100 * (baudRate)
			- (baudRate) * (2))) {
		errno = EBAUDRATE;
		return -1;
	}

	UBRRH = uwBaud >> 8;
	UBRRL = uwBaud;

	if (true == useX2) {
		UCSRC |= _BV(1<<U2X);
	} else {
		UCSRC &= ~(_BV(1<<U2X));
	}

	return 0;
}

int usartSingleSetNumBit(USART_NumBits_t numBit) {
	uint8_t ubBit;
	switch (numBit) {
	case USART_NumBits_5:
		ubBit = 0x00;
		break;
	case USART_NumBits_6:
		ubBit = 0x01;
		break;
	case USART_NumBits_7:
		ubBit = 0x02;
		break;
	case USART_NumBits_8:
		ubBit = 0x03;
		break;
	case USART_NumBits_9:
		ubBit = 0x07;
		break;
	default:
		errno = EINVAL;
		return -1;
		break;
	}
	UCSRC &= ~(_BV(UCSZ0) | _BV(UCSZ1) | _BV(UCSZ1));
	UCSRC |= (ubBit << UCSZ0);

	return 0;
}

int usartSingleSetParity(USART_Parity_t partity) {
	uint8_t ubParity;
	switch (partity) {
	case USART_Parity_None:
		ubParity = 0;
		break;
	case USART_Parity_Even:
		ubParity = 2;
		break;
	case USART_Parity_Odd:
		ubParity = 3;
		break;
	default:
		errno = EINVAL;
		return -1;
		break;
	}
	UCSRC &= ~(_BV(UPM0) | _BV(UPM1));
	UCSRC = (ubParity << UPM0);

	return 0;
}

int usartSingleSetStopBit(USART_StopBit_t stopBit) {
	switch (stopBit) {
	case USART_StopBit_1:
		UCSRC &= ~(_BV(USBS));
		break;
	case USART_StopBit_2:
		UCSRC |= _BV(USBS);
		break;
	default:
		errno = EINVAL;
		return -1;
		break;
	}

	return 0;
}

int usartSingleSetMode(USART_Mode_t mode) {
	//TODO handle mode, Async, Sync, etc.
	return 0;
}

int usartSingleEnableRx(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(RXEN);
	} else {
		UCSRB &= ~_BV(RXEN);
	}

	return 0;
}

int usartSingleEnableTx(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(TXEN);
	} else {
		UCSRB &= ~_BV(TXEN);
	}

	return 0;
}

int usartSinglePutc(char data) {
	if (false != (UCSRB & (1 << TXEN))) {
		while (!(UCSRA & (1 << UDRE)))
			;
		UDR = data;
		return 0;
	} else {
		errno = ETXDISABLED;
		return -1;
	}
}

int usartSingleGetc(char* data) {
	int wRetVal = 0;
	uint8_t ubStatus = UCSRB;

	if ((ubStatus & (1 << RXEN)) == 0) {
		errno = ERXDISABLED;
		wRetVal = -1;
	} else {
		ubStatus = UCSRA;

		if ((ubStatus & USART_RX_CHAR_IN) != 0) {
			if ((ubStatus & USART_RX_ERR_MASK) != 0) {
				switch (ubStatus) {
				case 0x04:
					errno = ERXPARITY;
					wRetVal = -1;//USART_ERR_PARITY;
					break;
				case 0x08:
					errno = ERXOVERRUN;
					wRetVal = -1;//USART_ERR_OVERRUN;
					break;
				case 0x10:
					errno = ERXFRAM;
					wRetVal = -1;//USART_ERR_FRAME;
					break;
				default:
					errno = ERXMULTI;
					wRetVal = -1;//USART_ERR_RX_MULTI;
					break;
				}
			} else {
			}
			*data = UDR;
		} else {
			wRetVal = -1;//USART_ERR_RX_EMPTY;
		}
	}
	return wRetVal;
}

_Bool usartSingleIsTx(void) {
	if ((UCSRA & (1 << UDRE))) {
		return false;
	} else {
		return true;
	}
}

int usartSingleEnableRxInt(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(RXCIE);
	} else {
		UCSRB &= ~_BV(RXCIE);
	}

	return 0;
}

int usartSingleEnableTxBufInt(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(UDRIE);
	} else {
		UCSRB &= ~_BV(UDRIE);
	}

	return 0;
}

int usartSingleEnableTxCmpInt(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(TXCIE);
	} else {
		UCSRB &= ~_BV(TXCIE);
	}

	return 0;
}

int usartSinglePutcISR(char data) {
	UDR = data;

	return 0;
}

int usartSingleGetcISR(char *data) {
	int wRetVal = 0;
	uint8_t ubStatus = 0x00;

	ubStatus = UCSRA;
	*data = UDR;

	if ((ubStatus & USART_RX_ERR_MASK) != 0) {
		switch (ubStatus) {
		case 0x04:
			errno = ERXPARITY;
			wRetVal = -1;//USART_ERR_PARITY;
			break;
		case 0x08:
			errno = ERXOVERRUN;
			wRetVal = -1;//USART_ERR_OVERRUN;
			break;
		case 0x10:
			errno = ERXFRAM;
			wRetVal = -1;//USART_ERR_FRAME;
			break;
		default:
			errno = ERXMULTI;
			wRetVal = -1;//USART_ERR_RX_MULTI;
			break;
		}
	} else {
	}

	return wRetVal;
}

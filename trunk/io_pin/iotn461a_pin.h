/* Copyright (c) 2010 Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/* avr/../io_pin/iotn461a_pin.h - definitions for ATtiny461A */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn461a_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATTINY461A_H_
#define _AVR_PIN_ATTINY461A_H_ 1


/* Device Pin Definitions */
#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   0

#define DI_B_DDR   DDRB
#define DI_B_PORT  PORTB
#define DI_B_PIN   PINB
#define DI_B_BIT   0

#define SDA_B_DDR   DDRB
#define SDA_B_PORT  PORTB
#define SDA_B_PIN   PINB
#define SDA_B_BIT   0

#define _OC1A_DDR   DDRB
#define _OC1A_PORT  PORTB
#define _OC1A_PIN   PINB
#define _OC1A_BIT   0

#define PCINT8_DDR   DDRB
#define PCINT8_PORT  PORTB
#define PCINT8_PIN   PINB
#define PCINT8_BIT   0

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   1

#define DO_B_DDR   DDRB
#define DO_B_PORT  PORTB
#define DO_B_PIN   PINB
#define DO_B_BIT   1

#define OC1A_DDR   DDRB
#define OC1A_PORT  PORTB
#define OC1A_PIN   PINB
#define OC1A_BIT   1

#define PCINT9_DDR   DDRB
#define PCINT9_PORT  PORTB
#define PCINT9_PIN   PINB
#define PCINT9_BIT   1

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   2

#define USCK_B_DDR   DDRB
#define USCK_B_PORT  PORTB
#define USCK_B_PIN   PINB
#define USCK_B_BIT   2

#define SCL_B_DDR   DDRB
#define SCL_B_PORT  PORTB
#define SCL_B_PIN   PINB
#define SCL_B_BIT   2

#define INV_OC1B_DDR   DDRB
#define INV_OC1B_PORT  PORTB
#define INV_OC1B_PIN   PINB
#define INV_OC1B_BIT   2

#define PCINT10_DDR   DDRB
#define PCINT10_PORT  PORTB
#define PCINT10_PIN   PINB
#define PCINT10_BIT   2

#define OC1B_DDR   DDRB
#define OC1B_PORT  PORTB
#define OC1B_PIN   PINB
#define OC1B_BIT   3

#define PCINT11_DDR   DDRB
#define PCINT11_PORT  PORTB
#define PCINT11_PIN   PINB
#define PCINT11_BIT   3

#define ADC7_DDR   DDRB
#define ADC7_PORT  PORTB
#define ADC7_PIN   PINB
#define ADC7_BIT   4

#define PCINT12_DDR   DDRB
#define PCINT12_PORT  PORTB
#define PCINT12_PIN   PINB
#define PCINT12_BIT   4

#define _OC1D_DDR   DDRB
#define _OC1D_PORT  PORTB
#define _OC1D_PIN   PINB
#define _OC1D_BIT   4

#define CLKI_DDR   DDRB
#define CLKI_PORT  PORTB
#define CLKI_PIN   PINB
#define CLKI_BIT   4

#define ADC8_DDR   DDRB
#define ADC8_PORT  PORTB
#define ADC8_PIN   PINB
#define ADC8_BIT   5

#define PCINT13_DDR   DDRB
#define PCINT13_PORT  PORTB
#define PCINT13_PIN   PINB
#define PCINT13_BIT   5

#define OC1D_DDR   DDRB
#define OC1D_PORT  PORTB
#define OC1D_PIN   PINB
#define OC1D_BIT   5

#define CKLO_DDR   DDRB
#define CKLO_PORT  PORTB
#define CKLO_PIN   PINB
#define CKLO_BIT   5

#define ADC9_DDR   DDRB
#define ADC9_PORT  PORTB
#define ADC9_PIN   PINB
#define ADC9_BIT   6

#define INT0_DDR   DDRB
#define INT0_PORT  PORTB
#define INT0_PIN   PINB
#define INT0_BIT   6

#define T0_DDR   DDRB
#define T0_PORT  PORTB
#define T0_PIN   PINB
#define T0_BIT   6

#define PCINT14_DDR   DDRB
#define PCINT14_PORT  PORTB
#define PCINT14_PIN   PINB
#define PCINT14_BIT   6

#define ADC10_DDR   DDRB
#define ADC10_PORT  PORTB
#define ADC10_PIN   PINB
#define ADC10_BIT   7

#define PCINT15_DDR   DDRB
#define PCINT15_PORT  PORTB
#define PCINT15_PIN   PINB
#define PCINT15_BIT   7

#define ADC6_DDR   DDRA
#define ADC6_PORT  PORTA
#define ADC6_PIN   PINA
#define ADC6_BIT   7

#define AIN1_DDR   DDRA
#define AIN1_PORT  PORTA
#define AIN1_PIN   PINA
#define AIN1_BIT   7

#define PCINT7_DDR   DDRA
#define PCINT7_PORT  PORTA
#define PCINT7_PIN   PINA
#define PCINT7_BIT   7

#define ADC5_DDR   DDRA
#define ADC5_PORT  PORTA
#define ADC5_PIN   PINA
#define ADC5_BIT   6

#define AIN0_DDR   DDRA
#define AIN0_PORT  PORTA
#define AIN0_PIN   PINA
#define AIN0_BIT   6

#define PCINT6_DDR   DDRA
#define PCINT6_PORT  PORTA
#define PCINT6_PIN   PINA
#define PCINT6_BIT   6

#define ADC4_DDR   DDRA
#define ADC4_PORT  PORTA
#define ADC4_PIN   PINA
#define ADC4_BIT   5

#define AIN2_DDR   DDRA
#define AIN2_PORT  PORTA
#define AIN2_PIN   PINA
#define AIN2_BIT   5

#define PCINT5_DDR   DDRA
#define PCINT5_PORT  PORTA
#define PCINT5_PIN   PINA
#define PCINT5_BIT   5

#define ADC3_DDR   DDRA
#define ADC3_PORT  PORTA
#define ADC3_PIN   PINA
#define ADC3_BIT   4

#define ICP0_DDR   DDRA
#define ICP0_PORT  PORTA
#define ICP0_PIN   PINA
#define ICP0_BIT   4

#define PCINT4_DDR   DDRA
#define PCINT4_PORT  PORTA
#define PCINT4_PIN   PINA
#define PCINT4_BIT   4

#define PCINT3_DDR   DDRA
#define PCINT3_PORT  PORTA
#define PCINT3_PIN   PINA
#define PCINT3_BIT   3

#define ADC2_DDR   DDRA
#define ADC2_PORT  PORTA
#define ADC2_PIN   PINA
#define ADC2_BIT   2

#define INT1_DDR   DDRA
#define INT1_PORT  PORTA
#define INT1_PIN   PINA
#define INT1_BIT   2

#define USCK_A_DDR   DDRA
#define USCK_A_PORT  PORTA
#define USCK_A_PIN   PINA
#define USCK_A_BIT   2

#define SCL_A_DDR   DDRA
#define SCL_A_PORT  PORTA
#define SCL_A_PIN   PINA
#define SCL_A_BIT   2

#define PCINT2_DDR   DDRA
#define PCINT2_PORT  PORTA
#define PCINT2_PIN   PINA
#define PCINT2_BIT   2

#define ADC1_DDR   DDRA
#define ADC1_PORT  PORTA
#define ADC1_PIN   PINA
#define ADC1_BIT   1

#define DO_A_DDR   DDRA
#define DO_A_PORT  PORTA
#define DO_A_PIN   PINA
#define DO_A_BIT   1

#define PCINT1_DDR   DDRA
#define PCINT1_PORT  PORTA
#define PCINT1_PIN   PINA
#define PCINT1_BIT   1

#define ADC0_DDR   DDRA
#define ADC0_PORT  PORTA
#define ADC0_PIN   PINA
#define ADC0_BIT   0

#define DI_A_DDR   DDRA
#define DI_A_PORT  PORTA
#define DI_A_PIN   PINA
#define DI_A_BIT   0

#define SDA_A_DDR   DDRA
#define SDA_A_PORT  PORTA
#define SDA_A_PIN   PINA
#define SDA_A_BIT   0

#define PCINT0_DDR   DDRA
#define PCINT0_PORT  PORTA
#define PCINT0_PIN   PINA
#define PCINT0_BIT   0

#endif /* _AVR_PIN_ATTINY461A_H_ */


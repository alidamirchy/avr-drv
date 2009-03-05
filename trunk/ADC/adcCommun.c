/*! \file adcCommun.c
 \brief This file contains common code for ADC.

 This file contains common function for all supported ADC.
 This file may eventually get modified as more AVR device get supported.

 Currently only use the following register:
 \li \c ADMUX
 \li \c ADCSRA
 \li \c ADCW
 \li \c ADCH
 \li \c ADCL

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

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>

void adcEnable(_Bool status)
{
	ADCSRA &= ~_BV(ADEN);
	if(status != false)
	{
		ADCSRA |= _BV(ADEN);
	}
}

void adcInterruptEnable(_Bool intEn)
{
	ADCSRA &= ~_BV(ADIE);
	if(intEn != false)
	{
		ADCSRA |= _BV(ADIE);
	}
}

void adcLeftAdjust(_Bool adjust)
{
	ADMUX &= ~_BV(ADLAR);
	if(adjust != false)
	{
		ADMUX |= _BV(ADLAR);
	}
}

void adcPrescalerSelection(ADC_Prescaler_t prescaler)
{
	assert (prescaler < ADC_DivFactorInvalid);

	ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
	ADCSRA |= prescaler;
}

uint16_t adcRead(void)
{
	return ADCW;
}

uint8_t adcReadHigh(void)
{
	return ADCH;
}

uint8_t adcReadLow(void)
{
	return ADCL;
}

_Bool adcReadIntFlag(void)
{
	return (ADCSRA & _BV(ADIF)) == 0 ? false:true;
}

void adcClearIntFlag(void)
{
	//Write a logical 1 to clear the flag
	ADCSRA |= _BV(ADIF);
}

void adcSelectVref(ADC_VoltageRef_t ref)
{
	assert (ref < ADC_VrefInvalid);

	ADMUX &= ~(1 << REFS1 | 1 << REFS0);
	ADMUX |= ref << REFS0;
}

void adcStartConversion(void)
{
	ADCSRA |= 1 << ADSC;
}


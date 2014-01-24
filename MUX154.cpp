/*
 * Copyright (c) 2014, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 *  1. Redistributions of source code must retain the above copyright notice, 
 *     this list of conditions and the following disclaimer.
 * 
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 * 
 *  3. Neither the name of Majenko Technologies nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without 
 *     specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <MUX154.h>

void MUX154::begin() {
    pinMode(_a0, OUTPUT);
    digitalWrite(_a0, LOW);
    pinMode(_a1, OUTPUT);
    digitalWrite(_a1, LOW);
    pinMode(_a2, OUTPUT);
    digitalWrite(_a2, LOW);
    pinMode(_a3, OUTPUT);
    digitalWrite(_a3, LOW);
    pinMode(_e0, OUTPUT);
    digitalWrite(_e0, HIGH);
    if (_e1 != 255) {
        pinMode(_e1, OUTPUT);
        digitalWrite(_e1, HIGH);
    }
    _selected = -1;
}

void MUX154::select(uint8_t s) {
    _selected = s;
    update();
}

void MUX154::inc() {
    _selected ++;
    if (_selected == 16) {
        _selected = 0;
    }
    update();
}

void MUX154::dec() {
    _selected --;
    if (_selected == 255) {
        _selected = 15;
    }
    update();
}

void MUX154::update() {
    digitalWrite(_e0, HIGH);
    if (_e1 != 255) {   
        digitalWrite(_e1, HIGH);
    }
    if (_selected > 15) {
        return;
    }

    digitalWrite(_a0, _selected & 0x01);
    digitalWrite(_a1, _selected & 0x02);
    digitalWrite(_a2, _selected & 0x04);
    digitalWrite(_a3, _selected & 0x08);
    digitalWrite(_e0, LOW);
    if (_e1 != 255) {   
        digitalWrite(_e1, LOW);
    }
}

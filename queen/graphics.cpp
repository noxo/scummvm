/* ScummVM - Scumm Interpreter
 * Copyright (C) 2003 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 *
 */

#include "stdafx.h"
#include "queen/graphics.h"
#include "queen/resource.h"


namespace Queen {


const uint8 Graphics::FONT[] = {
	0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 
	0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 
	0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 
	0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 
	0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 
	0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 
	0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 
	0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 
	0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 
	0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 
	0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 
	0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 
	0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 
	0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 
	0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 
	0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 
	0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 
	0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 
	0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 
	0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 
	0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 
	0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 
	0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 
	0xC0, 0x00, 0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 
	0xF8, 0xB0, 0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0xF8, 0xB0, 
	0xB0, 0x80, 0xB0, 0xB0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0xC0, 
	0xC0, 0x00, 0xD8, 0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x6C, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0x6C, 0x00, 0x30, 0x7C, 
	0xC0, 0x78, 0x0C, 0xF8, 0x30, 0x00, 0x00, 0xC6, 0xCC, 0x18, 
	0x30, 0x66, 0xC6, 0x00, 0x38, 0x6C, 0x68, 0x36, 0xDC, 0xCC, 
	0x76, 0x00, 0x60, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x30, 0x60, 0xC0, 0xC0, 0xC0, 0x60, 0x30, 0x00, 0xC0, 0x60, 
	0x30, 0x30, 0x30, 0x60, 0xC0, 0x00, 0x00, 0x6C, 0x38, 0xFE, 
	0x38, 0x6C, 0x00, 0x00, 0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0xC0, 
	0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x03, 0x06, 0x0C, 0x18, 
	0x30, 0x60, 0xC0, 0x00, 0x78, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 
	0x78, 0x00, 0x30, 0x70, 0xF0, 0x30, 0x30, 0x30, 0x30, 0x00, 
	0x78, 0xCC, 0x0C, 0x78, 0xC0, 0xC0, 0xFC, 0x00, 0x78, 0xCC, 
	0x0C, 0x38, 0x0C, 0xCC, 0x78, 0x00, 0x1C, 0x3C, 0x6C, 0xCC, 
	0xFC, 0x0C, 0x0C, 0x00, 0xFC, 0xC0, 0xF8, 0x0C, 0x0C, 0xCC, 
	0x78, 0x00, 0x78, 0xCC, 0xC0, 0xF8, 0xCC, 0xCC, 0x78, 0x00, 
	0xFC, 0xCC, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00, 0x78, 0xCC, 
	0xCC, 0x78, 0xCC, 0xCC, 0x78, 0x00, 0x78, 0xCC, 0xCC, 0x7C, 
	0x0C, 0xCC, 0x78, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0xC0, 
	0xC0, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x60, 0x60, 0xC0, 
	0x18, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x18, 0x00, 0x00, 0x00, 
	0xFC, 0x00, 0xFC, 0x00, 0x00, 0x00, 0xC0, 0x60, 0x30, 0x18, 
	0x30, 0x60, 0xC0, 0x00, 0x78, 0xCC, 0x0C, 0x18, 0x30, 0x00, 
	0x30, 0x00, 0x6C, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x10, 0x00, 
	0x38, 0x7C, 0xC6, 0xC6, 0xFE, 0xC6, 0xC6, 0x00, 0xF8, 0xCC, 
	0xCC, 0xF8, 0xCC, 0xCC, 0xF8, 0x00, 0x78, 0xCC, 0xC0, 0xC0, 
	0xC0, 0xCC, 0x78, 0x00, 0xF8, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 
	0xF8, 0x00, 0xFC, 0xC0, 0xC0, 0xF0, 0xC0, 0xC0, 0xFC, 0x00, 
	0xFC, 0xC0, 0xC0, 0xF0, 0xC0, 0xC0, 0xC0, 0x00, 0x78, 0xCC, 
	0xC0, 0xDC, 0xCC, 0xCC, 0x7C, 0x00, 0xCC, 0xCC, 0xCC, 0xFC, 
	0xCC, 0xCC, 0xCC, 0x00, 0xF0, 0x60, 0x60, 0x60, 0x60, 0x60, 
	0xF0, 0x00, 0x0C, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78, 0x00, 
	0xC6, 0xCC, 0xD8, 0xF8, 0xD8, 0xCC, 0xC6, 0x00, 0xC0, 0xC0, 
	0xC0, 0xC0, 0xC0, 0xC0, 0xFC, 0x00, 0x82, 0xC6, 0xEE, 0xFE, 
	0xD6, 0xC6, 0xC6, 0x00, 0xC6, 0xE6, 0xF6, 0xDE, 0xCE, 0xC6, 
	0xC6, 0x00, 0x78, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x78, 0x00, 
	0xF8, 0xCC, 0xCC, 0xF8, 0xC0, 0xC0, 0xC0, 0x00, 0x78, 0xCC, 
	0xCC, 0xCC, 0xCC, 0xDC, 0x78, 0x0C, 0xF8, 0xCC, 0xCC, 0xF8, 
	0xD8, 0xCC, 0xCC, 0x00, 0x78, 0xCC, 0xC0, 0x78, 0x0C, 0xCC, 
	0x78, 0x00, 0xFC, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 
	0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x7C, 0x00, 0xC6, 0xC6, 
	0x6C, 0x6C, 0x38, 0x38, 0x10, 0x00, 0xC6, 0xC6, 0xC6, 0xD6, 
	0xFE, 0xEE, 0xC6, 0x00, 0xC6, 0x6C, 0x38, 0x10, 0x38, 0x6C, 
	0xC6, 0x00, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x30, 0x30, 0x00, 
	0xFC, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0xFC, 0x00, 0xF0, 0xC0, 
	0xC0, 0xC0, 0xC0, 0xC0, 0xF0, 0x00, 0xC0, 0x60, 0x30, 0x18, 
	0x0C, 0x06, 0x03, 0x00, 0xF0, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0xF0, 0x00, 0xE8, 0x4D, 0x4A, 0x48, 0x00, 0x00, 0x00, 0x00, 
	0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 
	0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x0C, 
	0x7C, 0xCC, 0x7C, 0x00, 0xC0, 0xC0, 0xF8, 0xCC, 0xCC, 0xCC, 
	0xF8, 0x00, 0x00, 0x00, 0x78, 0xCC, 0xC0, 0xCC, 0x78, 0x00, 
	0x0C, 0x0C, 0x7C, 0xCC, 0xCC, 0xCC, 0x7C, 0x00, 0x00, 0x00, 
	0x78, 0xCC, 0xFC, 0xC0, 0x78, 0x00, 0x38, 0x6C, 0x60, 0xF8, 
	0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x7C, 0xCC, 0xCC, 0x7C, 
	0x0C, 0x78, 0xC0, 0xC0, 0xF8, 0xCC, 0xCC, 0xCC, 0xCC, 0x00, 
	0xC0, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x0C, 0x00, 
	0x0C, 0x0C, 0x0C, 0x0C, 0xCC, 0x78, 0xC0, 0xC0, 0xCC, 0xD8, 
	0xF0, 0xD8, 0xCC, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
	0xC0, 0x00, 0x00, 0x00, 0xCC, 0xEE, 0xD6, 0xC6, 0xC6, 0x00, 
	0x00, 0x00, 0xF8, 0xCC, 0xCC, 0xCC, 0xCC, 0x00, 0x00, 0x00, 
	0x78, 0xCC, 0xCC, 0xCC, 0x78, 0x00, 0x00, 0x00, 0xF8, 0xCC, 
	0xCC, 0xF8, 0xC0, 0xC0, 0x00, 0x00, 0x7C, 0xCC, 0xCC, 0x7C, 
	0x0C, 0x0C, 0x00, 0x00, 0xF8, 0xCC, 0xC0, 0xC0, 0xC0, 0x00, 
	0x00, 0x00, 0x7C, 0xC0, 0x78, 0x0C, 0x78, 0x00, 0x30, 0x30, 
	0xFC, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0xCC, 0xCC, 
	0xCC, 0xCC, 0x7C, 0x00, 0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x78, 
	0x30, 0x00, 0x00, 0x00, 0xC6, 0xD6, 0xD6, 0x6C, 0x6C, 0x00, 
	0x00, 0x00, 0xCC, 0x78, 0x30, 0x78, 0xCC, 0x00, 0x00, 0x00, 
	0xCC, 0xCC, 0xCC, 0x78, 0x30, 0xE0, 0x00, 0x00, 0xFC, 0x18, 
	0x30, 0x60, 0xFC, 0x00, 0x38, 0x60, 0x60, 0xC0, 0x60, 0x60, 
	0x38, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 
	0xE0, 0x30, 0x30, 0x18, 0x30, 0x30, 0xE0, 0x00, 0x38, 0x44, 
	0xBA, 0xAA, 0xBA, 0x44, 0x38, 0x00, 0x00, 0x98, 0x30, 0x60, 
	0xC8, 0x98, 0x30, 0x00, 0x1E, 0x30, 0x60, 0x60, 0x30, 0x1E, 
	0x0C, 0x18, 0x00, 0x66, 0x00, 0x66, 0x66, 0x66, 0x3E, 0x00, 
	0x0C, 0x18, 0x3C, 0x66, 0x7E, 0x60, 0x3C, 0x00, 0x18, 0x66, 
	0x3C, 0x06, 0x3E, 0x66, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x3C, 0x06, 0x3E, 0x66, 
	0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1E, 0x30, 0x60, 0x60, 0x30, 0x1E, 0x0C, 0x18, 0x18, 0x66, 
	0x3C, 0x66, 0x7E, 0x60, 0x3C, 0x00, 0x66, 0x00, 0x3C, 0x66, 
	0x7E, 0x60, 0x3C, 0x00, 0x30, 0x18, 0x3C, 0x66, 0x7E, 0x60, 
	0x3C, 0x00, 0x00, 0x66, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 
	0x18, 0x66, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0x30, 0x18, 
	0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x18, 0x30, 0xFC, 0xC0, 0xF0, 0xC0, 0xFC, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x66, 0x00, 0x3C, 
	0x66, 0x66, 0x3C, 0x00, 0x00, 0x66, 0x00, 0x3C, 0x66, 0x66, 
	0x3C, 0x00, 0x30, 0x18, 0x00, 0x3C, 0x66, 0x66, 0x3C, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 
	0x00, 0x66, 0x66, 0x66, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x18, 0x30, 0x78, 0x0C, 0x7C, 0xCC, 0x7C, 0x00, 0x0C, 0x18, 
	0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x30, 0x00, 0x78, 
	0xCC, 0xCC, 0x78, 0x00, 0x18, 0x30, 0x00, 0xCC, 0xCC, 0xCC, 
	0x7C, 0x00, 0x71, 0x8E, 0x00, 0x7C, 0x66, 0x66, 0x66, 0x00, 
	0x71, 0xCE, 0xE6, 0xF6, 0xDE, 0xCE, 0xC6, 0x00, 0x18, 0x18, 
	0x18, 0x00, 0x18, 0x18, 0x18, 0x00, 0x3C, 0x60, 0x3C, 0x66, 
	0x3C, 0x06, 0x3C, 0x00, 0x18, 0x00, 0x18, 0x0C, 0x06, 0x66, 
	0x3C, 0x00, 0x3F, 0x40, 0x4E, 0x58, 0x4E, 0x40, 0x3F, 0x00, 
	0x1C, 0xA4, 0xC4, 0xBC, 0x80, 0xFE, 0x00, 0x00, 0x00, 0x33, 
	0x66, 0xCC, 0x66, 0x33, 0x00, 0x00, 0x3E, 0x06, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0xC0, 0xC0, 0xC0, 
	0xC0, 0x00, 0x81, 0xB9, 0xA5, 0xB9, 0xA5, 0x81, 0x7E, 0x00, 
	0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xCC, 
	0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0xFC, 0x30, 
	0x30, 0x00, 0xFC, 0x00, 0xF0, 0x18, 0x30, 0x60, 0xF8, 0x00, 
	0x00, 0x00, 0xF0, 0x18, 0x30, 0x18, 0xF0, 0x00, 0x00, 0x00, 
	0x30, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xCC, 0xCC, 0xCC, 0xCC, 0xFE, 0xC0, 0x3E, 0x7A, 0x7A, 0x3A, 
	0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x60, 
	0x60, 0xE0, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x38, 0x44, 
	0x44, 0x38, 0x00, 0x7C, 0x00, 0x00, 0x00, 0xCC, 0x66, 0x33, 
	0x66, 0xCC, 0x00, 0x00, 0x40, 0xC6, 0x4C, 0x58, 0x32, 0x66, 
	0xCF, 0x02, 0x40, 0xC6, 0x4C, 0x58, 0x3E, 0x62, 0xC4, 0x0E, 
	0xC0, 0x23, 0x66, 0x2C, 0xD9, 0x33, 0x67, 0x01, 0x18, 0x00, 
	0x18, 0x30, 0x60, 0x66, 0x3C, 0x00, 0x60, 0x30, 0x7C, 0xC6, 
	0xFE, 0xC6, 0xC6, 0x00, 0x0C, 0x18, 0x7C, 0xC6, 0xFE, 0xC6, 
	0xC6, 0x00, 0x38, 0xC6, 0x7C, 0xC6, 0xFE, 0xC6, 0xC6, 0x00, 
	0x71, 0x8E, 0x7C, 0xC6, 0xFE, 0xC6, 0xC6, 0x00, 0x6C, 0x00, 
	0x7C, 0xC6, 0xFE, 0xC6, 0xC6, 0x00, 0x38, 0x44, 0x7C, 0xC6, 
	0xFE, 0xC6, 0xC6, 0x00, 0x1F, 0x3C, 0x3C, 0x6F, 0x7C, 0xCC, 
	0xCF, 0x00, 0x1E, 0x30, 0x60, 0x60, 0x30, 0x1E, 0x0C, 0x18, 
	0x60, 0x30, 0xFC, 0xC0, 0xF0, 0xC0, 0xFC, 0x00, 0x18, 0x30, 
	0xFC, 0xC0, 0xF0, 0xC0, 0xFC, 0x00, 0x30, 0xCC, 0xFC, 0xC0, 
	0xF0, 0xC0, 0xFC, 0x00, 0xCC, 0x00, 0xFC, 0xC0, 0xF0, 0xC0, 
	0xFC, 0x00, 0x60, 0x30, 0x78, 0x30, 0x30, 0x30, 0x78, 0x00, 
	0x18, 0x30, 0x78, 0x30, 0x30, 0x30, 0x78, 0x00, 0x30, 0xCC, 
	0x78, 0x30, 0x30, 0x30, 0x78, 0x00, 0xCC, 0x00, 0x78, 0x30, 
	0x30, 0x30, 0x78, 0x00, 0x78, 0x6C, 0x66, 0xF6, 0x66, 0x6C, 
	0x78, 0x00, 0x71, 0xCE, 0xE6, 0xF6, 0xDE, 0xCE, 0xC6, 0x00, 
	0x30, 0x18, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00, 0x0C, 0x18, 
	0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00, 0x18, 0x66, 0x3C, 0x66, 
	0x66, 0x66, 0x3C, 0x00, 0x71, 0x8E, 0x3C, 0x66, 0x66, 0x66, 
	0x3C, 0x00, 0xC3, 0x3C, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00, 
	0x00, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x00, 0x00, 0x3F, 0x66, 
	0x6E, 0x7E, 0x76, 0x66, 0xFC, 0x00, 0x30, 0x18, 0x66, 0x66, 
	0x66, 0x66, 0x3E, 0x00, 0x0C, 0x18, 0x66, 0x66, 0x66, 0x66, 
	0x3E, 0x00, 0x18, 0x24, 0x66, 0x66, 0x66, 0x66, 0x3E, 0x00, 
	0x66, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3E, 0x00, 0x06, 0x08, 
	0xC3, 0x66, 0x3C, 0x18, 0x18, 0x00, 0x60, 0x60, 0x7E, 0x63, 
	0x7E, 0x60, 0x60, 0x00, 0x3C, 0x66, 0x66, 0x6C, 0x66, 0x66, 
	0x6C, 0x60, 0x30, 0x18, 0x3C, 0x06, 0x3E, 0x66, 0x3E, 0x00, 
	0x0C, 0x18, 0x3C, 0x06, 0x3E, 0x66, 0x3E, 0x00, 0x18, 0x66, 
	0x3C, 0x06, 0x3E, 0x66, 0x3E, 0x00, 0x71, 0x8E, 0x3C, 0x06, 
	0x3E, 0x66, 0x3E, 0x00, 0x66, 0x00, 0x3C, 0x06, 0x3E, 0x66, 
	0x3E, 0x00, 0x18, 0x24, 0x3C, 0x06, 0x3E, 0x66, 0x3E, 0x00, 
	0x00, 0x00, 0x7E, 0x1B, 0x7F, 0xD8, 0x77, 0x00, 0x00, 0x00, 
	0x3C, 0x60, 0x60, 0x60, 0x3C, 0x18, 0x30, 0x18, 0x3C, 0x66, 
	0x7E, 0x60, 0x3C, 0x00, 0x0C, 0x18, 0x3C, 0x66, 0x7E, 0x60, 
	0x3C, 0x00, 0x18, 0x66, 0x3C, 0x66, 0x7E, 0x60, 0x3C, 0x00, 
	0x66, 0x00, 0x3C, 0x66, 0x7E, 0x60, 0x3C, 0x00, 0x30, 0x18, 
	0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0x0C, 0x18, 0x00, 0x18, 
	0x18, 0x18, 0x18, 0x00, 0x18, 0x66, 0x00, 0x18, 0x18, 0x18, 
	0x18, 0x00, 0x00, 0x66, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 
	0x60, 0xFC, 0x18, 0x3C, 0x66, 0x66, 0x3C, 0x00, 0x71, 0x8E, 
	0x00, 0x7C, 0x66, 0x66, 0x66, 0x00, 0x30, 0x18, 0x00, 0x3C, 
	0x66, 0x66, 0x3C, 0x00, 0x0C, 0x18, 0x00, 0x3C, 0x66, 0x66, 
	0x3C, 0x00, 0x18, 0x66, 0x00, 0x3C, 0x66, 0x66, 0x3C, 0x00, 
	0x71, 0x8E, 0x00, 0x3C, 0x66, 0x66, 0x3C, 0x00, 0x00, 0x66, 
	0x00, 0x3C, 0x66, 0x66, 0x3C, 0x00, 0x00, 0x18, 0x00, 0x7E, 
	0x00, 0x18, 0x00, 0x00, 0x00, 0x02, 0x7C, 0xCE, 0xD6, 0xE6, 
	0x7C, 0x80, 0x30, 0x18, 0x00, 0x66, 0x66, 0x66, 0x3E, 0x00, 
	0x0C, 0x18, 0x00, 0x66, 0x66, 0x66, 0x3E, 0x00, 0x18, 0x66, 
	0x00, 0x66, 0x66, 0x66, 0x3E, 0x00, 0x00, 0x66, 0x00, 0x66, 
	0x66, 0x66, 0x3E, 0x00, 0x0C, 0x18, 0x00, 0x66, 0x66, 0x3C, 
	0x18, 0x30, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60, 
	0x00, 0x66, 0x00, 0x66, 0x66, 0x3C, 0x18, 0x30, 0xFF 
};


const uint8 Graphics::FONT_SIZES[] = {
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
	0x06, 0x06, 0x04, 0x03, 0x06, 0x08, 0x07, 0x08, 0x08, 0x04,
	0x05, 0x05, 0x08, 0x07, 0x04, 0x07, 0x03, 0x09, 0x07, 0x05,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x04,
	0x06, 0x07, 0x06, 0x07, 0x08, 0x08, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x05, 0x07, 0x08, 0x07, 0x08, 0x08, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x07,
	0x07, 0x05, 0x09, 0x05, 0x08, 0x02, 0x04, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x07, 0x07, 0x03, 0x08,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08,
	0x07, 0x07, 0x07, 0x06, 0x03, 0x06, 0x08, 0x06, 0x08, 0x08,
	0x08, 0x08, 0x02, 0x08, 0x02, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x06, 0x02, 0x02, 0x07, 0x02, 0x02, 0x08, 0x08, 0x08,
	0x02, 0x08, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x07, 0x07, 0x07, 0x07, 0x09, 0x09, 0x06, 0x08, 0x08, 0x09,
	0x08, 0x09, 0x08, 0x03, 0x09, 0x07, 0x07, 0x07, 0x06, 0x06,
	0x05, 0x08, 0x08, 0x06, 0x05, 0x04, 0x07, 0x09, 0x09, 0x08,
	0x09, 0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x09, 0x08,
	0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x07, 0x07, 0x08, 0x09,
	0x08, 0x08, 0x08, 0x09, 0x09, 0x08, 0x09, 0x08, 0x08, 0x08,
	0x08, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08,
	0x09, 0x07, 0x08, 0x08, 0x08, 0x08, 0x06, 0x07, 0x08, 0x08,
	0x08, 0x09, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08
};


Graphics::Graphics(Resource *resource)
	: _cameraBob(0), _resource(resource) {
		
	memset(_frames, 0, sizeof(_frames));
	memset(_banks, 0, sizeof(_banks));
	memset(_bobs, 0, sizeof(_bobs));
	memset(_sortedBobs, 0, sizeof(_sortedBobs));
	_sortedBobsCount = 0;
	_shrinkBuffer.data = new uint8[ BOB_SHRINK_BUF_SIZE ];
	_backdrop = new uint8[ BACKDROP_W * BACKDROP_H ];
	_panel = new uint8[ PANEL_W * PANEL_H ];
	_screen = new uint8[ SCREEN_W * SCREEN_H ];
	_fullscreen = true;
	_horizontalScroll = 0;
	_palette = new uint8[ 256 * 4 ];
}


Graphics::~Graphics() {
	uint32 i;
	for(i = 0; i < ARRAYSIZE(_banks); ++i) {
		delete _banks[i].data;
	}
	frameEraseAll(true);
	delete[] _shrinkBuffer.data;
	delete[] _backdrop;
	delete[] _panel;
	delete[] _screen;
	delete[] _palette;
}


void Graphics::bankLoad(const char *bankname, uint32 bankslot) {
	
	int16 i;
	
	bankErase(bankslot);
	_banks[bankslot].data = _resource->loadFile(bankname);
	if (!_banks[bankslot].data) {
	  error("Unable to open bank '%s'", bankname);	
	}

	int16 entries = (int16)READ_LE_UINT16(_banks[bankslot].data);
	if (entries < 0 || entries >= MAX_BANK_SIZE) {
	  error("Maximum bank size exceeded or negative bank size : %d", entries);
	}
	
	uint32 offset = 2;
	uint8 *p = _banks[bankslot].data;
	for (i = 1; i <= entries; ++i) {
		_banks[bankslot].indexes[i] = offset;
		uint16 w = READ_LE_UINT16(p + offset + 0);
		uint16 h = READ_LE_UINT16(p + offset + 2);
		// jump to next entry, skipping data & header
		offset += w * h + 8; 
	}
	
	debug(5, "Loaded bank '%s' in slot %d, %d entries", bankname, bankslot, entries); 
}


void Graphics::bankUnpack(uint32 srcframe, uint32 dstframe, uint32 bankslot) {
	
	uint8 *p = _banks[bankslot].data + _banks[bankslot].indexes[srcframe];
		
	BobFrame *pbf = &_frames[dstframe];
	delete[] pbf->data;

	pbf->width    = READ_LE_UINT16(p + 0);
	pbf->height   = READ_LE_UINT16(p + 2);
	pbf->xhotspot = READ_LE_UINT16(p + 4);
	pbf->yhotspot = READ_LE_UINT16(p + 6);
	
	uint32 size = pbf->width * pbf->height;
	pbf->data = new uint8[ size ];
	memcpy(pbf->data, p + 8, size);
	
	debug(5, "Unpacked frame %d from bank slot %d to frame slot %d", srcframe, bankslot, dstframe);
}


void Graphics::bankOverpack(uint32 srcframe, uint32 dstframe, uint32 bankslot) {
	
	uint8 *p = _banks[bankslot].data + _banks[bankslot].indexes[srcframe];
	uint16 src_w = READ_LE_UINT16(p + 0);
	uint16 src_h = READ_LE_UINT16(p + 2);
	
	// unpack if destination frame is smaller than source one
	if (_frames[dstframe].width < src_w || _frames[dstframe].height < src_h) {
		bankUnpack(srcframe, dstframe, bankslot);
	}
	else {
		// copy data 'over' destination frame (without changing frame header)
		memcpy(_frames[dstframe].data, p, src_w * src_h);
	}
	
	debug(5, "Overpacked frame %d from bank slot %d to frame slot %d", srcframe, bankslot, dstframe);
}


void Graphics::bankErase(uint32 bankslot) {
	
	delete[] _banks[bankslot].data;
	_banks[bankslot].data = 0;
	
	debug(5, "Erased bank in slot %d", bankslot);
}


void Graphics::bobSetupControl() {

	bankLoad("control.BBK",17);
	bankUnpack(1, 1, 17); // Mouse pointer
    bankUnpack(3, 3, 17); // Up arrow dialogue
    bankUnpack(4, 4, 17); // Down arrow dialogue
    bankErase(17);
}


void Graphics::bobAnimString(uint32 bobnum, uint8* animBuf) {

	BobSlot *pbs = &_bobs[bobnum];
	pbs->active = true;
	pbs->animating = true;
	pbs->anim.string.buffer = animBuf;
	pbs->anim.string.curPos = animBuf;
	pbs->frameNum = READ_LE_UINT16(animBuf);
	pbs->anim.speed = READ_LE_UINT16(animBuf + 2) / 4;
}


void Graphics::bobAnimNormal(uint32 bobnum, uint16 firstFrame, uint16 lastFrame, uint16 speed, bool rebound, bool xflip) {

	BobSlot *pbs = &_bobs[bobnum];
	pbs->active = true;
	pbs->animating = true;
	pbs->frameNum = firstFrame;
	pbs->anim.speed = speed;
	pbs->anim.speedBak = speed;
	pbs->anim.string.buffer = NULL;
	pbs->anim.normal.firstFrame = firstFrame;
	pbs->anim.normal.lastFrame = lastFrame;
	pbs->anim.normal.rebound = rebound;
	pbs->frameDir = 1;
	pbs->xflip = xflip;
}


void Graphics::bobMove(uint32 bobnum, uint16 endx, uint16 endy, int16 speed) {

	debug(5, "Graphics::bobMove(%d, %d, %d, %d)", bobnum, endx, endy, speed);

	BobSlot *pbs = &_bobs[bobnum];

	pbs->active = true;
	pbs->moving = true;

	pbs->endx = endx;
	pbs->endy = endy;

	pbs->speed = (speed < 1) ? 1 : speed;

	int16 dx = endx - pbs->x;
	if (dx < 0) {
		pbs->dx   = -dx;
		pbs->xdir = -1;
	}
	else {
		pbs->dx   = dx;
		pbs->xdir = 1;
	}
	int16 dy = endy - pbs->y;
	if (dy < 0) {
		pbs->dy   = -dy;
		pbs->ydir = -1;
	}
	else {
		pbs->dy   = dy;
		pbs->ydir = 1;
	}

	if (pbs->dx > pbs->dy) {
		pbs->total = pbs->dy / 2;
		pbs->xmajor = true;
	}
	else {
		pbs->total = pbs->dx / 2;
		pbs->xmajor = false;
	}

	// move one step along line to avoid glitching
	pbs->moveOneStep();
}


void BobSlot::moveOneStep() {

	if(xmajor) {
		if(x == endx) {
			y = endy;
			moving = false;
		}
		else {
			x += xdir;
			total += dy;
			if(total > dx) {
				y += ydir;
				total -= dx;
			}
		}
	}
	else {
		if(y == endy) {
			x = endx;
			moving = false;
		}
		else {
			y += ydir;
			total += dx;
			if(total > dy) {
				x += xdir;
				total -= dy;
			}
		}
	}
}


void BobSlot::animOneStep() {

	if (anim.string.buffer != NULL) {
		--anim.speed;
		if(anim.speed == 0) {
			anim.string.curPos += 4;
			uint16 nextFrame = READ_LE_UINT16(anim.string.curPos);
			if (nextFrame == 0) {
				anim.string.curPos = anim.string.buffer;
				frameNum = READ_LE_UINT16(anim.string.curPos);
			}
			else {
				frameNum = nextFrame;
			}
			anim.speed = READ_LE_UINT16(anim.string.curPos + 2) / 4;

			// FIXME: handle that when QueenSound class is ready
			// play memory sfx and move on to next frame
			if(frameNum > 500) {
				frameNum -= 500;
				// _sound->sfxplay(NULLstr);
			}
		}
	}
	else {
		// normal looping animation
		--anim.speed;
		if(anim.speed == 0) {
			anim.speed = anim.speedBak;

			uint16 nextFrame = frameNum + frameDir;
			if (nextFrame > anim.normal.lastFrame || nextFrame < anim.normal.firstFrame) {
				if (anim.normal.rebound) {
					frameDir *= -1;
				}
				else {
					frameNum = anim.normal.firstFrame - 1;
				}
			}
			frameNum += frameDir;
		}
	}
}
          

void Graphics::bobDraw(uint32 bobnum, uint16 x, uint16 y, uint16 scale, bool xflip, const Box& box) {

	uint16 w, h;

	debug(5, "Preparing to draw frame %d, scale = %d, coords = (%d,%d)", bobnum, scale, x, y);

	BobFrame *pbf = &_frames[bobnum];
	if (scale < 100) {
		bobShrink(pbf, scale);
		pbf = &_shrinkBuffer;
	}
	w = pbf->width;
	h = pbf->height;

	if(w != 0 && h != 0 && box.intersects(x, y, w, h)) {

		uint8 *src = pbf->data;
		uint16 x_skip = 0;
		uint16 y_skip = 0;
		uint16 w_new = w;
		uint16 h_new = h;

		// compute bounding box intersection with frame
		if (x < box.x1) {
			x_skip = box.x1 - x;
			w_new -= x_skip;
			x = box.x1;
		}

		if (y < box.y1) {
			y_skip = box.y1 - y;
			h_new -= y_skip;
			y = box.y1;
		}

		if (x + w_new > box.x2 + 1) {
			w_new = box.x2 - x + 1;
		}

		if (y + h_new > box.y2 + 1) {
			h_new = box.y2 - y + 1;
		}

		src += w * y_skip;
		if (!xflip) {
			src += x_skip;
			displayBlit(_screen, x, y, SCREEN_W, src, w_new, h_new, w, xflip, true);
		}
		else {
			src += w - w_new - x_skip;
			x += w_new - 1;
			displayBlit(_screen, x, y, SCREEN_W, src, w_new, h_new, w, xflip, true);
		}
    }

}


void Graphics::bobDrawInventoryItem(uint32 bobnum, uint16 x, uint16 y) {
	if (bobnum == 0) {
		// clear panel area
		memset(_panel + y * 32 + x, INK_BG_PANEL, 32 * 32);
	}
	else {
		BobFrame *pbf = &_frames[bobnum];
		displayBlit(_panel, x, y, 320, pbf->data, pbf->width, pbf->height, pbf->width, false, false);
	}
}


void Graphics::bobPaste(uint32 bobnum, uint16 x, uint16 y) {

	BobFrame *pbf = &_frames[bobnum];
	displayBlit(_backdrop, x, y, 640, pbf->data, pbf->width, pbf->height, pbf->width, false, true);
	frameErase(bobnum);
}


void Graphics::bobShrink(const BobFrame* pbf, uint16 percentage) {

	// computing new size, rounding to upper value
	uint16 new_w = (pbf->width  * percentage + 50) / 100;
	uint16 new_h = (pbf->height * percentage + 50) / 100;

	debug(5, "Shrinking bob, buffer size = %d", new_w * new_h);

	if (new_w != 0 && new_h != 0) {

		_shrinkBuffer.width  = new_w;
		_shrinkBuffer.height = new_h;

		uint32 shrinker = (100 << 0x10) / percentage;
		uint16 x_scale = shrinker >> 0x10;
		uint16 y_scale = x_scale * pbf->width;   
		shrinker &= 0xFFFF;

		uint8* src = pbf->data;
		uint8* dst = _shrinkBuffer.data;

		uint32 y_count = 0;
		while (new_h--) {
			uint16 i;
			uint32 x_count = 0;
			uint8 *p = src;
			for(i = 0; i < new_w; ++i) {
				*dst++ = *p;
				p += x_scale;
				x_count += shrinker;
				if (x_count > 0xFFFF) {
					++p;
					x_count &= 0xFFFF;
				}
			}
			src += y_scale;
			y_count += shrinker;
			if (y_count > 0xFFFF) {
				src += pbf->width;
				y_count &= 0xFFFF;
			}
		}
	}
}


void Graphics::bobClear(uint32 bobnum) {

	BobSlot *pbs = &_bobs[bobnum];

	pbs->active = 0;
	pbs->xflip  = false;
	pbs->anim.string.buffer = NULL;
	pbs->moving = false;
	pbs->scale  = 100;
	pbs->box.x1 = 0;
	pbs->box.y1 = 0;
	pbs->box.x2 = GAME_SCREEN_WIDTH - 1;
	if (_fullscreen || bobnum == 16) { // FIXME: does bob number 16 really used ?
		pbs->box.y2 = GAME_SCREEN_HEIGHT - 1;
	}
	else {
		pbs->box.y2 = ROOM_ZONE_HEIGHT - 1; 
	}
}


void Graphics::bobSortAll() {

	_sortedBobsCount = 0;

	// animate/move the bobs
	for (int32 i = 0; i < ARRAYSIZE(_bobs); ++i) {

		BobSlot *pbs = &_bobs[i];
		if (pbs->active) {
			_sortedBobs[_sortedBobsCount] = pbs;
			++_sortedBobsCount;

			if (pbs->animating) {
				pbs->animOneStep();
			}
			if (pbs->moving) {
				for (uint32 j = 0; pbs->moving && j < pbs->speed; ++j) {
					pbs->moveOneStep();
				}
			}
		}
	}

	// bubble sort the bobs
	for (int32 index = 0; index < _sortedBobsCount - 1; ++index) {
		int32 smallest = index;
		for (int32 compare = index + 1; compare <= _sortedBobsCount - 1; ++compare) {
			if (_sortedBobs[compare]->y < _sortedBobs[compare]->y) {
				smallest = compare;
			}
		}
		if (index != smallest) {
			SWAP(_sortedBobs[index], _sortedBobs[smallest]);
		}
	}

}


void Graphics::bobDrawAll() {

	int i;
	for (i = 0; i < _sortedBobsCount; ++i) {
		BobSlot *pbs = _sortedBobs[i];
		if (pbs->active) {
			BobFrame *pbf = &_frames[ pbs->frameNum ];
			uint16 xh, yh, x, y;

			xh = pbf->xhotspot;
			yh = pbf->yhotspot;

			if (pbs->xflip) {
				xh = pbf->width - xh;
			}

			// adjusts hot spots when object is scaled
			if (pbs->scale != 100) {
				xh = (xh * pbs->scale) / 100;
				yh = (yh * pbs->scale) / 100;
			}

			// adjusts position to hot-spot and screen scroll
			x = pbs->x - xh; // - _display->scrollx;
			y = pbs->y - yh;

			bobDraw(pbs->frameNum, x, y, pbs->scale, pbs->xflip, pbs->box);
		}
	}
}


void Graphics::bobClearAll() {

	for(int32 i = 0; i < ARRAYSIZE(_bobs); ++i) {
		bobClear(i);
	}
}


BobSlot *Graphics::bob(int index) {

	if (index < MAX_BOBS_NUMBER)
		return _bobs + index;
	else {
		error("QueenGraphics::bob called with index = %i but MAX_BOBS_NUMBER = %i", 
				index, MAX_BOBS_NUMBER);
	}
}


void Graphics::textCurrentColor(uint8 color) {
	_curTextColor = color;
}


void Graphics::textSet(uint16 x, uint16 y, const char *text, bool outlined) {
	if (y < GAME_SCREEN_HEIGHT) {
		if (x == 0) x = 1;
		if (y == 0) y = 1;
		TextSlot *pts = &_texts[y];

		pts->x = x;
		pts->color = _curTextColor;
		pts->outlined = outlined;
		pts->text = text;
	}
}


void Graphics::textDrawAll() {
	int y;
	for (y = GAME_SCREEN_HEIGHT - 1; y > 0; --y) {
		const TextSlot *pts = &_texts[y];
		if (!pts->text.isEmpty()) {
			displayText(pts, y);
		}
	}
}


void Graphics::textClear(uint16 y1, uint16 y2) {

	while (y1 <= y2) {
		_texts[y1].text.clear();
		++y1;
	}
}


uint16 Graphics::textWidth(const char* text) const {

	uint16 len = 0;
	while (*text) {
		len += FONT_SIZES[ (int)*text ];
		++text;
	}
	return len;
}


void Graphics::frameErase(uint32 fslot) {

	BobFrame *pbf = &_frames[fslot];
	pbf->width  = 0;
	pbf->height = 0;
	delete[] pbf->data;
	pbf->data = 0;
}


void Graphics::frameEraseAll(bool joe) {

    int i = 0;
	if (!joe) {
		i = FRAMES_JOE + FRAMES_JOE_XTRA;
	}
	while (i < 256) {
		frameErase(i);
		++i;
	}
}


void Graphics::backdropLoad(const char* name, uint16 room) {

	// init Dynalum
	char roomPrefix[20];
	strcpy(roomPrefix, name);
	roomPrefix[ strlen(roomPrefix) - 4 ] = '\0';
//	_display->dynalumInit(_resource, roomPrefix, room);

	uint8 *pcxbuf = _resource->loadFile(name);
	if (pcxbuf == NULL) {
		error("Unable to load backdrop : '%s'", name);
	}

	uint32 size = _resource->fileSize(name);
	displaySetPal(pcxbuf + size - 768, 0, (room <= 144) ? 144 : 256);

	_backdropWidth  = READ_LE_UINT16(pcxbuf +  12);
	_backdropHeight = READ_LE_UINT16(pcxbuf +  14);

	if (room >= 90) {
		_cameraBob = 0;
	}

	readPCX(pcxbuf + 128, _backdrop, BACKDROP_W, _backdropWidth, _backdropHeight);
	delete[] pcxbuf;
}


void Graphics::backdropDraw() {

	int n = 3;
	if (_fullscreen) {
		n = 4;
	}
	uint8 *dst = _screen;
	uint8 *src = _backdrop + _horizontalScroll;
	while (n--) {
		int i;
		for (i = 0; i < 50; ++i) {
			memcpy(dst, src, SCREEN_W);
			dst += SCREEN_W;
			src += BACKDROP_W;
		}
	}
}


void Graphics::panelLoad() {

	uint8 *pcxbuf = _resource->loadFile("panel.pcx");
	if (pcxbuf == NULL) {
		error("Unable to open panel file");
	}
	uint32 size = _resource->fileSize("panel.pcx");
	displaySetPal(pcxbuf + size - 768, 144, 256);
	readPCX(pcxbuf + 128, _panel + PANEL_W * 10, PANEL_W, PANEL_W, PANEL_H - 10);
	delete[] pcxbuf;
}


void Graphics::panelDraw() {
	memcpy(_screen + SCREEN_W * ROOM_ZONE_HEIGHT, _panel, PANEL_W * PANEL_H);
}


void Graphics::panelClear() {
	memset(_screen + SCREEN_W * ROOM_ZONE_HEIGHT, 0, PANEL_W * PANEL_H);
}


void Graphics::readPCX(const uint8 *src, uint8 *dst, uint16 dstPitch, uint16 w, uint16 h) {

	while (h--) {
		uint8 *p = dst;
		while (p < dst + w ) {
			uint8 col = *src++;
			if ((col & 0xC0) == 0xC0) {
				uint8 len = col & 0x3F;
				memset(p, *src++, len);
				p += len;
			}
			else {
				*p++ = col;
			}
		}
		dst += dstPitch;
	}
}


void Graphics::boxDraw(const Box &b, uint8 color) {

	int x, y;

	for (y = b.y1; y <= b.y2; ++y) {
		*(_backdrop + y * 640 + b.x1) = color;
		*(_backdrop + y * 640 + b.x2) = color;
	}
	for (x = b.x1; x <= b.x2; ++x) {
		*(_backdrop + b.y1 * 640 + x) = color;
		*(_backdrop + b.y2 * 640 + x) = color;
	}
}


void Graphics::useJournal() { // GameSettings* pgs

	int i;

	bobClearAll();
	backdropLoad("journal.pcx", 160);
//	_display->fadeout(0,255);

	// load and unpack journal frames
	frameEraseAll(false);
    bankLoad("journal.BBK", 8);
	for(i = 1; i <= 20; ++i) {
		bankUnpack(i, FRAMES_JOURNAL + i, 8);
		// set hot spots to zero
		_frames[FRAMES_JOURNAL + i].xhotspot = 0;
		_frames[FRAMES_JOURNAL + i].yhotspot = 0;
	}
	// adjust info box hot spot to put it on top always
	_frames[FRAMES_JOURNAL + 20].yhotspot = 200;
    bankErase(8);

	// TODO: setup zones

	journalBobPreDraw();
//	_display->fadein(0, 255);
}


void Graphics::journalBobSetup(uint32 bobnum, uint16 x, uint16 y, uint16 frame) {

	BobSlot *pbs = &_bobs[bobnum];
	pbs->active = true;
	pbs->x = x;
	pbs->y = y;
	pbs->frameNum = FRAMES_JOURNAL + frame;
	pbs->box.y2 = GAME_SCREEN_HEIGHT - 1;
}


void Graphics::journalBobPreDraw() { // GameSettings* pgs

	journalBobSetup(1, 32, 8, 1); // Review entry
	journalBobSetup(2, 32, 56, 2); // Make entry
	journalBobSetup(3, 32, 104, 1); // Close book
	journalBobSetup(4, 32, 152, 3); // Give up
//	journalBobSetup(5, 136 + pgs->talkSpeed * 4 - 4, 164, 18); // Text speed
	journalBobSetup(6, 221, 155, 16); // SFX on/off
//	_bobs[6].active = pgs->sfxToggle;
//	journalBobSetup(7, 136 + (pgs->volume * 130) / 100 - 4, 177, 19); // Music volume
	journalBobSetup(10, 158, 155, 16); // Voice on/off
//	_bobs[10].active = pgs->voiceToggle;
	journalBobSetup(11, 125, 167, 16); // Text on/off
//	_bobs[11].active = pgs->textToggle;
	journalBobSetup(12, 125, 181, 16); // Music on/off
//	_bobs[12].active = pgs->musicToggle;
}


void Graphics::update() {
	// FIXME: incomplete !
	bobSortAll();
	if (_panelFlag) {
		panelDraw();
	}
	else if (!_fullscreen) {
		panelClear();
	}
	backdropDraw();
	bobDrawAll();
	textDrawAll();
	displayScreen();
	g_system->delay_msecs(100); // TEMP: move to Logic::update()
}


void Graphics::displayText(const TextSlot *pts, uint16 y) {

	uint16 x = pts->x;
	const uint8 *str = (const uint8*)pts->text.c_str();
	while (*str && x < GAME_SCREEN_WIDTH) {
		const uint8 *pchr = FONT + (*str) * 8;
//		if (_resource->_gameVersion->versionString[1] == 'F' && *str == 150) {
//			chr = 251;
//		}
		if (pts->outlined) {
			displayChar(x - 1, y - 1, INK_OUTLINED_TEXT, pchr);
			displayChar(x    , y - 1, INK_OUTLINED_TEXT, pchr);
			displayChar(x + 1, y - 1, INK_OUTLINED_TEXT, pchr);
			displayChar(x + 1, y    , INK_OUTLINED_TEXT, pchr);
			displayChar(x + 1, y + 1, INK_OUTLINED_TEXT, pchr);
			displayChar(x    , y + 1, INK_OUTLINED_TEXT, pchr);
			displayChar(x - 1, y + 1, INK_OUTLINED_TEXT, pchr);
			displayChar(x - 1, y    , INK_OUTLINED_TEXT, pchr);
		}
		displayChar(x, y, pts->color, pchr);

		x += FONT_SIZES[ *str ];
		++str;
	}
}


void Graphics::displayChar(uint16 x, uint16 y, uint8 color, const uint8 *chr) {

	int i, j;
	uint8 *dst = _screen + y * SCREEN_W + x;
	for (j = 0; j < 8; ++j) {
		uint8* p = dst;
		uint8 c = *chr++;
		if (c != 0) {
			for (i = 0; i < 8; ++i) {
				if(c & 0x80) {
					*p = color;
				}
				++p;
				c <<= 1;
			}
		}
		dst += SCREEN_W;
	}
}


void Graphics::displayBlit(uint8 *dst_buf, uint16 dst_x, uint16 dst_y, uint16 dst_pitch, const uint8 *src_buf, uint16 src_w, uint16 src_h, uint16 src_pitch, bool xflip, bool masked) {

	dst_buf += dst_y * dst_pitch + dst_x;
	if (!masked) { // Unmasked always unflipped
		while (src_h--) {
			memcpy(dst_buf, src_buf, src_w);
			src_buf += src_pitch;
			dst_buf += dst_pitch;
		}
	}
	else if (!xflip) { // Masked bitmap unflipped
		while (src_h--) {
			int i;
			for(i = 0; i < src_w; ++i) {
				uint8 b = *(src_buf + i);
				if(b != 0) {
					*(dst_buf + i) = b;
				}
			}
			src_buf += src_pitch;
			dst_buf += dst_pitch;
		}
	}
	else { // Masked bitmap flipped
		while (src_h--) {
			int i;
			for(i = 0; i < src_w; ++i) {
				uint8 b = *(src_buf + i);
				if(b != 0) {
					*(dst_buf - i) = b;
				}
			}
			src_buf += src_pitch;
			dst_buf += dst_pitch;   
		}
	}
}


void Graphics::displaySetPal(uint8 *pal, int start, int end) {
	int i;
	pal += start * 3;
	for (i = start; i < end; ++i, pal += 3) {
		_palette[i << 2 | 0] = *(pal + 0);
		_palette[i << 2 | 1] = *(pal + 1);
		_palette[i << 2 | 2] = *(pal + 2);
		_palette[i << 2 | 3] = 0;
	}
}


void Graphics::displayScreen() {
	// FIXME: temporary code ; cleanup/move to Display class.
	g_system->set_palette(_palette, 0, 256);
	g_system->copy_rect(_screen, SCREEN_W, 0, 0, SCREEN_W, SCREEN_H);
	g_system->update_screen();
}


void Graphics::setScreenMode(int comPanel, bool inCutaway) {
	if (comPanel == 2 && inCutaway) {
		if (_backdropHeight == GAME_SCREEN_HEIGHT) {
			_fullscreen = true;
			_panelFlag = false;
		}
		else {
			_fullscreen = false;
			_panelFlag = true;
		}
	}
	else {
		_fullscreen = 0;
		_panelFlag = (comPanel == 1);
	}
}



} // End of namespace Queen


/* ScummVM - Scumm Interpreter
 * Copyright (C) 2001  Ludvig Strigeus
 * Copyright (C) 2001/2002 The ScummVM project
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

#ifndef COMMON_STREAM_H
#define COMMON_STREAM_H

#include "stdafx.h"
#include "common/scummsys.h"


namespace Common {

class WriteStream {
public:
	virtual uint32 write(const void *ptr, uint32 size) = 0;

	// The remaining methods all have default implementations

	void writeByte(byte value);
	void writeSByte(int8 value);

	void writeUint16LE(uint16 value);
	void writeUint24LE(uint32 value);
	void writeUint32LE(uint32 value);

	void writeUint16BE(uint16 value);
	void writeUint24BE(uint32 value);
	void writeUint32BE(uint32 value);

	void writeSint16LE(int16 value);
	void writeSint24LE(int32 value);
	void writeSint32LE(int32 value);

	void writeSint16BE(int16 value);
	void writeSint24BE(int32 value);
	void writeSint32BE(int32 value);
};


class ReadStream {
public:
	virtual uint32 read(void *ptr, uint32 size) = 0;

	// The remaining methods all have default implementations

	byte readByte();
	int8 readSByte();

	uint16 readUint16LE();
	uint32 readUint24LE();
	uint32 readUint32LE();

	uint16 readUint16BE();
	uint32 readUint24BE();
	uint32 readUint32BE();

	int16 readSint16LE();
	int32 readSint24LE();
	int32 readSint32LE();

	int16 readSint16BE();
	int32 readSint24BE();
	int32 readSint32BE();
};

/**
 * XORReadStream is a wrapper around an arbitrary other ReadStream,
 * which 'decrypts' the data being read by XORing all data bytes with the given
 * encryption 'key'.
 *
 * Currently, this is not used anywhere, it's just a demo of how one can chain
 * streams if necessary.
 */
class XORReadStream : public ReadStream {
private:
	byte _encbyte;
	ReadStream *_realStream;
public:
	XORReadStream(ReadStream *in = 0, byte enc = 0) :  _encbyte(enc), _realStream(in) {}
	void setStream(ReadStream *in) { _realStream = in; }
	void setEnc(byte value) { _encbyte = value; }

	uint32 read(void *ptr, uint32 size) {
		assert(_realStream);
		uint32 len = _realStream->read(ptr, size);
		if (_encbyte) {
			byte *p = (byte *)ptr;
			byte *end = p + len;
			while (p < end)
				*p++ ^= _encbyte;
		}
		return len;
	}
};

/**
 * Simple memory based 'stream', which implements the ReadStream interface for
 * a plain memory block.
 */
class MemoryReadStream : public ReadStream {
private:
	const byte *_ptr;
	const byte * const _ptrOrig;
	const uint32 _bufSize;
	uint32 _pos;
public:
	MemoryReadStream(const byte *buf, uint32 len) : _ptr(buf), _ptrOrig(buf), _bufSize(len), _pos(0) {}

	uint32 read(void *ptr, uint32 len) {
		// Read at most as many bytes as are still available...
		if (len > _bufSize - _pos)
			len = _bufSize - _pos;
		memcpy(ptr, _ptr, len);
		_ptr += len;
		_pos += len;
		return len;
	}

	bool eof() { return _pos == _bufSize; }
	uint32 pos() { return _pos; }
	uint32 size() { return _bufSize; }

	void seek(uint32 offs, int whence = SEEK_SET) {
		// Pre-Condition
		assert(_pos <= _bufSize);
		switch (whence) {
		case SEEK_END:
			// SEEK_END works just like SEEK_SET, only 'reversed',
			// i.e. from the end.
			offs = _bufSize - offs;
			// Fall through
		case SEEK_SET:
			_ptr = _ptrOrig + offs;
			_pos = offs;
			break;

		case SEEK_CUR:
			_ptr += offs;
			_pos += offs;
			break;
		}
		// Post-Condition
		assert(_pos <= _bufSize);
	}
};

}	// End of namespace Common

#endif

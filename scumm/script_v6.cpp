
/* ScummVM - Scumm Interpreter
 * Copyright (C) 2001  Ludvig Strigeus
 * Copyright (C) 2001-2005 The ScummVM project
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

#include "common/config-manager.h"

#include "scumm/actor.h"
#include "scumm/charset.h"
#include "scumm/imuse.h"
#include "scumm/imuse_digi/dimuse.h"
#include "scumm/intern.h"
#include "scumm/object.h"
#include "scumm/resource.h"
#include "scumm/scumm.h"
#include "scumm/sound.h"
#include "scumm/verbs.h"
#include "scumm/smush/smush_player.h"

#include "sound/mididrv.h"
#include "sound/mixer.h"

#include "scumm/insane/insane.h"

namespace Scumm {

#define OPCODE(x)	_OPCODE(ScummEngine_v6, x)

void ScummEngine_v6::setupOpcodes() {
	static const OpcodeEntryV6 opcodes[256] = {
		/* 00 */
		OPCODE(o6_pushByte),
		OPCODE(o6_pushWord),
		OPCODE(o6_pushByteVar),
		OPCODE(o6_pushWordVar),
		/* 04 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_byteArrayRead),
		OPCODE(o6_wordArrayRead),
		/* 08 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_byteArrayIndexedRead),
		OPCODE(o6_wordArrayIndexedRead),
		/* 0C */
		OPCODE(o6_dup),
		OPCODE(o6_not),
		OPCODE(o6_eq),
		OPCODE(o6_neq),
		/* 10 */
		OPCODE(o6_gt),
		OPCODE(o6_lt),
		OPCODE(o6_le),
		OPCODE(o6_ge),
		/* 14 */
		OPCODE(o6_add),
		OPCODE(o6_sub),
		OPCODE(o6_mul),
		OPCODE(o6_div),
		/* 18 */
		OPCODE(o6_land),
		OPCODE(o6_lor),
		OPCODE(o6_pop),
		OPCODE(o6_invalid),
		/* 1C */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 20 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 24 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 28 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 2C */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 30 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 34 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 38 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 3C */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* 40 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_writeByteVar),
		OPCODE(o6_writeWordVar),
		/* 44 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_byteArrayWrite),
		OPCODE(o6_wordArrayWrite),
		/* 48 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_byteArrayIndexedWrite),
		OPCODE(o6_wordArrayIndexedWrite),
		/* 4C */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_byteVarInc),
		OPCODE(o6_wordVarInc),
		/* 50 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_byteArrayInc),
		OPCODE(o6_wordArrayInc),
		/* 54 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_byteVarDec),
		OPCODE(o6_wordVarDec),
		/* 58 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_byteArrayDec),
		OPCODE(o6_wordArrayDec),
		/* 5C */
		OPCODE(o6_if),
		OPCODE(o6_ifNot),
		OPCODE(o6_startScript),
		OPCODE(o6_startScriptQuick),
		/* 60 */
		OPCODE(o6_startObject),
		OPCODE(o6_drawObject),
		OPCODE(o6_drawObjectAt),
		OPCODE(o6_drawBlastObject),
		/* 64 */
		OPCODE(o6_setBlastObjectWindow),
		OPCODE(o6_stopObjectCode),
		OPCODE(o6_stopObjectCode),
		OPCODE(o6_endCutscene),
		/* 68 */
		OPCODE(o6_cutscene),
		OPCODE(o6_stopMusic),
		OPCODE(o6_freezeUnfreeze),
		OPCODE(o6_cursorCommand),
		/* 6C */
		OPCODE(o6_breakHere),
		OPCODE(o6_ifClassOfIs),
		OPCODE(o6_setClass),
		OPCODE(o6_getState),
		/* 70 */
		OPCODE(o6_setState),
		OPCODE(o6_setOwner),
		OPCODE(o6_getOwner),
		OPCODE(o6_jump),
		/* 74 */
		OPCODE(o6_startSound),
		OPCODE(o6_stopSound),
		OPCODE(o6_startMusic),
		OPCODE(o6_stopObjectScript),
		/* 78 */
		OPCODE(o6_panCameraTo),
		OPCODE(o6_actorFollowCamera),
		OPCODE(o6_setCameraAt),
		OPCODE(o6_loadRoom),
		/* 7C */
		OPCODE(o6_stopScript),
		OPCODE(o6_walkActorToObj),
		OPCODE(o6_walkActorTo),
		OPCODE(o6_putActorAtXY),
		/* 80 */
		OPCODE(o6_putActorAtObject),
		OPCODE(o6_faceActor),
		OPCODE(o6_animateActor),
		OPCODE(o6_doSentence),
		/* 84 */
		OPCODE(o6_pickupObject),
		OPCODE(o6_loadRoomWithEgo),
		OPCODE(o6_invalid),
		OPCODE(o6_getRandomNumber),
		/* 88 */
		OPCODE(o6_getRandomNumberRange),
		OPCODE(o6_invalid),
		OPCODE(o6_getActorMoving),
		OPCODE(o6_isScriptRunning),
		/* 8C */
		OPCODE(o6_getActorRoom),
		OPCODE(o6_getObjectX),
		OPCODE(o6_getObjectY),
		OPCODE(o6_getObjectOldDir),
		/* 90 */
		OPCODE(o6_getActorWalkBox),
		OPCODE(o6_getActorCostume),
		OPCODE(o6_findInventory),
		OPCODE(o6_getInventoryCount),
		/* 94 */
		OPCODE(o6_getVerbFromXY),
		OPCODE(o6_beginOverride),
		OPCODE(o6_endOverride),
		OPCODE(o6_setObjectName),
		/* 98 */
		OPCODE(o6_isSoundRunning),
		OPCODE(o6_setBoxFlags),
		OPCODE(o6_createBoxMatrix),
		OPCODE(o6_resourceRoutines),
		/* 9C */
		OPCODE(o6_roomOps),
		OPCODE(o6_actorOps),
		OPCODE(o6_verbOps),
		OPCODE(o6_getActorFromXY),
		/* A0 */
		OPCODE(o6_findObject),
		OPCODE(o6_pseudoRoom),
		OPCODE(o6_getActorElevation),
		OPCODE(o6_getVerbEntrypoint),
		/* A4 */
		OPCODE(o6_arrayOps),
		OPCODE(o6_saveRestoreVerbs),
		OPCODE(o6_drawBox),
		OPCODE(o6_pop),
		/* A8 */
		OPCODE(o6_getActorWidth),
		OPCODE(o6_wait),
		OPCODE(o6_getActorScaleX),
		OPCODE(o6_getActorAnimCounter1),
		/* AC */
		OPCODE(o6_soundKludge),
		OPCODE(o6_isAnyOf),
		OPCODE(o6_quitPauseRestart),
		OPCODE(o6_isActorInBox),
		/* B0 */
		OPCODE(o6_delay),
		OPCODE(o6_delaySeconds),
		OPCODE(o6_delayMinutes),
		OPCODE(o6_stopSentence),
		/* B4 */
		OPCODE(o6_printLine),
		OPCODE(o6_printCursor),
		OPCODE(o6_printDebug),
		OPCODE(o6_printSystem),
		/* B8 */
		OPCODE(o6_printActor),
		OPCODE(o6_printEgo),
		OPCODE(o6_talkActor),
		OPCODE(o6_talkEgo),
		/* BC */
		OPCODE(o6_dimArray),
		OPCODE(o6_dummy),
		OPCODE(o6_startObjectQuick),
		OPCODE(o6_startScriptQuick2),
		/* C0 */
		OPCODE(o6_dim2dimArray),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* C4 */
		OPCODE(o6_abs),
		OPCODE(o6_distObjectObject),
		OPCODE(o6_distObjectPt),
		OPCODE(o6_distPtPt),
		/* C8 */
		OPCODE(o6_kernelGetFunctions),
		OPCODE(o6_kernelSetFunctions),
		OPCODE(o6_delayFrames),
		OPCODE(o6_pickOneOf),
		/* CC */
		OPCODE(o6_pickOneOfDefault),
		OPCODE(o6_stampObject),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* D0 */
		OPCODE(o6_getDateTime),
		OPCODE(o6_stopTalking),
		OPCODE(o6_getAnimateVariable),
		OPCODE(o6_invalid),
		/* D4 */
		OPCODE(o6_shuffle),
		OPCODE(o6_jumpToScript),
		OPCODE(o6_band),
		OPCODE(o6_bor),
		/* D8 */
		OPCODE(o6_isRoomScriptRunning),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* DC */
		OPCODE(o6_invalid),
		OPCODE(o6_findAllObjects),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* E0 */
		OPCODE(o6_invalid),
		OPCODE(o6_getPixel),
		OPCODE(o6_invalid),
		OPCODE(o6_pickVarRandom),
		/* E4 */
		OPCODE(o6_setBoxSet),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* E8 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* EC */
		OPCODE(o6_getActorLayer),
		OPCODE(o6_getObjectNewDir),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* F0 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* F4 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* F8 */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		/* FC */
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
		OPCODE(o6_invalid),
	};

	_opcodesV6 = opcodes;
}

void ScummEngine_v6::executeOpcode(byte i) {
	OpcodeProcV6 op = _opcodesV6[i].proc;
	(this->*op) ();
}

const char *ScummEngine_v6::getOpcodeDesc(byte i) {
	return _opcodesV6[i].desc;
}

int ScummEngine_v6::popRoomAndObj(int *room) {
	int obj;

	if (_version >= 7) {
		obj = pop();
		*room = getObjectRoom(obj);
	} else {
		*room = pop();
		obj = pop();
	}

	return obj;
}

ScummEngine_v6::ArrayHeader *ScummEngine_v6::defineArray(int array, int type, int dim2, int dim1) {
	if (_heversion >= 72)
		error("Call to old defineArray");

	int id;
	int size;
	ArrayHeader *ah;
	
	assert(0 <= type && type <= 5);

	
	if (_heversion >= 60) {
		if (type == kBitArray || type == kNibbleArray)
			type = kByteArray;
	} else {
		// NOTE: The following code turns all arrays except string arrays into
		// integer arrays. There seems to be no reason for this, and it wastes
		// space. However, we can't just remove this either, as that would
		// break savegame compatibility. So do not touch this unless you are
		// also adding code which updated old savegames, too. And of course
		// readArray() and writeArray() would have to be updated, too...
		if (type != kStringArray)
			type = kIntArray;
	}

	nukeArray(array);

	id = findFreeArrayId();

	if (_version == 8) {
		if (array & 0x40000000) {
		}
	
		if (array & 0x80000000) {
			error("Can't define bit variable as array pointer");
		}

		size = (type == kIntArray) ? 4 : 1;
	} else {
		if (array & 0x4000) {
		}
	
		if (array & 0x8000) {
			error("Can't define bit variable as array pointer");
		}

		size = (type == kIntArray) ? 2 : 1;
	}

	writeVar(array, id);

	size *= dim2 + 1;
	size *= dim1 + 1;

	ah = (ArrayHeader *)res.createResource(rtString, id, size + sizeof(ArrayHeader));

	ah->type = TO_LE_16(type);
	ah->dim1 = TO_LE_16(dim1 + 1);
	ah->dim2 = TO_LE_16(dim2 + 1);

	return ah;
}

void ScummEngine_v6::nukeArray(int a) {
	int data;

	data = readVar(a);

	if (data)
		res.nukeResource(rtString, data);
	if (_features & GF_HUMONGOUS)
		_arraySlot[data] = 0;

	writeVar(a, 0);
}

int ScummEngine_v6::findFreeArrayId() {
	byte **addr = res.address[rtString];
	int i;

	for (i = 1; i < _numArray; i++) {
		if (!addr[i])
			return i;
	}
	error("Out of array pointers, %d max", _numArray);
	return -1;
}

#define SWAP16(x)  x = SWAP_BYTES_16(x)

ScummEngine_v6::ArrayHeader *ScummEngine_v6::getArray(int array) {
	ArrayHeader *ah = (ArrayHeader *)getResourceAddress(rtString, readVar(array));
	if (!ah)
		return 0;
	
	// Workaround for a long standing bug where we save array headers in native
	// endianness, instead of a fixed endianness. We try to detect savegames
	// which were created on a big endian system and convert them to little
	// endian.
	if ((FROM_LE_16(ah->dim1) & 0xF000) || (FROM_LE_16(ah->dim2) & 0xF000) || (FROM_LE_16(ah->type) & 0xFF00)) {
		SWAP16(ah->dim1);
		SWAP16(ah->dim2);
		SWAP16(ah->type);
	}
	
	return ah;
}

int ScummEngine_v6::readArray(int array, int idx, int base) {
	if (_heversion >= 72)
		error("Call to old readArray");

	ArrayHeader *ah = getArray(array);

	if (ah == NULL || ah->data == NULL)
		error("readArray: invalid array %d (%d)", array, readVar(array));
	
	// WORKAROUND bug #645711. This is clearly a script bug, as this script
	// excerpt shows nicely:
	// ...
	// [03A7] (5D)         if (isAnyOf(array-447[localvar13][localvar14],[0,4])) {
	// [03BD] (5D)           if ((localvar13 != -1) && (localvar14 != -1)) {
	// [03CF] (B6)             printDebug.begin()
	// ...
	if (_gameId == GID_FT && array == 447 && _currentRoom == 95 && vm.slot[_currentScript].number == 2010 && idx == -1 && base == -1) {
		return 0;
	}

	const int offset = base + idx * FROM_LE_16(ah->dim1);

	if (offset < 0 || offset >= FROM_LE_16(ah->dim1) * FROM_LE_16(ah->dim2)) {
		error("readArray: array %d out of bounds: [%d,%d] exceeds [%d,%d]",
			array, base, idx, FROM_LE_16(ah->dim1), FROM_LE_16(ah->dim2));
	}

	if (FROM_LE_16(ah->type) != kIntArray) {
		return ah->data[offset];
	} else if (_version == 8) {
		return (int32)READ_LE_UINT32(ah->data + offset * 4);
	} else {
		return (int16)READ_LE_UINT16(ah->data + offset * 2);
	}
}

void ScummEngine_v6::writeArray(int array, int idx, int base, int value) {
	if (_heversion >= 72)
		error("Call to old writeArray");

	ArrayHeader *ah = getArray(array);
	if (!ah)
		return;

	const int offset = base + idx * FROM_LE_16(ah->dim1);

	if (offset < 0 || offset >= FROM_LE_16(ah->dim1) * FROM_LE_16(ah->dim2)) {
		error("writeArray: array %d out of bounds: [%d,%d] exceeds [%d,%d]",
			array, base, idx, FROM_LE_16(ah->dim1), FROM_LE_16(ah->dim2));
	}

	if (FROM_LE_16(ah->type) != kIntArray) {
		ah->data[offset] = value;
	} else if (_version == 8) {
		WRITE_LE_UINT32(ah->data + offset * 4, value);
	} else {
		WRITE_LE_UINT16(ah->data + offset * 2, value);
	}
}

void ScummEngine_v6::readArrayFromIndexFile() {
	int num;
	int a, b, c;

	while ((num = _fileHandle->readUint16LE()) != 0) {
		a = _fileHandle->readUint16LE();
		b = _fileHandle->readUint16LE();
		c = _fileHandle->readUint16LE();
		if (c == kBitArray)
			defineArray(num, kBitArray, a, b);
		else
			defineArray(num, kIntArray, a, b);
	}
}

int ScummEngine_v6::getStackList(int *args, uint maxnum) {
	uint num, i;

	for (i = 0; i < maxnum; i++)
		args[i] = 0;

	num = pop();

	if (num > maxnum)
		error("Too many items %d in stack list, max %d", num, maxnum);

	i = num;
	while (i--) {
		args[i] = pop();
	}

	return num;
}

void ScummEngine_v6::o6_pushByte() {
	push(fetchScriptByte());
}

void ScummEngine_v6::o6_pushWord() {
	push(fetchScriptWordSigned());
}

void ScummEngine_v6::o6_pushByteVar() {
	push(readVar(fetchScriptByte()));
}

void ScummEngine_v6::o6_pushWordVar() {
	push(readVar(fetchScriptWord()));
}

void ScummEngine_v6::o6_invalid() {
	error("Invalid opcode '%x' at %x", _opcode, _scriptPointer - _scriptOrgPointer);
}

void ScummEngine_v6::o6_byteArrayRead() {
	int base = pop();
	push(readArray(fetchScriptByte(), 0, base));
}

void ScummEngine_v6::o6_wordArrayRead() {
	int base = pop();
	push(readArray(fetchScriptWord(), 0, base));
}

void ScummEngine_v6::o6_byteArrayIndexedRead() {
	int base = pop();
	int idx = pop();
	push(readArray(fetchScriptByte(), idx, base));
}

void ScummEngine_v6::o6_wordArrayIndexedRead() {
	int base = pop();
	int idx = pop();
	push(readArray(fetchScriptWord(), idx, base));
}

void ScummEngine_v6::o6_dup() {
	int a = pop();
	push(a);
	push(a);
}

void ScummEngine_v6::o6_not() {
	push(pop() == 0);
}

void ScummEngine_v6::o6_eq() {
	push(pop() == pop());
}

void ScummEngine_v6::o6_neq() {
	push(pop() != pop());
}

void ScummEngine_v6::o6_gt() {
	int a = pop();
	push(pop() > a);
}

void ScummEngine_v6::o6_lt() {
	int a = pop();
	push(pop() < a);
}

void ScummEngine_v6::o6_le() {
	int a = pop();
	push(pop() <= a);
}

void ScummEngine_v6::o6_ge() {
	int a = pop();
	push(pop() >= a);
}

void ScummEngine_v6::o6_add() {
	int a = pop();
	push(pop() + a);
}

void ScummEngine_v6::o6_sub() {
	int a = pop();
	push(pop() - a);
}

void ScummEngine_v6::o6_mul() {
	int a = pop();
	push(pop() * a);
}

void ScummEngine_v6::o6_div() {
	int a = pop();
	if (a == 0)
		error("division by zero");
	push(pop() / a);
}

void ScummEngine_v6::o6_land() {
	int a = pop();
	push(pop() && a);
}

void ScummEngine_v6::o6_lor() {
	int a = pop();
	push(pop() || a);
}

void ScummEngine_v6::o6_bor() {
	int a = pop();
	push(pop() | a);
}

void ScummEngine_v6::o6_band() {
	int a = pop();
	push(pop() & a);
}

void ScummEngine_v6::o6_pop() {
	pop();
}

void ScummEngine_v6::o6_writeByteVar() {
	writeVar(fetchScriptByte(), pop());
}

void ScummEngine_v6::o6_writeWordVar() {
	writeVar(fetchScriptWord(), pop());
}

void ScummEngine_v6::o6_byteArrayWrite() {
	int a = pop();
	writeArray(fetchScriptByte(), 0, pop(), a);
}

void ScummEngine_v6::o6_wordArrayWrite() {
	int a = pop();
	writeArray(fetchScriptWord(), 0, pop(), a);
}

void ScummEngine_v6::o6_byteArrayIndexedWrite() {
	int val = pop();
	int base = pop();
	writeArray(fetchScriptByte(), pop(), base, val);
}

void ScummEngine_v6::o6_wordArrayIndexedWrite() {
	int val = pop();
	int base = pop();
	writeArray(fetchScriptWord(), pop(), base, val);
}

void ScummEngine_v6::o6_byteVarInc() {
	int var = fetchScriptByte();
	writeVar(var, readVar(var) + 1);
}

void ScummEngine_v6::o6_wordVarInc() {
	int var = fetchScriptWord();
	writeVar(var, readVar(var) + 1);
}

void ScummEngine_v6::o6_byteArrayInc() {
	int var = fetchScriptByte();
	int base = pop();
	writeArray(var, 0, base, readArray(var, 0, base) + 1);
}

void ScummEngine_v6::o6_wordArrayInc() {
	int var = fetchScriptWord();
	int base = pop();
	writeArray(var, 0, base, readArray(var, 0, base) + 1);
}

void ScummEngine_v6::o6_byteVarDec() {
	int var = fetchScriptByte();
	writeVar(var, readVar(var) - 1);
}

void ScummEngine_v6::o6_wordVarDec() {
	int var = fetchScriptWord();
	writeVar(var, readVar(var) - 1);
}

void ScummEngine_v6::o6_byteArrayDec() {
	int var = fetchScriptByte();
	int base = pop();
	writeArray(var, 0, base, readArray(var, 0, base) - 1);
}

void ScummEngine_v6::o6_wordArrayDec() {
	int var = fetchScriptWord();
	int base = pop();
	writeArray(var, 0, base, readArray(var, 0, base) - 1);
}

void ScummEngine_v6::o6_if() {
	if (pop())
		o6_jump();
	else
		fetchScriptWord();
}

void ScummEngine_v6::o6_ifNot() {
	if (!pop())
		o6_jump();
	else
		fetchScriptWord();
}

void ScummEngine_v6::o6_jump() {
	int offset = fetchScriptWordSigned();
	_scriptPointer += offset;
}

void ScummEngine_v6::o6_startScript() {
	int args[25];
	int script, flags;

	getStackList(args, ARRAYSIZE(args));
	script = pop();
	flags = pop();
	
	// WORKAROUND bug #556558: At Dino Bungee National Memorial, the buttons for
	// the Wally and Rex dinosaurs will always restart their speech, instead of 
	// stopping and starting their speech. This was a script bug in the original 
	// game.
	if (_gameId == GID_SAMNMAX && _roomResource == 59 &&
		vm.slot[_currentScript].number == 201 && script == 48) {
		o6_breakHere();
	}

	// WORKAROUND bug #903223: In Puerto Pollo, if you have Guybrush examine
	// the church clock, he'll read out the current time. Nice touch, only that
	// it sounds crap in the german version (and maybe others, too). It seems
	// the original engine of the german version played just a simple fixed
	// text in this spot, for the above reason. Since the data files are
	// unchanged, it must have been an engine hack job. No idea how they did
	// it exactly, but this here is how we do it :-)
	if (_gameId == GID_CMI && script == 204 &&
		_currentRoom == 15 && vm.slot[_currentScript].number == 421 &&
		_language == Common::DE_DEU) {

		_actorToPrintStrFor = 1;
		_string[0].loadDefault();
		actorTalk((const byte *)"/VDSO325/Whoa! Look at the time. Gotta scoot.");

		return;
	}
	
	runScript(script, (flags & 1) != 0, (flags & 2) != 0, args);
}

void ScummEngine_v6::o6_jumpToScript() {
	int args[25];
	int script, flags;

	getStackList(args, ARRAYSIZE(args));
	script = pop();
	flags = pop();
	stopObjectCode();
	runScript(script, (flags & 1) != 0, (flags & 2) != 0, args);
}

void ScummEngine_v6::o6_startScriptQuick() {
	int args[25];
	int script;
	getStackList(args, ARRAYSIZE(args));
	script = pop();
	runScript(script, 0, 0, args);
}

void ScummEngine_v6::o6_startScriptQuick2() {
	int args[25];
	int script;
	getStackList(args, ARRAYSIZE(args));
	script = pop();
	runScript(script, 0, 1, args);
}

void ScummEngine_v6::o6_startObject() {
	int args[25];
	int script, entryp;
	int flags;
	getStackList(args, ARRAYSIZE(args));
	entryp = pop();
	script = pop();
	flags = pop();
	runObjectScript(script, entryp, (flags & 1) != 0, (flags & 2) != 0, args);
}

void ScummEngine_v6::o6_startObjectQuick() {
	int args[25];
	int script, entryp;
	getStackList(args, ARRAYSIZE(args));
	entryp = pop();
	script = pop();
	runObjectScript(script, entryp, 0, 1, args);
}

void ScummEngine_v6::o6_drawObject() {
	int state = pop();
	int obj = pop();

	// This is based on disassembly
	if (state == 0)
		state = 1;

	setObjectState(obj, state, -1, -1);
}

void ScummEngine_v6::o6_drawObjectAt() {
	int y = pop();
	int x = pop();
	int obj = pop();
	setObjectState(obj, 1, x, y);
}

void ScummEngine_v6::o6_stopObjectCode() {
	stopObjectCode();
}

void ScummEngine_v6::o6_endCutscene() {
	endCutscene();
}

void ScummEngine_v6::o6_cutscene() {
	int args[25];
	getStackList(args, ARRAYSIZE(args));
	beginCutscene(args);
}

void ScummEngine_v6::o6_stopMusic() {
	_sound->stopAllSounds();
}

void ScummEngine_v6::o6_freezeUnfreeze() {
	int a = pop();

	if (a)
		freezeScripts(a);
	else
		unfreezeScripts();
}

void ScummEngine_v6::o6_cursorCommand() {
	int a, i;
	int args[16];
	int subOp = fetchScriptByte();

	switch (subOp) {
	case 0x90:		// SO_CURSOR_ON Turn cursor on
		_cursor.state = 1;
		verbMouseOver(0);
		break;
	case 0x91:		// SO_CURSOR_OFF Turn cursor off
		_cursor.state = 0;
		verbMouseOver(0);
		break;
	case 0x92:		// SO_USERPUT_ON
		_userPut = 1;
		break;
	case 0x93:		// SO_USERPUT_OFF
		_userPut = 0;
		break;
	case 0x94:		// SO_CURSOR_SOFT_ON Turn soft cursor on
		_cursor.state++;
		if (_cursor.state > 1)
			error("Cursor state greater than 1 in script");
		verbMouseOver(0);
		break;
	case 0x95:		// SO_CURSOR_SOFT_OFF Turn soft cursor off
		_cursor.state--;
		verbMouseOver(0);
		break;
	case 0x96:		// SO_USERPUT_SOFT_ON
		_userPut++;
		break;
	case 0x97:		// SO_USERPUT_SOFT_OFF
		_userPut--;
		break;
	case 0x99: 		// SO_CURSOR_IMAGE Set cursor image
		{
			int room, obj;
			if (_heversion >= 70) {
				obj = pop();
				room = getObjectRoom(obj);
			} else {
				obj = popRoomAndObj(&room);
			}
			setCursorFromImg(obj, room, 1);
			break;
		}
	case 0x9A:		// SO_CURSOR_HOTSPOT Set cursor hotspot
		a = pop();
		setCursorHotspot(pop(), a);
		break;
	case 0x9C:		// SO_CHARSET_SET
		initCharset(pop());
		break;
	case 0x9D:		// SO_CHARSET_COLOR
		getStackList(args, ARRAYSIZE(args));
		for (i = 0; i < 16; i++)
			_charsetColorMap[i] = _charsetData[_string[1]._default.charset][i] = (unsigned char)args[i];
		break;
	case 0xD6:		// SO_CURSOR_TRANSPARENT Set cursor transparent color
		setCursorTransparency(pop());
		break;
	default:
		error("o6_cursorCommand: default case %x", subOp);
	}

	VAR(VAR_CURSORSTATE) = _cursor.state;
	VAR(VAR_USERPUT) = _userPut;
}

void ScummEngine_v6::o6_breakHere() {
	updateScriptPtr();
	_currentScript = 0xFF;
}

void ScummEngine_v6::o6_ifClassOfIs() {
	int args[16];
	int num, obj, cls;
	bool b;
	int cond = 1;

	num = getStackList(args, ARRAYSIZE(args));
	obj = pop();

	if (_heversion >= 80 && num == 0) {
		push(_classData[obj]);
		return;
	}

	while (--num >= 0) {
		cls = args[num];
		b = getClass(obj, cls);
		if ((cls & 0x80 && !b) || (!(cls & 0x80) && b))
			cond = 0;
	}
	push(cond);
}

void ScummEngine_v6::o6_setClass() {
	int args[16];
	int num, obj, cls;

	num = getStackList(args, ARRAYSIZE(args));
	obj = pop();

	while (--num >= 0) {
		cls = args[num];
		if (cls == 0)
			_classData[num] = 0;
		else if (cls & 0x80)
			putClass(obj, cls, 1);
		else
			putClass(obj, cls, 0);
	}
}

void ScummEngine_v6::o6_getState() {
	push(getState(pop()));
}

void ScummEngine_v6::o6_setState() {
	int state = pop();
	int obj = pop();

	putState(obj, state);
	markObjectRectAsDirty(obj);
	if (_bgNeedsRedraw)
		clearDrawObjectQueue();
}

void ScummEngine_v6::o6_setOwner() {
	int owner = pop();
	int obj = pop();
	setOwnerOf(obj, owner);
}

void ScummEngine_v6::o6_getOwner() {
	push(getOwner(pop()));
}

void ScummEngine_v6::o6_startSound() {
	int offset = 0;

	// In Fatty Bear's Birthday Surprise the piano uses offsets 1 - 23 to
	// indicate which note to play, but only when using the standard piano
	// sound. See also o6_soundOps()
	if ((_features & GF_HUMONGOUS) && (_gameId != GID_PUTTDEMO))
		offset = pop();
		
	if (_features & GF_DIGI_IMUSE)
		_imuseDigital->startSfx(pop(), 64);
	else 
		_sound->addSoundToQueue(pop(), offset);
}

void ScummEngine_v6::o6_stopSound() {
	_sound->stopSound(pop());
}

void ScummEngine_v6::o6_startMusic() {
	if (_features & GF_DIGI_IMUSE)
		error("o6_startMusic() It shouldn't be called here for imuse digital");

	_sound->addSoundToQueue(pop());
}

void ScummEngine_v6::o6_stopObjectScript() {
	stopObjectScript(pop());
}

void ScummEngine_v6::o6_panCameraTo() {
	if (_version >= 7) {
		int y = pop();
		int x = pop();
		panCameraTo(x, y);
	} else {
		panCameraTo(pop(), 0);
	}
}

void ScummEngine_v6::o6_actorFollowCamera() {
	if (_version >= 7)
		setCameraFollows(derefActor(pop(), "actorFollowCamera"));
	else
		actorFollowCamera(pop());
}

void ScummEngine_v6::o6_setCameraAt() {
	if (_version >= 7) {
		int x, y;

		camera._follows = 0;
		VAR(VAR_CAMERA_FOLLOWED_ACTOR) = 0;

		y = pop();
		x = pop();

		setCameraAt(x, y);
	} else {
		setCameraAtEx(pop());
	}
}

void ScummEngine_v6::o6_loadRoom() {
	int room = pop();
	startScene(room, 0, 0);
	if (_features & GF_HUMONGOUS) {
		setCameraAt(camera._cur.x, 0);
	}
	_fullRedraw = 1;
}

void ScummEngine_v6::o6_stopScript() {
	int script = pop();
	if (script == 0)
		stopObjectCode();
	else
		stopScript(script);
}

void ScummEngine_v6::o6_walkActorToObj() {
	int act, obj, dist;
	Actor *a, *a2;
	int x, y;

	dist = pop();
	obj = pop();
	act = pop();
	a = derefActor(act, "o6_walkActorToObj");

	if (obj >= _numActors) {
		int wio = whereIsObject(obj);

		if (wio != WIO_FLOBJECT && wio != WIO_ROOM)
			return;

		int dir;
		getObjectXYPos(obj, x, y, dir);
		a->startWalkActor(x, y, dir);
	} else {
		a2 = derefActorSafe(obj, "o6_walkActorToObj(2)");
		if (_gameId == GID_SAMNMAX && a2 == 0) {
			// FIXME: This is a hack to work around bug #742676 SAM: Fish Farm.
			// Note quite sure why it happens, though, if it's normal or due to
			// a bug in the ScummVM code.
			warning("o6_walkActorToObj: invalid actor %d", obj);
			return;
		}
		if (!a->isInCurrentRoom() || !a2->isInCurrentRoom())
			return;
		if (dist == 0) {
			dist = a2->_scalex * a2->_width / 0xFF;
			dist += dist / 2;
		}
		x = a2->_pos.x;
		y = a2->_pos.y;
		if (x < a->_pos.x)
			x += dist;
		else
			x -= dist;
		a->startWalkActor(x, y, -1);
	}
}

void ScummEngine_v6::o6_walkActorTo() {
	int x, y;
	y = pop();
	x = pop();
	Actor *a = derefActor(pop(), "o6_walkActorTo");
	a->startWalkActor(x, y, -1);
}

void ScummEngine_v6::o6_putActorAtXY() {
	int room, x, y, act;
	Actor *a;

	room = pop();
	y = pop();
	x = pop();
	act = pop();
	a = derefActor(act, "o6_putActorAtXY");

	if (room == 0xFF || room == 0x7FFFFFFF) {
		room = a->_room;
	} else {
		if (a->_visible && _currentRoom != room && getTalkingActor() == a->_number) {
			stopTalk();
		}
		if (room != 0)
			a->_room = room;
	}
	a->putActor(x, y, room);
}


void ScummEngine_v6::o6_putActorAtObject() {
	int room, obj, x, y;
	Actor *a;

	obj = popRoomAndObj(&room);

	a = derefActor(pop(), "o6_putActorAtObject");
	if (whereIsObject(obj) != WIO_NOT_FOUND) {
		getObjectXYPos(obj, x, y);
	} else {
		x = 160;
		y = 120;
	}
	if (room == 0xFF)
		room = a->_room;
	a->putActor(x, y, room);
}

void ScummEngine_v6::o6_faceActor() {
	int obj = pop();
	Actor *a = derefActor(pop(), "o6_faceActor");
	a->faceToObject(obj);
}

void ScummEngine_v6::o6_animateActor() {
	int anim = pop();
	int act = pop();
	if (_gameId == GID_TENTACLE && _roomResource == 57 &&
		vm.slot[_currentScript].number == 19 && act == 593) {
		// FIXME: This very odd case (animateActor(593,250)) occurs in DOTT, in the
		// cutscene after George cuts down the "cherry tree" and the tree Laverne
		// is trapped in vanishes... see bug #743363.
		// Not sure if this means animateActor somehow also must work for objects
		// (593 is the time machine in room 57), or if this is simply a script bug.
		act = 6;
	}
	Actor *a = derefActor(act, "o6_animateActor");
	a->animateActor(anim);
}

void ScummEngine_v6::o6_doSentence() {
	int verb, objectA, objectB, dummy = 0;

	objectB = pop();
	if (_version < 8)
		dummy = pop();	// dummy pop (in Sam&Max, seems to be always 0 or 130)
	objectA = pop();
	verb = pop();

	doSentence(verb, objectA, objectB);
}

void ScummEngine_v6::o6_pickupObject() {
	int obj, room;
	int i;

	obj = popRoomAndObj(&room);
	if (room == 0)
		room = _roomResource;

	for (i = 0; i < _numInventory; i++) {
		if (_inventory[i] == (uint16)obj) {
			putOwner(obj, VAR(VAR_EGO));
			runInventoryScript(obj);
			return;
		}
	}

	addObjectToInventory(obj, room);
	putOwner(obj, VAR(VAR_EGO));
	putClass(obj, kObjectClassUntouchable, 1);
	putState(obj, 1);
	markObjectRectAsDirty(obj);
	clearDrawObjectQueue();
	runInventoryScript(obj);									/* Difference */
}

void ScummEngine_v6::o6_loadRoomWithEgo() {
	Actor *a;
	int obj, room, x, y;

	y = pop();
	x = pop();

	obj = popRoomAndObj(&room);

	a = derefActor(VAR(VAR_EGO), "o6_loadRoomWithEgo");
	a->putActor(0, 0, room);
	_egoPositioned = false;

	if (VAR_WALKTO_OBJ != 0xFF)
		VAR(VAR_WALKTO_OBJ) = obj;
	startScene(a->_room, a, obj);
	if (VAR_WALKTO_OBJ != 0xFF)
		VAR(VAR_WALKTO_OBJ) = 0;

	if (_version == 6) {
		camera._cur.x = camera._dest.x = a->_pos.x;
		setCameraFollows(a);
	}

	_fullRedraw = 1;

	if (x != -1 && x != 0x7FFFFFFF) {
		a->startWalkActor(x, y, -1);
	}
}

void ScummEngine_v6::o6_getRandomNumber() {
	int rnd;
	rnd = _rnd.getRandomNumber(pop());
	if (VAR_RANDOM_NR != 0xFF)
		VAR(VAR_RANDOM_NR) = rnd;
	push(rnd);
}

void ScummEngine_v6::o6_getRandomNumberRange() {
	int max = pop();
	int min = pop();
	int rnd = _rnd.getRandomNumberRng(min, max);
	if (VAR_RANDOM_NR != 0xFF)
		VAR(VAR_RANDOM_NR) = rnd;
	push(rnd);
}

void ScummEngine_v6::o6_isScriptRunning() {
	push(isScriptRunning(pop()));
}

void ScummEngine_v6::o6_isRoomScriptRunning() {
	push(isRoomScriptRunning(pop()));
}

void ScummEngine_v6::o6_getActorMoving() {
	Actor *a = derefActor(pop(), "o6_getActorMoving");
	push(a->_moving);
}

void ScummEngine_v6::o6_getActorRoom() {
	int act = pop();

	if (act == 0) {
		// This case occurs at the very least in COMI. That's because in COMI's script 28,
		// there is a check which looks as follows:
		//   if (((VAR_TALK_ACTOR != 0) && (VAR_HAVE_MSG == 1)) &&
		//        (getActorRoom(VAR_TALK_ACTOR) == VAR_ROOM))
		// Due to the way this is represented in bytecode, the engine cannot
		// short circuit. Hence, even though this would be perfectly fine code
		// in C/C++, here it can (and does) lead to getActorRoom(0) being
		// invoked. We silently ignore this.
		push(0);
		return;
	}

	if (act == 255) {
		// This case also occurs in COMI...
		push(0);
		return;
	}

	Actor *a = derefActor(act, "o6_getActorRoom");
	push(a->_room);
}

void ScummEngine_v6::o6_getActorWalkBox() {
	Actor *a = derefActor(pop(), "o6_getActorWalkBox");
	push(a->_ignoreBoxes ? 0 : a->_walkbox);
}

void ScummEngine_v6::o6_getActorCostume() {
	Actor *a = derefActor(pop(), "o6_getActorCostume");
	push(a->_costume);
}

void ScummEngine_v6::o6_getActorElevation() {
	Actor *a = derefActor(pop(), "o6_getActorElevation");
	push(a->getElevation());
}

void ScummEngine_v6::o6_getActorWidth() {
	Actor *a = derefActor(pop(), "o6_getActorWidth");
	push(a->_width);
}

void ScummEngine_v6::o6_getActorScaleX() {
	Actor *a = derefActor(pop(), "o6_getActorScale");
	push(a->_scalex);
}

void ScummEngine_v6::o6_getActorAnimCounter1() {
	Actor *a = derefActor(pop(), "o6_getActorAnimCounter");
	push(a->_cost.animCounter);
}

void ScummEngine_v6::o6_getAnimateVariable() {
	int var = pop();
	Actor *a = derefActor(pop(), "o6_getAnimateVariable");
	push(a->getAnimVar(var));
}

void ScummEngine_v6::o6_isActorInBox() {
	int box = pop();
	Actor *a = derefActor(pop(), "o6_isActorInBox");
	push(checkXYInBoxBounds(box, a->_pos.x, a->_pos.y));
}

void ScummEngine_v6::o6_getActorLayer() {
	Actor *a = derefActor(pop(), "getActorLayer");
	push(a->_layer);
}

void ScummEngine_v6::o6_getObjectX() {
	push(getObjX(pop()));
}

void ScummEngine_v6::o6_getObjectY() {
	push(getObjY(pop()));
}

void ScummEngine_v6::o6_getObjectOldDir() {
	push(getObjOldDir(pop()));
}

void ScummEngine_v6::o6_getObjectNewDir() {
	push(getObjNewDir(pop()));
}

void ScummEngine_v6::o6_findInventory() {
	int idx = pop();
	int owner = pop();
	push(findInventory(owner, idx));
}

void ScummEngine_v6::o6_getInventoryCount() {
	push(getInventoryCount(pop()));
}

void ScummEngine_v6::o6_getVerbFromXY() {
	int y = pop();
	int x = pop();
	int over = findVerbAtPos(x, y);
	if (over)
		over = _verbs[over].verbid;
	push(over);
}

void ScummEngine_v6::o6_beginOverride() {
	beginOverride();
}

void ScummEngine_v6::o6_endOverride() {
	endOverride();
}

void ScummEngine_v6::o6_setObjectName() {
	int obj = pop();
	setObjectName(obj);
}

void ScummEngine_v6::o6_isSoundRunning() {
	int snd = pop();

	if (snd)
		snd = _sound->isSoundRunning(snd);

	push(snd);
}

void ScummEngine_v6::o6_setBoxFlags() {
	int table[65];
	int num, value;

	value = pop();
	num = getStackList(table, ARRAYSIZE(table));

	while (--num >= 0) {
		setBoxFlags(table[num], value);
	}
}

void ScummEngine_v6::o6_createBoxMatrix() {
	createBoxMatrix();

	if ((_gameId == GID_DIG) || (_gameId == GID_CMI))
		putActors();
}

void ScummEngine_v6::o6_resourceRoutines() {
	int resid, op;
	op = fetchScriptByte();

	switch (op) {
	case 100:		// SO_LOAD_SCRIPT
		resid = pop();
		if (_version >= 7)
			if (resid >= _numGlobalScripts)
				break;
		ensureResourceLoaded(rtScript, resid);
		break;
	case 101:		// SO_LOAD_SOUND
		resid = pop();
		ensureResourceLoaded(rtSound, resid);
		break;
	case 102:		// SO_LOAD_COSTUME
		resid = pop();
		ensureResourceLoaded(rtCostume, resid);
		break;
	case 103:		// SO_LOAD_ROOM
		resid = pop();
		ensureResourceLoaded(rtRoom, resid);
		break;
	case 104:		// SO_NUKE_SCRIPT
		resid = pop();
		if (_version >= 7)
			if (resid >= _numGlobalScripts)
				break;
		res.setResourceCounter(rtScript, resid, 0x7F);
		break;
	case 105:		// SO_NUKE_SOUND
		resid = pop();
		res.setResourceCounter(rtSound, resid, 0x7F);
		break;
	case 106:		// SO_NUKE_COSTUME
		resid = pop();
		res.setResourceCounter(rtCostume, resid, 0x7F);
		break;
	case 107:		// SO_NUKE_ROOM
		resid = pop();
		res.setResourceCounter(rtRoom, resid, 0x7F);
		break;
	case 108:		// SO_LOCK_SCRIPT
		resid = pop();
		if (resid >= _numGlobalScripts)
			break;
		res.lock(rtScript, resid);
		break;
	case 109:		// SO_LOCK_SOUND
		resid = pop();
		res.lock(rtSound, resid);
		break;
	case 110:		// SO_LOCK_COSTUME
		resid = pop();
		res.lock(rtCostume, resid);
		break;
	case 111:		// SO_LOCK_ROOM
		resid = pop();
		if (resid > 0x7F)
			resid = _resourceMapper[resid & 0x7F];
		res.lock(rtRoom, resid);
		break;
	case 112:		// SO_UNLOCK_SCRIPT
		resid = pop();
		if (resid >= _numGlobalScripts)
			break;
		res.unlock(rtScript, resid);
		break;
	case 113:		// SO_UNLOCK_SOUND
		resid = pop();
		res.unlock(rtSound, resid);
		break;
	case 114:		// SO_UNLOCK_COSTUME
		resid = pop();
		res.unlock(rtCostume, resid);
		break;
	case 115:		// SO_UNLOCK_ROOM
		resid = pop();
		if (resid > 0x7F)
			resid = _resourceMapper[resid & 0x7F];
		res.unlock(rtRoom, resid);
		break;
	case 116:		// SO_CLEAR_HEAP
		/* this is actually a scumm message */
		error("clear heap not working yet");
		break;
	case 117:		// SO_LOAD_CHARSET
		resid = pop();
		loadCharset(resid);
		break;
	case 118:		// SO_NUKE_CHARSET
		resid = pop();
		nukeCharset(resid);
		break;
	case 119:		// SO_LOAD_OBJECT
		{
			int room, obj = popRoomAndObj(&room);
			loadFlObject(obj, room);
			break;
		}
	default:
		error("o6_resourceRoutines: default case %d", op);
	}
}


void ScummEngine_v6::o6_roomOps() {
	int a, b, c, d, e;
	byte op;

	op = fetchScriptByte();

	switch (op) {
	case 172:		// SO_ROOM_SCROLL
		b = pop();
		a = pop();
		if (a < (_screenWidth / 2))
			a = (_screenWidth / 2);
		if (b < (_screenWidth / 2))
			b = (_screenWidth / 2);
		if (a > _roomWidth - (_screenWidth / 2))
			a = _roomWidth - (_screenWidth / 2);
		if (b > _roomWidth - (_screenWidth / 2))
			b = _roomWidth - (_screenWidth / 2);
		VAR(VAR_CAMERA_MIN_X) = a;
		VAR(VAR_CAMERA_MAX_X) = b;
		break;

	case 174:		// SO_ROOM_SCREEN
		b = pop();
		a = pop();
		initScreens(a, b);
		break;

	case 175:		// SO_ROOM_PALETTE
		d = pop();
		c = pop();
		b = pop();
		a = pop();
		setPalColor(d, a, b, c);
		break;

	case 176:		// SO_ROOM_SHAKE_ON
		setShake(1);
		break;

	case 177:		// SO_ROOM_SHAKE_OFF
		setShake(0);
		break;

	case 179:		// SO_ROOM_INTENSITY
		c = pop();
		b = pop();
		a = pop();
		darkenPalette(a, a, a, b, c);
		break;

	case 180:		// SO_ROOM_SAVEGAME
		_saveTemporaryState = true;
		_saveLoadSlot = pop();
		_saveLoadFlag = pop();
		if (_gameId == GID_TENTACLE)
			_saveSound = (_saveLoadSlot != 0);
		break;

	case 181:		// SO_ROOM_FADE
		a = pop();
		if (a) {
			_switchRoomEffect = (byte)(a & 0xFF);
			_switchRoomEffect2 = (byte)(a >> 8);
		} else {
			fadeIn(_newEffect);
		}
		break;

	case 182:		// SO_RGB_ROOM_INTENSITY
		e = pop();
		d = pop();
		c = pop();
		b = pop();
		a = pop();
		darkenPalette(a, b, c, d, e);
		break;

	case 183:		// SO_ROOM_SHADOW
		e = pop();
		d = pop();
		c = pop();
		b = pop();
		a = pop();
		setupShadowPalette(a, b, c, d, e, 0, 256);
		break;

	case 184:		// SO_SAVE_STRING
		error("save string not implemented");
		break;

	case 185:		// SO_LOAD_STRING
		error("load string not implemented");
		break;

	case 186:		// SO_ROOM_TRANSFORM
		d = pop();
		c = pop();
		b = pop();
		a = pop();
		palManipulateInit(a, b, c, d);
		break;

	case 187:		// SO_CYCLE_SPEED
		b = pop();
		a = pop();
		checkRange(16, 1, a, "o6_roomOps: 187: color cycle out of range (%d)");
		_colorCycle[a - 1].delay = (b != 0) ? 0x4000 / (b * 0x4C) : 0;
		break;

	case 213:		// SO_ROOM_NEW_PALETTE
		a = pop();

		// This opcode is used when turning off noir mode in Sam & Max,
		// but since our implementation of this feature doesn't change
		// the original palette there's no need to reload it. Doing it
		// this way, we avoid some graphics glitches that the original
		// interpreter had.

		if (_gameId == GID_SAMNMAX && vm.slot[_currentScript].number == 64)
			setDirtyColors(0, 255);
		else
			setPalette(a);
		break;
	default:
		error("o6_roomOps: default case %d", op);
	}
}

void ScummEngine_v6::o6_actorOps() {
	Actor *a;
	int i, j, k;
	int args[8];
	byte subOp;

	subOp = fetchScriptByte();
	if (subOp == 197) {
		_curActor = pop();
		return;
	}

	a = derefActorSafe(_curActor, "o6_actorOps");
	if (!a)
		return;

	switch (subOp) {
	case 76:		// SO_COSTUME
		a->setActorCostume(pop());
		break;
	case 77:		// SO_STEP_DIST
		j = pop();
		i = pop();
		a->setActorWalkSpeed(i, j);
		break;
	case 78:		// SO_SOUND
		k = getStackList(args, ARRAYSIZE(args));
		for (i = 0; i < k; i++)
			a->_sound[i] = args[i];
		break;
	case 79:		// SO_WALK_ANIMATION
		a->_walkFrame = pop();
		break;
	case 80:		// SO_TALK_ANIMATION
		a->_talkStopFrame = pop();
		a->_talkStartFrame = pop();
		break;
	case 81:		// SO_STAND_ANIMATION
		a->_standFrame = pop();
		break;
	case 82:		// SO_ANIMATION
		// dummy case in scumm6
		pop();
		pop();
		pop();
		break;
	case 83:		// SO_DEFAULT
		a->initActor(0);
		break;
	case 84:		// SO_ELEVATION
		a->setElevation(pop());
		break;
	case 85:		// SO_ANIMATION_DEFAULT
		a->_initFrame = 1;
		a->_walkFrame = 2;
		a->_standFrame = 3;
		a->_talkStartFrame = 4;
		a->_talkStopFrame = 5;
		break;
	case 86:		// SO_PALETTE
		j = pop();
		i = pop();
		checkRange(255, 0, i, "Illegal palette slot %d");
		a->setPalette(i, j);
		break;
	case 87:		// SO_TALK_COLOR
		a->_talkColor = pop();
		break;
	case 88:		// SO_ACTOR_NAME
		loadPtrToResource(rtActorName, a->_number, NULL);
		break;
	case 89:		// SO_INIT_ANIMATION
		a->_initFrame = pop();
		break;
	case 91:		// SO_ACTOR_WIDTH
		a->_width = pop();
		break;
	case 92:		// SO_SCALE
		i = pop();
		a->setScale(i, i);
		break;
	case 93:		// SO_NEVER_ZCLIP
		a->_forceClip = 0;
		break;
	case 225:		// SO_ALWAYS_ZCLIP
	case 94:		// SO_ALWAYS_ZCLIP
		a->_forceClip = pop();
		break;
	case 95:		// SO_IGNORE_BOXES
		a->_ignoreBoxes = 1;
		a->_forceClip = (_version >= 7) ? 100 : 0;
		if (a->isInCurrentRoom())
			a->putActor(a->_pos.x, a->_pos.y, a->_room);
		break;
	case 96:		// SO_FOLLOW_BOXES
		a->_ignoreBoxes = 0;
		a->_forceClip = (_version >= 7) ? 100 : 0;
		if (a->isInCurrentRoom())
			a->putActor(a->_pos.x, a->_pos.y, a->_room);
		break;
	case 97:		// SO_ANIMATION_SPEED
		a->setAnimSpeed(pop());
		break;
	case 98:		// SO_SHADOW
		a->_shadowMode = pop();
		break;
	case 99:		// SO_TEXT_OFFSET
		a->_talkPosY = pop();
		a->_talkPosX = pop();
		break;
	case 198:		// SO_ACTOR_VARIABLE
		i = pop();
		a->setAnimVar(pop(), i);
		break;
	case 215:		// SO_ACTOR_IGNORE_TURNS_ON
		a->_ignoreTurns = true;
		break;
	case 216:		// SO_ACTOR_IGNORE_TURNS_OFF
		a->_ignoreTurns = false;
		break;
	case 217:		// SO_ACTOR_NEW
		a->initActor(2);
		break;
	case 227:		// SO_ACTOR_DEPTH
		a->_layer = pop();
		break;
	case 228:		// SO_ACTOR_WALK_SCRIPT
		a->_walkScript = pop();
		break;
	case 229:		// SO_ACTOR_STOP
		a->stopActorMoving();
		a->startAnimActor(a->_standFrame);
		break;
	case 230:										/* set direction */
		a->_moving &= ~MF_TURN;
		a->setDirection(pop());
		break;
	case 231:										/* turn to direction */
		a->turnToDirection(pop());
		break;
	case 233:		// SO_ACTOR_WALK_PAUSE
		a->_moving |= MF_FROZEN;
		break;
	case 234:		// SO_ACTOR_WALK_RESUME
		a->_moving &= ~MF_FROZEN;
		break;
	case 235:		// SO_ACTOR_TALK_SCRIPT
		a->_talkScript = pop();
		break;
	default:
		error("o6_actorOps: default case %d", subOp);
	}
}

void ScummEngine_v6::o6_verbOps() {
	int slot, a, b;
	VerbSlot *vs;
	byte op;

	op = fetchScriptByte();
	if (op == 196) {
		_curVerb = pop();
		_curVerbSlot = getVerbSlot(_curVerb, 0);
		checkRange(_numVerbs - 1, 0, _curVerbSlot, "Illegal new verb slot %d");
		return;
	}
	vs = &_verbs[_curVerbSlot];
	slot = _curVerbSlot;
	switch (op) {
	case 124:		// SO_VERB_IMAGE
		a = pop();
		if (_curVerbSlot) {
			setVerbObject(_roomResource, a, slot);
			vs->type = kImageVerbType;
			if (_heversion >= 60)
				vs->imgindex = a;
		}
		break;
	case 125:		// SO_VERB_NAME
		loadPtrToResource(rtVerb, slot, NULL);
		vs->type = kTextVerbType;
		vs->imgindex = 0;
		break;
	case 126:		// SO_VERB_COLOR
		vs->color = pop();
		break;
	case 127:		// SO_VERB_HICOLOR
		vs->hicolor = pop();
		break;
	case 128:		// SO_VERB_AT
		vs->curRect.top = pop();
		vs->curRect.left = pop();
		break;
	case 129:		// SO_VERB_ON
		vs->curmode = 1;
		break;
	case 130:		// SO_VERB_OFF
		vs->curmode = 0;
		break;
	case 131:		// SO_VERB_DELETE
		if (_features & GF_HUMONGOUS)
			slot = getVerbSlot(pop(), 0);
		killVerb(slot);
		break;
	case 132:		// SO_VERB_NEW
		slot = getVerbSlot(_curVerb, 0);
		if (slot == 0) {
			for (slot = 1; slot < _numVerbs; slot++) {
				if (_verbs[slot].verbid == 0)
					break;
			}
			if (slot == _numVerbs)
				error("Too many verbs");
			_curVerbSlot = slot;
		}
		vs = &_verbs[slot];
		vs->verbid = _curVerb;
		vs->color = 2;
		vs->hicolor = 0;
		vs->dimcolor = 8;
		vs->type = kTextVerbType;
		vs->charset_nr = _string[0]._default.charset;
		vs->curmode = 0;
		vs->saveid = 0;
		vs->key = 0;
		vs->center = 0;
		vs->imgindex = 0;
		break;
	case 133:		// SO_VERB_DIMCOLOR
		vs->dimcolor = pop();
		break;
	case 134:		// SO_VERB_DIM
		vs->curmode = 2;
		break;
	case 135:		// SO_VERB_KEY
		vs->key = pop();
		break;
	case 136:		// SO_VERB_CENTER
		vs->center = 1;
		break;
	case 137:		// SO_VERB_NAME_STR
		a = pop();
		if (a == 0) {
			loadPtrToResource(rtVerb, slot, (const byte *)"");
		} else {
			loadPtrToResource(rtVerb, slot, getStringAddress(a));
		}
		vs->type = kTextVerbType;
		vs->imgindex = 0;
		break;
	case 139:		// SO_VERB_IMAGE_IN_ROOM
		b = pop();
		a = pop();

		if (slot && a != vs->imgindex) {
			setVerbObject(b, a, slot);
			vs->type = kImageVerbType;
			vs->imgindex = a;
		}
		break;
	case 140:		// SO_VERB_BAKCOLOR
		vs->bkcolor = pop();
		break;
	case 255:
		drawVerb(slot, 0);
		verbMouseOver(0);
		break;
	default:
		error("o6_verbops: default case %d", op);
	}
}

void ScummEngine_v6::o6_getActorFromXY() {
	int y = pop();
	int x = pop();
	push(getActorFromPos(x, y));
}

void ScummEngine_v6::o6_findObject() {
	int y = pop();
	int x = pop();
	int r = findObject(x, y);
	push(r);
}

void ScummEngine_v6::o6_pseudoRoom() {
	int list[100];
	int num, a, value;

	num = getStackList(list, ARRAYSIZE(list));
	value = pop();

	while (--num >= 0) {
		a = list[num];
		if (a > 0x7F)
			_resourceMapper[a & 0x7F] = value;
	}
}

void ScummEngine_v6::o6_getVerbEntrypoint() {
	int e = pop();
	int v = pop();
	push(getVerbEntrypoint(v, e));
}

void ScummEngine_v6::o6_arrayOps() {
	byte subOp = fetchScriptByte();
	int array = fetchScriptWord();
	int b, c, d, len;
	ArrayHeader *ah;
	int list[128];

	switch (subOp) {
	case 205:		// SO_ASSIGN_STRING
		b = pop();
		len = resStrLen(_scriptPointer);
		ah = defineArray(array, kStringArray, 0, len + 1);
		copyScriptString(ah->data + b);
		break;
	case 208:		// SO_ASSIGN_INT_LIST
		b = pop();
		c = pop();
		d = readVar(array);
		if (d == 0) {
			defineArray(array, kIntArray, 0, b + c);
		}
		while (c--) {
			writeArray(array, 0, b + c, pop());
		}
		break;
	case 212:		// SO_ASSIGN_2DIM_LIST
		b = pop();
		len = getStackList(list, ARRAYSIZE(list));
		d = readVar(array);
		if (d == 0)
			error("Must DIM a two dimensional array before assigning");
		c = pop();
		while (--len >= 0) {
			writeArray(array, c, b + len, list[len]);
		}
		break;
	default:
		error("o6_arrayOps: default case %d (array %d)", subOp, array);
	}
}

void ScummEngine_v6::o6_saveRestoreVerbs() {
	int a, b, c;
	int slot, slot2;

	c = pop();
	b = pop();
	a = pop();

	byte subOp = fetchScriptByte();
	if (_version == 8) {
		subOp = (subOp - 141) + 0xB4;
	}
	
	switch (subOp) {
	case 141:		// SO_SAVE_VERBS
		while (a <= b) {
			slot = getVerbSlot(a, 0);
			if (slot && _verbs[slot].saveid == 0) {
				_verbs[slot].saveid = c;
				drawVerb(slot, 0);
				verbMouseOver(0);
			}
			a++;
		}
		break;
	case 142:		// SO_RESTORE_VERBS
		while (a <= b) {
			slot = getVerbSlot(a, c);
			if (slot) {
				slot2 = getVerbSlot(a, 0);
				if (slot2)
					killVerb(slot2);
				slot = getVerbSlot(a, c);
				_verbs[slot].saveid = 0;
				drawVerb(slot, 0);
				verbMouseOver(0);
			}
			a++;
		}
		break;
	case 143:		// SO_DELETE_VERBS
		while (a <= b) {
			slot = getVerbSlot(a, c);
			if (slot)
				killVerb(slot);
			a++;
		}
		break;
	default:
		error("o6_saveRestoreVerbs: default case");
	}
}

void ScummEngine_v6::o6_drawBox() {
	int x, y, x2, y2, color;
	color = pop();
	y2 = pop();
	x2 = pop();
	y = pop();
	x = pop();
	drawBox(x, y, x2, y2, color);
}

void ScummEngine_v6::o6_wait() {
	int actnum;
	int offs = -2;
	Actor *a;
	byte subOp = fetchScriptByte();

	switch (subOp) {
	case 168:		// SO_WAIT_FOR_ACTOR Wait for actor
		offs = fetchScriptWordSigned();
		actnum = pop();
		a = derefActor(actnum, "o6_wait:168");
		if (a->isInCurrentRoom() && a->_moving)
			break;
		return;
	case 169:		// SO_WAIT_FOR_MESSAGE Wait for message
		if (VAR(VAR_HAVE_MSG))
			break;
		return;
	case 170:		// SO_WAIT_FOR_CAMERA Wait for camera
		if (_version >= 7) {
			if (camera._dest != camera._cur)
				break;
		} else {
			if (camera._cur.x / 8 != camera._dest.x / 8)
				break;
		}

		return;
	case 171:		// SO_WAIT_FOR_SENTENCE
		if (_sentenceNum) {
			if (_sentence[_sentenceNum - 1].freezeCount && !isScriptInUse(VAR(VAR_SENTENCE_SCRIPT)))
				return;
			break;
		}
		if (!isScriptInUse(VAR(VAR_SENTENCE_SCRIPT)))
			return;
		break;
	case 226:		// SO_WAIT_FOR_ANIMATION
		offs = fetchScriptWordSigned();
		actnum = pop();
		a = derefActor(actnum, "o6_wait:226");
		if (a->isInCurrentRoom() && a->_needRedraw)
			break;
		return;
	case 232:		// SO_WAIT_FOR_TURN
		// FIXME: This opcode is really odd. It's used a lot in The Dig.
		// But sometimes it receives the actor ID as params, and sometimes an
		// angle. However in (almost?) all cases, just before calling it, _curActor
		// is set, so we can use it. I tried to add code that detects if an angle
		// is passed, and if so, wait till that angle is reached, but that leads to hangs.
		// It would be very good if somebody could disassmble the original code
		// for this opcode so that we could figure out what's really going on here.
		//
		// For now, if the value passed in is divisible by 45, assume it is an
		// angle, and use _curActor as the actor to wait for.
		offs = fetchScriptWordSigned();
		actnum = pop();
		if (actnum % 45 == 0) {
			actnum = _curActor;
		}
		a = derefActor(actnum, "o6_wait:232b");
		if (a->isInCurrentRoom() && a->_moving & MF_TURN)
			break;
		return;
	default:
		error("o6_wait: default case 0x%x", subOp);
	}

	_scriptPointer += offs;
	o6_breakHere();
}

void ScummEngine_v6::o6_soundKludge() {
	int list[16];
	int num = getStackList(list, ARRAYSIZE(list));

	_sound->soundKludge(list, num);
}

void ScummEngine_v6::o6_isAnyOf() {
	int list[100];
	int num;
	int16 val;

	num = getStackList(list, ARRAYSIZE(list));
	val = pop();

	while (--num >= 0) {
		if (list[num] == val) {
			push(1);
			return;
		}
	}

	push(0);
}

void ScummEngine_v6::o6_quitPauseRestart() {
	byte subOp = fetchScriptByte();
	switch (subOp) {
	case 158:		// SO_RESTART
		restart();
		break;
	case 159:		// SO_PAUSE
		pauseGame();
		break;
	case 160:		// SO_QUIT
		shutDown();
		break;
	default:
		error("o6_quitPauseRestart invalid case %d", subOp);
	}
}

void ScummEngine_v6::o6_delay() {
	// FIXME - what exactly are we measuring here? In order for the other two
	// delay functions to be right, it should be 1/60th of a second. But for
	// CMI it would seem this should delay for 1/10th of a second...
	uint32 delay = (uint16)pop();
	vm.slot[_currentScript].delay = delay;
	vm.slot[_currentScript].status = ssPaused;
	o6_breakHere();
}

void ScummEngine_v6::o6_delaySeconds() {
	uint32 delay = (uint32)pop();
	if (_gameId != GID_CMI)
		// FIXME - are we really measuring minutes here?
		delay = delay * 60;
	else
		// FIXME - Is this the same in ComI? Seem to need a 1.5 minute 
		// multiplier for correct timing - see patch 664893
		delay = delay * 90;

	vm.slot[_currentScript].delay = delay;
	vm.slot[_currentScript].status = ssPaused;
	o6_breakHere();
}

void ScummEngine_v6::o6_delayMinutes() {
	// FIXME - are we really measuring minutes here?
	uint32 delay = (uint16)pop() * 3600;
	vm.slot[_currentScript].delay = delay;
	vm.slot[_currentScript].status = ssPaused;
	o6_breakHere();
}

void ScummEngine_v6::o6_stopSentence() {
	_sentenceNum = 0;
	stopScript(VAR(VAR_SENTENCE_SCRIPT));
	clearClickedStatus();
}

void ScummEngine_v6::o6_printLine() {
	_actorToPrintStrFor = 0xFF;
	decodeParseString(0, 0);
}

void ScummEngine_v6::o6_printCursor() {
	decodeParseString(1, 0);
}

void ScummEngine_v6::o6_printDebug() {
	decodeParseString(2, 0);
}

void ScummEngine_v6::o6_printSystem() {
	decodeParseString(3, 0);
}

void ScummEngine_v6::o6_printActor() {
	decodeParseString(0, 1);
}

void ScummEngine_v6::o6_printEgo() {
	push(VAR(VAR_EGO));
	decodeParseString(0, 1);
}

void ScummEngine_v6::o6_talkActor() {
	_actorToPrintStrFor = pop();

	_string[0].loadDefault();
	actorTalk(_scriptPointer);

	_scriptPointer += resStrLen(_scriptPointer) + 1;
}

void ScummEngine_v6::o6_talkEgo() {
	push(VAR(VAR_EGO));
	o6_talkActor();
}

void ScummEngine_v6::o6_dimArray() {
	int data;

	switch (fetchScriptByte()) {
	case 199:		// SO_INT_ARRAY
		data = kIntArray;
		break;
	case 200:		// SO_BIT_ARRAY
		data = kBitArray;
		break;
	case 201:		// SO_NIBBLE_ARRAY
		data = kNibbleArray;
		break;
	case 202:		// SO_BYTE_ARRAY
		data = kByteArray;
		break;
	case 203:		// SO_STRING_ARRAY
		data = kStringArray;
		break;
	case 204:		// SO_UNDIM_ARRAY
		nukeArray(fetchScriptWord());
		return;
	default:
		error("o6_dimArray: default case");
	}

	defineArray(fetchScriptWord(), data, 0, pop());
}

void ScummEngine_v6::o6_dummy() {
	if (_features & GF_HUMONGOUS)	
		stopObjectCode();
	/* nothing */
}

void ScummEngine_v6::o6_dim2dimArray() {
	int a, b, data;
	switch (fetchScriptByte()) {
	case 199:		// SO_INT_ARRAY
		data = kIntArray;
		break;
	case 200:		// SO_BIT_ARRAY
		data = kBitArray;
		break;
	case 201:		// SO_NIBBLE_ARRAY
		data = kNibbleArray;
		break;
	case 202:		// SO_BYTE_ARRAY
		data = kByteArray;
		break;
	case 203:		// SO_STRING_ARRAY
		data = kStringArray;
		break;
	default:
		error("o6_dim2dimArray: default case");
	}

	b = pop();
	a = pop();
	defineArray(fetchScriptWord(), data, a, b);
}

void ScummEngine_v6::o6_abs() {
	int a = pop();	// palmos: prevent multi pop if we use an abs function defined as : #define abs(a) ((a) < 0 ? -(a) : (a))
	push(abs(a));
}

void ScummEngine_v6::o6_distObjectObject() {
	int a, b;
	b = pop();
	a = pop();
	push(getDistanceBetween(true, a, 0, true, b, 0));
}

void ScummEngine_v6::o6_distObjectPt() {
	int a, b, c;
	c = pop();
	b = pop();
	a = pop();
	push(getDistanceBetween(true, a, 0, false, b, c));
}

void ScummEngine_v6::o6_distPtPt() {
	int a, b, c, d;
	d = pop();
	c = pop();
	b = pop();
	a = pop();
	push(getDistanceBetween(false, a, b, false, c, d));
}

void ScummEngine_v6::o6_drawBlastObject() {
	int args[16];
	int a, b, c, d, e;

	getStackList(args, ARRAYSIZE(args));
	e = pop();
	d = pop();
	c = pop();
	b = pop();
	a = pop();
	enqueueObject(a, b, c, d, e, 0xFF, 0xFF, 1, 0);
}

// Set BOMP processing window
void ScummEngine_v6::o6_setBlastObjectWindow() {
	// TODO - implement this
	int a, b, c, d;

	d = pop();
	c = pop();
	b = pop();
	a = pop();

	warning("o6_setBlastObjectWindow(%d, %d, %d, %d)", a, b, c, d);
}

void ScummEngine_v6::o6_kernelSetFunctions() {
	int args[30];
	int num;
	Actor *a;

	num = getStackList(args, ARRAYSIZE(args));

	if (_version >= 7) {
		switch (args[0]) {
		case 4:
			grabCursor(args[1], args[2], args[3], args[4]);
			break;
		case 6: {
				uint32 speed;
				if (_smushFrameRate == 0) 
					_smushFrameRate = 14;
				speed = 1000000 / _smushFrameRate;

				// SMUSH movie playback
				if (args[1] == 0) {
					assert(getStringAddressVar(VAR_VIDEONAME));
					if (strcmp((char *)getStringAddressVar(VAR_VIDEONAME), "sq3.san") == 0)
						speed = 1000000 / 14;

					SmushPlayer *sp = new SmushPlayer(this, speed);

					// Correct incorrect smush filename in Macintosh FT demo
					if ((_gameId == GID_FT) && (_features & GF_DEMO) && (_features & GF_MACINTOSH) &&
					    (strcmp((char *)getStringAddressVar(VAR_VIDEONAME), "jumpgorge.san") == 0))
						sp->play("jumpgorg.san");
					else
						sp->play((char *)getStringAddressVar(VAR_VIDEONAME));
					delete sp;
				} else if (_gameId == GID_FT) {
					const int insaneVarNum = ((_features & GF_DEMO) && (_features & GF_PC)) 
						? 232 : 233;

					_insaneRunning = true;
					_insane->setSmushParams(speed);
					_insane->runScene(insaneVarNum);
					_insaneRunning = false;
				}
			}
			break;
		case 12:
			setCursorFromImg(args[1], (uint) - 1, args[2]);
			break;
		case 13:
			derefActor(args[1], "o6_kernelSetFunctions:13")->remapActorPalette(args[2], args[3], args[4], -1);
			break;
		case 14:
			derefActor(args[1], "o6_kernelSetFunctions:14")->remapActorPalette(args[2], args[3], args[4], args[5]);
			break;
		case 15:
			_smushFrameRate = args[1];
			break;
		case 16:
		case 17:
			enqueueText(getStringAddressVar(VAR_STRING2DRAW), args[3], args[4], args[2], args[1], (args[0] == 16));
			break;
		case 20:
			// it's used for turn on/off 'RadioChatter' effect for voice in the dig, but i's not needed
			break;
		case 107:
			a = derefActor(args[1], "o6_kernelSetFunctions: 107");
			a->setScale((unsigned char)args[2], -1);
			break;
		case 108:
			setupShadowPalette(args[1], args[2], args[3], args[4], args[5], args[6]);
			break;
		case 109:
			setupShadowPalette(0, args[1], args[2], args[3], args[4], args[5]);
			break;
		case 114:
			warning("o6_kernelSetFunctions: stub114()");
			break;
		case 117:
			freezeScripts(2);
			break;
		case 118:
			enqueueObject(args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], 3);
			break;
		case 119:
			enqueueObject(args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], 0);
			break;
		case 124:
			_saveSound = args[1];
			break;
		case 215:
			ConfMan.set("subtitles", args[1] != 0);
			break;
		default:
			error("o6_kernelSetFunctions: default case %d (param count %d)", args[0], num);
			break;
		}
	} else {
		switch (args[0]) {
		case 3:
			// Dummy case
			break;
		case 4:
			grabCursor(args[1], args[2], args[3], args[4]);
			break;
		case 5:
			fadeOut(args[1]);
			break;
		case 6:
			_fullRedraw = 1;
			redrawBGAreas();
			setActorRedrawFlags();
			processActors();
			fadeIn(args[1]);
			break;
		case 8:
			startManiac();
			break;
		case 9:
			killAllScriptsExceptCurrent();
			break;
		case 104:									/* samnmax */
			nukeFlObjects(args[2], args[3]);
			break;
		case 107:									/* set actor scale */
			a = derefActor(args[1], "o6_kernelSetFunctions: 107");
			a->setScale((unsigned char)args[2], -1);
			break;
		case 108:									/* create proc_special_palette */
		case 109:
			// Case 108 and 109 share the same function
			if (num != 6)
				warning("o6_kernelSetFunctions sub op %d: expected 6 params but got %d", args[0], num);
			setupShadowPalette(args[3], args[4], args[5], args[1], args[2], 0, 256);
			break;
		case 110:
			_charset->clearCharsetMask();
			break;
		case 111:
			a = derefActor(args[1], "o6_kernelSetFunctions: 111");
			a->_shadowMode = args[2] + args[3];
			break;
		case 112:									/* palette shift? */
			setupShadowPalette(args[3], args[4], args[5], args[1], args[2], args[6], args[7]);
			break;
		case 114:
			// Sam & Max film noir mode
			if (_gameId == GID_SAMNMAX) {
				// At this point ScummVM will already have set
				// variable 0x8000 to indicate that the game is
				// in film noir mode. All we have to do here is
				// to mark the palette as "dirty", because
				// updatePalette() will desaturate the colors
				// as they are uploaded to the backend.
				//
				// This actually works better than the original
				// interpreter, where actors would sometimes
				// still be drawn in color.
				setDirtyColors(0, 255);
			} else
				warning("stub o6_kernelSetFunctions_114()");
			break;
		case 117:
			// Sam & Max uses this opcode in script-43, right
			// before a screensaver is selected.
			//
			// Sam & Max uses variable 132 to specify the number of
			// minutes of inactivity (no mouse movements) before
			// starting the screensaver, so setting it to 0 will
			// help in debugging.
			freezeScripts(0x80);
			break;
		case 119:
			enqueueObject(args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], 0);
			break;
		case 120:
			swapPalColors(args[1], args[2]);
			break;
		case 122:
			VAR(VAR_SOUNDRESULT) =
				(short)_imuse->doCommand (num - 1, &args[1]);
			break;
		case 123:
			copyPalColor(args[2], args[1]);
			break;
		case 124:
			_saveSound = args[1];
			break;
		default:
			error("o6_kernelSetFunctions: default case %d (param count %d)", args[0], num);
			break;
		}
	}
}

void ScummEngine_v6::o6_kernelGetFunctions() {
	int args[30];
	int i;
	int slot;
	Actor *a;

	getStackList(args, ARRAYSIZE(args));

	switch (args[0]) {
	case 113:
		// This is used for the Sam & Max paint-by-numbers mini-game
		// to find out what color to change. I think that what we have
		// the virtual mouse coordinates, because that's what used
		// everywhere else in the script.

		{
			VirtScreen *vs = &virtscr[0];
			if (args[1] < 0 || args[1] >= vs->w || args[2] < 0 || args[2] >= vs->h) {
				// FIXME: Until we know what to do in this case...
				warning("o6_kernelGetFunctions:113: asking for pixel (%d, %d) outside of %dx%d screen", args[1], args[2], vs->w, vs->h);
				push(0);
			} else
				push(*((byte *)vs->pixels + args[1] + args[2] * vs->pitch));
		}
		break;
	case 115:
		push(getSpecialBox(args[1], args[2]));
		break;
	case 116:
		push(checkXYInBoxBounds(args[3], args[1], args[2]));
		break;
	case 206:
		push(remapPaletteColor(args[1], args[2], args[3], -1));
		break;
	case 207:
		i = getObjectIndex(args[1]);
		assert(i);
		push(_objs[i].x_pos);
		break;
	case 208:
		i = getObjectIndex(args[1]);
		assert(i);
		push(_objs[i].y_pos);
		break;
	case 209:
		i = getObjectIndex(args[1]);
		assert(i);
		push(_objs[i].width);
		break;
	case 210:
		i = getObjectIndex(args[1]);
		assert(i);
		push(_objs[i].height);
		break;
	case 211:
		/*
		   13 = thrust
		   336 = thrust
		   328 = thrust
		   27 = abort
		   97 = left
		   331 = left
		   115 = right
		   333 = right
		 */

		push(getKeyState(args[1]));
		break;
	case 212:
		a = derefActor(args[1], "o6_kernelGetFunctions:212");
		// This is used by walk scripts
		push(a->_frame);
		break;
	case 213:
		slot = getVerbSlot(args[1], 0);
		push(_verbs[slot].curRect.left);
		break;
	case 214:
		slot = getVerbSlot(args[1], 0);
		push(_verbs[slot].curRect.top);
		break;
	case 215:
		if ((_extraBoxFlags[args[1]] & 0x00FF) == 0x00C0) {
			push(_extraBoxFlags[args[1]]);
		} else {
			push(getBoxFlags(args[1]));
		}
		break;
	default:
		error("o6_kernelGetFunctions: default case %d", args[0]);
	}
}

// FIXME: check either some warning will trigger. I am not sure that those
// keys are queried in scripts at all
int ScummEngine::getKeyState(int key) {
	switch (key) {
	case 0x145:
		warning("ScummEngine::getKeyState(%x) 'numlock' is probed", key);
		return 0;
		break;
	case 0x164:
		warning("ScummEngine::getKeyState(%x) 'left shift' is probed", key);
		return 0;
		break;
	case 0x165:
		warning("ScummEngine::getKeyState(%x) 'right shift' is probed", key);
		return 0;
		break;
	case 0x166:
	case 0x167:
		warning("ScummEngine::getKeyState(%x) 'alt' is probed", key);
		return 0;
		break;
	case 0x168:
		warning("ScummEngine::getKeyState(%x) 'left ctrl' is probed", key);
		return 0;
		break;
	case 0x202a:
		warning("ScummEngine::getKeyState(%x) 'gray *' is probed", key);
		return 0;
		break;
	case 0x202d:
		warning("ScummEngine::getKeyState(%x) 'gray -' is probed", key);
		return 0;
		break;
	case 0x147: // Home
		return (_keyDownMap[0x107] || _keyDownMap[0x115]) ? 1 : 0;
		break;
	case 0x148: // Up
		return (_keyDownMap[0x108] || _keyDownMap[0x111] ||
				_keyDownMap[0x38]) ? 1 : 0;
		break;
	case 0x149: // PgUp
		return (_keyDownMap[0x109] || _keyDownMap[0x118]) ? 1 : 0;
		break;
	case 0x14A: // Gray-
		return (_keyDownMap[0x10d] || _keyDownMap[0x2d]) ? 1 : 0;
		break;
	case 0x14B: // Left
		return (_keyDownMap[0x104] || _keyDownMap[0x114] ||
				_keyDownMap[0x34]) ? 1 : 0;
		break;
	case 0x14C: // 5
		return (_keyDownMap[0x105]) ? 1 : 0;
		break;
	case 0x14D: // Right
		return (_keyDownMap[0x106] || _keyDownMap[0x113] ||
				_keyDownMap[0x36]) ? 1 : 0;
		break;
	case 0x14E: // Gray+
		return (_keyDownMap[0x10e] || 
				(_keyDownMap[0x13d] && _keyDownMap[0x12f])) ? 1 : 0;
		break;
	case 0x14F: // End
		return (_keyDownMap[0x101] || _keyDownMap[0x117]) ? 1 : 0;
		break;
	case 0x150: // Down
		return (_keyDownMap[0x102] || _keyDownMap[0x112] ||
				_keyDownMap[0x32]) ? 1 : 0;
		break;
	case 0x151: // PgDn
		return (_keyDownMap[0x103] || _keyDownMap[0x119]) ? 1 : 0;
		break;
	case 0x152: // Ins
		return (_keyDownMap[0x100] || _keyDownMap[0x115]) ? 1 : 0;
		break;
	case 0x153: // Del
		return (_keyDownMap[0x10a] || _keyDownMap[0x7f]) ? 1 : 0;
		break;
	default:
		break;
	}

	if (key >= 0x13b && key <= 0x144) { // F1-F10
		key -= 0x13b - 0x11a;
	} else if (key >= 0x154 && key <= 0x15d) { // Shift+F1-F10
		key -= 0x154 - 0x11a; // map it to just F1-F10

		warning("ScummEngine::getKeyState(%x) 'Shift-F%d' is probed", key, key-0x153);
	} else if (key > 0x8000) { // Alt
		key -= 0x8000;
		key += 154; // see ScummEngine::parseEvents()
	} else if (key > 0x4000) { // Ctrl
		key -= 0x4000;
		key -= 0x40;
	} else if (key > 0x2000) { // Gray keys
		key -= 0x2000;
		warning("ScummEngine::getKeyState(%x) 'gray key' is probed", key);
	}

	return (_keyDownMap[key]) ? 1 : 0;
}

void ScummEngine_v6::o6_delayFrames() {
	ScriptSlot *ss = &vm.slot[_currentScript];
	if (ss->delayFrameCount == 0) {
		ss->delayFrameCount = pop();
	} else {
		ss->delayFrameCount--;
	}
	if (ss->delayFrameCount) {
		_scriptPointer--;
		o6_breakHere();
	}
}

void ScummEngine_v6::o6_pickOneOf() {
	int args[100];
	int i, num;

	num = getStackList(args, ARRAYSIZE(args));
	i = pop();
	if (i < 0 || i > num)
		error("o6_pickOneOf: %d out of range (0, %d)", i, num - 1);
	push(args[i]);
}

void ScummEngine_v6::o6_pickOneOfDefault() {
	int args[100];
	int i, num, def;

	def = pop();
	num = getStackList(args, ARRAYSIZE(args));
	i = pop();
	if (i < 0 || i >= num)
		i = def;
	else
		i = args[i];
	push(i);
}

void ScummEngine_v6::o6_stampObject() {
	int object, x, y, state;

	// dummy opcode in tentacle
	if (_gameId == GID_TENTACLE)
		return;

	state = pop();
	y = pop();
	x = pop();
	object = pop();
	if (_version >= 7 && object < 30) {
		if (state == 0)
			state = 255;

		Actor *a = derefActor(object, "o6_stampObject");
		a->_scalex = state;
		a->_scaley = state;
		a->putActor(x, y, _currentRoom);
		a->_drawToBackBuf = true;
		a->drawActorCostume();
		a->_drawToBackBuf = false;
		a->drawActorCostume();
		return;
	}
	
	if (state == 0)
		state = 1;

	int objnum = getObjectIndex(object);
	if (objnum == -1)
		return;

	if (x != -1) {
		_objs[objnum].x_pos = x * 8;
		_objs[objnum].y_pos = y * 8;
	}

	putState(object, state);
	drawObject(objnum, 0);
}

void ScummEngine_v6::o6_stopTalking() {
	stopTalk();
}

void ScummEngine_v6::o6_findAllObjects() {
	int room = pop();
	int i = 1;

	if (room != _currentRoom)
		warning("o6_findAllObjects: current room is not %d", room);
	writeVar(0, 0);
	defineArray(0, kIntArray, 0, _numLocalObjects + 1);
	writeArray(0, 0, 0, _numLocalObjects);
	
	while (i < _numLocalObjects) {
		writeArray(0, 0, i, _objs[i].obj_nr);
		i++;
	}
	
	push(readVar(0));
}

void ScummEngine_v6::shuffleArray(int num, int minIdx, int maxIdx) {
	int range = maxIdx - minIdx;
	int count = range * 2;

	// Shuffle the array 'num'
	while (count--) {
		// Determine two random elements...
		int rand1 = _rnd.getRandomNumber(range) + minIdx;
		int rand2 = _rnd.getRandomNumber(range) + minIdx;
		
		// ...and swap them
		int val1 = readArray(num, 0, rand1);
		int val2 = readArray(num, 0, rand2);
		writeArray(num, 0, rand1, val2);
		writeArray(num, 0, rand2, val1);
	}
}

void ScummEngine_v6::o6_shuffle() {
	int b = pop();
	int a = pop();
	shuffleArray(fetchScriptWord(), a, b);
}

void ScummEngine_v6::o6_pickVarRandom() {
	int num;
	int args[100];
	int dim1;

	num = getStackList(args, ARRAYSIZE(args));
	int value = fetchScriptWord();

	if (readVar(value) == 0) {
		defineArray(value, kIntArray, 0, num);
		if (num > 0) {
			int16 counter = 0;
			do {
				writeArray(value, 0, counter + 1, args[counter]);
			} while (++counter < num);
		}

		shuffleArray(value, 1, num);
		writeArray(value, 0, 0, 2);
		push(readArray(value, 0, 1));
		return;
	}

	num = readArray(value, 0, 0);

	ArrayHeader *ah = (ArrayHeader *)getResourceAddress(rtString, readVar(value));
	dim1 = FROM_LE_16(ah->dim1) - 1;

	if (dim1 < num) {
		int16 var_2 = readArray(value, 0, num - 1);
		shuffleArray(value, 1, dim1);
		if (readArray(value, 0, 1) == var_2) {
			num = 2;
		} else {
			num = 1;
		}
	}

	writeArray(value, 0, 0, num + 1);
	push(readArray(value, 0, num));
}

void ScummEngine_v6::o6_getDateTime() {
	struct tm *t;
	time_t now = time(NULL);
	
	t = localtime(&now);

	VAR(VAR_TIMEDATE_YEAR) = t->tm_year;
	VAR(VAR_TIMEDATE_MONTH) = t->tm_mon;
	VAR(VAR_TIMEDATE_DAY) = t->tm_mday;
	VAR(VAR_TIMEDATE_HOUR) = t->tm_hour;
	VAR(VAR_TIMEDATE_MINUTE) = t->tm_min;
	
	if (_version == 8)
		VAR(VAR_TIMEDATE_SECOND) = t->tm_sec;
}

void ScummEngine_v6::o6_getPixel() {
	// this opcode check ground area in minigame "Asteroid Lander" in the dig
	int x, y;

	if (_heversion == 60) {
		x = pop();
		y = pop();
	} else {
		y = pop();
		x = pop();
	}

	VirtScreen *vs = findVirtScreen(y);

	if (vs == NULL || x > _screenWidth - 1 || x < 0) {
		push(-1);
		return;
	}

	byte area = *vs->getPixels(x, y - vs->topline);
	push(area);
}

void ScummEngine_v6::o6_setBoxSet() {
	int arg = pop() - 1;

	const byte *room = getResourceAddress(rtRoom, _roomResource);
	const byte *boxd = NULL, *boxm = NULL;
	int32 dboxSize, mboxSize;
	int i;

	ResourceIterator boxds(room, false);
	for (i = 0; i < arg; i++)
		boxd = boxds.findNext(MKID('BOXD'));

	if (!boxd)
		error("ScummEngine_v6::o6_setBoxSet: Can't find dboxes for set %d", arg);

	dboxSize = READ_BE_UINT32(boxd + 4) - 8;
	byte *matrix = res.createResource(rtMatrix, 2, dboxSize);

	assert(matrix);
	memcpy(matrix, boxd + 8, dboxSize);

	ResourceIterator boxms(room, false);
	for (i = 0; i < arg; i++)
		boxm = boxms.findNext(MKID('BOXM'));

	if (!boxm)
		error("ScummEngine_v6::o6_setBoxSet: Can't find mboxes for set %d", arg);

	mboxSize = READ_BE_UINT32(boxm + 4) - 8;
	matrix = res.createResource(rtMatrix, 1, mboxSize);

	assert(matrix);
	memcpy(matrix, boxm + 8, mboxSize);

	if (_version == 7)
		putActors();
}

void ScummEngine_v6::decodeParseString(int m, int n) {
	byte b;

	b = fetchScriptByte();

	switch (b) {
	case 65:		// SO_AT
		_string[m].ypos = pop();
		_string[m].xpos = pop();
		_string[m].overhead = false;
		break;
	case 66:		// SO_COLOR
		_string[m].color = pop();
		break;
	case 67:		// SO_CLIPPED
		_string[m].right = pop();
		break;
	case 69:		// SO_CENTER
		_string[m].center = true;
		_string[m].overhead = false;
		break;
	case 71:		// SO_LEFT
		_string[m].center = false;
		_string[m].overhead = false;
		break;
	case 72:		// SO_OVERHEAD
		_string[m].overhead = true;
		_string[m].no_talk_anim = false;
		break;
	case 73:		// SO_SAY_VOICE
		error("decodeParseString: case 73");
		break;
	case 74:		// SO_MUMBLE
		_string[m].no_talk_anim = true;
		break;
	case 75:		// SO_TEXTSTRING
		printString(m, _scriptPointer);
		_scriptPointer += resStrLen(_scriptPointer) + 1;
		break;
	case 0xFE:
		_string[m].loadDefault();
		if (n)
			_actorToPrintStrFor = pop();
		break;
	case 0xFF:
		_string[m].saveDefault();
		break;
	default:
		error("decodeParseString: default case 0x%x", b);
	}
}

} // End of namespace Scumm

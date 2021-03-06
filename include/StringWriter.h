/*
Copyright 2016 Thomas Jammet
mathieu.poux[a]gmail.com
jammetthomas[a]gmail.com

This file is part of Librtmfp.

Librtmfp is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Librtmfp is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Librtmfp.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "Base/Mona.h"
#include "DataWriter.h"

class StringWriter : public DataWriter, public virtual Base::Object {
public:

	StringWriter(Base::Buffer& buffer) : _pString(NULL), DataWriter(buffer) {}
	StringWriter(std::string& buffer) : _pString(&buffer) {}

	Base::UInt64 beginObject(const char* type = NULL) { return 0; }
	void   endObject() {}

	void   writePropertyName(const char* name) { append(name); }

	Base::UInt64 beginArray(Base::UInt32 size) { return 0; }
	void   endArray() {}

	void   writeNumber(double value) { append(value); }
	void   writeString(const char* value, Base::UInt32 size) { append(value, size); }
	void   writeBoolean(bool value) { append(value ? "true" : "false"); }
	void   writeNull() { writer.write("null", 4); }
	Base::UInt64 writeDate(const Base::Date& date) { std::string buffer; append(Base::String::Date(date, Base::Date::FORMAT_SORTABLE)); return 0; }
	Base::UInt64 writeBytes(const Base::UInt8* data, Base::UInt32 size) { append(data, size); return 0; }

	void   clear() { if (_pString) _pString->clear(); else writer.clear(); }
private:
	void append(const void* value, Base::UInt32 size) {
		if (_pString)
			_pString->append(STR value, size);
		else
			writer.write(value, size);
	}

	template<typename ValueType>
	void append(const ValueType& value) {
		if (_pString)
			Base::String::Append(*_pString, value);
		else
			Base::String::Append(writer, value);
	}

	std::string* _pString;

};

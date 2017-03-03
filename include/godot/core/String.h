#ifndef STRING_H
#define STRING_H

namespace godot {


#include <godot/godot_string.h>

#include <string.h>


class String
{
	godot_string _godot_string;
public:
	String()
	{
		godot_string_new(&_godot_string);
	}

	String(const char *contents)
	{
		godot_string_new_data(&_godot_string, contents, strlen(contents));
	}

	String(const wchar_t *contents)
	{
		// @Todo
		// godot_string_new_data(&_godot_string, contents, strlen(contents));
		godot_string_new(&_godot_string);
	}

	String(const wchar_t c)
	{
		// @Todo
		godot_string_new(&_godot_string);
	}

	String(const String& other)
	{
		godot_string_new(&_godot_string);
		godot_string_copy_string(&_godot_string, &other._godot_string);
	}

	~String()
	{
		godot_string_destroy(&_godot_string);
	}


	String substr(int p_from,int p_chars) const
	{
		return String(); // @Todo
	}


	wchar_t &operator [](const int idx)
	{
		return *godot_string_operator_index(&_godot_string, idx);
	}

	wchar_t operator [](const int idx) const
	{
		return *godot_string_operator_index((godot_string *) &_godot_string, idx);
	}

	int length() const
	{
		int len = 0;
		godot_string_get_data(&_godot_string, nullptr, &len);
		return len;
	}

	bool operator ==(const String &s)
	{
		return godot_string_operator_equal(&_godot_string, &s._godot_string);
	}

	bool operator !=(const String &s)
	{
		return !(*this == s);
	}

	String operator +(const String &s)
	{
		String new_string;
		godot_string_operator_plus(&new_string._godot_string, &_godot_string, &s._godot_string);

		return new_string;
	}

	void operator +=(const String &s)
	{
		godot_string_operator_plus(&_godot_string, &_godot_string, &s._godot_string);
	}

	void operator +=(const wchar_t c)
	{
		// @Todo
	}

	bool operator <(const String &s)
	{
		return godot_string_operator_less(&_godot_string, &s._godot_string);
	}

	bool operator <=(const String &s)
	{
		return godot_string_operator_less(&_godot_string, &s._godot_string) || (*this == s);
	}

	bool operator >(const String &s)
	{
		return !(*this <= s);
	}

	bool operator >=(const String &s)
	{
		return !(*this < s);
	}

	const wchar_t *c_string()
	{
		return godot_string_c_str(&_godot_string);
	}

};



}



#endif // STRING_H

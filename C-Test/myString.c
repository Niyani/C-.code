class String
{
public:
	String(const char *str = "")
	{
		if (NULL == str)
			_str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);

	}
	String(const String& str)
		:_str(NULL)
	{
		String tmpStr(str._str);
		swap(_str, tmpStr._str);
	}
	/*    第一种写法   */
	/*String& operator=(const String& str)
	{
		if (this != &str)
		{
			String tmpStr(str._str);
			swap(_str, tmpStr._str);
		}
		return *this;
	}*/
	/*   第二种写法   */
	String& operator=(String str)
	{
		swap(_str, str._str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
		}
	}
private:
	char *_str;

};

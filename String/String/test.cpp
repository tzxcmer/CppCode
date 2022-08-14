#define _CRT_SECURE_NO_WARNINGS 1


#include"string.h"


void test1()
{
	tzx::string s("asdasd");
	cout << s.c_str();
	/*for (auto& ch : s)
	{
		cout << ch << endl;
	}
	cout << s.size() << endl;
	cout << s[0] << endl;*/
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	s.push_back('g');
	cout << s.c_str();
	s += 'c';
	cout << s.c_str();
}


void test2()
{
	tzx::string s("asdasd");
	size_t size = s.size();
	//s.insert(size, "aasjdkjaskldasdasdasdf");
	cout << s << endl;
	s.insert(size, '1');
	cout << s << endl;
}

void test3()
{
	string filename("test.cpp");
	cout << filename << endl;
	cout << filename.c_str() << endl;

	FILE* fout = fopen(filename.c_str(), "r");
	assert(fout);
	char ch = fgetc(fout);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fout);
	}
}

void test4()
{
	int ival;
	double dval;
	cin >> ival >> dval;
	std::string istr = to_string(ival);
	std::string dstr = to_string(dval);
	cout << istr << endl;
	cout << dstr << endl;

	istr = "9999";
	dstr = "9999.99";
	ival = stoi(istr);
	dval = stod(dstr);
}

void test5()
{
	std::string s0;
	string s1("111111");
	string s2("1111111111111111111111111111111111111111111111111111111111111");
	cout << sizeof(s0) << endl;
	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;
}

void DealUrl(const string& url)
{
	size_t pos1 = url.find("://");
	if (pos1 == string::npos)
	{
		cout << "非法url" << endl;
		return;
	}

	string protocol = url.substr(0, pos1);
	cout << protocol << endl;

	size_t pos2 = url.find('/', pos1 + 3);
	if (pos2 == string::npos)
	{
		cout << "非法url" << endl;
		return;
	}
	string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
	cout << domain << endl;

	string uri = url.substr(pos2 + 1);
	cout << uri << endl << endl;
}

void test6()
{
	string filename("test.cpp.tar.zip");
	// 后缀
	//size_t pos = filename.find('.');
	size_t pos = filename.rfind('.');
	if (pos != string::npos)
	{
		//string suff = filename.substr(pos, filename.size() - pos);
		string suff = filename.substr(pos);

		cout << suff << endl;
	}

	string url1 = "https://cplusplus.com/reference/string/string/";
	string url2 = "https://image.baidu.com/search/detail?ct=503316480&z=0&ipn=d&word=ascall&step_word=&hs=0&pn=0&spn=0&di=7108135681917976577&pi=0&rn=1&tn=baiduimagedetail&is=0%2C0&istype=0&ie=utf-8&oe=utf-8&in=&cl=2&lm=-1&st=undefined&cs=2613959014%2C543572025&os=2740573600%2C1059518451&simid=2613959014%2C543572025&adpicid=0&lpn=0&ln=179&fr=&fmq=1660115697093_R&fm=&ic=undefined&s=undefined&hd=undefined&latest=undefined&copyright=undefined&se=&sme=&tab=0&width=undefined&height=undefined&face=undefined&ist=&jit=&cg=&bdtype=0&oriquery=&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fimg.php.cn%2Fupload%2Fimage%2F147%2F157%2F796%2F1593765739620093.png%26refer%3Dhttp%3A%2F%2Fimg.php.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Dauto%3Fsec%3D1662707704%26t%3Da68cb238bbb3f99d0554098c785d526e&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3Brir_z%26e3BvgAzdH3FuwqAzdH3F9c9amd_z%26e3Bip4s&gsm=1&rpstart=0&rpnum=0&islist=&querylist=&nojc=undefined&dyTabStr=MCwzLDIsNCw2LDEsNSw3LDgsOQ%3D%3D";
	string url3 = "ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf";

	DealUrl(url1);
	DealUrl(url2);
	DealUrl(url3);
}

void test7()
{
	string s("hello");
	s.push_back('-');
	s.push_back('-');
	s.append("world");
	cout << s << endl;

	string str("我来了");
	s += '@';
	s += str;
	s += "!!!";
	cout << s << endl;

	s.append(++str.begin(), --str.end());
	cout << s << endl;

	//string copy(++s.begin(), --s.end());
	string copy(s.begin() + 5, s.end() - 5);
	cout << copy << endl;
}

void test8()
{
	string s1("hello");
	s1.erase(1, 10);
	cout << s1.c_str() << endl;


	string s2("hello");
	s2.erase(1);
	cout << s2.c_str() << endl;

	string s3("hello");
	s3.erase(1, 2);
	cout << s3.c_str() << endl;
}

void test9()
{
	string s1;
	s1.resize(20);

	string s2("hello");
	s2.resize(20, 'x');

	s2.resize(10);
}
int main()
{
	test8();
}




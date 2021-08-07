#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int n,m;
char c;

void integer_output(const string& str);
void mantissa_output(const string& str);

int main()
{
				string input = {"\0"};
				int i;
				while (cin>>input)
				{
								cin >> n;
								cin >> m;
								cin.get(c);
								cin.get(c);
								if (input.find('.') == -1)
								{
												integer_output(input);
								}
								else
								{
												for (i = input.find('.') + 1; i < input.size(); i++)
												{
																if (input[i] != '0')
																				break;
												}
												if (i == input.size())
												{
																input.erase(input.begin() + input.find('.'), input.end());
																integer_output(input);
												}
												else
												{
																mantissa_output(input);
												}
												//cout << input << "= double" << endl;
								}
				}
				input.erase(input.begin(), input.end());
} 
void mantissa_output(const string& str)
{
				int i;
				int len = str.length();
				int point = str.find('.')+1;
				if (m <= len - point&&m!=0)//no 0
				{
								if (n > point + m)//c and longer mantissa
								{
												for (i = 0; i < n - point - m; i++)
												{
																cout << c;
												}
												for (i = 0; i < point; i++)
												{
																cout << str[i];
												}
												for (i = point; i < point + m; i++)
												{
																cout << str[i];
												}
												cout << endl;
								}
								else//no c and longer than mantissa
								{
												for (i = 0; i < point; i++)
												{
																cout << str[i];
												}
												for (i = point; i < point + m; i++)
												{
																cout << str[i];
												}
												cout << endl;
								}
				}
				else if (m == 0)
				{
								if (n > point - 1)//前面補C
								{
												for (i = 0; i <= n - point; i++)
												{
																cout << c;
												}
												for (i = 0; i < point - 1; i++)
												{
																cout << str[i];
												}
												cout << endl;
								}
								else//前面no c
								{
												for (i = 0; i < point - 1; i++)
												{
																cout << str[i];
												}
												cout << endl;
								}
				}
				else//with 0
				{
								if (n > point + m)//with c and 0
								{
												for (i = 0; i < n - point - m; i++)
												{
																cout << c;
												}
												cout << str;
												for (i = 0; i < point + m - len; i++)
												{
																cout << "0";
												}
												cout << endl;
								}
								else//no c but 0
								{
												cout << str;
												for (i = 0; i < point+m-len; i++)
												{
																cout << 0;
												}
												cout << endl;
								}
				}
}

void integer_output(const string& str)//integer(done)
{
				int i;
				int len = str.length();
				if (m != 0)//with 0
				{
								if (n > len + 1 + m)//with c and 0
								{
												for (i = 0; i < n - len - 1 - m; i++)
												{
																cout << c;
												}
												cout << str<<'.';
												for (i = 0; i < m; i++)
												{
																cout << "0";
												}
												cout << endl;
								}
								else//no c but 0
								{
												cout << str<<'.';
												for (i = 0; i < m; i++)
												{
																cout << "0";
												}
												cout << endl;
								}
				}
				else//no 0
				{
								if (n<=len)//no c no 0
								{
												cout << str << endl;
								}
								else// with c but 0
								{
												for (i = 0; i < n - len; i++)
												{
																cout << c;
												}
												cout << str << endl;
								}
				}
				return;
}
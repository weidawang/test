#include <iostream>
using namespace std;

const int MAX = 3;
class CString {
	char s[MAX + 1];
public:
	CString(char* ss)
	{
		for (int i = 0; i < MAX; i++) {
			s[i] = ss[i];
			if (s[i] == '\0')
				break;
		}
		s[MAX] = '\0';
		//cout << "CString(" << ss << ") stored -->" << s << "<--\n";
	}
	void display(ostream& os) {
		os << s;
	}
};

ostream& operator << (ostream& os, CString& cs)
{
	static int count = 0;
	os << count << ": ";
	cs.display(os);
	os << "\n";
	count++;
	return os;
}

void Process(char* s)
{
	cout << "Process(" << s << ")\n";
	CString cs(s);

	//cout << "cs.display:\n";
	//cs.display(cout);
	//cout << "\n";
	cout << cs;
}

int main(int argc, char* argv[])
{
	//count << "argc=" << argc << "\n";
	for (int arg = 1; arg < argc; arg++)
		Process(argv[arg]);
	cout << "\n";

	cin.get();  //this is for testing purpose, delete before submit!!
}

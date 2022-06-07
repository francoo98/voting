#include <fstream>
#include <string>
//#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
    char var[512];
    char c = '"';
    string str;
    string reemplazo = "'";
    if(!*(argv+1))
        return 0;
    ofstream xs("index.cpp");
    ifstream fs(*(argv+1));
	xs << "#include <iostream>" << endl;
	xs << "#include <string>" << endl;
	xs << "using namespace std;" << endl;
	xs << "" << endl;
	xs << "int main()" << endl;
	xs << "{" << endl;
	xs << "cout << \"""""Content-type: text/html\""""" <<endl<<endl;" << endl;
    while(!fs.eof())
    {
        fs.getline(var, 512);
        str = var;
        for (int i = 0; i < (int)str.length(); ++i) {
        if(str[i]==c)
        {
            str.replace(i,1,reemplazo);
        }
    }
        if(str != "")
        xs << "cout << \"" << str << "\" << endl;" << endl;
        else
            xs << endl;
    }
	xs << "return 0;" << endl;
	xs << "}" << endl;
//MessageBoxA(NULL, "Texto C++ en index.cpp", "xdXdxDx", MB_OK | MB_ICONEXCLAMATION);
}

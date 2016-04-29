#include <iostream>
#include <map>
#include <string>

using namespace std;

string GetOpt(int argc, char* argv[], int pos, map<string, bool> &params);
string ErrMsg(string invalid_param);
string GetHelp(map<string, bool> &params, string progname);

int main(int argc, char *argv[], int pos) 
{
	map<string, bool> parameters;
	parameters.insert(make_pair("--param1", false));
	parameters.insert(make_pair("--param2", true));
	parameters.insert(make_pair("--param3", true));
	parameters.insert(make_pair("--param4", false));

	for (int i = 1; i < argc; i++)
		cout << GetOpt(argc, argv, i, parameters) << endl;


	system("PAUSE");
	return 0;

}

string GetOpt(int argc, char* argv[], int pos, map<string, bool> &params)
{
	if (argc == 1)
		return "";
	if (argc == 2 && string(argv[1]) == "--help")
		return GetHelp(params, string(argv[0]));
	string argVal (string(argv[pos]), string(argv[pos]).find("=") + 1);
	string param  (string(argv[pos]), 0, string(argv[pos]).find("=") );
	map<string, bool>::iterator p;
	p = params.find(param);
	if (p != params.end()) {
		if (argVal.empty())
			return "parameter value required";
		if (params[param])
			return param+ "=" +argVal;
		else
			return "[" + param + "=" + argVal + "]";
	}
		

	return ErrMsg(param);
}

string ErrMsg(string invalid_param)
{
	string err("parameter " + invalid_param + " is not existed in database or wrong syntax. "
		"Use --help for help.");
	return err;
}

string GetHelp(map<string, bool> &params, string progname)
{
	string helpMsg("Use the following syntax: " + progname);
	map<string, bool>::iterator p;
	p = params.begin();
	while (p != params.end()) {
		string param = p->first;
		if (p->second)
			helpMsg.append(param+" ");
		else
			helpMsg.append(" ["+param+"] ");
		p++;
	}
	return helpMsg;
}
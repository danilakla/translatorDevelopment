#include "stdafx.h"
#include "Error.h"		//��������� ������
#include "Parm.h"		//��������� ����������
#include "Log.h"		//������ � ����������
#include "In.h"			//���� ��������� �����

#include <iostream>
#include <cwchar>
#include <time.h>

using namespace std;

int wmain(int argc, wchar_t* argv[]) {
	setlocale(LC_ALL, "russian");

	Log::LOG log = Log::INITLOG;

	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		Log::LOG log = Log::getlog(parm.log);
		Log::WriteLine(log, "����: ", "��� ������\n", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e) {
		Log::WriteError(log, e);

	}

	return 0;
}
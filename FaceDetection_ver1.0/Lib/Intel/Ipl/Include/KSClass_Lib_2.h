#pragma once

// �ڵ����� KSClass ���̺귯���� ��ũ���ִ� �ɼ��̴�.
#ifndef KS_CLASS_LIB

	#define KS_CLASS_LIB

	#ifdef _DEBUG
		#pragma message("linking to KSClass_D.lib")
		#pragma comment(lib, "KSClass_D.lib")
	#else
		#pragma message("linking to KSClass_R.lib")
		#pragma comment(lib, "KSClass_R.lib")
	#endif // _DEBUG

#endif // __KSCLASS_LIB__

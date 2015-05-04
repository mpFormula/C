
//#pragma once
//#pragma warning(disable: 4127 4800 4512 4244)
//#pragma warning(disable: 4244)




#ifdef GIESEKE_EXPORTS
    #define MPNUMC_DLL_IMPORTEXPORT __declspec(dllexport)
#else
    #define MPNUMC_DLL_IMPORTEXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

MPNUMC_DLL_IMPORTEXPORT double npFunction00d(int dps, int FunctionEnum);

MPNUMC_DLL_IMPORTEXPORT double npFunction01d(int dps, int FunctionEnum, double x1);

MPNUMC_DLL_IMPORTEXPORT double npFunction02d(int dps, int FunctionEnum, double x1, double x2);

MPNUMC_DLL_IMPORTEXPORT double npFunction03d(int dps, int FunctionEnum, double x1, double x2, double x3);

MPNUMC_DLL_IMPORTEXPORT double npFunction04d(int dps, int FunctionEnum, double x1, double x2, double x3, double x4);

MPNUMC_DLL_IMPORTEXPORT double npFunction05d(int dps, int FunctionEnum, double x1, double x2, double x3, double x4, double x5);



MPNUMC_DLL_IMPORTEXPORT char* npFunction00s(int dps, int FunctionEnum);

MPNUMC_DLL_IMPORTEXPORT char* npFunction01s(int dps, int FunctionEnum, const char* x1);

MPNUMC_DLL_IMPORTEXPORT char* npFunction02s(int dps, int FunctionEnum, const char* x1, const char* x2);

MPNUMC_DLL_IMPORTEXPORT char* npFunction03s(int dps, int FunctionEnum, const char* x1, const char* x2, const char* x3);

MPNUMC_DLL_IMPORTEXPORT char* npFunction04s(int dps, int FunctionEnum, const char* x1, const char* x2, const char* x3, const char* x4);

MPNUMC_DLL_IMPORTEXPORT char* npFunction05s(int dps, int FunctionEnum, const char* x1, const char* x2, const char* x3, const char* x4, const char* x5);

#ifdef __cplusplus
}
#endif

#ifndef __MAIN_H__
#define __MAIN_H__

//#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_EIGEN_DLL
    #define EIGEN_DLL_IMPORTEXPORT __declspec(dllexport)
#else
    #define EIGEN_DLL_IMPORTEXPORT __declspec(dllimport)
#endif

//
//#ifdef __cplusplus
//extern "C"
//{
//#endif
//
//void EIGEN_DLL_IMPORTEXPORT SomeFunction(const LPCSTR sometext);
//
//#ifdef __cplusplus
//}
//#endif

#endif // __MAIN_H__

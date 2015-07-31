
//#include "stdafx.h"
#include <cstring>
#include "mpRealDecimal.h"

using std::ws;
using std::cerr;
using std::endl;
using std::string;
using std::ostream;
using std::istream;


namespace mpDec
{
int mpRealInterval::IsInitialized = 0;
uint32_t mpRealInterval::Dec_Status = 0;
uint32_t mpRealInterval::Default_Digits = 34;
//mpd_context_t mpdec_class::ctx;
//
//void set_precision(int prec)
//{
//	if (mpdec_class::IsInitialized == 0)
//        {mpdec_class::IsInitialized = 1; mpd_init(&mpdec_class::ctx, prec);	}
//	else
//        {
//            mpd_defaultcontext(&mpdec_class::ctx);
//            if (!mpd_qsetprec(&mpdec_class::ctx, prec))
//            {mpd_addstatus_raise(&mpdec_class::ctx, MPD_Invalid_context); return; }
//        }
//}
//
//void set_decimal32()
//{
//	if (mpdec_class::IsInitialized == 0)
//        {mpdec_class::IsInitialized = 1; mpd_init(&mpdec_class::ctx, mpdec_class::Default_Digits);	}
//    mpd_ieee_context(&mpdec_class::ctx, MPD_DECIMAL32);
//}
//
//
//void set_decimal64()
//{
//	if (mpdec_class::IsInitialized == 0)
//        {mpdec_class::IsInitialized = 1; mpd_init(&mpdec_class::ctx, mpdec_class::Default_Digits);	}
//    mpd_ieee_context(&mpdec_class::ctx, MPD_DECIMAL64);
//}
//
//
//void set_decimal128()
//{
//	if (mpdec_class::IsInitialized == 0)
//        {mpdec_class::IsInitialized = 1; mpd_init(&mpdec_class::ctx, mpdec_class::Default_Digits);	}
//    mpd_ieee_context(&mpdec_class::ctx, MPD_DECIMAL128);
//}
//
//// Default constructor: creates mp number and initializes it to 0.
//mpdec_class::mpdec_class()
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//	mpd_qset_i32(mp, 0, &ctx, &Dec_Status);
//}
//
//mpdec_class::mpdec_class(const mpdec_class& u)
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//  mpd_copy(mp, u.mp, &ctx);
//}
//
//mpdec_class::mpdec_class(const double u)
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//	std::stringstream ss;
//	ss.precision (15);
//	ss << u;
//	std::string s = ss.str();
//	mpd_set_string(mp, s.c_str(), &ctx);
//}
//
//mpdec_class::mpdec_class(const unsigned long int u)
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//	mpd_qset_i32(mp, u, &ctx, &Dec_Status);
//}
//
//mpdec_class::mpdec_class(const unsigned int u)
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//	mpd_qset_i32(mp, u, &ctx, &Dec_Status);
//}
//
//mpdec_class::mpdec_class(const long int u)
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//	mpd_qset_i32(mp, u, &ctx, &Dec_Status);
//}
//
//
//
//	// Begin Change DH
//mpdec_class::mpdec_class(const __int64 u)
//{
//	Dec_Status = 0;
////	#if defined (_WIN64)
////			mpd_qset_u64(mp, u, &ctx,  &Dec_Status);
////	#else
//			mpd_qset_i32(mp, (long) u, &ctx, &Dec_Status);
////	#endif
//}
//	// End Change DH
//
//
//
//
//
//mpdec_class::mpdec_class(const int u)
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//	mpd_qset_i32(mp, u, &ctx, &Dec_Status);
//}
//
//mpdec_class::mpdec_class(const char* s)
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//  mpd_set_string(mp, s, &ctx);
//}
//
//mpdec_class::mpdec_class(const std::string& s)
//{
//	if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mp = mpd_new(&ctx);
//  mpd_set_string(mp, s.c_str(), &ctx);
//}
//
//mpdec_class::~mpdec_class()
//{
//	mpd_del(mp);
//}
//
//// Operators - Assignment
//mpdec_class& mpdec_class::operator=(const char* s)
//{
//		if (IsInitialized == 0)
//	{
//		IsInitialized = 1;
////	  Dec_Status = 0;
//    mpd_init(&ctx, Default_Digits);
//	}
//	mpd_t *t;
//	//Dec_Status = 0;
// // mpd_init(&ctx, Default_Digits);
//	t = mpd_new(&ctx);
//  mpd_set_string(t, s, &ctx);
//	mpd_copy(mp, t, &ctx);
//	mpd_del(t);
//	return *this;
//}
//
//template <class T>
//std::string to_string(T t, std::ios_base & (*f)(std::ios_base&))
//{
//	std::ostringstream oss;
//	oss << f << t;
//	return oss.str();
//}
//
//mpdec_class::operator std::string() const
//{
//	return to_string();
//}
//
//std::string mpdec_class::to_string(size_t n) const
//{
//	char *s = NULL;
//	string out;
//
//	s  = mpd_to_sci(mp, 1);
//	out = string(s);
//	return out;
//}
//
////////////////////////////////////////////////////////////////////////////
//// I/O
//ostream& operator<<(ostream& os, const mpdec_class& v)
//{
//	return os<<v.to_string(static_cast<size_t>(os.precision()));
//}
//
//istream& operator>>(istream &is, mpdec_class& v)
//{
//	char c;
//	string s = "";
//	mpd_t *t;
//
//
//	if(is.good())
//	{
//		is>>ws;
//		while ((c = is.get())!=EOF)
//		{
//			if(c ==' ' || c == '\t' || c == '\n' || c == '\r')
//			{
//				is.putback(c);
//				break;
//			}
//			s += c;
//		}
//
//		if(s.size() != 0)
//		{
//			// Protect current value from alternation in case of input error
//			// so some error handling(roll back) procedure can be used
//
//			mpdec_class::Dec_Status = 0;
//			//mpd_init(&mpdec_class::ctx, mpdec_class::Default_Digits);
//			t = mpd_new(&mpdec_class::ctx);
//			mpd_set_string(t, s.c_str(), &mpdec_class::ctx);
//
//
//			//if(0==mpfr_init_set_str(t,s.c_str(),mpdec_class::default_base,mpdec_class::default_rnd))
//			//{
//			 mpd_copy(v.mp, t, &mpdec_class::ctx);
//				//mpfr_set(v.mp,t,mpdec_class::default_rnd);
//			   mpd_del(t);
//				//mpfr_clear(t);
//
//			//}else{
//				//mpfr_clear(t);
//				//cerr<<"error reading from istream"<<endl;
//				// throw an exception
//			//}
//		}
//	}
//	return is;
//}
//

} // end namespace mpDec


// find real roots for quartic equations with real coefficients
// Author: Dongxu Li
// Written for the LibreCAD project: http://librecad.org/
//
#include"quarticSolver.h"

// ce is a pointer to an array of equation coefficients
// root is a pointer to roots to be stored,
// there's no attempt verify validity of the argument pointer
//

unsigned int quadraticSolver(double * ce, double * roots)
//quadratic solver for
// x^2 + ce[0] x + ce[2] =0
{
		double discriminant=0.25*ce[0]*ce[0]-ce[1];
		if (discriminant < 0. ) return 0;
		roots[0]= -0.5*ce[0] + sqrt(discriminant);
		roots[1]= -ce[0] - roots[0];
		return 2;
}

unsigned int cubicSolver(double * ce, double *roots)
//cubic equation solver
// x^3 + ce[0] x^2 + ce[1] x + ce[2] = 0
{
// depressed cubic, Tschirnhaus transformation, x= t - b/(3a)
// t^3 + p t +q =0
		unsigned int ret=0;
		double shift=(1./3)*ce[0];
		double p=ce[1] -shift*ce[0];
		double q=ce[0]*( (2./27)*ce[0]*ce[0]-(1./3)*ce[1])+ce[2];
		//Cardano's method,
		// t=u+v
		// u^3 + v^3 + ( 3 uv + p ) (u+v) + q =0
		// select 3uv + p =0, then,
		// u^3 + v^3 = -q
		// u^3 v^3 = - p^3/27
		// so, u^3 and v^3 are roots of equation,
		// z^2 + q z - p^3/27 = 0
		// and u^3,v^3 are,
		// -q/2 \pm sqrt(q^2/4 + p^3/27)
		// discriminant= q^2/4 + p^3/27
		std::cout<<"cubicSolver:: p="<<p<<"\tq="<<q<<std::endl;
		double discriminant= (1./27)*p*p*p+(1./4)*q*q;
		if ( fabs(p)< 1.0e-75) {
			ret=1;
			*roots=(q>0)?-pow(q,(1./3)):pow(-q,(1./3));
			*roots -= shift;
			return ret;
		}
		std::cout<<"cubicSolver:: discriminant="<<discriminant<<std::endl;
		if(discriminant>0) {
				double ce2[2]= {q, -1./27*p*p*p},u3[2];
				ret=quadraticSolver(ce2,u3);
				if (! ret ) { //should not happen
				std::cerr<<"cubicSolver::Error cubicSolver("<<ce[0]<<' '<<ce[1]<<' '<<ce[2]<<")\n";
				}
				ret=1;
				double u,v;
				u= (q<=0) ? pow(u3[0], 1./3): -pow(-u3[1],1./3);
				//u=(q<=0)?pow(-0.5*q+sqrt(discriminant),1./3):-pow(0.5*q+sqrt(discriminant),1./3);
				v=(-1./3)*p/u;
				std::cout<<"cubicSolver:: u="<<u<<"\tv="<<v<<std::endl;
				std::cout<<"cubicSolver:: u^3="<<u*u*u<<"\tv^3="<<v*v*v<<std::endl;
				*roots=u+v - shift;
				return ret;
		}
		ret=3;
		std::complex<double> u(q,0),rt[3];
		u=pow(-0.5*u-sqrt(0.25*u*u+p*p*p/27),1./3);
		rt[0]=u-p/(3.*u)-shift;
		std::complex<double> w(-0.5,sqrt(3.)/2);
		rt[1]=u*w-p/(3.*u*w)-shift;
		rt[2]=u/w-p*w/(3.*u)-shift;
		// std::cout<<"Roots:\n";
		// std::cout<<rt[0]<<std::endl;
		// std::cout<<rt[1]<<std::endl;
		// std::cout<<rt[2]<<std::endl;
		roots[0]=rt[0].real();
		roots[1]=rt[1].real();
		roots[2]=rt[2].real();
		return ret;
}

unsigned int quarticSolver(double * ce, double *roots)
//quartic solver
// x^4 + ce[0] x^3 + ce[1] x^2 + ce[2] x + ce[3] = 0
{
		// x^4 + a x^3 + b x^2 +c x + d = 0
		// depressed quartic, x= t - a/4
		// t^4 + ( b - 3/8 a^2 ) t^2 + (c - a b/2 + a^3/8) t + d - a c /4 + a^2 b/16 - 3 a^4/256 =0
		// t^4 + p t^2 + q t + r =0
		// p= b - (3./8)*a*a;
		// q= c - 0.5*a*b+(1./8)*a*a*a;
		// r= d - 0.25*a*c+(1./16)*a*a*b-(3./256)*a^4
		unsigned int ret=0;
		double shift=0.25*ce[0];
		double shift2=shift*shift;
		double a2=ce[0]*ce[0];
		double p= ce[1] - (3./8)*a2;
		double q= ce[2] + ce[0]*((1./8)*a2 - 0.5*ce[1]);
		double r= ce[3] - shift*ce[2] + (ce[1] - 3.*shift2)*shift2;
		std::cout<<"quarticSolver:: p="<<p<<"\tq="<<q<<"\tr="<<r<<std::endl;
		if (fabs(q) <= 1.0e-75) {// Biquadratic equations
				double discriminant= 0.25*p*p -r;
				if (discriminant < 0.) {
						return 0;
				}
				double t2[2];
				t2[0]=-0.5*p-sqrt(discriminant);
				t2[1]= -p - t2[0];
				if ( t2[0] >= 0. ) {// four real roots
						roots[0]=sqrt(t2[0])-shift;
						roots[1]= -sqrt(t2[0])-shift;
						roots[2]=sqrt(t2[1])-shift;
						roots[3]= -sqrt(t2[1])-shift;
						return 4;
				}
				if ( t2[1] >= 0.) { // two real roots
						roots[0]=sqrt(t2[1])-shift;
						roots[1]= -roots[0]-shift;
						return 2;
				}
				return 0;
		}
		if ( fabs(r)< 1.0e-75 ) {
				double cubic[3]= {0.,p,q};
				roots[0]=0.;
				ret=1+cubicSolver(cubic,roots+1);
				for(unsigned int i=0; i<ret; i++) roots[i] -= shift;
				return ret;
		}
		// depressed quartic to two quadratic equations
		// t^4 + p t^2 + q t + r = ( t^2 + u t + v) ( t^2 - u t + w)
		// so,
		// p + u^2= w+v
		// q/u= w-v
		// r= wv
		// so,
		// (p+u^2)^2 - (q/u)^2 = 4 r
		// y=u^2,
		// y^3 + 2 p y^2 + ( p^2 - 4 r) y - q^2 =0
		//
		double cubic[3]= {2.*p,p*p-4.*r,-q*q},croots[3];
		ret = cubicSolver(cubic,croots);
		std::cout<<"quarticSolver:: real roots from cubic: "<<ret<<std::endl;
		for(unsigned int i=0; i<ret; i++)
		std::cout<<"cubic["<<i<<"]="<<cubic[i]<<" x= "<<croots[i]<<std::endl;
		if (ret==1) { //one real root from cubic
				if (croots[0]< 0.) {//this should not happen
						std::cerr<<"Quartic Error:: Found one real root for cubic, but negative\n";
						return 0;
				}
				double sqrtz0=sqrt(croots[0]);
				double ce2[2];
				ce2[0]= -sqrtz0;
				ce2[1]=0.5*(p+croots[0])+0.5*q/sqrtz0;
				ret=quadraticSolver(ce2,roots);
				if (! ret ) {
				ce2[0]= sqrtz0;
				ce2[1]=0.5*(p+croots[0])-0.5*q/sqrtz0;
				ret=quadraticSolver(ce2,roots);
				}
				ret=2;
				for(unsigned int i=0; i<ret; i++) roots[i] -= shift;
				return ret;
		}
		if ( croots[0]> 0. && croots[1] > 0. ) {
				double sqrtz0=sqrt(croots[0]);
				double ce2[2];
				ce2[0]= -sqrtz0;
				ce2[1]=0.5*(p+croots[0])+0.5*q/sqrtz0;
				ret=quadraticSolver(ce2,roots);
				ce2[0]= sqrtz0;
				ce2[1]=0.5*(p+croots[0])-0.5*q/sqrtz0;
				ret=quadraticSolver(ce2,roots+2);
				ret=4;
				for(unsigned int i=0; i<ret; i++) roots[i] -= shift;
				return ret;
		}
		return 0;
}





int main(int argc, char * argv[])
{
		unsigned int counts;
		double ce[4]= {1.87832,-0.0950376,-1.87832,-0.882024};
		unsigned int j=5;
		if(argc < j ) j=argc;
		for(unsigned int i=1; i< j; i++) {
				ce[i-1]=strtod(argv[i],NULL);
		}
		std::cout<<"x^4";
		if(argc == 1) j=4;
		else j--;
		for(unsigned int i=0; i< j; i++) {
				std::cout<<" + ("<<ce[i]<<")";
				if ( i != 3 ) {
						std::cout<<"*x^"<<3-i;
				} else {
						std::cout<<" =0\n";
				}
		}

		double roots[4];
		switch (j) {
		case 4:
				std::cout<<"quadratic:\n";
				counts=quarticSolver(ce,roots);
				break;
		case 3:
				std::cout<<"cubic:\n";
				counts=cubicSolver(ce,roots);
				break;
		default:
				std::cout<<"quartic:\n";
				counts=quadraticSolver(ce,roots);
		}
		std::cout<<"Number of real roots="<<counts<<std::endl;
		for(unsigned int i=0; i<counts; i++) {
				std::cout<<"x= "<<roots[i]<<'\t';
		}
		std::cout<<std::endl;
		return 0;
}

 
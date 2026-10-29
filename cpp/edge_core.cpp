#include <array>
#include <cmath>
#include <cstdint>
#include <algorithm>
constexpr int N=64; struct S{float x,y,z;}; struct F{float rms,peak,dominant;};
F extract(const std::array<S,N>& s,float sr){float a[N],sq=0,p=0;for(int i=0;i<N;i++){a[i]=sqrt(s[i].x*s[i].x+s[i].y*s[i].y+s[i].z*s[i].z);sq+=a[i]*a[i];p=std::max(p,a[i]);}float best=0;int bk=0;for(int k=1;k<N/2;k++){float re=0,im=0;for(int n=0;n<N;n++){float q=2*3.14159265f*k*n/N;re+=a[n]*cos(q);im-=a[n]*sin(q);}float e=re*re+im*im;if(e>best){best=e;bk=k;}}return {sqrt(sq/N),p,bk*sr/N};}
int8_t q8(float x,float scale){int q=lround(x/scale);return int8_t(std::max(-128,std::min(127,q)));}
constexpr int working_set_bytes=N*3*sizeof(float)+N*sizeof(float)+3*sizeof(float)+5*sizeof(int8_t);
static_assert(working_set_bytes < 64*1024,"64KB design budget exceeded");

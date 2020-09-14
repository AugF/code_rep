// https://www.bilibili.com/video/BV1aW411H7Xa

#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>

class ostream;
class complex;
complex& __doap1 (complex* ths, const complex&);
// forward declarations
template<typename T> 
class complex // class declarations
{
public:
    complex (double r = 0, double i = 0)
    : re(r), im(i) {}

    complex& operator += (const complex&);
    T real () const { return re; }
    T imag () const { return im; }

    int func(const complex& param) {
        return param.re + param.im; 
        // 这里直观上看破坏了封装性，本质是相同class的各个objects互为friends（友元）
    }

private:
    T re, im;
    
    friend complex& __doap1 (complex* ths, const complex& r); // 朋友打开了封装
};

inline complex& __doap1 (complex* ths, const complex& r) {
    
}
#endif
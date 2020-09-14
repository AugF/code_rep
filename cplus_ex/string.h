#ifndef __STRNG__
#define __STRNG__

class String // 4 bytes
{
public:
    String(const char* str = 0);
    String(const String& str); // 不会改
    String& operator=(const String& str);
    ~String();
    char* get_c_str() const {return m_data};

private:
    char* m_data;
};

inline String::String(const char* cstr = 0) {
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

String::~String() {
    delete[] m_data;
}

inline String::String(const String& str) {
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str) { // type&, 引用
    if (this == &str) return *this; // object前面，取地址；自我赋值

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this; // 传出去的一定是String对象
}
#endif
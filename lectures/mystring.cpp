#include <iostream>
#include <cstring>
#include <cassert>

class MyString {
public:
  MyString() {
    m_len = 0;
    m_buf = nullptr;
  }

  MyString(const char* str) {
    m_len = strlen(str)+1;
    m_buf = (char*) malloc(m_len);
    strncpy(m_buf, str, m_len);
  }

  MyString(const MyString& orig) {
    m_len = orig.m_len;
    m_buf = (char*) malloc(m_len);
    strncpy(m_buf, orig.m_buf, m_len);  
  }

  MyString& operator=(const MyString& orig) {
    if (this == &orig) {
      return *this;
    }
 
    clear();
    m_len = orig.m_len;
    m_buf = (char*) malloc(orig.m_len);
    strncpy(m_buf, orig.m_buf, m_len);  
    return *this;
  }

  virtual ~MyString() {
    clear();
  }

  bool operator==(const MyString& other) {
    if (this == &other) {
      return true;
    }

    if (other.m_len != m_len) {
      return false;
    }
 
    return strncmp(other.m_buf, m_buf, m_len) == 0;
  }

  bool operator!=(const MyString& other) {
    return !(*this == other);
  }

  char& operator[](int idx) {
    assert(idx >= 0 && idx < m_len-1);
    return m_buf[idx];
  }

  const char& operator[](int idx) const {
    assert(idx >= 0 && idx < m_len-1);
    return m_buf[idx];
  }

  int size() const {
    return m_len-1;
  }

  const char* c_str() const {
    return m_buf;
  }

  friend std::ostream& operator<<(std::ostream& os, const MyString& str);

private:
  void clear() {
    if (m_buf) {
      free(m_buf);
      m_len = 0;
      m_buf = nullptr;
    }
  }

private:
  char* m_buf;
  unsigned int m_len;
};

std::ostream& operator<<(std::ostream& os, const MyString& str) {
  os << str.m_buf;
  return os;
}

int main() {
  MyString a;
  MyString b = "hello";
  MyString c = b;
  a = b;

  MyString* d = new MyString();
  *d = "bye";

  std::cout << "a: " << a << std::endl; 
  std::cout << "b: " << b << std::endl; 
  std::cout << "c: " << c << std::endl; 
  std::cout << "d: " << *d << std::endl; 

  delete d;

  MyString e = MyString("eee");
  const MyString f("fff");

  for (int i = 0; i < f.size(); i++) {
    printf("%c\n", f[i]);
  }

  a[0] = 'y';
  std::cout << "a: " << a << std::endl; 

  if (e != f) std::cout << "Not equal\n";
  if (b == c) std::cout << "Equal\n";


  return 0;
}


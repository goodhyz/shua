#include<bits/stdc++.h>

// C++11以上，自带两段检查锁机制确保static变量只实例化一次
// 懒汉模式1
class Singleton1 {
  private:
    Singleton1() = default;                             // 默认构造函数
    ~Singleton1() = default;                            // 默认析构函数
    Singleton1(const Singleton1 &) = delete;            // 删除拷贝构造函数
    Singleton1 &operator=(const Singleton1 &) = delete; // 删除赋值操作符

  public:
    static Singleton1 &GetInstance() {
        static Singleton1 singleton1; // 局部静态变量，c++11以上线程安全
        return singleton1;
    }
};

// 手动使用双检锁 
// 懒汉模式2
class Singleton2{
  private:
    Singleton2()=default;
    ~Singleton2()=default;
    Singleton2(Singleton2&)=delete;
    Singleton2 & operator = (const Singleton2 &) = delete;
  private:
    static std::mutex _mutex;
    static Singleton2* instance; 
  public:
    static Singleton2* GetInstance(){
        if(instance==nullptr){
            _mutex.lock();
            // 避免被阻塞的线程重新继续创建
            if(instance==nullptr){
                instance = new Singleton2();
            }
            _mutex.unlock();
        }
        return instance;
    }
};

// 饿汉式，直接初始化
// 需要在类外初始化
class Singleton3{
  private:
    Singleton3()=default;
    ~Singleton3()=default;
    Singleton3(Singleton3&)=delete;
    Singleton3& operator = (const Singleton3&)=delete;
  private:
    static Singleton3 instance;
  public:
    // 返回Singleton的指针
    static Singleton3* GetInstance(){
        return &instance;
    }
};
Singleton3 Singleton3::instance;

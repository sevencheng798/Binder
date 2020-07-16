Binder
================

主要学习Binder的有关通信，包括Native Binder通信、Framework层Binder通信、AIDL通信、及交叉层直接的Binder通信

# Binder通信流程
- [Binder流程跟踪](https://blog.csdn.net/innost/article/details/47208049)

- 从通信流程角度来看整个过程:
<div align=center> <img src=image/protocol.jpg /> </div>

- REPLY通信流程
<div align=center> <img src=image/reply.jpg /> </div>

- ONEWAY通信流程
<div align=center> <img src=image/oneway.png /> </div>

# Binder通信实例

- [NativeBinder通信](https://github.com/sevencheng798/Binder/tree/master/NativeBinder)
```
    用C++写的本地Binder服务，使用service manager注册本地服务
````
- [NativeBinder中级应用](NativeBinderAdvanced)
```
    创建IMemory共享内存通过Binder进行读写操作。
```

- NativeBinder和Framework通信



Binder
================

主要学习Binder的有关通信，包括Native Binder通信、Framework层Binder通信、AIDL通信、及交叉层直接的Binder通信

# Binder通信实例

- [NativeBinder通信](https://github.com/sevencheng798/Binder/tree/master/NativeBinder)
```
    用C++写的本地Binder服务，使用service manager注册本地服务
````
- [NativeBinder中级应用](NativeBinderAdvanced)
```
    创建IMemory共享内存通过Binder进行读写操作。
```

- [NativeBinder和Framework通信](FrameworkBinderDemo)
```
    从framework角度编写的Binder Demo程序
```

- [NativeBinder和APK通信](AppBinder)
```
    通过APK调用framework binder与底层![native binder](NativeAppBinder)直接通信。
    其实与framework binder使用的api完全一样，区别在于通过Activity启用service。
    该实例主要分两部分： 
    APK Binder Client -> NativeAppBinder Service
    APK Binder Service -> NativeAppBinder Client
```

- AIDL通信实例
```
    真正的从Apk角度编写的Binder Demo程序，也是binder从底层层层向上封装最终提供给APK调用的方式，即AIDL接口。
```

- [AIDL callback通信](NativeBinderAndAidl)
```
    本地native binder service和java aidl client进行通信。
    同时client可以注册callback到native service中。 native service定时的调用callback通知client
```


# Binder通信流程
- [Binder流程跟踪](https://blog.csdn.net/innost/article/details/47208049)

- 从通信流程角度来看整个过程:
<div align=center> <img src=image/protocol.jpg /> </div>

- REPLY通信流程
<div align=center> <img src=image/reply.jpg /> </div>

- ONEWAY通信流程
<div align=center> <img src=image/oneway.png /> </div>

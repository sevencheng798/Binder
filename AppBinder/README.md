AppBinder Test
================

通过APK直接调用framework binder通信接口，与本地native Binder通信。
主要包含APK Binder Service和APK Binder Client的例程。
测试时需要分别对应配合本地服务例程测试native binder service和native binder client

# 主要包含两个APK程序:

- [binder service服务端](AppBinderService)
  
- [binder service客户端](AppBinderClient)
  
# 配合测试用的本地Binder

- [NativeBinder服务端](../NativeAppBinder)
- [NativeBinder客户端](../NativeAppBinder)
 
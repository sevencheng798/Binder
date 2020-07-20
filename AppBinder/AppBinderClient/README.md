AppBinderClient Test
================

APK Binder 和 Native binder直接通信。

# 可生成APK测试程序:
  
  binder service客户端: AppBinderClientTest.apk
  
 注意： 该测试需要配合native service服务端程序。该实例基于native service在[NativeAppBinder中](../../NativeAppBiner)
 
# 编译并执行

- 执行Service端
    ```
	./AppBinderService
	// 等待客户端进行通信
	Now server receive requset from client: [call setName SvenCheng]
	Now server receive requset from client: [call getName SvenCheng]
	Now server receive requset from client: [call add 11]
	```

- 执行Client端
    ```
	首先，编译产出apk，然后通过adb install -r AppBinderClientTest.apk 安装到设备中。
	然后点击程序运行： SetName / GetName / Add / GetSum
	````
	
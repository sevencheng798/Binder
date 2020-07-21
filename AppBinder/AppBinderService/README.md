AppBinderService Test
================

APK Binder 和 Native binder直接通信。

# 可生成APK测试程序:
  
  binder service服务端: AppBinderService.apk
  
 注意： 该测试需要配合native binder客户端程序。该实例基于native binder client在[NativeAppBinder中](../../NativeAppBinder)
 
# 编译并执行
- 编译
```
    该工程是基于Android Studio IDE中环境搭建的。同时也提供了Android.mk编译文件，可以直接放到AOSP中通过mmm进行编译。
    最终会产出AppBinderService.apk。
    然后通过adb install -r AppBinderService.apk 安装到设备中。
```

- 执行Service端
    ```
	通过点击应用图标运行Service。
	// 等待客户端进行通信， 如果客户被执行后，Service会输出下面日志：
	2020-07-20 17:46:15.948 750-750/com.example.appbinderservice D/Sven AppBinderService: AppBinderService start.
	2020-07-20 17:46:30.403 750-775/com.example.appbinderservice D/Sven FirstAppBinderService: setName() Entry - newName is: SvenCheng
	2020-07-20 17:46:30.408 750-775/com.example.appbinderservice D/Sven FirstAppBinderService: getName() Entry - the name is: SvenCheng
	2020-07-20 17:46:30.415 750-775/com.example.appbinderservice D/Sven FirstAppBinderService: add() Entry - the a is: 5, the b is: 6
	```

- 执行Client端
    ```
    ./AppBinderClient   // 运行客户端建立通信
	main():LINE:16 Start.
	main():LINE:51 End.
	````
	
# 注意
```
    APK或者framework直接调用做service时需要进行系统签名，否则在ServiceManager.add_service时会提示权限问题：
    add_service('FirstAppBinderService',95) uid=10050 - PERMISSION DENIED - 原因：这个应用程序不是系统用户运行的，只有系统服务允许登记了应用程序系统才能正常运行。
    因此需要在AndroidManifest.xml中增加 - android:sharedUserId="android.uid.system" 并在工程中增加签名文件。
	
```	

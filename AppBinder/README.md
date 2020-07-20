NativeAppBinder Test
================

用C++写的本地Binder服务，使用service manager注册本地服务，

# 可生成两个程序:

  binder service服务端: AppBinderService
  
  binder service客户端: AppBinderClient
  
该测试程序主要用来配合上层framework和APK 的Binder通信测试。 
 
 
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
    ./AppBinderClient   // 运行客户端建立通信
	main():LINE:16 Start.
	main():LINE:51 End.
	````
	
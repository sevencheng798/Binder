NativeBinder Test
================

用C++写的本地Binder服务，使用service manager注册本地服务，

# 可生成两个程序:

  binder service服务端: FirstBinderTestService
  
  binder service客户端: FirstBinderTestClient
  
# 编译并执行

- 执行Service端
    
	./FirstBinderTestService
	07-15 09:38:43.573  2388  2388 D FirstBinderServiceTest: ServiceManager: 0xb5b8fca0  
	
    07-15 09:38:43.574  2388  2388 D FirstBinderServiceTest: main():line:64 start addServer().  
	
    07-15 09:38:43.576  2388  2388 D FirstBinderServiceTest: main():line:67 start ThreadPool().  
	
    07-15 09:38:43.576  2388  2388 D FirstBinderServiceTest: main():line:70 start joinThreadPool().  
	

- 执行Client端

    ./FirstBinderTestClient  
	
	07-15 09:38:51.928  2390  2390 D FirstBinderClientTest: main():LINE:15 Start.  
	
	07-15 09:38:51.929  2390  2390 D FirstBinderClientTest: ServiceManager: 0xaf08fca0  
	
	07-15 09:38:51.930  2390  2390 D FirstBinderClientTest: main():LINE:37 start setName().  
	
	07-15 09:38:51.931  2390  2390 D BpFirstBinder: setName():LINE:29 Entry the new name: SvenCheng.  
	
	07-15 09:38:51.931  2388  2389 D FirstBinderServiceTest: setName() LINE: 25, name: SvenCheng  
	
	07-15 09:38:51.932  2390  2390 D BpFirstBinder: setName():LINE:36 reply:0, Leave.  
	
	07-15 09:38:51.932  2390  2390 D FirstBinderClientTest: main():LINE:40 start getName().  
	
	07-15 09:38:51.933  2390  2390 D BpFirstBinder: getName():LINE:43 Entry.  
	
	07-15 09:38:51.933  2388  2389 D FirstBinderServiceTest: getName() LINE: 35, name: SvenCheng  
	
	07-15 09:38:51.934  2390  2390 D FirstBinderClientTest: main():LINE:42 getName()->SvenCheng.  
	
	07-15 09:38:51.934  2390  2390 D FirstBinderClientTest: main():LINE:44 start add().  
	
	07-15 09:38:51.935  2390  2390 D BpFirstBinder: add():LINE:54 Entry.  
	
	07-15 09:38:51.935  2390  2390 D BpFirstBinder: add():LINE:62 reply:11, Leave.  
	
	07-15 09:38:51.936  2390  2390 D FirstBinderClientTest: main():LINE:46 start total().  
	
	07-15 09:38:51.936  2390  2390 D BpFirstBinder: total():LINE:68 Entry.  
	
	07-15 09:38:51.937  2390  2390 D BpFirstBinder: total():LINE:74 total->reply:11, Leave.  
	
	07-15 09:38:51.938  2390  2390 D FirstBinderClientTest: main():LINE:49 End.  
	
	
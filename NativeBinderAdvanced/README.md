NativeBinder Test
================

用C++写的本地Binder服务，使用service manager注册本地服务，

# 可生成三个程序:

  binder service服务端: SharedBufferService
  
  binder service客户端写: SharedBufferClientW
  
  binder service客户端读: SharedBufferClientR
  
# 编译并执行

- 执行Service端
    ```
	./SharedBufferService
	07-16 14:22:14.061 10165 10165 D SharedBufferService: ServiceManager: 0xab48fca0
	07-16 14:22:14.061 10165 10165 D SharedBufferService: main():line:65 start addServer().
	07-16 14:22:14.063 10165 10165 D SharedBufferService: main():line:68 start ThreadPool().
	07-16 14:22:14.063 10165 10165 D SharedBufferService: main():line:71 start joinThreadPool().
    ```

- 执行写Client端
    ```
    ./SharedBufferClientW  
	07-16 14:22:25.520 10173 10173 D SharedBufferClientW: main():LINE:19 Start.
	07-16 14:22:25.521 10173 10173 D SharedBufferClientW: main() LINE:26 sm.get:0xb1d8fca0
	07-16 14:22:25.522 10173 10173 D BpSharedBuffer: getBuffer() LINE = 25 Entry.
	07-16 14:22:25.523 10173 10173 D BpSharedBuffer: getBuffer() LINE = 34 Leave.
	07-16 14:22:25.524 10173 10173 D SharedBufferClientW: main() LINE:56 Get IMemory->size() -> 1048576
	07-16 14:22:25.524 10173 10173 D SharedBufferClientW: main() LINE:61 End. 
    ````
- 执行写Client端
	````
	./SharedBufferClientR
	07-16 14:22:27.920 10176 10176 D SharedBufferClientR: main():LINE:19 Start.
	07-16 14:22:27.920 10176 10176 D SharedBufferClientR: main() LINE:26 sm.get:0xb268fca0
	07-16 14:22:27.920 10176 10176 D BpSharedBuffer: getBuffer() LINE = 25 Entry.
	07-16 14:22:27.920 10176 10176 D BpSharedBuffer: getBuffer() LINE = 34 Leave.
	07-16 14:22:27.921 10176 10176 D SharedBufferClientR: main() LINE:57 Get IMemory->size() -> 1048576 - 0
	07-16 14:22:27.921 10176 10176 D SharedBufferClientR: main() LINE:58 read data: I am is SharedBuffer example!!!
	07-16 14:22:27.921 10176 10176 D SharedBufferClientR: main() LINE:60 End.
	````
	
[详细介绍参考](https://blog.csdn.net/jltxgcy/article/details/31724655)	
	
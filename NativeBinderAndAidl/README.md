NativeBinderAndAidl test
================

主要学习Binder的有关通信，包括Native Binder通信、AIDL通信。  
该测试是通过.aidl文件自动在native生成相关的BnBinder和BpBinder类接口。   
开发者只实现native service(BnBinder)即可，该方法省略了自己编写BnBinder及BpBinder的实现细节。   
该小节还实现了通过aidl注册callback用于service主动通知client有关的信息。   

# 目录结构
.  
├── aidl-generated   
│   ├── include  
│   └── src  
└── NativeAidl  
    ├── android  
    ├   └── notification  
    ├── Android.mk  
    ├── main.cpp  
    ├── NotificationBinderService.cpp  
    └── NotificationBinderService.h  

- aidl-generated 为Android.mk编译的时候自动生成的。 主要aidl工具链自动实现了Bnbinder和BpBinder接口类。   
- NativeAidl 包含了aidl接口定义及Bnbinder service的实现。   

# 编译
```
   cd NativeAidl
   mm
```
会生成NativetestService可执行文件。  
同时会自动生成aidl-generated接口类的实现。目录通常在：  
`out/target/product/${target_board}/obj/EXECUTABLES/NativetestService_intermediates/aidl-generated/`


# Client实现

### java aidl client实现

首先，要把aidl文件放置到AS对应aidl目录中。  
```java
import android.notification.INotificationGatewayService;
import android.notification.INotificationGatewayCallback;

        INotificationGatewayService mNotificationServer;
        IBinder notificationBinder = ServiceManager.getService("notification_service");
        if(notificationBinder != null) {
            Log.d(TAG, "======Client getService notification_service sucessfully.");
            mNotificationServer = INotificationGatewayService.Stub.asInterface(notificationBinder);
            try {
                // register a callback. service会间隔5s调用callback一次
                mNotificationServer.registerNotificationCallback(new INotificationGatewayCallback.Stub() {
                    @Override
                    public void onClickNotification(String notificationid) throws RemoteException {
                        Log.i(TAG, "==================>>>>onClickNotification: " + notificationid);
                    }

                    @Override
                    public void onDelNotification(String notificationid) throws RemoteException {
                        Log.i(TAG, "==================>>>>onDelNotification");
                    }
                });

            } catch(RemoteException e) {
                e.printStackTrace();
            }
        } else {
            Log.d(TAG, "======Client getService notification_service failed.");
            return;
        }
```


### native client实现

暂未实现
```cpp
	   sp<IServiceManager> sm = defaultServiceManager();
	    sp<IBinder> binder = sm->getService(String16(INotificationGatewayService::SERVICE_NAME());
	    sp<INotificationBinderService> cs = interface_cast<INotificationBinderService>(binder);
	    cs->onClickNotification(String16("10"));   //调用service里面的方法

```

# Native service执行
将可执行文件NativetestService push到android设备。 
```bash
./NativetestService 

09-01 14:20:20.268 19892 19892 E NotificationBinderService: Notification>>NotificationBinderService
09-01 14:20:25.269 19892 19897 D NotificationBinderService: Notification>>INotificationGatewayCallback callback_ is null notificationid:1
09-01 14:20:25.434 19892 19898 D NotificationBinderService: Notification>>Success to register callback, already registered
09-01 14:20:30.270 19892 19897 D NotificationBinderService: Notification>>onClickNotification
09-01 14:20:35.274 19892 19897 D NotificationBinderService: Notification>>onClickNotification
09-01 14:20:40.276 19892 19897 D NotificationBinderService: Notification>>onClickNotification
09-01 14:20:45.281 19892 19897 D NotificationBinderService: Notification>>onClickNotification
09-01 14:20:50.284 19892 19897 D NotificationBinderService: Notification>>onClickNotification
09-01 14:20:55.290 19892 19897 D NotificationBinderService: Notification>>onClickNotification

```

# Java aidl client执行

执行apk后回调没隔5s被执行一次：  
回调输出日志：
```bash
09-01 14:20:08.909 19763 19763 D BinderActivity: [ThreadId 2] [ProcessId 19763]  onCreate
09-01 14:20:08.914 19763 19763 D BinderActivity: ======Client getService test failed.
09-01 14:20:25.433 19763 19763 D BinderActivity: ======Client getService notification_service sucessfully.
09-01 14:20:30.271 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:20:35.275 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:20:40.277 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:20:45.282 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:20:50.289 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:20:55.292 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:21:00.295 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:21:05.297 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:21:10.300 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:21:15.304 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
09-01 14:21:20.307 19763 19796 I BinderActivity: ==================>>>>onClickNotification: 123abc
```

[参考连接https://blog.csdn.net/po__oq/article/details/80985658](https://blog.csdn.net/po__oq/article/details/80985658)
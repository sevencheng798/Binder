package com.example.appbinder;

import android.os.IInterface;
import android.os.RemoteException;

public interface IFirstAppBinder extends IInterface {
	/**
	 * 这个Descriptor必须和 binder service name 一致，否则会发生无法获取服务BBinder问题， 导致程序奔溃
	 * 在此我们使用AppBinderService.cpp中的BinderService->getServiceName.
	 */
	static final java.lang.String DESCRIPTOR = "app.binder.service";

	int setName(String name) throws RemoteException;

	String getName() throws RemoteException;

	int add(int a, int b) throws RemoteException;

	int total() throws  RemoteException;

	static final int TRANSACTION_SET_NAME = (android.os.IBinder.FIRST_CALL_TRANSACTION );
	static final int TRANSACTION_GET_NAME = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
	static final int TRANSACTION_ADD = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
	static final int TRANSACTION_TOTAL = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
}

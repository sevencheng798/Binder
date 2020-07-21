package com.example.appbinderservice;

import android.os.IInterface;
import android.os.RemoteException;

public interface IFirstAppBinder extends IInterface {
	/**
	 * 这个Descriptor必须和 binder client name 一致，否则会发生无法获取服务BBinder问题， 导致程序奔溃.
	 * 有以上，Server端的功能就已经可以实现，但在两端通信时，为了两端Binder匹配，我们还需要在Server端做一次验证，
	 * 用到data.enforceInterface(DESCRIPTOR)这个方法，DESCRIPTOR是Binder描述符，Binder Server和Client之间将通过
	 * 这个描述符做验证，要想通过验证Binder通信的两端DESCRIPTOR必须相同，这也是为什么我们在使用AIDL帮助我们生成
	 * Binder代码的时候，必须把AIDL放在相同的包名下，因为SDK会根据包名为我们生成对应的DESCRIPTOR字符串，这里我们
	 * 手写Binder，只需要保证两端相同就好了，包名字符串不是必须的
	 *
	 * 作者：许峻华
	 * 链接：https://www.jianshu.com/p/0fff33c09f34
	 * 来源：简书
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

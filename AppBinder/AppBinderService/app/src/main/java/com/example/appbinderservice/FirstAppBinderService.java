package com.example.appbinderservice;

import android.os.Binder;
import android.os.IBinder;
import android.os.IInterface;
import android.os.Parcel;
import android.os.RemoteException;
import android.util.Log;

public class FirstAppBinderService extends Binder implements IFirstAppBinder {
	private String TAG = "Sven FirstAppBinderService";
	private String mName;
	private int mTotal;
	public FirstAppBinderService() {
		this.attachInterface(this, DESCRIPTOR);
	}

	@Override
	public IBinder asBinder() {
		return this;
	}

	/** 将FirstAppBinderService转换为IFirstAppBinder接口 **/
	public static IFirstAppBinder asInterface(
			android.os.IBinder obj) {
		if ((obj == null)) {
			return null;
		}
		android.os.IInterface iInterface = obj.queryLocalInterface(DESCRIPTOR);
		if (((iInterface != null) && (iInterface instanceof IFirstAppBinder))) {
			return ((IFirstAppBinder) iInterface);
		}
		return null;
	}

	/**  服务端，接收远程消息，处理onTransact方法  **/
	@Override
	protected boolean onTransact(int code, Parcel data, Parcel reply, int flags)
			throws RemoteException {
		switch (code) {
			case TRANSACTION_SET_NAME: {
				data.enforceInterface(DESCRIPTOR);
				String newName = data.readString();
				int result = setName(newName);
				reply.writeInt(result);
				break;
			}
			case TRANSACTION_GET_NAME: {
				data.enforceInterface(DESCRIPTOR);
				String name = getName();
				reply.writeString(name);
			}
			break;
			case TRANSACTION_ADD: {
				data.enforceInterface(DESCRIPTOR);
				// 按写入顺序读取数据
				int a = data.readInt();
				int b = data.readInt();
				int sum = add(a, b);
				reply.writeInt(sum);
			}
			break;
			case TRANSACTION_TOTAL: {
				data.enforceInterface(DESCRIPTOR);
				int sum = total();
				reply.writeInt(sum);
			}
			break;
			default: {
				return super.onTransact(code, data, reply, flags);
			}
		}

		return true;
	}

	@Override
	public int setName(String name) {
		Log.d(TAG, "setName() Entry - newName is: "+name);
		if(name != null) {
			mName = name;
			return 0;
		}
		return -1;
	}

	@Override
	public String getName() {
		Log.d(TAG, "getName() Entry - the name is: "+mName);
		return mName;
	}

	@Override
	public int add(int a, int b) {
		Log.d(TAG, "add() Entry - the a is: "+a + ", the b is: "+b);
		mTotal = a+b;
		return mTotal;
	}

	@Override
	public int total() {
		Log.d(TAG, "total() Entry - the total is: "+mTotal);
		return mTotal;
	}
}

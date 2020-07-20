package com.example.appbinder;

import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

public class FirstAppBinderProxy implements IFirstAppBinder {
    private String TAG = "Sven FirstAppBinderProxy";
	private android.os.IBinder mRemote;

	public FirstAppBinderProxy(android.os.IBinder remote) {
	    Log.d(TAG, "Constructor FirstAppBinderProxy()!!!");
		mRemote = remote;
	}

	public java.lang.String getInterfaceDescriptor() {
		return DESCRIPTOR;
	}

	@Override
	public int setName(String str) throws RemoteException {
		int result = -1;
		android.os.Parcel _data = android.os.Parcel.obtain();
		android.os.Parcel _reply = android.os.Parcel.obtain();
		try {
			Log.d(TAG, "=======================> setName() new name: "+str);
			// First, make sure interface verification.
			// BnService 也需要进行校验，在读取数据，需要client-service配对
			_data.writeInterfaceToken(DESCRIPTOR);
			_data.writeString(str);
			mRemote.transact(TRANSACTION_SET_NAME, _data, _reply, 0);
			_reply.readException();
			result = _reply.readInt();
			Log.d(TAG, "setName() result: "+result);
		} finally {
			_reply.recycle();
			_data.recycle();
		}

		return result;
	}

	@Override
	public String getName() throws RemoteException {
		String name;
		android.os.Parcel _data = android.os.Parcel.obtain();
		android.os.Parcel _reply = android.os.Parcel.obtain();

		try {
			Log.d(TAG, "==============================> getName().");
			_data.writeInterfaceToken(DESCRIPTOR);
			mRemote.transact(TRANSACTION_GET_NAME, _data, _reply, 0);
			name = _reply.readString();
			Log.d(TAG, "setName() result: "+name);
		} finally {
			_reply.recycle();
			_data.recycle();
		}
		return name;
	}

	@Override
	public int add(int a, int b) throws RemoteException {
		android.os.Parcel _data = android.os.Parcel.obtain();
		android.os.Parcel _reply = android.os.Parcel.obtain();
		int result = -1;
		try {
			Log.d(TAG, "==============================>  add() function");
			_data.writeInterfaceToken(DESCRIPTOR);
			_data.writeInt(a);
			_data.writeInt(b);
			mRemote.transact(TRANSACTION_ADD, _data, _reply, 0);
			result = _reply.readInt();
			Log.d(TAG, "==============================>  add() result: "+result);
		} finally {
			_reply.recycle();
			_data.recycle();
		}
		return result;
	}

	@Override
	public IBinder asBinder() {
		return mRemote;
	}

	@Override
	public int total() throws RemoteException {
		int result = -1;
		android.os.Parcel _data = android.os.Parcel.obtain();
		android.os.Parcel _reply = android.os.Parcel.obtain(); 
		try {
            Log.d(TAG, "==============================>  total() function");
			_data.writeInterfaceToken(DESCRIPTOR); 
			mRemote.transact(TRANSACTION_TOTAL, _data, _reply, 0);
			result = _reply.readInt();
			Log.d(TAG, "==============================>  total() result: "+result);
		} finally {
			_reply.recycle();
			_data.recycle();
		}

		return result;
	}

}

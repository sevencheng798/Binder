package com.example.appbinder;

import android.app.Activity;
import android.os.Bundle;
import android.os.IBinder;
import android.os.Process;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;
import android.view.View;

public class MainActivity extends Activity {
    private String TAG = "Sven MainActivity";
    private IFirstAppBinder binderProxy = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.d(TAG, "[ThreadId " + Thread.currentThread().getId() + "] [ProcessId " + Process.myPid() + "]  onCreate");
        findViewById(R.id.btn_setName).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Log.d(TAG, "=========== Client call AppBinder setName() function");
                    binderProxy.setName("HelloSven");
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
            }
        });

        findViewById(R.id.btn_getName).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Log.d(TAG, "=========== Client call AppBinder getName() function");
                    String name = binderProxy.getName();
                    Log.d(TAG, "=========== Client call AppBinder getName() name: "+name);
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
            }
        });

        findViewById(R.id.btn_add).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Log.d(TAG, "======Client call AppBinder add() function");
                    int a = binderProxy.add(3, 2);
                    Log.d(TAG, "======Client call AppBinder add() function reuslt : " + a);
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
            }
        });

        findViewById(R.id.btn_getSum).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Log.d(TAG, "======Client call AppBinder total() function");
                   int result =  binderProxy.total();
                    Log.d(TAG, "======Client call AppBinder add() function reuslt : " + result);
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
            }
        });

    }

    @Override
    protected void onStart() {
        super.onStart();
        IBinder binder = ServiceManager.getService("app.binder.service");
        if(binder != null) {
            Log.d(TAG, "======Client getService test sucessfully.");
        } else {
            Log.d(TAG, "======Client getService test failed.");
            return;
        }
        binderProxy = new FirstAppBinderProxy(binder);
        findViewById(R.id.btn_setName).setEnabled(true);
        findViewById(R.id.btn_getName).setEnabled(true);
        findViewById(R.id.btn_add).setEnabled(true);
        findViewById(R.id.btn_getSum).setEnabled(true);
    }

    @Override
    protected void onStop() {
        super.onStop();
    }

    @Override
    protected void onDestroy() {

        super.onDestroy();

    }

}

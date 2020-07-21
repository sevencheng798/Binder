package com.example.appbinderservice;

import android.app.Activity;
import android.os.Bundle;
import android.os.ServiceManager;
import android.util.Log;

public class MainActivity extends Activity {
    private String TAG = "Sven AppBinderService";
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        System.out.println("AppBinderService Start");
        Log.d(TAG, "AppBinderService start.");
        ServiceManager.addService(IFirstAppBinder.DESCRIPTOR, new FirstAppBinderService());//注册服务
    }
}

package android.os;

/**
 * ClassName:ServiceManager
 * 
 * @author Zhouyaoyun
 * @version
 * @since Ver 1.1
 * @Date 2014-4-18 下午7:12:14
 * 
 * @see
 */
import android.util.Log;
public class ServiceManager {
    private static String TAG = "ServiceManager";
    public static IBinder getService(String name) {
        Log.d(TAG, "getService entry!");
        return null;
    }

}

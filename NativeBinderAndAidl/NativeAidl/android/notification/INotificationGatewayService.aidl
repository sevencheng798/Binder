package android.notification;

import android.notification.INotificationGatewayCallback;

/**
 * {@hide}
 */
	
interface INotificationGatewayService {
		const String SERVICE_NAME = "notification_service";
		/**
	     * new notification to linux
		 * param priority: [-2,2]. 2 is highest priority
		 * param isAction: set true,it is triggered and opened the detailed page
	     */
		void addNotification(String title, String content, String icon, String notificationid, String packageName, int priority,boolean isAction);
	
	/**
     * new popup to linux.  
	 * param paramsJson: see specific doc
     */
	void addPopup(String notificationid, String packageName, String icon, String paramsJson);

	/**
     * delete all notifications of certain app(app uninstall)
     */ 
	void delAllNotification(String packageName);

	/**
     * register callback
     */ 
    void registerNotificationCallback(INotificationGatewayCallback callback);
}

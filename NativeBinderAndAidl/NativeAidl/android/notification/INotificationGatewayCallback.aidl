package android.notification;


interface INotificationGatewayCallback{
	/**
	 * click event, android will receive and handle
	 */ 	
    void onClickNotification(String notificationid);
	
	/**
     * delete notification
     */ 
	void onDelNotification(String notificationid);
}

HIDL HAL Interfaces Test
================

这是一个HIDL带有异步回调的应用实例，我们需要给这个简单的例子起一个牛逼的名字，我这里叫Hello

# 快速上手
```bash
  1. Hidl接口服务端编译，执行以下指令
    #拷贝hal/hello目录到${AOSP}/vendor/mediatek/proprietary/hardware/interfaces/目录下
    cp hal/hello -rf ${AOSP}/vendor/mediatek/proprietary/hardware/interfaces
    #进入Android源码顶层目录
    cd ${AOSP}/
    #编译
    mmm vendor/mediatek/proprietary/hardware/interfaces/hello
  2. Hidl客户端测试程序，执行以下指令
    #拷贝client到external目录
	cp client -rf ${AOSP}/vendor/mediatek/proprietary/external/hello_client
	#进入Android源码顶层目录
    cd ${AOSP}/
    #编译
    mmm vendor/mediatek/proprietary/external/hello_client
  3. 增加Selinux访问权限
	# device/mediatek/mt8167/manifest.xml
	<hal format="hidl">
		<name>vendor.mediatek.hardware.hello</name>
		<transport>hwbinder</transport>
		<version>1.0</version>
		<interface>
			<name>IHello</name>
			<instance>default</instance>
		</interface>
	</hal>
   4.整编整个系统并烧录固件到设备中。
   注意修改了manifest.xml文件必须要整编
```

# 执行测试
服务端运行：
```bash
  /vendor/bin/hw/vendor.mediatek.hardware.hello@1.0-service
```

客户端运行：
```bash
  /system/bin/hello_client
```
执行完成之后回输出：
```
    07-29 10:38:01.449  2060  2060 D HelloClient: main: get hello service ok
	07-29 10:38:02.451  2060  2061 D HelloClient: onNotify: value = 0
	07-29 10:38:03.452  2060  2061 D HelloClient: onNotify: value = 1
	07-29 10:38:04.452  2060  2061 D HelloClient: onNotify: value = 2
	07-29 10:38:05.453  2060  2061 D HelloClient: onNotify: value = 3
	07-29 10:38:06.454  2060  2061 D HelloClient: onNotify: value = 4
	07-29 10:38:07.455  2060  2061 D HelloClient: onNotify: value = 5
	07-29 10:38:08.455  2060  2061 D HelloClient: onNotify: value = 6
	07-29 10:38:09.456  2060  2061 D HelloClient: onNotify: value = 7
	07-29 10:38:10.457  2060  2061 D HelloClient: onNotify: value = 8
	07-29 10:38:11.457  2060  2061 D HelloClient: onNotify: value = 9

```

[详细说明请参考](https://blog.csdn.net/sevenjoin/article/details/107644774)
	
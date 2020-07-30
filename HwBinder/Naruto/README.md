HIDL HAL Interfaces Test
================

这是第一个HIDL应用实例，我们需要给这个简单的例子起一个牛逼的名字，我这里叫Naruto

# 快速上手
```bash
  1. Hidl接口服务端编译，执行以下指令
    #拷贝hal/naruto目录到${AOSP}/hardware/interfaces/目录下
    cp hal/naruto -rf ${AOSP}/hardware/interfaces/
    #进入Android源码顶层目录
    cd ${AOSP}/
    #编译
    mmm hardware/interfaces/naruto
  2. Hidl客户端测试程序，执行以下指令
    #拷贝client到external目录
	cp client -rf ${AOSP}/external/naruto_client
	#进入Android源码顶层目录
    cd ${AOSP}/
    #编译
    mmm external/naruto_client
  3. 增加Selinux访问权限
	# device/mediatek/mt8167/manifest.xml
	<hal format="hidl">
		<name>android.hardware.naruto</name>
		<transport>hwbinder</transport>
		<version>1.0</version>
		<interface>
			<name>INaruto</name>
			<instance>default</instance>
		</interface>
	</hal>
   4.整编整个系统并烧录固件到设备中。
   注意修改了manifest.xml文件必须要整编
```

# 执行测试
服务端运行：
```bash
  /system/bin/android.hardware.naruto@1.0-service
```

客户端运行：
```bash
  /vendor/bin/hw/naruto_test
```
执行完成之后回输出：
```
   结果输出"HelloWorld, SvenCheng", 符合我们的预期结果
```

[详细说明请参考](https://blog.csdn.net/sevenjoin/article/details/107619014)
	
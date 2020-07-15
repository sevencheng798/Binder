// 这是第一个native binder测试程序
// 2020-07-14
// Creator @Sven
// 这是Bnbinder 服务端业务逻辑

class FirstBinderServiceTest : public BnFirstBinderTest {
public:
	FirstBinderServiceTest();
	
	virtual int add(int a, int b);
};


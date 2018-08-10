#ifndef _HERO_H_
#define _HERO_H_

#include "cocos2d.h"

USING_NS_CC;

//ֻ�����ó�ʼλ�á�
class Hero : public Sprite
{
public:
	Hero();
	~Hero();
	virtual bool init(Layer* layer, std::string plist, std::string png);
	virtual void update(float dt);

private:
	enum actionMessage { up = 1001, betterUp, left, right, down, betterDown, stay, sleep, over };//������ϢЭ��
	enum Tag { HeroTag, BlockTag, PowerBlockTag };
	Layer* _layer;
	int _message;//��Ϣ�洢��
	int _actMessage = stay;//��ʼ������Ϣ
	Vec2 _pointRecord;//λ�ü�¼��

private:
	std::string _plist;
	std::string _png;

private:
	Sprite* upIng;
	Sprite* downIng;
	Sprite* leftIng;
	Sprite* rightIng;
	Sprite* stayIng;
	Sprite* sleepIng;
	Sprite* overIng;

private:
	bool _bodyInit();//��ʼ������
	bool _spriteInit();//��ʼ������
	void _dealWithMessage();//��Ϣ�ַ�������
	void _dealWithActionMessage();//������Ϣ������
	void autoJump();
	void jump();

public:
	int height;//���ⲿʹ��
	int overHeight = 0;
	
public:
	//����ɫλ�ã��������ƶ��������Ϊ����߶�
	virtual void heroListener(float positionY);
	//ǿ���ƶ�����
	virtual void actionCommander(int act);

	//�õ���ǰhero״̬
	int getMessage();

	//** this layer, Hero's plist and png.
	//* Uping.png, Downing.png, Lefting.png, Righting.png, Staying.png, Sleeping.png, Overing.png
	//public: height, overHeight, heroListener, actionCommander, getMessage
	static Hero* create(Layer* layer, std::string plist, std::string png);//���þ�̬ȫ�ַ������������ⲿָ��

};

#endif

/**
*ע�⣺������ռ����Լ��ⲿ����Ϣ�������ڲ�������Ӧ���ⲿֻ�����ö���ļ�����ǿ�����
*

//////////////////////////////////////////////////////////////////////////

��Ϣ������ƣ�

private��
	0.��Ϣ�洢�� _message ������洢��Ϣ��
	1.��ϢЭ�� enum Message { up = 1001, left, right, down, stay, sleep, over }��
	2.��Ϣ������ _dealWithMessage ���������Լ���ѭ���У����ռ�������Ϣ����ʶ����

public��
	3.��Ϣ������ heroListener() ����������ѭ���г����������ռ���Ϣ��
	4.ǿ������ actionCommander(int message) ��ֱ��ָ����ɫ��Ϣ��

//////////////////////////////////////////////////////////////////////////

static��̬ȡ��[�ⲿ������]���ƣ�

private��
	1.������ַ���� Layer* _layer;
	2.���Ƶ�ַ���� void copyAdress(Layer* layer);//���������ĵ�ַ��
public:
	3.���캯��static ����* create(����* );//newһ���������autorelease������copyAdress����󷵻ء�

//////////////////////////////////////////////////////////////////////////

thisָ��ȡ���������ָ����е��ø���ķ�����

//////////////////////////////////////////////////////////////////////////
*/
